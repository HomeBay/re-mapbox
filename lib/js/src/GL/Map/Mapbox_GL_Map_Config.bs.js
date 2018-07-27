'use strict';

var Belt_Option = require("bs-platform/lib/js/belt_Option.js");
var Js_primitive = require("bs-platform/lib/js/js_primitive.js");

function tToJs(data) {
  if (typeof data === "number") {
    switch (data) {
      case 0 : 
          return "mapbox://styles/mapbox/streets-v10";
      case 1 : 
          return "mapbox://styles/mapbox/outdoors-v10";
      case 2 : 
          return "mapbox://styles/mapbox/light-v9";
      case 3 : 
          return "mapbox://styles/mapbox/dark-v9";
      case 4 : 
          return "mapbox://styles/mapbox/satellite-v9";
      case 5 : 
          return "mapbox://styles/mapbox/satellite-streets-v10";
      case 6 : 
          return "mapbox://styles/mapbox/navigation-preview-day-v2";
      case 7 : 
          return "mapbox://styles/mapbox/navigation-preview-night-v2";
      case 8 : 
          return "mapbox://styles/mapbox/navigation-guidance-day-v2";
      case 9 : 
          return "mapbox://styles/mapbox/navigation-guidance-night-v2";
      
    }
  } else {
    switch (data.tag | 0) {
      case 0 : 
          return "mapbox://styles/" + (data[0] + ("/" + data[1]));
      case 1 : 
      case 2 : 
          return data[0];
      
    }
  }
}

var Style = /* module */[/* tToJs */tToJs];

function tToJs$1(data) {
  switch (data) {
    case 0 : 
        return "top-left";
    case 1 : 
        return "top-right";
    case 2 : 
        return "bottom-left";
    case 3 : 
        return "bottom-right";
    
  }
}

var LogoPosition = /* module */[/* tToJs */tToJs$1];

function tToJs$2(data) {
  return data[0];
}

var MapContainer = /* module */[/* tToJs */tToJs$2];

function make(container, minZoom, maxZoom, style, hash, interactive, bearingSnap, pitchWithRotate, attributionControl, logoPosition, failIfMajorPerformanceCaveat, preserveDrawingBuffer, refreshExpiredTiles, maxBounds, scrollZoom, boxZoom, dragRotate, dragPan, keyboard, doubleClickZoom, touchZoomRotate, trackResize, center, zoom, _) {
  return /* record */[
          /* container */container,
          /* minZoom */minZoom,
          /* maxZoom */maxZoom,
          /* style */style,
          /* hash */hash,
          /* interactive */interactive,
          /* bearingSnap */bearingSnap,
          /* pitchWithRotate */pitchWithRotate,
          /* attributionControl */attributionControl,
          /* logoPosition */logoPosition,
          /* failIfMajorPerformanceCaveat */failIfMajorPerformanceCaveat,
          /* preserveDrawingBuffer */preserveDrawingBuffer,
          /* refreshExpiredTiles */refreshExpiredTiles,
          /* maxBounds */maxBounds,
          /* scrollZoom */scrollZoom,
          /* boxZoom */boxZoom,
          /* dragRotate */dragRotate,
          /* dragPan */dragPan,
          /* keyboard */keyboard,
          /* doubleClickZoom */doubleClickZoom,
          /* touchZoomRotate */touchZoomRotate,
          /* trackResize */trackResize,
          /* center */center,
          /* zoom */zoom
        ];
}

function tToJs$3(data) {
  var tmp = {
    container: tToJs$2(data[/* container */0]),
    style: tToJs(data[/* style */3])
  };
  var tmp$1 = data[/* minZoom */1];
  if (tmp$1 !== undefined) {
    tmp.minZoom = Js_primitive.valFromOption(tmp$1);
  }
  var tmp$2 = data[/* maxZoom */2];
  if (tmp$2 !== undefined) {
    tmp.maxZoom = Js_primitive.valFromOption(tmp$2);
  }
  var tmp$3 = data[/* hash */4];
  if (tmp$3 !== undefined) {
    tmp.hash = Js_primitive.valFromOption(tmp$3);
  }
  var tmp$4 = data[/* interactive */5];
  if (tmp$4 !== undefined) {
    tmp.interactive = Js_primitive.valFromOption(tmp$4);
  }
  var tmp$5 = data[/* bearingSnap */6];
  if (tmp$5 !== undefined) {
    tmp.bearingSnap = Js_primitive.valFromOption(tmp$5);
  }
  var tmp$6 = data[/* pitchWithRotate */7];
  if (tmp$6 !== undefined) {
    tmp.pitchWithRotate = Js_primitive.valFromOption(tmp$6);
  }
  var tmp$7 = data[/* attributionControl */8];
  if (tmp$7 !== undefined) {
    tmp.attributionControl = Js_primitive.valFromOption(tmp$7);
  }
  var tmp$8 = Belt_Option.map(data[/* logoPosition */9], tToJs$1);
  if (tmp$8 !== undefined) {
    tmp.logoPosition = Js_primitive.valFromOption(tmp$8);
  }
  var tmp$9 = data[/* failIfMajorPerformanceCaveat */10];
  if (tmp$9 !== undefined) {
    tmp.failIfMajorPerformanceCaveat = Js_primitive.valFromOption(tmp$9);
  }
  var tmp$10 = data[/* preserveDrawingBuffer */11];
  if (tmp$10 !== undefined) {
    tmp.preserveDrawingBuffer = Js_primitive.valFromOption(tmp$10);
  }
  var tmp$11 = data[/* refreshExpiredTiles */12];
  if (tmp$11 !== undefined) {
    tmp.refreshExpiredTiles = Js_primitive.valFromOption(tmp$11);
  }
  var tmp$12 = data[/* maxBounds */13];
  if (tmp$12 !== undefined) {
    tmp.maxBounds = Js_primitive.valFromOption(tmp$12);
  }
  var tmp$13 = data[/* scrollZoom */14];
  if (tmp$13 !== undefined) {
    tmp.scrollZoom = Js_primitive.valFromOption(tmp$13);
  }
  var tmp$14 = data[/* boxZoom */15];
  if (tmp$14 !== undefined) {
    tmp.boxZoom = Js_primitive.valFromOption(tmp$14);
  }
  var tmp$15 = data[/* dragRotate */16];
  if (tmp$15 !== undefined) {
    tmp.dragRotate = Js_primitive.valFromOption(tmp$15);
  }
  var tmp$16 = data[/* dragPan */17];
  if (tmp$16 !== undefined) {
    tmp.dragPan = Js_primitive.valFromOption(tmp$16);
  }
  var tmp$17 = data[/* keyboard */18];
  if (tmp$17 !== undefined) {
    tmp.keyboard = Js_primitive.valFromOption(tmp$17);
  }
  var tmp$18 = data[/* doubleClickZoom */19];
  if (tmp$18 !== undefined) {
    tmp.doubleClickZoom = Js_primitive.valFromOption(tmp$18);
  }
  var tmp$19 = data[/* touchZoomRotate */20];
  if (tmp$19 !== undefined) {
    tmp.touchZoomRotate = Js_primitive.valFromOption(tmp$19);
  }
  var tmp$20 = data[/* trackResize */21];
  if (tmp$20 !== undefined) {
    tmp.trackResize = Js_primitive.valFromOption(tmp$20);
  }
  var tmp$21 = data[/* center */22];
  if (tmp$21 !== undefined) {
    tmp.center = Js_primitive.valFromOption(tmp$21);
  }
  var tmp$22 = data[/* zoom */23];
  if (tmp$22 !== undefined) {
    tmp.zoom = Js_primitive.valFromOption(tmp$22);
  }
  return tmp;
}

exports.Style = Style;
exports.LogoPosition = LogoPosition;
exports.MapContainer = MapContainer;
exports.make = make;
exports.tToJs = tToJs$3;
/* No side effect */
