type t('a) =
  | GetExpr(string) /* outputs ["get", "value"] */
  | RawExpr(array(string)) /* you do you */
  | RawValue('a) /* int or float */
  ;

let tToJS = (valueToJS, expr) => {
  open Js.Json;

  switch expr {
  | GetExpr(v) => array([| string("get"), string(v) |])
  | RawExpr(arr) => Belt.Array.map(arr, string) |> array
  | RawValue(n) => valueToJS(n)
  }
};
