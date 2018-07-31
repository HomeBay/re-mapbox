'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var Belt_Array = require("bs-platform/lib/js/belt_Array.js");
var Mapbox_GL_Style_Expression = require("./Mapbox_GL_Style_Expression.bs.js");

function makeStop(value, until) {
  return /* record */[
          /* value */value,
          /* until */until
        ];
}

function stopToJS(numberToJSON, valueToJSON, param) {
  return /* array */[
          Curry._1(valueToJSON, param[/* value */0]),
          Curry._1(numberToJSON, param[/* until */1])
        ];
}

function make(input, stops, finalStop) {
  return /* record */[
          /* input */input,
          /* stops */stops,
          /* finalStop */finalStop
        ];
}

function tToJS(numberToJSON, valueToJSON, param) {
  var arr = /* array */[
    "step",
    Mapbox_GL_Style_Expression.tToJS(numberToJSON, param[/* input */0])
  ];
  var stopsArr = Belt_Array.reduce(param[/* stops */1], /* array */[], (function (acc, curr) {
          return Belt_Array.concat(acc, stopToJS(numberToJSON, valueToJSON, curr));
        }));
  return Belt_Array.concatMany(/* array */[
              arr,
              stopsArr,
              /* array */[Curry._1(valueToJSON, param[/* finalStop */2])]
            ]);
}

exports.makeStop = makeStop;
exports.stopToJS = stopToJS;
exports.make = make;
exports.tToJS = tToJS;
/* No side effect */
