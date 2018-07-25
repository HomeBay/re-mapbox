type shape = {
  startEnd: GeoJSON_Position.t,
  second: GeoJSON_Position.t,
  third: GeoJSON_Position.t,
  rest: list(GeoJSON_Position.t)
};

let shapeToJSON = ({ startEnd, second, third, rest }) => {
  let pos = GeoJSON_Position.toJSON;
  let r = rest |. Belt.List.map(pos) |. Belt.List.toArray;
  Js.Array.concat(
    [| pos(startEnd), pos(second), pos(third) |],
    Js.Array.concat(r, [| pos(startEnd) |])
  ) |> Js.Json.array;
};

type t =
  | Shape(shape)
  | LinearRing(list(shape));

let makeShape = (~startEnd, ~second, ~third, ~rest=[], ()): shape =>
  { startEnd, second, third, rest };

let toJSON = data => switch data {
| Shape(s) => [| shapeToJSON(s) |]
| LinearRing(l) => l |. Belt.List.map(shapeToJSON) |. Belt.List.toArray
} |. Js.Json.array;
