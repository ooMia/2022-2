/**
 * proj_path: ch06/ex/proj/ex-02-1
 * ./src/App.js
 */

// import data and module
import Star from "./components/Star";

function App() {
  return (
    // return Star component with selected property
    <Star selected={false} />
  );
}

// export module
export default App;