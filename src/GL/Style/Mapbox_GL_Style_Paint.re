/**
 * TODO
 *
 * This type is very incomplete. Without digging through examples or the source,
 * I'm not even sure from the documentation how exactly this object should be
 * structured.
 *
 * For now, I've opted for no type safety, and a `paint` style is simply a Dict
 * with string keys and JSON values (to accomodate both strings and numbers).
 */

type t = Js.Dict.t(Js.Json.t);



/* type t = {
  backgroundColor: option(string), /* TODO: color type */
  backgroundPattern: option(string),

};

[@bs.deriving abstract]
type t_js = {
  [@bs.optional][@bs.as "background-color"] backgroundColor: string,
  [@bs.optional][@bs.as "background-pattern"] backgroundPattern: string
};

let tToJs = data => {
  /* open Belt.Option; */
  t_js(
    ~backgroundColor= ?data.backgroundColor,
    ~backgroundPattern= ?data.backgroundPattern,
    ()
  );
}; */