'use strict';

var Belt_Option = require("bs-platform/lib/js/belt_Option.js");
var Js_primitive = require("bs-platform/lib/js/js_primitive.js");
var Mapbox_Map_Config_Zoom = require("./Mapbox_Map_Config_Zoom.bs.js");
var Mapbox_Map_Config_Style = require("./Mapbox_Map_Config_Style.bs.js");

function tToJs(data) {
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

var LogoPosition = /* module */[/* tToJs */tToJs];

function tToJs$1(data) {
  return data[0];
}

var MapContainer = /* module */[/* tToJs */tToJs$1];

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

function tToJs$2(data) {
  var tmp = {
    container: tToJs$1(data[/* container */0]),
    style: Mapbox_Map_Config_Style.tToJs(data[/* style */3])
  };
  var tmp$1 = Belt_Option.map(data[/* minZoom */1], Mapbox_Map_Config_Zoom.tToJs);
  if (tmp$1) {
    tmp.minZoom = Js_primitive.valFromOption(tmp$1);
  }
  var tmp$2 = Belt_Option.map(data[/* maxZoom */2], Mapbox_Map_Config_Zoom.tToJs);
  if (tmp$2) {
    tmp.maxZoom = Js_primitive.valFromOption(tmp$2);
  }
  var tmp$3 = data[/* hash */4];
  if (tmp$3) {
    tmp.hash = Js_primitive.valFromOption(tmp$3);
  }
  var tmp$4 = data[/* interactive */5];
  if (tmp$4) {
    tmp.interactive = Js_primitive.valFromOption(tmp$4);
  }
  var tmp$5 = data[/* bearingSnap */6];
  if (tmp$5) {
    tmp.bearingSnap = Js_primitive.valFromOption(tmp$5);
  }
  var tmp$6 = data[/* pitchWithRotate */7];
  if (tmp$6) {
    tmp.pitchWithRotate = Js_primitive.valFromOption(tmp$6);
  }
  var tmp$7 = data[/* attributionControl */8];
  if (tmp$7) {
    tmp.attributionControl = Js_primitive.valFromOption(tmp$7);
  }
  var tmp$8 = Belt_Option.map(data[/* logoPosition */9], tToJs);
  if (tmp$8) {
    tmp.logoPosition = Js_primitive.valFromOption(tmp$8);
  }
  var tmp$9 = data[/* failIfMajorPerformanceCaveat */10];
  if (tmp$9) {
    tmp.failIfMajorPerformanceCaveat = Js_primitive.valFromOption(tmp$9);
  }
  var tmp$10 = data[/* preserveDrawingBuffer */11];
  if (tmp$10) {
    tmp.preserveDrawingBuffer = Js_primitive.valFromOption(tmp$10);
  }
  var tmp$11 = data[/* refreshExpiredTiles */12];
  if (tmp$11) {
    tmp.refreshExpiredTiles = Js_primitive.valFromOption(tmp$11);
  }
  var tmp$12 = data[/* maxBounds */13];
  if (tmp$12) {
    tmp.maxBounds = Js_primitive.valFromOption(tmp$12);
  }
  var tmp$13 = data[/* scrollZoom */14];
  if (tmp$13) {
    tmp.scrollZoom = Js_primitive.valFromOption(tmp$13);
  }
  var tmp$14 = data[/* boxZoom */15];
  if (tmp$14) {
    tmp.boxZoom = Js_primitive.valFromOption(tmp$14);
  }
  var tmp$15 = data[/* dragRotate */16];
  if (tmp$15) {
    tmp.dragRotate = Js_primitive.valFromOption(tmp$15);
  }
  var tmp$16 = data[/* dragPan */17];
  if (tmp$16) {
    tmp.dragPan = Js_primitive.valFromOption(tmp$16);
  }
  var tmp$17 = data[/* keyboard */18];
  if (tmp$17) {
    tmp.keyboard = Js_primitive.valFromOption(tmp$17);
  }
  var tmp$18 = data[/* doubleClickZoom */19];
  if (tmp$18) {
    tmp.doubleClickZoom = Js_primitive.valFromOption(tmp$18);
  }
  var tmp$19 = data[/* touchZoomRotate */20];
  if (tmp$19) {
    tmp.touchZoomRotate = Js_primitive.valFromOption(tmp$19);
  }
  var tmp$20 = data[/* trackResize */21];
  if (tmp$20) {
    tmp.trackResize = Js_primitive.valFromOption(tmp$20);
  }
  var tmp$21 = data[/* center */22];
  if (tmp$21) {
    tmp.center = Js_primitive.valFromOption(tmp$21);
  }
  var tmp$22 = Belt_Option.map(data[/* zoom */23], Mapbox_Map_Config_Zoom.tToJs);
  if (tmp$22) {
    tmp.zoom = Js_primitive.valFromOption(tmp$22);
  }
  return tmp;
}

var LngLat = 0;

var LngLatBounds = 0;

var Zoom = 0;

var Style = 0;

exports.LngLat = LngLat;
exports.LngLatBounds = LngLatBounds;
exports.Zoom = Zoom;
exports.Style = Style;
exports.LogoPosition = LogoPosition;
exports.MapContainer = MapContainer;
exports.make = make;
exports.tToJs = tToJs$2;
/* No side effect */
