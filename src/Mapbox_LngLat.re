type t = {.
  "lng": float,
  "lat": float,
  [@bs.meth] "wrap": unit => t,
  [@bs.meth] "toArray": unit => array(float),
  [@bs.meth] "toString": unit => string,
  /* TODO: commented out `toBounds` to avoid cyclic module resolution */
  /* [@bs.meth] "toBounds": float => Mapbox_LngLatBounds.t */
};

[@bs.new][@bs.module "mapbox-gl/dist/mapbox-gl.js"]
external create: (float, float) => t = "LngLat";

let make = (~latitude, ~longitude): t =>
  create(longitude, latitude);
