
type t = {
  latitude: float,
  longitude: float,
  altitude: option(float)
};

let make = (~latitude, ~longitude, ~altitude=?, ()) =>
  { latitude, longitude, altitude };

let latLong = (~latitude, ~longitude) =>
  make(~latitude, ~longitude, ());

let toArray = ({ latitude, longitude, altitude }) => {
  let out = [| latitude, longitude |];
  switch altitude {
  | Some(n) => Js.Array.concat(out, [| n |])
  | None => out
  }
};

let toJSON = data => toArray(data)
  |> Js.Array.map(Js.Json.number)
  |> Js.Json.array;