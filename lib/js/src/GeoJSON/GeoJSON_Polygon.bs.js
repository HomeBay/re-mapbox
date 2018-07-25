'use strict';

var Belt_List = require("bs-platform/lib/js/belt_List.js");
var GeoJSON_Position = require("./GeoJSON_Position.bs.js");

function shapeToJSON(param) {
  var startEnd = param[/* startEnd */0];
  var r = Belt_List.toArray(Belt_List.map(param[/* rest */3], GeoJSON_Position.toJSON));
  return /* array */[GeoJSON_Position.toJSON(startEnd)].concat(r).concat(/* array */[
              GeoJSON_Position.toJSON(startEnd),
              GeoJSON_Position.toJSON(param[/* second */1]),
              GeoJSON_Position.toJSON(param[/* third */2])
            ]);
}

function makeShape(startEnd, second, third, $staropt$star, _) {
  var rest = $staropt$star !== undefined ? $staropt$star : /* [] */0;
  return /* record */[
          /* startEnd */startEnd,
          /* second */second,
          /* third */third,
          /* rest */rest
        ];
}

function toJSON(data) {
  if (data.tag) {
    return Belt_List.toArray(Belt_List.map(data[0], shapeToJSON));
  } else {
    return /* array */[shapeToJSON(data[0])];
  }
}

exports.shapeToJSON = shapeToJSON;
exports.makeShape = makeShape;
exports.toJSON = toJSON;
/* No side effect */
