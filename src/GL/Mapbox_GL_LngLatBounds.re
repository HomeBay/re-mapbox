type t;

/**
 * Create a new LngLatBounds. The constructor takes two LngLat objects in
 * (sw, ne) order.
 */
[@bs.new][@bs.module "mapbox-gl/dist/mapbox-gl.js"]
external create: (Mapbox_GL_LngLat.t, Mapbox_GL_LngLat.t) => t = "LngLatBounds";

[@bs.send] external setNorthEast: (t, Mapbox_GL_LngLat.t) => t = "setNorthEast";
[@bs.send] external setSouthWest: (t, Mapbox_GL_LngLat.t) => t = "setSouthWest";
[@bs.send] external extend: (t, t) => t = "extend";
[@bs.send] external getCenter: t => Mapbox_GL_LngLat.t = "getCenter";
[@bs.send] external getSouthWest: t => Mapbox_GL_LngLat.t = "getSouthWest";
[@bs.send] external getNorthEast: t => Mapbox_GL_LngLat.t = "getNorthEast";
[@bs.send] external getNorthWest: t => Mapbox_GL_LngLat.t = "getNorthWest";
[@bs.send] external getSouthEast: t => Mapbox_GL_LngLat.t = "getSouthEast";
[@bs.send] external getWest: t => float = "getWest";
[@bs.send] external getSouth: t => float = "getSouth";
[@bs.send] external getEast: t => float = "getEast";
[@bs.send] external getNorth: t => float = "getNorth";
[@bs.send] external toArray: t => array(array(float)) = "toArray";
[@bs.send] external toString: t => string = "toString";
[@bs.send] external isEmpty: t => bool = "isEmpty";

/* This function can't live in the LngLat module becuase of circular deps */
[@bs.send] external fromLngLat: Mapbox_GL_LngLat.t => t = "toBounds";


let make = (~n, ~e, ~s, ~w): t =>
  create(
    Mapbox_GL_LngLat.make(~latitude=s, ~longitude=w),
    Mapbox_GL_LngLat.make(~latitude=n, ~longitude=e)
  );
