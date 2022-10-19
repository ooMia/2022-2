/**
 * proj_path: ch06/proj/color-org-w07-1
 * ./src/App.js
 */

import { useState } from "react";
import ColorList from "./components/ColorList";
import colorData from "./data/color-data.json";

function App() {
  const [colors] = useState(colorData);
  return (
    <ColorList 
      colors={colors}
    />
  );
}

export default App;
