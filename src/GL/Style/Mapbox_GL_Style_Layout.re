/**
 * This type is very incomplete. Without digging through examples or the source,
 * I'm not even sure from the documentation how exactly this object should be
 * structured.
 *
 * For now, I've opted for no type safety, and a `paint` style is simply a Dict
 * with string keys and JSON values (to accomodate both strings and numbers).
 */

type t = Js.Dict.t(Js.Json.t);

/* type visibility = Visible | None;
let visibilityToString = v => switch v {
| Visible => "visible"
| None => "none"
};

type t = {
  visibility: option(visibility),

};

[@bs.deriving abstract]
type t_js = {
  [@bs.optional] visibility: string
};

let tToJs = data => {
  open Belt.Option;
  t_js(
    ~visibility = ?data.visibility |. map(visibilityToString),
    ()
  );
}; */