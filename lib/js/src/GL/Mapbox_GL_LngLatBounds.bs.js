'use strict';

var Mapbox_GL_LngLat = require("./Mapbox_GL_LngLat.bs.js");
var MapboxGlJs = require("mapbox-gl/dist/mapbox-gl.js");

function make(n, e, s, w) {
  return new MapboxGlJs.LngLatBounds(Mapbox_GL_LngLat.make(s, w), Mapbox_GL_LngLat.make(n, e));
}

exports.make = make;
/* Mapbox_GL_LngLat Not a pure module */
