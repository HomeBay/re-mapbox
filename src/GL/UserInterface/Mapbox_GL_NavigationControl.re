module Options = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] showCompass: bool,
    [@bs.optional] showZoom: bool,
  };
};

type t;

[@bs.new] [@bs.module "mapbox-gl/dist/mapbox-gl.js"]
external make: unit => t = "NavigationControl";

[@bs.new] [@bs.module "mapbox-gl/dist/mapbox-gl.js"]
external makeWithOptions: Options.t => t = "NavigationControl";

external toControl: t => Mapbox_GL_Control.t = "%identity";
