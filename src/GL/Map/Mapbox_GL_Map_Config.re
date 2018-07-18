module Style = {
  type owner = string;
  type styleID = string;

  type t =
    | Streets
    | Outdoors
    | Light
    | Dark
    | Satellite
    | SatelliteStreets
    | NavPreviewDay
    | NavPreviewNight
    | NavGuidanceDay
    | NavGuidanceNight
    | LoadNamed(owner, styleID)
    | LoadJSON(string)
    | RawStyle(Js.Json.t) /* TODO: this actually has to have certain fields */
  ;

  let tToJs = (data: t): Js.Json.t => switch data {
  | Streets => Js.Json.string("mapbox://styles/mapbox/streets-v10")
  | Outdoors => Js.Json.string("mapbox://styles/mapbox/outdoors-v10")
  | Light => Js.Json.string("mapbox://styles/mapbox/light-v9")
  | Dark => Js.Json.string("mapbox://styles/mapbox/dark-v9")
  | Satellite => Js.Json.string("mapbox://styles/mapbox/satellite-v9")
  | SatelliteStreets => Js.Json.string("mapbox://styles/mapbox/satellite-streets-v10")
  | NavPreviewDay => Js.Json.string("mapbox://styles/mapbox/navigation-preview-day-v2")
  | NavPreviewNight => Js.Json.string("mapbox://styles/mapbox/navigation-preview-night-v2")
  | NavGuidanceDay => Js.Json.string("mapbox://styles/mapbox/navigation-guidance-day-v2")
  | NavGuidanceNight => Js.Json.string("mapbox://styles/mapbox/navigation-guidance-night-v2")
  | LoadNamed(owner, id) => Js.Json.string("mapbox://styles/" ++ owner ++ "/" ++ id)
  | LoadJSON(url) => Js.Json.string(url)
  | RawStyle(data) => data
  };
};

module LogoPosition = {
  type t =
    | TopLeft
    | TopRight
    | BottomLeft
    | BottomRight;

  let tToJs = (data: t): string => switch data {
  | TopLeft => "top-left"
  | TopRight => "top-right"
  | BottomLeft => "bottom-left"
  | BottomRight => "bottom-right"
  };
};

module MapContainer = {
  type t =
    | ID(string)
    | El(Dom.element);

  type t_js;

  external _tToJs : 'a => t_js = "%identity";

  let tToJs = (data: t): t_js => switch data {
  | ID(str) => str |> _tToJs;
  | El(el) => el |> _tToJs;
  };
};

type t = {
  container: MapContainer.t,
  minZoom: option(float), /* default: 0.0 */
  maxZoom: option(float), /* default 22.0 */
  style: Style.t,
  hash: option(bool), /* default false */
  interactive: option(bool), /* default true */
  bearingSnap: option(float), /* default 7 */
  pitchWithRotate: option(bool), /* default true */
  attributionControl: option(bool), /* default true */
  logoPosition: option(LogoPosition.t), /* default BottomLeft */
  failIfMajorPerformanceCaveat: option(bool), /* default false */
  preserveDrawingBuffer: option(bool), /* default false */
  refreshExpiredTiles: option(bool), /*default true */
  maxBounds: option(Mapbox_GL_LngLatBounds.t),
  scrollZoom: option(bool), /* default true  */
  boxZoom: option(bool), /* default true */
  dragRotate: option(bool), /* default true */
  dragPan: option(bool), /* default true */
  keyboard: option(bool), /* default true */
  doubleClickZoom: option(bool), /* default true */
  touchZoomRotate: option(bool), /* TODO: or object with options for handler */
  trackResize: option(bool), /* Resize map when browser resizes, default true */
  center: option(Mapbox_GL_LngLat.t), /* default [0. 0] */
  zoom: option(float) /* default 0.0 */
};

type jsObj = {.
  "container": MapContainer.t_js,
  "minZoom": Js.undefined(float),
  "maxZoom": Js.undefined(float),
  "style": Js.Json.t,
  "hash": Js.undefined(bool),
  "interactive": Js.undefined(bool),
  "bearingSnap": Js.undefined(float),
  "pitchWithRotate": Js.undefined(bool),
  "attributionControl": Js.undefined(bool),
  "logoPosition": Js.undefined(string),
  "failIfMajorPerformanceCaveat": Js.undefined(bool),
  "preserveDrawingBuffer": Js.undefined(bool),
  "refreshExpiredTiles": Js.undefined(bool),
  "maxBounds": Js.undefined(Mapbox_GL_LngLatBounds.t),
  "scrollZoom": Js.undefined(bool),
  "boxZoom": Js.undefined(bool),
  "dragRotate": Js.undefined(bool),
  "dragPan": Js.undefined(bool),
  "keyboard": Js.undefined(bool),
  "doubleClickZoom": Js.undefined(bool),
  "touchZoomRotate": Js.undefined(bool),
  "trackResize": Js.undefined(bool),
  "center": Js.undefined(Mapbox_GL_LngLat.t),
  "zoom": Js.undefined(float)
};

let make = (
  ~container,
  ~minZoom=?,
  ~maxZoom=?,
  ~style,
  ~hash=?,
  ~interactive=?,
  ~bearingSnap=?,
  ~pitchWithRotate=?,
  ~attributionControl=?,
  ~logoPosition=?,
  ~failIfMajorPerformanceCaveat=?,
  ~preserveDrawingBuffer=?,
  ~refreshExpiredTiles=?,
  ~maxBounds=?,
  ~scrollZoom=?,
  ~boxZoom=?,
  ~dragRotate=?,
  ~dragPan=?,
  ~keyboard=?,
  ~doubleClickZoom=?,
  ~touchZoomRotate=?,
  ~trackResize=?,
  ~center=?,
  ~zoom=?,
  ()
): t =>
{ container, minZoom, maxZoom, style, hash, interactive, bearingSnap,
  pitchWithRotate, attributionControl, logoPosition, failIfMajorPerformanceCaveat,
  preserveDrawingBuffer, refreshExpiredTiles, scrollZoom, boxZoom, dragRotate,
  dragPan, keyboard, doubleClickZoom, touchZoomRotate, trackResize, center,
  zoom, maxBounds };

/**
 * This is a special, magic function that will produce a JS object with fields
 * omitted entirely where optional values are `None`. We need this because the
 * Mapbox API expects unset config fields to be excluded, rather than set to
 * `undefined`. https://github.com/mapbox/mapbox-gl-js/issues/6635
 */
[@bs.obj] external makeConfig : (
  ~container: MapContainer.t_js,
  ~minZoom: float=?,
  ~maxZoom: float=?,
  ~style: Js.Json.t,
  ~hash: bool=?,
  ~interactive: bool=?,
  ~bearingSnap: float=?,
  ~pitchWithRotate: bool=?,
  ~attributionControl: bool=?,
  ~logoPosition: string=?,
  ~failIfMajorPerformanceCaveat: bool=?,
  ~preserveDrawingBuffer: bool=?,
  ~refreshExpiredTiles: bool=?,
  ~maxBounds: Mapbox_GL_LngLatBounds.t=?,
  ~scrollZoom: bool=?,
  ~boxZoom: bool=?,
  ~dragRotate: bool=?,
  ~dragPan: bool=?,
  ~keyboard: bool=?,
  ~doubleClickZoom: bool=?,
  ~touchZoomRotate: bool=?,
  ~trackResize: bool=?,
  ~center: Mapbox_GL_LngLat.t=?,
  ~zoom: float=?,
  unit
) => _ = "";

let tToJs = (data: t): jsObj => {
  let map =  Belt.Option.map;

  makeConfig(
    ~container= MapContainer.tToJs(data.container),
    ~minZoom= ?data.minZoom,
    ~maxZoom= ?data.maxZoom,
    ~style= data.style |> Style.tToJs,
    ~hash= ?data.hash,
    ~interactive= ?data.interactive,
    ~bearingSnap= ?data.bearingSnap,
    ~pitchWithRotate= ?data.pitchWithRotate,
    ~attributionControl= ?data.attributionControl,
    ~logoPosition= ?data.logoPosition |. map(LogoPosition.tToJs),
    ~failIfMajorPerformanceCaveat= ?data.failIfMajorPerformanceCaveat,
    ~preserveDrawingBuffer= ?data.preserveDrawingBuffer,
    ~refreshExpiredTiles= ?data.refreshExpiredTiles,
    ~maxBounds= ?data.maxBounds,
    ~scrollZoom= ?data.scrollZoom,
    ~boxZoom= ?data.boxZoom,
    ~dragRotate= ?data.dragRotate,
    ~dragPan= ?data.dragPan,
    ~keyboard= ?data.keyboard,
    ~doubleClickZoom= ?data.doubleClickZoom,
    ~touchZoomRotate= ?data.touchZoomRotate,
    ~trackResize= ?data.trackResize,
    ~center= ?data.center,
    ~zoom= ?data.zoom,
    ()
  );
};
