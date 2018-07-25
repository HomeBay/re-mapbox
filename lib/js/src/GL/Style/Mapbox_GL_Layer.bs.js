'use strict';

var Js_primitive = require("bs-platform/lib/js/js_primitive.js");

function layerTypeString(v) {
  if (typeof v === "number") {
    return "background";
  } else {
    switch (v.tag | 0) {
      case 0 : 
          return "fill";
      case 1 : 
          return "line";
      case 2 : 
          return "symbol";
      case 3 : 
          return "circle";
      case 4 : 
          return "heatmap";
      case 5 : 
          return "fill-extrusion";
      case 6 : 
          return "raster";
      case 7 : 
          return "hillshade";
      
    }
  }
}

function getLayerSource(v) {
  if (typeof v === "number") {
    return undefined;
  } else {
    return v[0];
  }
}

function tToJS(v) {
  var partial_arg = v[/* paint */8];
  var partial_arg$1 = v[/* layout */7];
  var partial_arg$2 = v[/* filter */6];
  var partial_arg$3 = v[/* maxZoom */5];
  var partial_arg$4 = v[/* minZoom */4];
  var partial_arg$5 = v[/* sourceLayer */3];
  var partial_arg$6 = getLayerSource(v[/* _type */1]);
  var partial_arg$7 = v[/* metadata */2];
  var partial_arg$8 = layerTypeString(v[/* _type */1]);
  var partial_arg$9 = v[/* id */0];
  return (function () {
      var tmp = {
        id: partial_arg$9,
        type: partial_arg$8
      };
      if (partial_arg$7) {
        tmp.metadata = Js_primitive.valFromOption(partial_arg$7);
      }
      if (partial_arg$6) {
        tmp.source = Js_primitive.valFromOption(partial_arg$6);
      }
      if (partial_arg$5) {
        tmp["source-layer"] = Js_primitive.valFromOption(partial_arg$5);
      }
      if (partial_arg$4) {
        tmp.minzoom = Js_primitive.valFromOption(partial_arg$4);
      }
      if (partial_arg$3) {
        tmp.maxzoom = Js_primitive.valFromOption(partial_arg$3);
      }
      if (partial_arg$2) {
        tmp.filter = Js_primitive.valFromOption(partial_arg$2);
      }
      if (partial_arg$1) {
        tmp.layout = Js_primitive.valFromOption(partial_arg$1);
      }
      if (partial_arg) {
        tmp.paint = Js_primitive.valFromOption(partial_arg);
      }
      return tmp;
    });
}

exports.layerTypeString = layerTypeString;
exports.getLayerSource = getLayerSource;
exports.tToJS = tToJS;
/* No side effect */
