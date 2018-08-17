type t;

[@bs.new][@bs.module "mapbox-gl/dist/mapbox-gl.js"]
external create: (float, float) => t = "Point";

[@bs.get] external getX: t => float = "x";
[@bs.get] external getY: t => float = "y";

let make = (~x, ~y): t =>
  create(x, y);
