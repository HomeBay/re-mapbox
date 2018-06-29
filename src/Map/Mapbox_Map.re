module Config = Mapbox_Map_Config;

module FitOptions = {
  type t_js = {.
    "duration": Js.undefined(int) /* in ms */
  };

  [@bs.obj] external makeJs : (
    ~duration: int=?,
    unit
  ) => _ = ""
};

type eventData = Js.Dict.t(Js.Json.t);

type t = {.
  [@bs.meth] "setCenter": Mapbox_LngLat.t => t,
  [@bs.meth] "setZoom": float => t,
  [@bs.meth] "fitBounds": Mapbox_LngLatBounds.t => FitOptions.t_js => t,
  [@bs.meth] "fitBounds__eventData": Mapbox_LngLatBounds.t => FitOptions.t_js => Js.Dict.t(Js.Json.t) => t,
  [@bs.meth] "on": (string, eventData => unit) => t,
  [@bs.meth] "remove": unit => unit,
  [@bs.meth] "resize": unit => unit,
  [@bs.meth] "getBounds": unit => Mapbox_LngLatBounds.t
};

[@bs.new][@bs.module "mapbox-gl/dist/mapbox-gl.js"]
external create: Config.jsObj => t = "Map";
