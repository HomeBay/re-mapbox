'use strict';


function tToJs(param) {
  return param + 0 | 0;
}

function tFromJs(param) {
  if (param <= 22 && 0 <= param) {
    return param - 0 | 0;
  }
  
}

exports.tToJs = tToJs;
exports.tFromJs = tFromJs;
/* No side effect */
