type owner = string;
type styleID = string;

type t =
  | Streets
  | Outdoors
  | Light
  | Dark
  | Satellite
  | SatelliteStreets
  | NavPreviewDay
  | NavPreviewNight
  | NavGuidanceDay
  | NavGuidanceNight
  | LoadNamed(owner, styleID)
  | LoadJSON(string)
  | RawStyle(Js.Json.t) /* TODO: this actually has to have certain fields */
;

let tToJs = (data: t): Js.Json.t => switch data {
| Streets => Js.Json.string("mapbox://styles/mapbox/streets-v10")
| Outdoors => Js.Json.string("mapbox://styles/mapbox/outdoors-v10")
| Light => Js.Json.string("mapbox://styles/mapbox/light-v9")
| Dark => Js.Json.string("mapbox://styles/mapbox/dark-v9")
| Satellite => Js.Json.string("mapbox://styles/mapbox/satellite-v9")
| SatelliteStreets => Js.Json.string("mapbox://styles/mapbox/satellite-streets-v10")
| NavPreviewDay => Js.Json.string("mapbox://styles/mapbox/navigation-preview-day-v2")
| NavPreviewNight => Js.Json.string("mapbox://styles/mapbox/navigation-preview-night-v2")
| NavGuidanceDay => Js.Json.string("mapbox://styles/mapbox/navigation-guidance-day-v2")
| NavGuidanceNight => Js.Json.string("mapbox://styles/mapbox/navigation-guidance-night-v2")
| LoadNamed(owner, id) => Js.Json.string("mapbox://styles/" ++ owner ++ "/" ++ id)
| LoadJSON(url) => Js.Json.string(url)
| RawStyle(data) => data
};
