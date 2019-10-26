module GeoJSON = Mapbox_GL_Source_GeoJSON;

// a function that will be called with either a (nullable) string error or a
// nullable value of some type
type callback('a) = (. Js.Nullable.t(string), Js.Nullable.t('a)) => unit;

type t;

external fromGeoJSON: GeoJSON.t => t = "%identity";

let geoJSONWithData = GeoJSON.makeWithJSON(~transformT=fromGeoJSON);
let geoJSONWithURL = GeoJSON.makeWithURL(~transformT=fromGeoJSON);

// Some map methods, such as `map.getSource(name)` return a source. I'm not 100%
// sure _that_ source is the same as the one defined here. The following
// functions definitely exist when you get a source from that method.
//
// Additionally, I'm not sure if different kinds of sources have different
// methods available, so maybe these aren't available everywhere?
[@bs.send] external setData: (t, Js.Json.t) => t = "setData";

[@bs.send]
external getClusterExpansionZoom: (t, float, callback(float)) => t =
  "getClusterExpansionZoom";

[@bs.send]
external getClusterChildren: (t, float, callback(Js.Json.t)) => t =
  "getClusterChildren";

[@bs.send]
external getClusterLeaves: (t, float, float, float, callback(Js.Json.t)) => t =
  "getClusterLeaves";
