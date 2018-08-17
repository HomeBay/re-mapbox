[@bs.deriving abstract]
type t = {
  [@bs.optional] duration: int, /* time in ms */
  [@bs.optional] easing: float => float,
  [@bs.optional] offset: Mapbox_GL_Point.t,
  [@bs.optional] animate: bool
};
