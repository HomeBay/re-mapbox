module Position = GeoJSON_Position;
module Line = GeoJSON_Line;
module Polygon = GeoJSON_Polygon;

type t =
  | Point(Position.t)
  | LineString(Line.t)
  | Polygon(Polygon.t)
  | MultiPoint(list(Position.t))
  | MultiLineString(list(Line.t))
  | MultiPolygon(list(Polygon.t))
  | GeometryCollection(list(t))
  ;

let rec toJSONFields = (data: t) => {
  open Js.Json;
  let pos = Position.toJSON;
  let line = Line.toJSON;
  let poly = Polygon.toJSON;

  switch data {
  | Point(p) => [
      ("type", string("Point")),
      ("coordinates", pos(p))
    ]

  | LineString(l) => [
      ("type", string("LineString")),
      ("coordinates", line(l))
    ]

  | Polygon(p) => [
      ("type", string("Polygon")),
      ("coordinates", poly(p))
    ]

  | MultiPoint(l) => [
      ("type", string("MultiPoint")),
      ("coordinates", l |. Belt.List.map(pos) |. Belt.List.toArray |. array)
    ]

  | MultiLineString(l) => [
      ("type", string("MultiLineString")),
      ("coordinates", l |. Belt.List.map(line) |. Belt.List.toArray |. array)
    ]

  | MultiPolygon(l) => [
      ("type", string("MultiPolygon")),
      ("coordinates", l |. Belt.List.map(poly) |. Belt.List.toArray |. array)
    ]

  | GeometryCollection(l) => [
      ("type", string("GeometryCollection")),
      ("geometries", l
        |. Belt.List.map(v => toJSONFields(v) |> Js.Dict.fromList |> Js.Json.object_)
        |. Belt.List.toArray |. array
      )
    ]
  }
};

let toJSON = data => toJSONFields(data) |> Js.Dict.fromList |> Js.Json.object_;
