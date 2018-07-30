'use strict';

var Belt_Option = require("bs-platform/lib/js/belt_Option.js");
var GeoJSON_Geometry = require("./GeoJSON_Geometry.bs.js");

function make(id, geometry, properties, _) {
  return /* record */[
          /* id */id,
          /* geometry */geometry,
          /* properties */properties
        ];
}

function toJSONFields(param) {
  var maybePrepend = function (lst, opt) {
    return Belt_Option.mapWithDefault(opt, lst, (function (v) {
                  return /* :: */[
                          v,
                          lst
                        ];
                }));
  };
  var featureIdToJSON = function (id) {
    return id[0];
  };
  return maybePrepend(maybePrepend(/* :: */[
                  /* tuple */[
                    "geometry",
                    Belt_Option.mapWithDefault(param[/* geometry */1], null, GeoJSON_Geometry.toJSON)
                  ],
                  /* [] */0
                ], Belt_Option.map(param[/* properties */2], (function (v) {
                        return /* tuple */[
                                "properties",
                                v
                              ];
                      }))), Belt_Option.map(param[/* id */0], (function (v) {
                    return /* tuple */[
                            "id",
                            featureIdToJSON(v)
                          ];
                  })));
}

exports.make = make;
exports.toJSONFields = toJSONFields;
/* GeoJSON_Geometry Not a pure module */
