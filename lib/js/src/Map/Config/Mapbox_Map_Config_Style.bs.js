'use strict';


function tToJs(data) {
  if (typeof data === "number") {
    switch (data) {
      case 0 : 
          return "mapbox://styles/mapbox/streets-v10";
      case 1 : 
          return "mapbox://styles/mapbox/outdoors-v10";
      case 2 : 
          return "mapbox://styles/mapbox/light-v9";
      case 3 : 
          return "mapbox://styles/mapbox/dark-v9";
      case 4 : 
          return "mapbox://styles/mapbox/satellite-v9";
      case 5 : 
          return "mapbox://styles/mapbox/satellite-streets-v10";
      case 6 : 
          return "mapbox://styles/mapbox/navigation-preview-day-v2";
      case 7 : 
          return "mapbox://styles/mapbox/navigation-preview-night-v2";
      case 8 : 
          return "mapbox://styles/mapbox/navigation-guidance-day-v2";
      case 9 : 
          return "mapbox://styles/mapbox/navigation-guidance-night-v2";
      
    }
  } else {
    switch (data.tag | 0) {
      case 0 : 
          return "mapbox://styles/" + (data[0] + ("/" + data[1]));
      case 1 : 
      case 2 : 
          return data[0];
      
    }
  }
}

exports.tToJs = tToJs;
/* No side effect */
