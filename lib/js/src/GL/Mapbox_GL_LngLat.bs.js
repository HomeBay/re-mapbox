'use strict';

var MapboxGlJs = require("mapbox-gl/dist/mapbox-gl.js");

function make(latitude, longitude) {
  return new MapboxGlJs.LngLat(longitude, latitude);
}

exports.make = make;
/* mapbox-gl/dist/mapbox-gl.js Not a pure module */
