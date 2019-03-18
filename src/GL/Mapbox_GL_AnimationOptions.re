[@bs.deriving abstract]
type t = {
  [@bs.optional] [@bs.as "duration"] durationMs: int,
  [@bs.optional] easing: float => float,
  [@bs.optional] offset: Mapbox_GL_Point.t,
  [@bs.optional] animate: bool
};
