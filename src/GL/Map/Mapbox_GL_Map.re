module Config = Mapbox_GL_Map_Config;

module FitOptions = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] duration: int, /* time in ms */
  };
};

module QueryRenderedFeaturesOptions = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] layers: array(string),
    [@bs.optional] filter: array(string)
  };
};

type callback('a) = (Js.null(string), 'a) => unit;

/* This thing is confusing. It's probably the original object you provided when
   creating the source, but with extra methods added to it, depending on what
   "type" of source it is. For now, we just expose all methods to you.
*/
type source = {.
  [@bs.meth] "setData": Js.Json.t => source,
  [@bs.meth] "getClusterExpansionZoom": (float, callback(float)) => source,
  [@bs.meth] "getClusterChildren": (float, callback(Js.Json.t)) => source,
  [@bs.meth] "getClusterLeaves": (float, float, float, callback(Js.Json.t)) => source
};

type eventData = Js.Dict.t(Js.Json.t);

type t;

[@bs.new][@bs.module "mapbox-gl/dist/mapbox-gl.js"]
external createExn: Config.jsObj => t = "Map";

let create = cfg =>
  try (Belt.Result.Ok(createExn(cfg))) {
  | _ => Belt.Result.Error("Failed to initialize MapboxGL")
  };

/* Methods to position the map */
[@bs.send] external setCenter: (t, float) => t = "setCenter";
[@bs.send] external setZoom: (t, float) => t = "setZoom";
[@bs.send] external fitBounds: (t, Mapbox_GL_LngLatBounds.t, FitOptions.t) => t = "fitBounds";
[@bs.send] external fitBoundsWithEventData: (t, Mapbox_GL_LngLatBounds.t, FitOptions.t, Js.Dict.t(Js.Json.t)) => t = "fitBounds";
[@bs.send] external easeTo: (t, Mapbox_GL_CameraAnimationOptions.t) => t = "easeTo";

/* Methods to deal with events */
[@bs.send] external on: (t, string, eventData => unit) => t = "on";
[@bs.send] external onLayerEvent: (t, string, string, eventData => unit) => t = "on";
[@bs.send] external off: (t, string, eventData => unit) => t = "off";
[@bs.send] external offLayerEvent: (t, string, string, eventData => unit) => t = "off";

/* Helpers for working with specific kinds of events */
let onClick = (map, callback) => on(map, "click", callback);
let onMouseEnter = (map, callback) => on(map, "mouseenter", callback);
let onMouseLeave = (map, callback) => on(map, "mouseleave", callback);

let onLayerClick = (map, layerId, callback) => onLayerEvent(map, "click", layerId, callback);
let onLayerMouseEnter = (map, layerId, callback) => onLayerEvent(map, "mouseenter", layerId, callback);
let onLayerMouseLeave = (map, layerId, callback) => onLayerEvent(map, "mouseleave", layerId, callback);

let offClick = (map, callback) => off(map, "click", callback);
let offMouseEnter = (map, callback) => off(map, "mouseenter", callback);
let offMouseLeave = (map, callback) => off(map, "mouseleave", callback);

let offLayerClick = (map, layerId, callback) => offLayerEvent(map, "click", layerId, callback);
let offLayerMouseEnter = (map, layerId, callback) => offLayerEvent(map, "mouseenter", layerId, callback);
let offLayerMouseLeave = (map, layerId, callback) => offLayerEvent(map, "mouseleave", layerId, callback);

/* Methods to deal with layers and sources */
[@bs.send] external addLayer: (t, Mapbox_GL_Layer.t_js) => t = "addLayer";
[@bs.send][@bs.return nullable] external getLayer: (t, string) => option(Mapbox_GL_Layer.t_js) = "getLayer";
[@bs.send] external removeLayer: (t, string) => unit = "removeLayer"; /* TODO: docs don't specify return */
[@bs.send] external addSource: (t, string) => Mapbox_GL_Source.t_js => t = "addSource";
[@bs.send][@bs.return nullable] external getSource: (t, string) => option(source) = "getSource";
[@bs.send] external removeSource: (t, string) => t = "removeSource";

/* Methods to deal with DOM elements */
[@bs.send] external getContainer: t => Dom.element = "getContainer";
[@bs.send] external getCanvasContainer: t => Dom.element = "getCanvasContainer";
[@bs.send] external getCanvas: t => Dom.element = "getCanvas";

/* Methods to deal with internal state, cleanup, and more */
[@bs.send] external getBounds: t => Mapbox_GL_LngLatBounds.t = "getBounds";
[@bs.send] external getZoom: t => float = "getZoom";
[@bs.send] external queryRenderedFeatures: (t, Mapbox_GL_Point.t, QueryRenderedFeaturesOptions.t) => array(Js.Json.t) = "queryRenderedFeatures";
[@bs.send] external resize: t => unit = "resize";
[@bs.send] external resizeWithEventData: t => Js.Dict.t(Js.Json.t) => unit = "resizeEventData";
[@bs.send] external remove: t => unit = "remove";
