type t = {
  first: GeoJSON_Position.t,
  second: GeoJSON_Position.t,
  rest: list(GeoJSON_Position.t)
};

let make = (~first, ~second, ~rest=[], ()): t =>
  { first, second, rest };

let twoPoints = (~first, ~second): t =>
  make(~first, ~second, ());

let toJSON = ({ first, second, rest}) => {
  let pos = GeoJSON_Position.toJSON;
  let r = rest |. Belt.List.map(pos) |. Belt.List.toArray;
  Js.Array.concat([| pos(first), pos(second)|], r) |. Js.Json.array;
};
