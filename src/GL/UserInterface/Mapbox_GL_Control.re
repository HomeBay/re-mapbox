/**
 * In Mapbox JS, there is no real `Control` type. Instead this type represents
 * the `IControl` interface. Individual control types can be converted into this
 * type and passed to `map.addControl(...)`.
 *
 * open Mapbox.GL;
 * let map = Map.make(cfg);
 * let nav = NavigationControl.make()->NavigationControl.toControl();
 * map->Map.addControl(nav);
 */
type t;
