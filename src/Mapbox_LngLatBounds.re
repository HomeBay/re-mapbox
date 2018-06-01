type t = {
  n: float,
  e: float,
  s: float,
  w: float
};

type t_js = Js.Array.t(float);

let make = (~n, ~e, ~s, ~w) =>
  { n, e, s, w };

/* TODO: check that this is correct type, correct order, etc */
let tToJs = ({ n, e, s, w }): t_js =>
  [|w, s, e, n|];
