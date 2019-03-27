/**
 * This is not a "real" type. It exists because some functions (e.g. `easeTo`)
 * allow passing in a combination of camera and animation options.
 */
[@bs.deriving abstract]
type t = {
  /* specific to fitOptions */
  [@bs.optional] [@bs.as "padding"] paddingPx: float,
  [@bs.optional] linear: bool,
  [@bs.optional] maxZoom: float,

  /* camera */
  [@bs.optional] center: Mapbox_GL_LngLat.t,
  [@bs.optional] zoom: float,
  [@bs.optional] bearing: float,
  [@bs.optional] pitch: float,
  [@bs.optional] around: Mapbox_GL_LngLat.t,

  /* animation */
  [@bs.optional] [@bs.as "duration"] durationMs: int,
  [@bs.optional] easing: float => float,
  [@bs.optional] offset: Mapbox_GL_Point.t,
  [@bs.optional] animate: bool
};
