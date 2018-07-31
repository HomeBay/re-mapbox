'use strict';

var MapboxGlJs = require("mapbox-gl/dist/mapbox-gl.js");

function make(x, y) {
  return new MapboxGlJs.Point(x, y);
}

exports.make = make;
/* mapbox-gl/dist/mapbox-gl.js Not a pure module */