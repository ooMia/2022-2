/**
 * proj_path: ch06/ex/proj/ex-02-2
 * ./src/components/Color.js
 */

// import modules
import StarRating from "./StarRating";
import { FaTrash } from "react-icons/fa";

const Color = ({ 
  id, title, color, rating,
  onRemove = f => f,
  onRate = f => f
 }) => 
  <section>
    <h1>{title}</h1>
    <button onClick={() => onRemove(id)}>
      <FaTrash />
    </button>
    <div style={{ backgroundColor: color, height: 50 }} />
    <StarRating 
      selectedStars={rating} 
      onRate={rating => onRate(id, rating)}
    />
  </section> 
  
// export module
export default Color;