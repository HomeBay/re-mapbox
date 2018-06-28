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

type t = {.
  [@bs.meth] "setCenter": Mapbox_LngLat.t => t,
  [@bs.meth] "setZoom": float => t,
  [@bs.meth] "fitBounds": Mapbox_LngLatBounds.t => FitOptions.t_js => t,
  [@bs.meth] "on": (string, unit => unit) => t,
  [@bs.meth] "remove": unit => unit,
  [@bs.meth] "resize": unit => unit,
  [@bs.meth] "getBounds": unit => Mapbox_LngLatBounds.t
};

[@bs.new][@bs.module "mapbox-gl/dist/mapbox-gl.js"]
external create: Config.jsObj => t = "Map";
