'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Js_dict = require("bs-platform/lib/js/js_dict.js");
var Belt_List = require("bs-platform/lib/js/belt_List.js");
var GeoJSON_Feature = require("./GeoJSON_Feature.bs.js");
var GeoJSON_Geometry = require("./GeoJSON_Geometry.bs.js");
var GeoJSON_BoundingBox = require("./GeoJSON_BoundingBox.bs.js");

function make(data, bbox, _) {
  return /* record */[
          /* data */data,
          /* bbox */bbox
        ];
}

function geometry(geom) {
  return /* record */[
          /* data : Geometry */Block.__(0, [geom]),
          /* bbox */undefined
        ];
}

function feature(feat) {
  return /* record */[
          /* data : Feature */Block.__(1, [feat]),
          /* bbox */undefined
        ];
}

function featureCollection(fc) {
  return /* record */[
          /* data : FeatureCollection */Block.__(2, [fc]),
          /* bbox */undefined
        ];
}

function toJSON(param) {
  var bbox = param[/* bbox */1];
  var data = param[/* data */0];
  var makeFeature = function (f) {
    return /* :: */[
            /* tuple */[
              "type",
              "Feature"
            ],
            GeoJSON_Feature.toJSONFields(f)
          ];
  };
  var fields;
  switch (data.tag | 0) {
    case 0 : 
        fields = GeoJSON_Geometry.toJSONFields(data[0]);
        break;
    case 1 : 
        fields = makeFeature(data[0]);
        break;
    case 2 : 
        fields = /* :: */[
          /* tuple */[
            "type",
            "FeatureCollection"
          ],
          /* :: */[
            /* tuple */[
              "features",
              Belt_List.toArray(Belt_List.map(data[0], (function (v) {
                          return Js_dict.fromList(makeFeature(v));
                        })))
            ],
            /* [] */0
          ]
        ];
        break;
    
  }
  return Js_dict.fromList(bbox !== undefined ? /* :: */[
                /* tuple */[
                  "bbox",
                  GeoJSON_BoundingBox.toJSON(bbox)
                ],
                fields
              ] : fields);
}

var Geometry = 0;

var Feature = 0;

var BoundingBox = 0;

exports.Geometry = Geometry;
exports.Feature = Feature;
exports.BoundingBox = BoundingBox;
exports.make = make;
exports.geometry = geometry;
exports.feature = feature;
exports.featureCollection = featureCollection;
exports.toJSON = toJSON;
/* Js_dict Not a pure module */
