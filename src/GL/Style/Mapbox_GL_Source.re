module GeoJSON = Mapbox_GL_Source_GeoJSON;

type t;

external fromGeoJSON: GeoJSON.t => t = "%identity";

let geoJSONWithData = GeoJSON.makeWithJSON(~transformT=fromGeoJSON);
let geoJSONWithURL = GeoJSON.makeWithURL(~transformT=fromGeoJSON);
