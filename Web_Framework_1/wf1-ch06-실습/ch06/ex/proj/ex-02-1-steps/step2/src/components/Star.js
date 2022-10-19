/**
 * proj_path: ch06/ex/proj/ex-02-1
 * ./src/components/Star.js
 */

// import module FaStar from react-icons/fa
import { FaStar } from "react-icons/fa";

const Star = ({ selected = false }) => 
  <FaStar color={selected ? "red" : "grey"} />
  
// export module
export default Star;