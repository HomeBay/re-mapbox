type t =
  | Center
  | Top
  | Bottom
  | Left
  | Right
  | TopLeft
  | TopRight
  | BottomLeft
  | BottomRight;

type t_js = string;

let tToJs = (data) => switch data {
  | Center => "center"
  | Top => "top"
  | Bottom => "bottom"
  | Left => "left"
  | Right => "right"
  | TopLeft => "top-left"
  | TopRight => "top-right"
  | BottomLeft => "bottom-left"
  | BottomRight => "bottom-right"
};
