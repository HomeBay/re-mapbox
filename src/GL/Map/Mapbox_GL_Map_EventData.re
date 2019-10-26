module Base = {
  type t;
};

module Error = {
  type t;
  external asBaseEvent: t => Base.t = "%identity";
  [@bs.get] external message: t => string = "message";
};

module ImageMissing = {
  type t;
  [@bs.get] external id: t => string = "id";
};

module Data = {
  type t;
  external asBaseEvent: t => Base.t = "%identity";
  [@bs.get] external type_: t => string = "type";
  [@bs.get] external dataType: t => string = "dataType";
  [@bs.get] external isSourceLoaded: t => bool = "isSourceLoaded";

  [@bs.get] [@bs.return nullable]
  external source: t => option(Mapbox_GL_Source.t) = "source";

  // TODO: not sure what the type of "tile" is... docs just say Object
  // [@bs.get] [@bs.return nullable]
  // external tile: t => option(???) = "tile";

  // TODO: docs claim the type is "Coordinate" but there's no definition
  // [@bs.get] [@bs.return nullable]
  // external coord: t => option(???) = "coord";

  [@bs.get] [@bs.return nullable]
  external sourceDataType: t => option(string) = "sourceDataType";
};

module Drag = {
  type t;
  external asBaseEvent: t => Base.t = "%identity";
  [@bs.get] external originalEvent: t => Dom.dragEvent = "originalEvent";
};

module Touch = {
  type t;

  external asBaseEvent: t => Base.t = "%identity";

  [@bs.get] external type_: t => string = "type";

  [@bs.get] external originalEvent: t => Dom.touchEvent = "originalEvent";
  [@bs.get] external point: t => Mapbox_GL_Point.t = "point";
  [@bs.get] external lngLat: t => Mapbox_GL_LngLat.t = "lngLat";

  // TODO: these are related to `TouchEvent.touches`, so I'm not sure if they're
  // actually arrays or something else
  [@bs.get] external points: t => array(Mapbox_GL_Point.t) = "points";
  [@bs.get] external lngLats: t => array(Mapbox_GL_LngLat.t) = "lngLats";

  [@bs.send] external preventDefault: t => unit = "preventDefault";
  [@bs.get] external defaultPrevented: t => bool = "defaultPrevented";
};

module Mouse = {
  // The docs (https://docs.mapbox.com/mapbox-gl-js/api/#mapmouseevent) are
  // pretty sparse when it comes to the actual _types_ of things available here.
  // For now, I'm just going to bind to what I need (and the few things that are
  // very clear in the docs).
  type t;

  external asBaseEvent: t => Base.t = "%identity";

  [@bs.get] external type_: t => string = "type";
  // [@bs.get] external target: t => Map.t = "target"; // circular ref...

  [@bs.get] external originalEvent: t => Dom.mouseEvent = "originalEvent";

  // this isn't clearly specified in the docs, so I'm making assumptions based
  // on the name
  [@bs.get] external point: t => Mapbox_GL_Point.t = "point";
  [@bs.get] external lngLat: t => Mapbox_GL_LngLat.t = "lngLat";

  [@bs.send] external preventDefault: t => unit = "preventDefault";
  [@bs.get] external defaultPrevented: t => bool = "defaultPrevented";
};

module MouseWheel = {
  type t;
  external asBaseEvent: t => Base.t = "%identity";
};

module BoxZoom = {
  type t;
  external asBaseEvent: t => Base.t = "%identity";
  [@bs.get] external originalEvent: t => Dom.mouseEvent = "originalEvent";
};

type t = Base.t;

external asDict: t => Js.Dict.t(Js.Json.t) = "%identity";

let getProp: (t, string) => option(Js.Json.t) =
  (evt, key) => Js.Dict.get(asDict(evt), key);

let getBoolProp: (t, string) => option(bool) =
  (evt, key) =>
    getProp(evt, key)->Belt.Option.flatMap(Js.Json.decodeBoolean);

let getStringProp: (t, string) => option(string) =
  (evt, key) =>
    getProp(evt, key)->Belt.Option.flatMap(Js.Json.decodeString);

let getFloatProp: (t, string) => option(float) =
  (evt, key) =>
    getProp(evt, key)->Belt.Option.flatMap(Js.Json.decodeNumber);
