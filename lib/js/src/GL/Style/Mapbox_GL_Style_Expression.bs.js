'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var Belt_Array = require("bs-platform/lib/js/belt_Array.js");

function tToJS(valueToJS, expr) {
  switch (expr.tag | 0) {
    case 0 : 
        return /* array */[
                "get",
                expr[0]
              ];
    case 1 : 
        return Belt_Array.map(expr[0], (function (prim) {
                      return prim;
                    }));
    case 2 : 
        return Curry._1(valueToJS, expr[0]);
    
  }
}

exports.tToJS = tToJS;
/* No side effect */
