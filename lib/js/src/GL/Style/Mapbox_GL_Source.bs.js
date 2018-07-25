'use strict';

var GeoJSON = require("../../GeoJSON/GeoJSON.bs.js");
var Belt_Option = require("bs-platform/lib/js/belt_Option.js");
var Js_primitive = require("bs-platform/lib/js/js_primitive.js");

function tToJS(v) {
  var src = v[0];
  var tmp = {
    type: "geojson"
  };
  var tmp$1 = Belt_Option.map(src[/* data */0], (function (v) {
          if (v.tag) {
            return GeoJSON.toJSON(v[0]);
          } else {
            return v[0];
          }
        }));
  if (tmp$1) {
    tmp.data = Js_primitive.valFromOption(tmp$1);
  }
  var tmp$2 = src[/* maxzoom */1];
  if (tmp$2) {
    tmp.maxzoom = Js_primitive.valFromOption(tmp$2);
  }
  var tmp$3 = src[/* attribution */2];
  if (tmp$3) {
    tmp.attribution = Js_primitive.valFromOption(tmp$3);
  }
  var tmp$4 = src[/* buffer */3];
  if (tmp$4) {
    tmp.buffer = Js_primitive.valFromOption(tmp$4);
  }
  var tmp$5 = src[/* tolerance */4];
  if (tmp$5) {
    tmp.tolerance = Js_primitive.valFromOption(tmp$5);
  }
  var tmp$6 = src[/* cluster */5];
  if (tmp$6) {
    tmp.cluster = Js_primitive.valFromOption(tmp$6);
  }
  var tmp$7 = src[/* clusterRadius */6];
  if (tmp$7) {
    tmp.clusterRadius = Js_primitive.valFromOption(tmp$7);
  }
  var tmp$8 = src[/* clusterMaxZoom */7];
  if (tmp$8) {
    tmp.clusterMaxZoom = Js_primitive.valFromOption(tmp$8);
  }
  var tmp$9 = src[/* lineMetrics */8];
  if (tmp$9) {
    tmp.lineMetrics = Js_primitive.valFromOption(tmp$9);
  }
  return tmp;
}

exports.tToJS = tToJS;
/* GeoJSON Not a pure module */
