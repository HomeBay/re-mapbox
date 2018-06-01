'use strict';


function make(n, e, s, w) {
  return /* record */[
          /* n */n,
          /* e */e,
          /* s */s,
          /* w */w
        ];
}

function tToJs(param) {
  return /* array */[
          param[/* w */3],
          param[/* s */2],
          param[/* e */1],
          param[/* n */0]
        ];
}

exports.make = make;
exports.tToJs = tToJs;
/* No side effect */
