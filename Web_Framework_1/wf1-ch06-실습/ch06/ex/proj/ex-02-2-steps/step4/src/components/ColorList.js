/**
 * proj_path: ch06/ex/proj/ex-02-2
 * ./src/components/ColorList.js
 */

// import modules
import Color from "./Color";

const ColorList = ({ 
  colors = [], 
  onRemoveColor = f => f,
  onRateColor = f => f
}) => 
  <div>
    {colors.map( color  =>
      <Color 
        key={color.id}
        {...color} 
        onRemove={onRemoveColor}
        onRate={onRateColor}
      />)}
  </div> 

// export module
export default ColorList;