[@bs.deriving abstract]
type t = {
  [@bs.optional] center: Mapbox_GL_LngLat.t,
  [@bs.optional] zoom: float,
  [@bs.optional] bearing: float,
  [@bs.optional] pitch: float,
  [@bs.optional] around: Mapbox_GL_LngLat.t
};
