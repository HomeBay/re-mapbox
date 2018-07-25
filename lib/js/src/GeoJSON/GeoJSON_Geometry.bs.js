'use strict';

var Js_dict = require("bs-platform/lib/js/js_dict.js");
var Belt_List = require("bs-platform/lib/js/belt_List.js");
var GeoJSON_Line = require("./GeoJSON_Line.bs.js");
var GeoJSON_Polygon = require("./GeoJSON_Polygon.bs.js");
var GeoJSON_Position = require("./GeoJSON_Position.bs.js");

function toJSONFields(data) {
  switch (data.tag | 0) {
    case 0 : 
        return /* :: */[
                /* tuple */[
                  "type",
                  "Point"
                ],
                /* :: */[
                  /* tuple */[
                    "coordinates",
                    GeoJSON_Position.toJSON(data[0])
                  ],
                  /* [] */0
                ]
              ];
    case 1 : 
        return /* :: */[
                /* tuple */[
                  "type",
                  "LineString"
                ],
                /* :: */[
                  /* tuple */[
                    "coordinates",
                    GeoJSON_Line.toJSON(data[0])
                  ],
                  /* [] */0
                ]
              ];
    case 2 : 
        return /* :: */[
                /* tuple */[
                  "type",
                  "Polygon"
                ],
                /* :: */[
                  /* tuple */[
                    "coordinates",
                    GeoJSON_Polygon.toJSON(data[0])
                  ],
                  /* [] */0
                ]
              ];
    case 3 : 
        return /* :: */[
                /* tuple */[
                  "type",
                  "MultiPoint"
                ],
                /* :: */[
                  /* tuple */[
                    "coordinates",
                    Belt_List.toArray(Belt_List.map(data[0], GeoJSON_Position.toJSON))
                  ],
                  /* [] */0
                ]
              ];
    case 4 : 
        return /* :: */[
                /* tuple */[
                  "type",
                  "MultiLineString"
                ],
                /* :: */[
                  /* tuple */[
                    "coordinates",
                    Belt_List.toArray(Belt_List.map(data[0], GeoJSON_Line.toJSON))
                  ],
                  /* [] */0
                ]
              ];
    case 5 : 
        return /* :: */[
                /* tuple */[
                  "type",
                  "MultiPolygon"
                ],
                /* :: */[
                  /* tuple */[
                    "coordinates",
                    Belt_List.toArray(Belt_List.map(data[0], GeoJSON_Polygon.toJSON))
                  ],
                  /* [] */0
                ]
              ];
    case 6 : 
        return /* :: */[
                /* tuple */[
                  "type",
                  "GeometryCollection"
                ],
                /* :: */[
                  /* tuple */[
                    "geometries",
                    Belt_List.toArray(Belt_List.map(data[0], (function (v) {
                                return Js_dict.fromList(toJSONFields(v));
                              })))
                  ],
                  /* [] */0
                ]
              ];
    
  }
}

function toJSON(data) {
  return Js_dict.fromList(toJSONFields(data));
}

var Position = 0;

var Line = 0;

var Polygon = 0;

exports.Position = Position;
exports.Line = Line;
exports.Polygon = Polygon;
exports.toJSONFields = toJSONFields;
exports.toJSON = toJSON;
/* Js_dict Not a pure module */
