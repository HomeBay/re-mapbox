module Config = Mapbox_GL_Map_Config;

module FitOptions = {
  type t_js = {.
    "duration": Js.undefined(int) /* in ms */
  };

  [@bs.obj] external makeJs : (
    ~duration: int=?,
    unit
  ) => _ = ""
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

/* TODO: I just filled in what I need, but this should be better-defined. */
/* In reality, this is the combination of CameraOptions and AnimationOptions */
type mapPosition = {.
  "center": Mapbox_GL_LngLat.t,
  "zoom": float
};

type eventData = Js.Dict.t(Js.Json.t);

type t = {.
  /* Methods to position the map */
  [@bs.meth] "setCenter": Mapbox_GL_LngLat.t => t,
  [@bs.meth] "setZoom": float => t,
  [@bs.meth] "fitBounds": Mapbox_GL_LngLatBounds.t => FitOptions.t_js => t,
  [@bs.meth] "fitBounds__eventData": Mapbox_GL_LngLatBounds.t => FitOptions.t_js => Js.Dict.t(Js.Json.t) => t,
  [@bs.meth] "easeTo": mapPosition => t,

  /* Methods to deal with events */
  [@bs.meth] "on": (string, eventData => unit) => t,
  [@bs.meth] "on__layerEvent": (string, string, eventData => unit) => t,
  [@bs.meth] "off": (string, eventData => unit) => t,
  [@bs.meth] "off__layerEvent": (string, string, eventData => unit) => t,

  /* Methods to deal with layers and sources */
  [@bs.meth] "addLayer": Mapbox_GL_Layer.t_js => t,
  [@bs.meth] "getLayer": string => Js.undefined(Mapbox_GL_Layer.t_js),
  [@bs.meth] "removeLayer": string => t, /* TODO: docs don't specify return */
  [@bs.meth] "addSource": string => Mapbox_GL_Source.t_js => t,
  [@bs.meth] "getSource": string => Js.undefined(source),
  [@bs.meth] "removeSource": string => t,

  /* Methods to deal with DOM elements */
  [@bs.meth] "getContainer": unit => Dom.element,
  [@bs.meth] "getCanvasContainer": unit => Dom.element,
  [@bs.meth] "getCanvas": unit => Dom.element,

  /* Methods to deal with internal state, cleanup, and more */
  [@bs.meth] "getBounds": unit => Mapbox_GL_LngLatBounds.t,
  [@bs.meth] "queryRenderedFeatures": (Mapbox_GL_Point.t, QueryRenderedFeaturesOptions.t) => array(Js.Json.t),
  [@bs.meth] "resize": unit => unit,
  [@bs.meth] "remove": unit => unit,
};

[@bs.new][@bs.module "mapbox-gl/dist/mapbox-gl.js"]
external createExn: Config.jsObj => t = "Map";

let create = cfg =>
  try (Belt.Result.Ok(createExn(cfg))) {
  | _ => Belt.Result.Error("Failed to initialize MapboxGL")
  };
