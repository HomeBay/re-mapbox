'use strict';

var Block = require("bs-platform/lib/js/block.js");
var MapboxGlJs = require("mapbox-gl/dist/mapbox-gl.js");

var FitOptions = /* module */[];

var QueryRenderedFeaturesOptions = /* module */[];

function create(cfg) {
  try {
    return /* Ok */Block.__(0, [new MapboxGlJs.Map(cfg)]);
  }
  catch (exn){
    return /* Error */Block.__(1, ["Failed to initialize MapboxGL"]);
  }
}

var Config = 0;

exports.Config = Config;
exports.FitOptions = FitOptions;
exports.QueryRenderedFeaturesOptions = QueryRenderedFeaturesOptions;
exports.create = create;
/* mapbox-gl/dist/mapbox-gl.js Not a pure module */
