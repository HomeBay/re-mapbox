type stop('number, 'output) = {
  value: 'output,
  until: 'number
};

let makeStop = (~value, ~until) =>
  { value, until };

let stopToJS = (numberToJSON, valueToJSON, { value, until }) => {
  [| valueToJSON(value), numberToJSON(until) |];
};

type t('number, 'output) = {
  input: Mapbox_GL_Style_Expression.t('number),
  stops: array(stop('number, 'output)),
  finalStop: 'output
};

let make = (~input, ~stops, ~finalStop) =>
  { input, stops, finalStop };

type t_js = array(Js.Json.t);

let tToJS = (numberToJSON, valueToJSON, { input, stops, finalStop }) => {
  open Js.Json;

  let arr = [|
    string("step"),
    Mapbox_GL_Style_Expression.tToJS(numberToJSON, input),
  |];

  let stopsArr = Belt.Array.reduce(stops, [||], (acc, curr) =>
    Belt.Array.concat(acc, stopToJS(numberToJSON, valueToJSON, curr))
  );

  Belt.Array.concatMany([| arr, stopsArr, [| valueToJSON(finalStop) |] |])
};
