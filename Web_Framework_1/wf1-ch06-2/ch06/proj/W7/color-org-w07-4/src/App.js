/**
 * proj_path: ch06/proj/color-org-w07-4
 * ./src/App.js
 */

import { useState } from "react";
import AddColorForm1 from "./components/AddColorForm1";
import AddColorForm2 from "./components/AddColorForm2";
import ColorList from "./components/ColorList";
import colorData from "./data/color-data.json";
import { v4 } from "uuid";

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
    <>
      <AddColorForm1
        onNewColor={(title, color) => {
          const newColors = [ ...colors, {
            id: v4(),
            rating: 0,
            title,
            color
          }];
          setColors(newColors);
        }}        
      />
      <AddColorForm2
        onNewColor={(title, color) => {
          const newColors = [...colors, {
            id: v4(),
            rating: 0,
            title,
            color
          }];
          setColors(newColors);
        }}
      />
      <ColorList
        colors={colors}
        onRemoveColor={removeColor}
        onRateColor={rateColor}
      />
    </>
    
  );
}

export default App;
