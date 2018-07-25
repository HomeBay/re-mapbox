module Geometry = GeoJSON_Geometry;
module Feature = GeoJSON_Feature;
module BoundingBox = GeoJSON_BoundingBox;

type kind =
  | Geometry(Geometry.t)
  | Feature(Feature.t)
  | FeatureCollection(list(Feature.t))
  ;

type t = {
  data: kind,
  bbox: option(BoundingBox.t)
};

let make = (~data, ~bbox=?, ()): t =>
  { data, bbox };

let geometry = (geom) => make(~data=Geometry(geom), ());
let feature = (feat) => make(~data=Feature(feat), ());
let featureCollection = (fc) => make(~data=FeatureCollection(fc), ());

let toJSON = ({ data, bbox }) => {
  let makeFeature = (f) => [
    ("type", Js.Json.string("Feature")),
    ...Feature.toJSONFields(f)
  ];

  let fields = switch data {
  | Geometry(g) => Geometry.toJSONFields(g)
  | Feature(f) => makeFeature(f)
  | FeatureCollection(l) => [
      ("type", Js.Json.string("FeatureCollection")),
      ("features", l
        |. Belt.List.map(v => makeFeature(v) |> Js.Dict.fromList |> Js.Json.object_)
        |. Belt.List.toArray |. Js.Json.array
      )
    ]
  };

  switch bbox {
  | Some(box) => [("bbox", BoundingBox.toJSON(box)), ...fields]
  | None => fields
  } |> Js.Dict.fromList |> Js.Json.object_
};


