/**
 * proj_path: ch06/ex/proj/ex-02-2
 * ./src/components/ColorList.js
 */

// import modules
import Color from "./Color";

const ColorList = ({ colors = [] }) => 
  <div>
    {colors.map( color  =>
      <Color 
        key={color.id}
        {...color} 
      />)}
  </div> 

// export module
export default ColorList;