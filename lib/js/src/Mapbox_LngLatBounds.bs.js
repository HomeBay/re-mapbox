'use strict';

var Mapbox_LngLat = require("./Mapbox_LngLat.bs.js");
var MapboxGlJs = require("mapbox-gl/dist/mapbox-gl.js");

function make(n, e, s, w) {
  return new MapboxGlJs.LngLatBounds(Mapbox_LngLat.make(s, w), Mapbox_LngLat.make(n, e));
}

exports.make = make;
/* Mapbox_LngLat Not a pure module */
