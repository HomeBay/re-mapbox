module Options = Mapbox_GL_Map_Options;
module FitOptions = Mapbox_GL_Map_FitOptions;
module Event = Mapbox_GL_Map_EventData;

module QueryRenderedFeaturesOptions = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    layers: array(string),
    [@bs.optional]
    filter: array(string),
  };
};

type t;

[@bs.new] [@bs.module "mapbox-gl/dist/mapbox-gl.js"]
external makeExn: Options.t => t = "Map";

let make = cfg =>
  try (Belt.Result.Ok(makeExn(cfg))) {
  | _ => Belt.Result.Error("Failed to initialize MapboxGL")
  };

// Methods to position the map
[@bs.send] external setCenter: (t, float) => t = "setCenter";
[@bs.send] external setZoom: (t, float) => t = "setZoom";

[@bs.send]
external fitBounds: (t, Mapbox_GL_LngLatBounds.t, FitOptions.t) => t =
  "fitBounds";

[@bs.send]
external fitBoundsWithEventData:
  (t, Mapbox_GL_LngLatBounds.t, FitOptions.t, Js.Dict.t(Js.Json.t)) => t =
  "fitBounds";

[@bs.send]
external easeTo: (t, Mapbox_GL_CameraAnimationOptions.t) => t = "easeTo";

/*******************************************************************************
 * Map Events
 *
 * You can attach event listeners to the map. While events with custom names may
 * be fired (e.g. by plugins), there's also a well-defined list of events, which
 * are included here so you don't need to mess around with string names.
 *
 * Many events can be fired manually, with arbitrary data payloads (treated as
 * dictionaries from string->json). TODO: I'm not not sure if those are nullable
 * for certain events...
 *
 * Other events are fired with specific payloads (e.g. mouse events include the
 * LngLat position of the mouse cursor). These payloads may also be treated as
 * a dictionary, since arbitrary metadata can be attached.
 ******************************************************************************/

/**
 * Simplest version of the function to add event listeners. There are no
 * guarantees here that the event will exist or that the payload will contain
 * any specific fields. Use this sparingly.
 */
[@bs.send]
external on: (t, string, Event.t => unit) => t = "on";

[@bs.send]
external onLayerEvent:
  (t, ~event: string, ~layerId: string, Event.t => unit) => t =
  "on";

/**
 * Fired immediately after the map has been resized.
 */
[@bs.send]
external onResize: (t, [@bs.as "resize"] _, Event.t => unit) => t = "on";

/**
 * Fired immediately after the map has been removed with Map.event:remove.
 */
[@bs.send]
external onRemove: (t, [@bs.as "remove"] _, Event.t => unit) => t = "on";

/**
 * Fired when a pointing device (usually a mouse) is pressed within the map.
 */
[@bs.send]
external onMouseDown: (t, [@bs.as "mousedown"] _, Event.Mouse.t => unit) => t =
  "on";

/**
 * Fired when a pointing device (usually a mouse) is released within the map.
 */
[@bs.send]
external onMouseUp: (t, [@bs.as "mouseup"] _, Event.Mouse.t => unit) => t =
  "on";

/**
 * Fired when a pointing device (usually a mouse) is moved within the map.
 */
[@bs.send]
external onMouseOver: (t, [@bs.as "mouseover"] _, Event.Mouse.t => unit) => t =
  "on";

/**
 * Fired when a pointing device (usually a mouse) is moved within the map.
 */
[@bs.send]
external onMouseMove: (t, [@bs.as "mousemove"] _, Event.Mouse.t => unit) => t =
  "on";

/**
 * Fired when a pointing device (usually a mouse) is pressed and released at the
 * same point on the map.
 */
[@bs.send]
external onClick: (t, [@bs.as "click"] _, Event.Mouse.t => unit) => t = "on";

[@bs.send]
external onLayerClick:
  (t, [@bs.as "click"] _, string, Event.Mouse.t => unit) => t =
  "on";

/**
 * Fired when a pointing device (usually a mouse) is clicked twice at the same
 * point on the map.
 */
[@bs.send]
external onDblClick: (t, [@bs.as "dblclick"] _, Event.Mouse.t => unit) => t =
  "on";

// Note: mouseenter and mouseleave only work for _layer_ events. This isn't an
// accidental omission...

/**
 * Fired when a pointing device (usually a mouse) enters a visible portion of a
 * specified layer from outside that layer or outside the map canvas.
 */
[@bs.send]
external onLayerMouseEnter:
  (t, [@bs.as "mouseenter"] _, string, Event.Mouse.t => unit) => t =
  "on";

/**
 * Fired when a pointing device (usually a mouse) leaves a visible portion of a
 * specified layer, or leaves the map canvas.
 */
[@bs.send]
external onLayerMouseLeave:
  (t, [@bs.as "mouseleave"] _, string, Event.Mouse.t => unit) => t =
  "on";

/**
 * Fired when a pointing device (usually a mouse) leaves the map's canvas.
 */
[@bs.send]
external onMouseOut: (t, [@bs.as "mouseout"] _, Event.Mouse.t => unit) => t =
  "on";

/**
 * Fired when the right button of the mouse is clicked or the context menu key
 * is pressed within the map.
 */
[@bs.send]
external onContextMenu:
  (t, [@bs.as "contextmenu"] _, Event.Mouse.t => unit) => t =
  "on";

/**
 * Fired when a wheel event occurs within the map.
 */
[@bs.send]
external onWheel: (t, [@bs.as "wheel"] _, Event.MouseWheel.t => unit) => t =
  "on";

/**
 * Fired when a touchstart event occurs within the map.
 */
[@bs.send]
external onTouchStart: (t, [@bs.as "touchstart"] _, Event.Touch.t => unit) => t =
  "on";

/**
 * Fired when a touchend event occurs within the map.
 */
[@bs.send]
external onTouchEnd: (t, [@bs.as "touchend"] _, Event.Touch.t => unit) => t =
  "on";

/**
 * Fired when a touchmove event occurs within the map.
 */
[@bs.send]
external onTouchMove: (t, [@bs.as "touchmove"] _, Event.Touch.t => unit) => t =
  "on";

/**
 * Fired when a touchcancel event occurs within the map.
 */
[@bs.send]
external onTouchCancel:
  (t, [@bs.as "touchcancel"] _, Event.Touch.t => unit) => t =
  "on";

/**
 * Fired just before the map begins a transition from one view to another, as
 * the result of either user interaction or methods such as Map#jumpTo.
 */
[@bs.send]
external onMoveStart: (t, [@bs.as "movestart"] _, Event.Drag.t => unit) => t =
  "on";

/**
 * Fired repeatedly during an animated transition from one view to another, as
 * the result of either user interaction or methods such as Map#flyTo.
 *
 * Note: the event payload could either be a Mouse event or a Touch event,
 * depending on how the event was initiated. We opt for `Mouse` here because
 * it's a (mostly) safe subset of `Touch`. If you need touch-specific fields,
 * you'll need to runtime check and type-cast.
 */
[@bs.send]
external onMove: (t, [@bs.as "move"] _, Event.Mouse.t => unit) => t = "on";

/**
 * Fired just after the map completes a transition from one view to another, as
 * the result of either user interaction or methods such as Map#jumpTo.
 */
[@bs.send]
external onMoveEnd: (t, [@bs.as "moveend"] _, Event.Drag.t => unit) => t =
  "on";

/**
 * Fired when a "drag to pan" interaction starts.
 */
[@bs.send]
external onDragStart: (t, [@bs.as "dragstart"] _, Event.Drag.t => unit) => t =
  "on";

/**
 * Fired repeatedly during a "drag to pan" interaction.
 *
 * Note: similar to `onMove`, this event payload could have either Mouse or
 * Touch data. We choose Mouse because it's mostly a subset of Touch.
 */
[@bs.send]
external onDrag: (t, [@bs.as "drag"] _, Event.Mouse.t => unit) => t = "on";

/**
 * Fired when a "drag to pan" interaction ends.
 */
[@bs.send]
external onDragEnd: (t, [@bs.as "dragend"] _, Event.Drag.t => unit) => t =
  "on";

[@bs.send]
external onZoomStart: (t, [@bs.as "zoomstart"] _, Event.Mouse.t => unit) => t =
  "on";

[@bs.send]
external onZoom: (t, [@bs.as "zoom"] _, Event.Mouse.t => unit) => t = "on";

[@bs.send]
external onZoomEnd: (t, [@bs.as "zoomend"] _, Event.Mouse.t => unit) => t =
  "on";

[@bs.send]
external onRotateStart:
  (t, [@bs.as "rotatestart"] _, Event.Mouse.t => unit) => t =
  "on";

[@bs.send]
external onRotate: (t, [@bs.as "rotate"] _, Event.Mouse.t => unit) => t = "on";

[@bs.send]
external onRotateEnd: (t, [@bs.as "rotateend"] _, Event.Mouse.t => unit) => t =
  "on";

[@bs.send]
external onPitchStart: (t, [@bs.as "pitchstart"] _, Event.t => unit) => t =
  "on";

[@bs.send]
external onPitch: (t, [@bs.as "pitch"] _, Event.t => unit) => t = "on";

[@bs.send]
external onPitchEnd: (t, [@bs.as "pitchend"] _, Event.t => unit) => t = "on";

[@bs.send]
external onBoxZoomStart:
  (t, [@bs.as "boxzoomstart"] _, Event.BoxZoom.t => unit) => t =
  "on";

[@bs.send]
external onBoxZoomEnd:
  (t, [@bs.as "boxzoomend"] _, Event.BoxZoom.t => unit) => t =
  "on";

[@bs.send]
external onBoxZoomCancel:
  (t, [@bs.as "boxzoomcancel"] _, Event.BoxZoom.t => unit) => t =
  "on";

[@bs.send]
external onWebGLContextLost:
  (t, [@bs.as "webglcontextlost"] _, Event.t => unit) => t =
  "on";

[@bs.send]
external onWebGLContextRestored:
  (t, [@bs.as "webglcontextrestored"] _, Event.t => unit) => t =
  "on";

[@bs.send]
external onLoad: (t, [@bs.as "load"] _, Event.t => unit) => t = "on";

[@bs.send]
external onRender: (t, [@bs.as "render"] _, Event.t => unit) => t = "on";

[@bs.send]
external onIdle: (t, [@bs.as "idle"] _, Event.t => unit) => t = "on";

[@bs.send]
external onError: (t, [@bs.as "error"] _, Event.Error.t => unit) => t = "on";

[@bs.send]
external onData: (t, [@bs.as "data"] _, Event.Data.t => unit) => t = "on";

[@bs.send]
external onStyleData: (t, [@bs.as "styledata"] _, Event.Data.t => unit) => t =
  "on";

[@bs.send]
external onSourceData: (t, [@bs.as "sourcedata"] _, Event.Data.t => unit) => t =
  "on";

[@bs.send]
external onDataLoading:
  (t, [@bs.as "dataloading"] _, Event.Data.t => unit) => t =
  "on";

[@bs.send]
external onStyleDataLoading:
  (t, [@bs.as "styledataloading"] _, Event.Data.t => unit) => t =
  "on";

[@bs.send]
external onSourceDataLoading:
  (t, [@bs.as "sourcedataloading"] _, Event.Data.t => unit) => t =
  "on";

[@bs.send]
external onStyleImageMissing:
  (t, [@bs.as "styleimagemissing"] _, Event.ImageMissing.t => unit) => t =
  "on";

// Methods to deal with layer events

[@bs.send] external off: (t, string, Event.t => unit) => t = "off";

[@bs.send]
external offLayerEvent:
  (t, ~event: string, ~layerId: string, Event.t => unit) => t =
  "off";

// Methods to deal with ui/layers and sources
[@bs.send] external addLayer: (t, Mapbox_GL_Layer.t_js) => t = "";

[@bs.send] [@bs.return nullable]
external getLayer: (t, string) => option(Mapbox_GL_Layer.t_js) = "";

[@bs.send] external removeLayer: (t, string) => unit = ""; /* TODO: docs don't specify return */

[@bs.send] external addSource: (t, string, Mapbox_GL_Source.t) => t = "";

[@bs.send] [@bs.return nullable]
external getSource: (t, string) => option(Mapbox_GL_Source.t) = "";

[@bs.send] external removeSource: (t, string) => t = "";
[@bs.send] external addControl: (t, Mapbox_GL_Control.t) => t = "";
[@bs.send]
external addControlToCorner:
  (t, Mapbox_GL_Control.t, Mapbox_GL_Map_Corner.t) => t =
  "addControl";

/* Methods to deal with DOM elements */
[@bs.send] external getContainer: t => Dom.element = "getContainer";
[@bs.send]
external getCanvasContainer: t => Dom.element = "getCanvasContainer";
[@bs.send] external getCanvas: t => Dom.element = "getCanvas";

/* Methods to deal with internal state, cleanup, and more */
[@bs.send] external getBounds: t => Mapbox_GL_LngLatBounds.t = "getBounds";
[@bs.send] external getZoom: t => float = "getZoom";
[@bs.send]
external queryRenderedFeatures:
  (t, Mapbox_GL_Point.t, QueryRenderedFeaturesOptions.t) => array(Js.Json.t) =
  "queryRenderedFeatures";

// When querying rendered features, it seems like you often want to specify one
// or more layers and no filters. Often enough that we provide helpers here.

let queryRenderedFeaturesForLayers:
  (t, Mapbox_GL_Point.t, array(string)) => array(Js.Json.t) =
  (map, point, layers) =>
    map->queryRenderedFeatures(
      point,
      QueryRenderedFeaturesOptions.t(~layers, ()),
    );

let queryRenderedFeaturesForLayer:
  (t, Mapbox_GL_Point.t, string) => array(Js.Json.t) =
  (map, point, layer) =>
    queryRenderedFeaturesForLayers(map, point, [|layer|]);

let firstRenderedFeatureForLayer:
  (t, Mapbox_GL_Point.t, string) => option(Js.Json.t) =
  (map, point, layer) =>
    queryRenderedFeaturesForLayer(map, point, layer)->Belt.Array.get(0);

[@bs.send] external resize: t => unit = "resize";

[@bs.send]
external resizeWithEventData: (t, Js.Dict.t(Js.Json.t)) => unit = "resize";

[@bs.send] external remove: t => unit = "remove";
