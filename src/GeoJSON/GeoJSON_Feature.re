type featureId =
  | StringID(string)
  | IntID(int);

type t = {
  id: option(featureId),
  geometry: option(GeoJSON_Geometry.t),
  properties: option(Js.Dict.t(Js.Json.t))
};

let make = (~id=?, ~geometry=?, ~properties=?, ()) =>
  { id, geometry, properties };

let toJSONFields = ({ id, geometry, properties }) => {
  open Js.Json;

  let maybePrepend = (lst, opt) =>
    Belt.Option.mapWithDefault(opt, lst, v => [v, ...lst]);

  let featureIdToJSON = id => switch id {
  | StringID(str) => string(str)
  | IntID(i) => number(float_of_int(i))
  };

  let geom = GeoJSON_Geometry.toJSON;

  [( "geometry", geometry |. Belt.Option.mapWithDefault(null, geom))]
    |. maybePrepend(properties |. Belt.Option.map(v => ("properties", object_(v))))
    |. maybePrepend(Belt.Option.map(id, v => ("id", featureIdToJSON(v))));
};