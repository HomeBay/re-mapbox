'use strict';

var Belt_Option = require("bs-platform/lib/js/belt_Option.js");
var Js_primitive = require("bs-platform/lib/js/js_primitive.js");

function tToJs(data) {
  switch (data) {
    case 0 : 
        return "center";
    case 1 : 
        return "top";
    case 2 : 
        return "bottom";
    case 3 : 
        return "left";
    case 4 : 
        return "right";
    case 5 : 
        return "top-left";
    case 6 : 
        return "top-right";
    case 7 : 
        return "bottom-left";
    case 8 : 
        return "bottom-right";
    
  }
}

var Anchor = /* module */[/* tToJs */tToJs];

function getElement(r) {
  if (r.tag) {
    return undefined;
  } else {
    return Js_primitive.some(r[0]);
  }
}

function getColor(r) {
  if (r.tag) {
    return r[0];
  }
  
}

function make(anchor, rendering, _) {
  return /* record */[
          /* anchor */anchor,
          /* rendering */rendering
        ];
}

var empty = /* record */[
  /* anchor */undefined,
  /* rendering */undefined
];

function tToJs$1(data) {
  var tmp = { };
  var tmp$1 = Belt_Option.flatMap(data[/* rendering */1], getElement);
  if (tmp$1 !== undefined) {
    tmp.element = Js_primitive.valFromOption(tmp$1);
  }
  var tmp$2 = Belt_Option.map(data[/* anchor */0], tToJs);
  if (tmp$2 !== undefined) {
    tmp.anchor = Js_primitive.valFromOption(tmp$2);
  }
  var tmp$3 = Belt_Option.flatMap(data[/* rendering */1], getColor);
  if (tmp$3 !== undefined) {
    tmp.color = Js_primitive.valFromOption(tmp$3);
  }
  return tmp;
}

var Config = /* module */[
  /* getElement */getElement,
  /* getColor */getColor,
  /* make */make,
  /* empty */empty,
  /* tToJs */tToJs$1
];

exports.Anchor = Anchor;
exports.Config = Config;
/* No side effect */
