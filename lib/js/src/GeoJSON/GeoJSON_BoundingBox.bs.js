'use strict';


function toArray(data) {
  if (data.tag) {
    var match = data[0];
    var d2 = match[/* d2 */0];
    return /* array */[
            d2[/* s */2],
            d2[/* w */3],
            d2[/* n */0],
            d2[/* e */1],
            match[/* highest */1],
            match[/* lowest */2]
          ];
  } else {
    var match$1 = data[0];
    return /* array */[
            match$1[/* s */2],
            match$1[/* w */3],
            match$1[/* n */0],
            match$1[/* e */1]
          ];
  }
}

function toJSON(data) {
  return toArray(data).map((function (prim) {
                return prim;
              }));
}

exports.toArray = toArray;
exports.toJSON = toJSON;
/* No side effect */
