'use strict';

var Belt_List = require("bs-platform/lib/js/belt_List.js");
var GeoJSON_Position = require("./GeoJSON_Position.bs.js");

function make(first, second, $staropt$star, _) {
  var rest = $staropt$star !== undefined ? $staropt$star : /* [] */0;
  return /* record */[
          /* first */first,
          /* second */second,
          /* rest */rest
        ];
}

function twoPoints(first, second) {
  return make(first, second, undefined, /* () */0);
}

function toJSON(param) {
  var r = Belt_List.toArray(Belt_List.map(param[/* rest */2], GeoJSON_Position.toJSON));
  return r.concat(/* array */[
              GeoJSON_Position.toJSON(param[/* first */0]),
              GeoJSON_Position.toJSON(param[/* second */1])
            ]);
}

exports.make = make;
exports.twoPoints = twoPoints;
exports.toJSON = toJSON;
/* No side effect */
