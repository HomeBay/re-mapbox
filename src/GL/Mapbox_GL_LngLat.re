type t;

[@bs.new][@bs.module "mapbox-gl/dist/mapbox-gl.js"]
external create: (float, float) => t = "LngLat";

[@bs.get] external getLongitude: t => float = "lng";
[@bs.get] external getLatitude: t => float = "lat";
[@bs.send] external wrap: t => t = "wrap";
[@bs.send] external toArray: t => array(float) = "toArray";
[@bs.send] external toString: t => string = "toString";

/* If you're looking for `toBounds`, it lives in LngLatBounds as `fromLngLat`.
   It can't exist here without running into cyclic module resolution issues. */

let make = (~latitude, ~longitude): t =>
  create(longitude, latitude);
