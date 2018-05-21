type t = {
  latitude: float,
  longitude: float
};

type t_js = {.
  "lng": float,
  "lat": float
};

let make = (~latitude, ~longitude): t =>
  { latitude, longitude };

let tToJs = ({latitude, longitude}): t_js => {
  "lng": longitude,
  "lat": latitude
};
