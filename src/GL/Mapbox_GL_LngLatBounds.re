type t = {.
  [@bs.meth] "setNorthEast": Mapbox_GL_LngLat.t => t,
  [@bs.meth] "setSouthWest": Mapbox_GL_LngLat.t => t,
  [@bs.meth] "extend": t => t,
  [@bs.meth] "getCenter": unit => Mapbox_GL_LngLat.t,
  [@bs.meth] "getSouthWest": unit => Mapbox_GL_LngLat.t,
  [@bs.meth] "getNorthEast": unit => Mapbox_GL_LngLat.t,
  [@bs.meth] "getNorthWest": unit => Mapbox_GL_LngLat.t,
  [@bs.meth] "getSouthEast": unit => Mapbox_GL_LngLat.t,
  [@bs.meth] "getWest": unit => float,
  [@bs.meth] "getSouth": unit => float,
  [@bs.meth] "getEast": unit => float,
  [@bs.meth] "getNorth": unit => float,
  [@bs.meth] "toArray": unit => array(array(float)),
  [@bs.meth] "toString": unit => string,
  [@bs.meth] "isEmpty": unit => bool
};

/**
 * Create a new LngLatBounds. The constructor takes two LngLat objects in
 * (sw, ne) order.
 */
[@bs.new][@bs.module "mapbox-gl/dist/mapbox-gl.js"]
external create: (Mapbox_GL_LngLat.t, Mapbox_GL_LngLat.t) => t = "LngLatBounds";

let make = (~n, ~e, ~s, ~w): t =>
  create(
    Mapbox_GL_LngLat.make(~latitude=s, ~longitude=w),
    Mapbox_GL_LngLat.make(~latitude=n, ~longitude=e)
  );
