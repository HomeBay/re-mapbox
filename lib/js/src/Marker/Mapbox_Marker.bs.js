'use strict';

var Belt_Option = require("bs-platform/lib/js/belt_Option.js");
var Js_primitive = require("bs-platform/lib/js/js_primitive.js");
var Mapbox_Marker_Anchor = require("./Mapbox_Marker_Anchor.bs.js");

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

function tToJs(data) {
  var tmp = { };
  var tmp$1 = Belt_Option.flatMap(data[/* rendering */1], getElement);
  if (tmp$1) {
    tmp.element = Js_primitive.valFromOption(tmp$1);
  }
  var tmp$2 = Belt_Option.map(data[/* anchor */0], Mapbox_Marker_Anchor.tToJs);
  if (tmp$2) {
    tmp.anchor = Js_primitive.valFromOption(tmp$2);
  }
  var tmp$3 = Belt_Option.flatMap(data[/* rendering */1], getColor);
  if (tmp$3) {
    tmp.color = Js_primitive.valFromOption(tmp$3);
  }
  return tmp;
}

var Config = /* module */[
  /* getElement */getElement,
  /* getColor */getColor,
  /* make */make,
  /* empty */empty,
  /* tToJs */tToJs
];

var Anchor = 0;

exports.Anchor = Anchor;
exports.Config = Config;
/* No side effect */
