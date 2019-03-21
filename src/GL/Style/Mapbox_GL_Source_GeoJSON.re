[@bs.deriving abstract]
type t = {
  [@bs.as "type"]
  type_: string,
  [@bs.optional]
  data: Js.Json.t,
  [@bs.optional]
  maxzoom: float,
  [@bs.optional]
  attribution: string,
  [@bs.optional]
  buffer: float,
  [@bs.optional]
  tolerance: float,
  [@bs.optional]
  cluster: bool,
  [@bs.optional]
  clusterRadius: float,
  [@bs.optional]
  clusterMaxZoom: float,
  [@bs.optional]
  lineMetrics: bool,
};

/* this is a helper that puts the non-optional data parameter last, so you
   don't have to use `()` when constructing a value of type `t` */
let make =
    (
      ~maxzoom=?,
      ~attribution=?,
      ~buffer=?,
      ~tolerance=?,
      ~cluster=?,
      ~clusterRadius=?,
      ~clusterMaxZoom=?,
      ~lineMetrics=?,
      ~transformData,
      ~transformT,
      data,
    ) =>
  t(
    ~type_="geojson",
    ~maxzoom?,
    ~attribution?,
    ~buffer?,
    ~tolerance?,
    ~cluster?,
    ~clusterRadius?,
    ~clusterMaxZoom?,
    ~lineMetrics?,
    ~data=transformData(data),
    (),
  ) |> transformT;

let makeWithJSON = make(~transformData=v => v);
let makeWithURL = make(~transformData=Js.Json.string);
