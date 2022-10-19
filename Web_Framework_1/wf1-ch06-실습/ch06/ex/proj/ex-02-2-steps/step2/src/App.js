/**
 * proj_path: ch06/ex/proj/ex-02-2
 * ./src/App.js
 */

// import data and module
import ColorList from "./components/ColorList";
import colorData from "./data/color-data.json";

function App() {
  return (
    // return StarRating component with totalStars property
    // <StarRating totalStars={5}/>
    <ColorList colors={colorData} />
  );
}

// export module
export default App;