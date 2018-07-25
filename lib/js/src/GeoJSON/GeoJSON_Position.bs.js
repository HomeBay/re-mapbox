'use strict';


function make(latitude, longitude, altitude, _) {
  return /* record */[
          /* latitude */latitude,
          /* longitude */longitude,
          /* altitude */altitude
        ];
}

function latLong(latitude, longitude) {
  return /* record */[
          /* latitude */latitude,
          /* longitude */longitude,
          /* altitude */undefined
        ];
}

function toArray(param) {
  var altitude = param[/* altitude */2];
  var out = /* array */[
    param[/* latitude */0],
    param[/* longitude */1]
  ];
  if (altitude !== undefined) {
    return /* array */[altitude].concat(out);
  } else {
    return out;
  }
}

function toJSON(data) {
  return toArray(data).map((function (prim) {
                return prim;
              }));
}

exports.make = make;
exports.latLong = latLong;
exports.toArray = toArray;
exports.toJSON = toJSON;
/* No side effect */
