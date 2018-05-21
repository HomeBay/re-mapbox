'use strict';


function tToJs(data) {
  switch (data) {
    case 0 : 
        return "center";
    case 1 : 
        return "top";
    case 2 : 
        return "bottom";
    case 3 : 
        return "left";
    case 4 : 
        return "right";
    case 5 : 
        return "top-left";
    case 6 : 
        return "top-right";
    case 7 : 
        return "bottom-left";
    case 8 : 
        return "bottom-right";
    
  }
}

exports.tToJs = tToJs;
/* No side effect */
