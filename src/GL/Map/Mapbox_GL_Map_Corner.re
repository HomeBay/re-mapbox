/**
 * This is also not a real type in the Mapbox world. Instead, this is a set of
 *  pre-defined values to help avoid the issues with stringly-typed arguments
 * in various config options.
 *
 * The downside of this approach is that you can't pattern match on these
 * values, but the upside is that you can't produce incorrect values of this
 * type, and there's no runtime conversion needed.
 */
type t;

/* TODO: hide from rei */
external fromString: string => t = "%identity";

let topLeft = fromString("top-left");
let topRight = fromString("top-right");
let bottomLeft = fromString("bottom-left");
let bottomRight = fromString("bottom-right");
