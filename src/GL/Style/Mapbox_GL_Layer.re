type sourceId = string;

type layerType =
  | Fill(sourceId)
  | Line(sourceId)
  | Symbol(sourceId)
  | Circle(sourceId)
  | Heatmap(sourceId)
  | FillExtrusion(sourceId)
  | Raster(sourceId)
  | Hillshade(sourceId)
  | Background
  ;

let layerTypeString = v => switch v {
| Fill(_) => "fill"
| Line(_) => "line"
| Symbol(_) => "symbol"
| Circle(_) => "circle"
| Heatmap(_) => "heatmap"
| FillExtrusion(_) => "fill-extrusion"
| Raster(_) => "raster"
| Hillshade(_) => "hillshade"
| Background => "background"
};

let getLayerSource = v => switch v {
| Fill(data) => Some(data)
| Line(data) => Some(data)
| Symbol(data) => Some(data)
| Circle(data) => Some(data)
| Heatmap(data) => Some(data)
| FillExtrusion(data) => Some(data)
| Raster(data) => Some(data)
| Hillshade(data) => Some(data)
| Background => None
};

type t = {
  id: string,
  _type: layerType,
  metadata: option(Js.Dict.t(Js.Json.t)),
  sourceLayer: option(string),
  minZoom: option(float),
  maxZoom: option(float),
  filter: option(array(string)),

  /* TODO: the correct layout/paint objects actually depend on layerType */
  layout: option(Mapbox_GL_Style_Layout.t),
  paint: option(Mapbox_GL_Style_Paint.t)
};

[@bs.deriving abstract]
type t_js = {
  id: string,
  [@bs.as "type"] _type: string,
  [@bs.optional] metadata: Js.Dict.t(Js.Json.t),
  [@bs.optional] source: string,
  [@bs.optional] [@bs.as "source-layer"] sourceLayer: string,
  [@bs.optional] minzoom: float,
  [@bs.optional] maxzoom: float,
  [@bs.optional] filter: array(string),
  [@bs.optional] layout: Js.Dict.t(Js.Json.t),
  [@bs.optional] paint: Js.Dict.t(Js.Json.t)
};

let tToJS = v => t_js(
  ~id= v.id,
  ~_type= layerTypeString(v._type),
  ~metadata= ?v.metadata,
  ~source= ?getLayerSource(v._type),
  ~sourceLayer= ?v.sourceLayer,
  ~minzoom= ?v.minZoom,
  ~maxzoom= ?v.maxZoom,
  ~filter= ?v.filter,
  ~layout= ?v.layout,
  ~paint= ?v.paint
);