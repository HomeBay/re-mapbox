type d2 = {
  n: float,
  e: float,
  s: float,
  w: float
};

type d3 = {
  d2: d2,
  highest: float,
  lowest: float
};

type t =
  | D2(d2)
  | D3(d3)
  ;

let toArray = data => switch data {
| D2({ n, e, s, w }) => [| s, w, n, e |]
| D3({ d2, highest, lowest}) => [| d2.s, d2.w, d2.n, d2.e, highest, lowest |]
};

let toJSON = data => toArray(data)
  |> Js.Array.map(Js.Json.number)
  |> Js.Json.array;