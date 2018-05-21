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
  [@bs.meth] "setCenter": Mapbox_LngLat.t_js => t,
  [@bs.meth] "setZoom": float => t,
  [@bs.meth] "fitBounds": Config.LngLatBounds.t_js => FitOptions.t_js => t,
  [@bs.meth] "on": (string, Js.Nullable.t(string), unit => unit) => t,
  [@bs.meth] "remove": unit => unit
};

[@bs.new][@bs.module "mapbox-gl/dist/mapbox-gl.js"]
external create: Config.jsObj => t = "Map";
