/**
 * proj_path: ch06/proj/color-org-w07-2
 * ./src/App.js
 */

import { useState } from "react";
import ColorList from "./components/ColorList";
import colorData from "./data/color-data.json";

function App() {
  const [colors, setColors] = useState(colorData);
  return (
    <ColorList 
      colors={colors}
      onRemoveColor={ id => {
        const newColors = colors.filter( color => color.id !== id );
        setColors(newColors);
      }}
    />
  );
}

export default App;
