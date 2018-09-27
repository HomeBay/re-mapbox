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

function onClick(map, callback) {
  return map.on("click", callback);
}

function onMouseEnter(map, callback) {
  return map.on("mouseenter", callback);
}

function onMouseLeave(map, callback) {
  return map.on("mouseleave", callback);
}

function onLayerClick(map, layerId, callback) {
  return map.on("click", layerId, callback);
}

function onLayerMouseEnter(map, layerId, callback) {
  return map.on("mouseenter", layerId, callback);
}

function onLayerMouseLeave(map, layerId, callback) {
  return map.on("mouseleave", layerId, callback);
}

function offClick(map, callback) {
  return map.off("click", callback);
}

function offMouseEnter(map, callback) {
  return map.off("mouseenter", callback);
}

function offMouseLeave(map, callback) {
  return map.off("mouseleave", callback);
}

function offLayerClick(map, layerId, callback) {
  return map.off("click", layerId, callback);
}

function offLayerMouseEnter(map, layerId, callback) {
  return map.off("mouseenter", layerId, callback);
}

function offLayerMouseLeave(map, layerId, callback) {
  return map.off("mouseleave", layerId, callback);
}

var Config = 0;

exports.Config = Config;
exports.FitOptions = FitOptions;
exports.QueryRenderedFeaturesOptions = QueryRenderedFeaturesOptions;
exports.create = create;
exports.onClick = onClick;
exports.onMouseEnter = onMouseEnter;
exports.onMouseLeave = onMouseLeave;
exports.onLayerClick = onLayerClick;
exports.onLayerMouseEnter = onLayerMouseEnter;
exports.onLayerMouseLeave = onLayerMouseLeave;
exports.offClick = offClick;
exports.offMouseEnter = offMouseEnter;
exports.offMouseLeave = offMouseLeave;
exports.offLayerClick = offLayerClick;
exports.offLayerMouseEnter = offLayerMouseEnter;
exports.offLayerMouseLeave = offLayerMouseLeave;
/* mapbox-gl/dist/mapbox-gl.js Not a pure module */
