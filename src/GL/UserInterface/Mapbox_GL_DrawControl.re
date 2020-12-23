module EventWithFeatures = {
  type t;
  [@bs.get] external features: t => array(Js.Json.t) = "features";
};

module EventWithMode = {
  type t;
  [@bs.get] external mode: t => string = "mode";
};

// TODO: Modes are probably pretty incomplete. There's a lot going on here, and
// I don't have any immediate need for it, so I stubbed out what I could easily
// make sense of from their examples here:
// github.com/mapbox/mapbox-gl-draw/blob/master/docs/MODES.md
module Mode = {
  // TODO: not sure where this event data comes from or what it looks like
  type e;

  [@bs.deriving abstract]
  type t('state) = {
    [@bs.optional]
    onSetup: 'state => 'state,
    [@bs.optional]
    onClick: ('state, e) => unit,
    [@bs.optional]
    onKeyUp: ('state, e) => unit,
    toDisplayFeatures: ('state, Js.Json.t, Js.Json.t => unit),
  };
};

module Options = {
  [@bs.deriving abstract]
  type t('state) = {
    [@bs.optional]
    keybindings: bool, // default: true
    [@bs.optional]
    touchEnabled: bool, // default: true
    [@bs.optional]
    boxSelect: bool, // default true
    [@bs.optional]
    clickBuffer: int, // in pixels, default 2
    [@bs.optional]
    touchBuffer: int, // in pixels, default 25
    [@bs.optional]
    controls: Js.Dict.t(bool), // control name as string key
    [@bs.optional]
    displayControlsDefault: bool, // default true
    // [@bs.optional] styles: array(Style??)
    [@bs.optional]
    modes: Js.Dict.t(Mode.t('state)),
    [@bs.optional]
    defaultMode: string, // default: 'simple_select'
    [@bs.optional]
    userProperties: bool // default: false
  };
};

type t('state);

[@bs.new] [@bs.module "@mapbox/mapbox-gl-draw"]
external make: unit => t('a) = "default";

[@bs.new] [@bs.module "@mapbox/mapbox-gl-draw"]
external makeWithOptions: Options.t('state) => t('state) = "default";

external toControl: t('a) => Mapbox_GL_Control.t = "%identity";

/**
 * This method takes either a GeoJSON Feature, FeatureCollection, or Geometry
 * and adds it to Draw. It returns an array of ids for interacting with the
 * added features. If a feature does not have its own id, one is automatically
 * generated.
 *
 * The supported GeoJSON feature types are supported: Point, LineString,
 * Polygon, MultiPoint, MultiLineString, and MultiPolygon.
 */
[@bs.send]
external add: (t('a), Js.Json.t) => array(string) = "";

/**
 * Returns the GeoJSON feature in Draw with the specified id, or undefined if
 * the id matches no feature.
 */
[@bs.send] [@bs.return nullable]
external get: (t('a), string) => option(Js.Json.t) = "";

// TODO:
// getFeatureIdsAt(point: { x: number, y: number }): Array<string>

/**
 * Returns an array of feature ids for features currently selected.
 */
[@bs.send]
external getSelectedIds: t('a) => array(string) = "";

/**
 * Returns a FeatureCollection of all the features currently selected.
 */
[@bs.send]
external getSelected: t('a) => Js.Json.t = "";

/**
 * Returns a FeatureCollection of Points representing all the vertices currently
 * selected.
 */
[@bs.send]
external getSelectedPoints: t('a) => Js.Json.t = "";

/**
 * Returns a FeatureCollection of all features.
 */
[@bs.send]
external getAll: t('a) => Js.Json.t = "";

/**
 * Removes features with the specified ids. Returns the draw instance for
 * chaining.
 *
 * In direct_select mode, deleting the active feature will exit that mode and
 * revert to the simple_select mode.
 */
[@bs.send]
external delete: (t('a), array(string)) => t('a) = "";

/**
 * Removes all features. Returns the draw instance for chaining.
 */
[@bs.send]
external deleteAll: t('a) => t('a) = "";

/**
 * Sets Draw's features to those in the specified FeatureCollection.
 *
 * Performs whatever delete, create, and update actions are necessary to make
 * Draw's features match the specified FeatureCollection. Effectively, this is
 * the same as Draw.deleteAll() followed by Draw.add(featureCollection) except
 * that it does not affect performance as much.
 */
[@bs.send]
external set: (t('a), Js.Json.t) => array(string) = "";

/**
 * Invokes the current mode's trash action. Returns the draw instance for
 * chaining.
 */
[@bs.send]
external trash: t('a) => t('a) = "";

/**
 * Invokes the current mode's combineFeatures action. Returns the draw instance
 * for chaining.
 */
[@bs.send]
external combineFeatures: t('a) => t('a) = "";

/**
 * Invokes the current mode's uncombineFeatures action. Returns the draw
 * instance for chaining.
 */
[@bs.send]
external uncombineFeatures: t('a) => t('a) = "";

/**
 * Returns Draw's current mode.
 */
[@bs.send]
external getMode: t('a) => string = "";

/**
 * Changes Draw to another mode. Returns the draw instance for chaining.
 *
 * The mode argument must be one of the mode names described above and
 * enumerated in Draw.modes.
 *
 * simple_select, direct_select, and draw_line_string modes accept an options
 * object.
 */
[@bs.send]
external changeMode: (t('state), string, 'state) => t('state) = "";

// TODO: not sure how this should be used
// setFeatureProperty(featureId: string, property: string, value: any): draw

// Events

[@bs.send]
external onCreate:
  (Mapbox_GL_Map.t, [@bs.as "draw.create"] _, EventWithFeatures.t => unit) =>
  Mapbox_GL_Map.t =
  "on";

[@bs.send]
external onDelete:
  (Mapbox_GL_Map.t, [@bs.as "draw.delete"] _, EventWithFeatures.t => unit) =>
  Mapbox_GL_Map.t =
  "on";

// TODO: combine
// TODO: uncombine

// TODO: the `update` event also has e.action == "move" | "change_coordinates"
[@bs.send]
external onUpdate:
  (Mapbox_GL_Map.t, [@bs.as "draw.update"] _, EventWithFeatures.t => unit) =>
  Mapbox_GL_Map.t =
  "on";

[@bs.send]
external onSelectionChange:
  (
    Mapbox_GL_Map.t,
    [@bs.as "draw.selectionchange"] _,
    EventWithFeatures.t => unit
  ) =>
  Mapbox_GL_Map.t =
  "on";

[@bs.send]
external onModeChange:
  (Mapbox_GL_Map.t, [@bs.as "draw.modechange"] _, EventWithMode.t => unit) =>
  Mapbox_GL_Map.t =
  "on";

// TODO: render
// TODO: actionable
