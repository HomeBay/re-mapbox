/**
 * The type `t` is an opaque type created only by importing from `mapbox-gl`.
 * Using the `mapboxgl` value below will require the node module.
 */
type t;
type supportedOpts = {.
  "failIfMajorPerformanceCaveat": bool
};

[@bs.val] [@bs.module] external mapboxgl: t = "mapbox-gl/dist/mapbox-gl.js";
[@bs.set] external setAccessToken : t => string => unit = "accessToken";
[@bs.send] external supported : t => bool = "supported";
[@bs.send] external supportedWithOpts : (t, supportedOpts) => bool = "supported";
[@bs.get] external version : t => string = "version";

/* TODO: unclear what argument is passed to the callback in the case of an error
   because docs don't mention it and examples don't include this callback. */
[@bs.send] external setRTLTextPlugin : (t, string, (string => unit)) => unit = "setRTLTextPlugin";

/**
 * Base API includes Map and lots of `Options` definitions used elsewhere
 */
module Map = Mapbox_GL_Map;
/* TODO: Animation Options */
/* TODO: Camera Options */
/* TODO: Padding Options */
/* TODO: Request Parameters */

/**
 * Geography and Geometry types and helpers
 */
module LngLat = Mapbox_GL_LngLat;
module LngLatBounds = Mapbox_GL_LngLatBounds;
/* TODO: Point */

/**
 * User Interface types and helpers
 */
/* TODO: Navigation Control */
/* TODO: Geolocate Control */
/* TODO: Attribution Control */
/* TODO: Scale Control */
/* TODO: Fullscreen Control */
/* TODO: Popup */
module Marker = Mapbox_GL_Marker;

/* TODO: User Interaction Handlers */

/* TODO: Sources */

/* TODO: Events */
