/**
 * proj_path: ch06/ex/proj/ex-02-2
 * ./src/App.js
 */

// import data and module
import Color from "./components/Color";
import colorData from "./data/color-data.json";

function App() {
  return (
    // return StarRating component with totalStars property
    // <StarRating totalStars={5}/>
    <Color colors={colorData} />
  );
}

// export module
export default App;