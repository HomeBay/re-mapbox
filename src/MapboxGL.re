type t;

[@bs.val] [@bs.module] external mapboxgl: t = "mapbox-gl/dist/mapbox-gl.js";

[@bs.set] external setAccessToken : t => string => unit = "accessToken";

module LngLat = Mapbox_LngLat;
module LngLatBounds = Mapbox_LngLatBounds;
module Map = Mapbox_Map;
module Marker = Mapbox_Marker;


