/**
 * proj_path: ch06/proj/color-org-w07-3
 * ./src/App.js
 */

import { useState } from "react";
import ColorList from "./components/ColorList";
import colorData from "./data/color-data.json";

function App() {
  const [colors, setColors] = useState(colorData);
  
  const removeColor = id => {
    const newColors = colors.filter(color => color.id !== id);
    setColors(newColors);
  };

  const rateColor = (id, rating) => {
    const newColors = colors.map( color => color.id === id ?
      {...color, rating} : color );
    setColors(newColors);
  }

  return (
    <ColorList 
      colors={colors}
      onRemoveColor={removeColor}
      onRateColor={rateColor}
    />
  );
}

export default App;
