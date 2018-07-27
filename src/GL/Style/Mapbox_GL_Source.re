type urlOr('a) =
  | Url(string)
  | Data('a);

type geoJsonSource = {
  data: option(urlOr(GeoJSON.t)),
  maxzoom: option(float),
  attribution: option(string),
  buffer: option(float),
  tolerance: option(float),
  cluster: option(bool),
  clusterRadius: option(float),
  clusterMaxZoom: option(float),
  lineMetrics: option(bool)
};

type t =
  | GeoJSON(geoJsonSource)
  ;

let geoJSON = (
  ~data=?,
  ~maxzoom=?,
  ~attribution=?,
  ~buffer=?,
  ~tolerance=?,
  ~cluster=?,
  ~clusterRadius=?,
  ~clusterMaxZoom=?,
  ~lineMetrics=?,
  ()
) => GeoJSON({ data, maxzoom, attribution, buffer, tolerance, cluster, clusterRadius, clusterMaxZoom, lineMetrics });

[@bs.deriving abstract]
type t_js = {
  [@bs.as "type"] _type: string,
  [@bs.optional] data: Js.Json.t,
  [@bs.optional] maxzoom: float,
  [@bs.optional] attribution: string,
  [@bs.optional] buffer: float,
  [@bs.optional] tolerance: float,
  [@bs.optional] cluster: bool,
  [@bs.optional] clusterRadius: float,
  [@bs.optional] clusterMaxZoom: float,
  [@bs.optional] lineMetrics: bool
};

let tToJS = v => switch v {
| GeoJSON(src) => t_js(
    ~_type= "geojson",
    ~data= ? src.data |. Belt.Option.map(v => switch v {
    | Url(str) => Js.Json.string(str)
    | Data(geojson) => GeoJSON.toJSON(geojson)
    }),
    ~maxzoom= ?src.maxzoom,
    ~attribution= ?src.attribution,
    ~buffer= ?src.buffer,
    ~tolerance= ?src.tolerance,
    ~cluster= ?src.cluster,
    ~clusterRadius= ?src.clusterRadius,
    ~clusterMaxZoom= ?src.clusterMaxZoom,
    ~lineMetrics= ?src.lineMetrics,
    ()
  )
};