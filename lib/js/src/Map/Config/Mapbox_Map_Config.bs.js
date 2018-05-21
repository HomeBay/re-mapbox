'use strict';

var Belt_Option = require("bs-platform/lib/js/belt_Option.js");
var Mapbox_LngLat = require("../../Mapbox_LngLat.bs.js");
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

function tToJs$2(param) {
  return /* array */[
          param[/* w */3],
          param[/* s */2],
          param[/* e */1],
          param[/* n */0]
        ];
}

var LngLatBounds = /* module */[/* tToJs */tToJs$2];

function make(container, minZoom, maxZoom, style, hash, interactive, bearingSnap, pitchWithRotate, attributionControl, logoPosition, failIfMajorPerformanceCaveat, preserveDrawingBuffer, refreshExpiredTiles, scrollZoom, boxZoom, dragRotate, dragPan, keyboard, doubleClickZoom, touchZoomRotate, trackResize, center, zoom, _) {
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
    container: tToJs$1(data[/* container */0]),
    style: Mapbox_Map_Config_Style.tToJs(data[/* style */3])
  };
  var tmp$1 = Belt_Option.map(data[/* minZoom */1], Mapbox_Map_Config_Zoom.tToJs);
  if (tmp$1) {
    tmp.minZoom = tmp$1[0];
  }
  var tmp$2 = Belt_Option.map(data[/* maxZoom */2], Mapbox_Map_Config_Zoom.tToJs);
  if (tmp$2) {
    tmp.maxZoom = tmp$2[0];
  }
  var tmp$3 = data[/* hash */4];
  if (tmp$3) {
    tmp.hash = tmp$3[0];
  }
  var tmp$4 = data[/* interactive */5];
  if (tmp$4) {
    tmp.interactive = tmp$4[0];
  }
  var tmp$5 = data[/* bearingSnap */6];
  if (tmp$5) {
    tmp.bearingSnap = tmp$5[0];
  }
  var tmp$6 = data[/* pitchWithRotate */7];
  if (tmp$6) {
    tmp.pitchWithRotate = tmp$6[0];
  }
  var tmp$7 = data[/* attributionControl */8];
  if (tmp$7) {
    tmp.attributionControl = tmp$7[0];
  }
  var tmp$8 = Belt_Option.map(data[/* logoPosition */9], tToJs);
  if (tmp$8) {
    tmp.logoPosition = tmp$8[0];
  }
  var tmp$9 = data[/* failIfMajorPerformanceCaveat */10];
  if (tmp$9) {
    tmp.failIfMajorPerformanceCaveat = tmp$9[0];
  }
  var tmp$10 = data[/* preserveDrawingBuffer */11];
  if (tmp$10) {
    tmp.preserveDrawingBuffer = tmp$10[0];
  }
  var tmp$11 = data[/* refreshExpiredTiles */12];
  if (tmp$11) {
    tmp.refreshExpiredTiles = tmp$11[0];
  }
  var tmp$12 = data[/* scrollZoom */13];
  if (tmp$12) {
    tmp.scrollZoom = tmp$12[0];
  }
  var tmp$13 = data[/* boxZoom */14];
  if (tmp$13) {
    tmp.boxZoom = tmp$13[0];
  }
  var tmp$14 = data[/* dragRotate */15];
  if (tmp$14) {
    tmp.dragRotate = tmp$14[0];
  }
  var tmp$15 = data[/* dragPan */16];
  if (tmp$15) {
    tmp.dragPan = tmp$15[0];
  }
  var tmp$16 = data[/* keyboard */17];
  if (tmp$16) {
    tmp.keyboard = tmp$16[0];
  }
  var tmp$17 = data[/* doubleClickZoom */18];
  if (tmp$17) {
    tmp.doubleClickZoom = tmp$17[0];
  }
  var tmp$18 = data[/* touchZoomRotate */19];
  if (tmp$18) {
    tmp.touchZoomRotate = tmp$18[0];
  }
  var tmp$19 = data[/* trackResize */20];
  if (tmp$19) {
    tmp.trackResize = tmp$19[0];
  }
  var tmp$20 = Belt_Option.map(data[/* center */21], Mapbox_LngLat.tToJs);
  if (tmp$20) {
    tmp.center = tmp$20[0];
  }
  var tmp$21 = Belt_Option.map(data[/* zoom */22], Mapbox_Map_Config_Zoom.tToJs);
  if (tmp$21) {
    tmp.zoom = tmp$21[0];
  }
  return tmp;
}

var LngLat = 0;

var Zoom = 0;

var Style = 0;

exports.LngLat = LngLat;
exports.Zoom = Zoom;
exports.Style = Style;
exports.LogoPosition = LogoPosition;
exports.MapContainer = MapContainer;
exports.LngLatBounds = LngLatBounds;
exports.make = make;
exports.tToJs = tToJs$3;
/* No side effect */
