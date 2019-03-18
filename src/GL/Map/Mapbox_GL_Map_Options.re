module Style = {
  type t;

  /* TODO: this actually requires specific fields */
  external rawStyle: Js.Json.t => t = "%identity";
  external fromURL: string => t = "%identity";

  let loadFromMapbox = (~owner, ~style) =>
    fromURL("mapbox://styles/" ++ owner ++ "/" ++ style);

  /* TODO: hide from rei */
  let mapboxStyle = style => loadFromMapbox(~owner="mapbox", ~style);

  let streets = mapboxStyle("streets-v10");
  let outdoors = mapboxStyle("outdoors-v10");
  let light = mapboxStyle("light-v9");
  let dark = mapboxStyle("dark-v9");
  let satellite = mapboxStyle("satellite-v9");
  let satelliteStreets = mapboxStyle("satellite-streets-v10");
  let navPreviewDay = mapboxStyle("navigation-preview-day-v2");
  let navPreviewNight = mapboxStyle("navigation-preview-night-v2");
  let navGuidanceDay = mapboxStyle("navigation-guidance-day-v2");
  let navGuidanceNight = mapboxStyle("navigation-guidance-night-v2");
};

module Corner = Mapbox_GL_Map_Corner;

module MapContainer = {
  type t;
  external fromElement: Dom.element => t = "%identity";
  external fromSelector: string => t = "%identity";
};

/**
 * Note that `[@bs.optional]` in a `[@bs.deriving abstract]` type will omit
 * fields entirely (instead of keeping the field with an `undefined` or `null`
 * value). This is **important** because Mapbox needs the fields to be omitted
 * completely: https://github.com/mapbox/mapbox-gl-js/issues/6635
 */
[@bs.deriving abstract]
type t = {
  container: MapContainer.t,
  [@bs.optional] minZoom: float,
  [@bs.optional] maxZoom: float,
  style: Style.t,
  [@bs.optional] hash: bool, /* sync URL hash: default false */
  [@bs.optional] interactive: bool, /* default: true */
  [@bs.optional] bearingSnap: float, /* default: 7 */
  [@bs.optional] pitchWithRotate: bool, /* default: true */
  [@bs.optional] attributionControl: bool, /* default: true */
  [@bs.optional] customAttribution: array(string),
  [@bs.optional] logoPosition: Corner.t, /* default: bottomLeft */
  [@bs.optional] failIfMajorPerformanceCaveat: bool, /* default: false */
  [@bs.optional] preserveDrawingBuffer: bool, /* default: false */
  [@bs.optional] refreshExpiredTiles: bool, /* default: true */
  [@bs.optional] maxBounds: Mapbox_GL_LngLatBounds.t,
  [@bs.optional] scrollZoom: bool, /* default: true */
  [@bs.optional] boxZoom: bool, /* default: true */
  [@bs.optional] dragRotate: bool, /* default: true */
  [@bs.optional] dragPan: bool, /* default: true */
  [@bs.optional] keyboard: bool, /* default: true */
  [@bs.optional] doubleClickZoom: bool, /* default: true */
  [@bs.optional] touchZoomRotate: bool, /* TODO: or config object for handler */
  [@bs.optional] trackResize: bool, /* default: true */
  [@bs.optional] center: Mapbox_GL_LngLat.t, /* default: [0, 0] */
  [@bs.optional] zoom: float, /* default: 0.0 */
  [@bs.optional] bearing: float, /* default: 0.0 */
  [@bs.optional] pitch: float, /* default: 0.0 */
  [@bs.optional] bounds: Mapbox_GL_LngLatBounds.t,
  [@bs.optional] renderWorldCopies: bool, /* default: true */
  [@bs.optional] maxTilesCacheSize: float, /* default: calculated dynamically */
  [@bs.optional] localIdeographFontFamily: string,
  /* TODO: transformRequest */
  [@bs.optional] collectResourceTiming: bool, /* default: true */
  [@bs.optional] fadeDuration: float, /* default: 300 */
  [@bs.optional] crossSourceCollisions: bool, /* default: true */
};
