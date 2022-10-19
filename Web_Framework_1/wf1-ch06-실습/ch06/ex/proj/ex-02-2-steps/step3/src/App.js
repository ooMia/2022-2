/**
 * proj_path: ch06/ex/proj/ex-02-2
 * ./src/App.js
 */

// import data and module
import { useState } from "react";
import ColorList from "./components/ColorList";
import colorData from "./data/color-data.json";

function App() {
  const [colors, setColors] = useState(colorData);

  return (
    // return StarRating component with totalStars property
    // <StarRating totalStars={5}/>
    <ColorList
      colors={colors} 
      onRemoveColor={id => {
        const newColor = colors.filter(color => color.id !== id)
        setColors(newColor);
      }}
    />
  );
}

// export module
export default App;