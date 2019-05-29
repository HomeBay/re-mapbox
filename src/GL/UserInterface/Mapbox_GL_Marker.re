module Options = {
  module Anchor = {
    type t;

    // TODO: hide from rei
    external fromString: string => t = "%identity";

    let center = fromString("center");
    let top = fromString("top");
    let bottom = fromString("bottom");
    let left = fromString("left");
    let right = fromString("right");
    let topLeft = fromString("top-left");
    let topRight = fromString("top-right");
    let bottomLeft = fromString("bottom-left");
    let bottomRight = fromString("bottom-right");
  };

  type rendering =
    | Custom(Dom.element)
    | Color(string);

  let getElement = r =>
    switch (r) {
    | Custom(el) => Some(el)
    | Color(_) => None
    };

  let getColor = r =>
    switch (r) {
    | Custom(_) => None
    | Color(color) => Some(color)
    };

  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    element: Dom.element,
    [@bs.optional]
    anchor: Anchor.t,
    [@bs.optional]
    offset: Mapbox_GL_Point.t,
    [@bs.optional]
    color: string,
    [@bs.optional]
    draggable: bool,
  };

  let makeLabels = t;
  let makeWithElement = (~element) => makeLabels(~color=?None, ~element);
};

type t;

[@bs.new] [@bs.module "mapbox-gl/dist/mapbox-gl.js"]
external make: unit => t = "Marker";

[@bs.new] [@bs.module "mapbox-gl/dist/mapbox-gl.js"]
external makeWithOptions: Options.t => t = "Marker";

[@bs.send] external addTo: (t, Mapbox_GL_Map.t) => t = "addTo";
[@bs.send] external remove: t => t = "remove";
[@bs.send] external getLngLat: t => Mapbox_GL_LngLat.t = "getLngLat";
[@bs.send] external setLngLat: (t, Mapbox_GL_LngLat.t) => t = "setLngLat";
[@bs.send] external getElement: t => Dom.element = "getElement";
// TODO: setPopup
// TODO: getPopup
// TODO: togglePopup
[@bs.send] external getOffset: t => Mapbox_GL_Point.t = "getOffset";
[@bs.send] external setOffset: (t, Mapbox_GL_Point.t) => t = "setOffset";
[@bs.send] external setDraggable: (t, bool) => t = "setDraggable";
[@bs.send] external isDraggable: t => bool = "isDraggable";
