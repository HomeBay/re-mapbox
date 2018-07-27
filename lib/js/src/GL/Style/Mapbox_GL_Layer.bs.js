'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Js_primitive = require("bs-platform/lib/js/js_primitive.js");

function layerTypeString(v) {
  if (typeof v === "number") {
    return "background";
  } else {
    switch (v.tag | 0) {
      case 0 : 
          return "fill";
      case 1 : 
          return "line";
      case 2 : 
          return "symbol";
      case 3 : 
          return "circle";
      case 4 : 
          return "heatmap";
      case 5 : 
          return "fill-extrusion";
      case 6 : 
          return "raster";
      case 7 : 
          return "hillshade";
      
    }
  }
}

function getLayerSource(v) {
  if (typeof v === "number") {
    return undefined;
  } else {
    return v[0];
  }
}

function make(id, _type, metadata, sourceLayer, minZoom, maxZoom, filter, layout, paint, _) {
  return /* record */[
          /* id */id,
          /* _type */_type,
          /* metadata */metadata,
          /* sourceLayer */sourceLayer,
          /* minZoom */minZoom,
          /* maxZoom */maxZoom,
          /* filter */filter,
          /* layout */layout,
          /* paint */paint
        ];
}

function fill(sourceId) {
  var arg = /* Fill */Block.__(0, [sourceId]);
  return (function (param) {
      return (function (param$1, param$2, param$3, param$4, param$5, param$6, param$7, param$8) {
          return make(param, arg, param$1, param$2, param$3, param$4, param$5, param$6, param$7, param$8);
        });
    });
}

function line(sourceId) {
  var arg = /* Line */Block.__(1, [sourceId]);
  return (function (param) {
      return (function (param$1, param$2, param$3, param$4, param$5, param$6, param$7, param$8) {
          return make(param, arg, param$1, param$2, param$3, param$4, param$5, param$6, param$7, param$8);
        });
    });
}

function symbol(sourceId) {
  var arg = /* Symbol */Block.__(2, [sourceId]);
  return (function (param) {
      return (function (param$1, param$2, param$3, param$4, param$5, param$6, param$7, param$8) {
          return make(param, arg, param$1, param$2, param$3, param$4, param$5, param$6, param$7, param$8);
        });
    });
}

function circle(sourceId) {
  var arg = /* Circle */Block.__(3, [sourceId]);
  return (function (param) {
      return (function (param$1, param$2, param$3, param$4, param$5, param$6, param$7, param$8) {
          return make(param, arg, param$1, param$2, param$3, param$4, param$5, param$6, param$7, param$8);
        });
    });
}

function heatmap(sourceId) {
  var arg = /* Heatmap */Block.__(4, [sourceId]);
  return (function (param) {
      return (function (param$1, param$2, param$3, param$4, param$5, param$6, param$7, param$8) {
          return make(param, arg, param$1, param$2, param$3, param$4, param$5, param$6, param$7, param$8);
        });
    });
}

function fillExtrusion(sourceId) {
  var arg = /* FillExtrusion */Block.__(5, [sourceId]);
  return (function (param) {
      return (function (param$1, param$2, param$3, param$4, param$5, param$6, param$7, param$8) {
          return make(param, arg, param$1, param$2, param$3, param$4, param$5, param$6, param$7, param$8);
        });
    });
}

function raster(sourceId) {
  var arg = /* Raster */Block.__(6, [sourceId]);
  return (function (param) {
      return (function (param$1, param$2, param$3, param$4, param$5, param$6, param$7, param$8) {
          return make(param, arg, param$1, param$2, param$3, param$4, param$5, param$6, param$7, param$8);
        });
    });
}

function hillshade(sourceId) {
  var arg = /* Hillshade */Block.__(7, [sourceId]);
  return (function (param) {
      return (function (param$1, param$2, param$3, param$4, param$5, param$6, param$7, param$8) {
          return make(param, arg, param$1, param$2, param$3, param$4, param$5, param$6, param$7, param$8);
        });
    });
}

function background(param) {
  return (function (param$1, param$2, param$3, param$4, param$5, param$6, param$7, param$8) {
      return make(param, /* Background */0, param$1, param$2, param$3, param$4, param$5, param$6, param$7, param$8);
    });
}

function tToJS(v) {
  var tmp = {
    id: v[/* id */0],
    type: layerTypeString(v[/* _type */1])
  };
  var tmp$1 = v[/* metadata */2];
  if (tmp$1 !== undefined) {
    tmp.metadata = Js_primitive.valFromOption(tmp$1);
  }
  var tmp$2 = getLayerSource(v[/* _type */1]);
  if (tmp$2 !== undefined) {
    tmp.source = Js_primitive.valFromOption(tmp$2);
  }
  var tmp$3 = v[/* sourceLayer */3];
  if (tmp$3 !== undefined) {
    tmp["source-layer"] = Js_primitive.valFromOption(tmp$3);
  }
  var tmp$4 = v[/* minZoom */4];
  if (tmp$4 !== undefined) {
    tmp.minzoom = Js_primitive.valFromOption(tmp$4);
  }
  var tmp$5 = v[/* maxZoom */5];
  if (tmp$5 !== undefined) {
    tmp.maxzoom = Js_primitive.valFromOption(tmp$5);
  }
  var tmp$6 = v[/* filter */6];
  if (tmp$6 !== undefined) {
    tmp.filter = Js_primitive.valFromOption(tmp$6);
  }
  var tmp$7 = v[/* layout */7];
  if (tmp$7 !== undefined) {
    tmp.layout = Js_primitive.valFromOption(tmp$7);
  }
  var tmp$8 = v[/* paint */8];
  if (tmp$8 !== undefined) {
    tmp.paint = Js_primitive.valFromOption(tmp$8);
  }
  return tmp;
}

exports.layerTypeString = layerTypeString;
exports.getLayerSource = getLayerSource;
exports.make = make;
exports.fill = fill;
exports.line = line;
exports.symbol = symbol;
exports.circle = circle;
exports.heatmap = heatmap;
exports.fillExtrusion = fillExtrusion;
exports.raster = raster;
exports.hillshade = hillshade;
exports.background = background;
exports.tToJS = tToJS;
/* No side effect */
