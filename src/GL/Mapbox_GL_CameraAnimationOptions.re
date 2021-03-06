/**
 * This is not a "real" type. It exists because some functions (e.g. `easeTo`)
 * allow passing in a combination of camera and animation options.
 */
[@bs.deriving abstract]
type t = {
  /* camera */
  [@bs.optional] center: Mapbox_GL_LngLat.t,
  [@bs.optional] zoom: float,
  [@bs.optional] bearing: float,
  [@bs.optional] pitch: float,
  [@bs.optional] around: Mapbox_GL_LngLat.t,

  /* animation */
  [@bs.optional] duration: int, /* time in ms */
  [@bs.optional] easing: float => float,
  [@bs.optional] offset: Mapbox_GL_Point.t,
  [@bs.optional] animate: bool
};
