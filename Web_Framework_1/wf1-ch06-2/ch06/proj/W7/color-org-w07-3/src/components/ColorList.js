/**
 * proj_path: ch06/proj/color-org-w07-3
 * ./src/components/ColorList.js
 */

import React from "react";
import Color from "./Color";

const ColorList = function ({ 
    colors = [], 
    onRemoveColor = f => f,
    onRateColor = f => f
  }) {
  return (
    <div>
      {colors.map(color =>
        <Color 
          key={color.id}
          {...color}
          onRemove={onRemoveColor}
          onRate={onRateColor}
        />)}
    </div>
  );
}

export default ColorList;
