'use strict';


function make(latitude, longitude) {
  return /* record */[
          /* latitude */latitude,
          /* longitude */longitude
        ];
}

function tToJs(param) {
  return {
          lng: param[/* longitude */1],
          lat: param[/* latitude */0]
        };
}

exports.make = make;
exports.tToJs = tToJs;
/* No side effect */
