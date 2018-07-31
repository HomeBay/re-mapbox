type t = {.
  "x": float,
  "y": float
};

[@bs.new][@bs.module "mapbox-gl/dist/mapbox-gl.js"]
external create: (float, float) => t = "Point";

let make = (~x, ~y): t =>
  create(x, y);
