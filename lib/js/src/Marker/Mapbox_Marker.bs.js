'use strict';

var Belt_Option = require("bs-platform/lib/js/belt_Option.js");
var Mapbox_Marker_Anchor = require("./Mapbox_Marker_Anchor.bs.js");

function getElement(r) {
  if (r.tag) {
    return /* None */0;
  } else {
    return /* Some */[r[0]];
  }
}

function getColor(r) {
  if (r.tag) {
    return /* Some */[r[0]];
  } else {
    return /* None */0;
  }
}

function make(anchor, rendering, _) {
  return /* record */[
          /* anchor */anchor,
          /* rendering */rendering
        ];
}

var empty = /* record */[
  /* anchor : None */0,
  /* rendering : None */0
];

function tToJs(data) {
  var tmp = { };
  var tmp$1 = Belt_Option.flatMap(data[/* rendering */1], getElement);
  if (tmp$1) {
    tmp.element = tmp$1[0];
  }
  var tmp$2 = Belt_Option.map(data[/* anchor */0], Mapbox_Marker_Anchor.tToJs);
  if (tmp$2) {
    tmp.anchor = tmp$2[0];
  }
  var tmp$3 = Belt_Option.flatMap(data[/* rendering */1], getColor);
  if (tmp$3) {
    tmp.color = tmp$3[0];
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
