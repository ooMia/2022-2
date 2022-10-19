/**
 * proj_path: ch06/proj/color-org-w07-1
 * ./src/components/ColorList.js
 */

import React from "react";
import Color from "./Color";

const ColorList = function ({ colors = [] }) {
  return (
    <div>
      {colors.map(color =>
        <Color 
          key={color.id}
          {...color}
        />)}
    </div>
  );
}

export default ColorList;
