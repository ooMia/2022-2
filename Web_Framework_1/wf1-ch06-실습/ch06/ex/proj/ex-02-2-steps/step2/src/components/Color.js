/**
 * proj_path: ch06/ex/proj/ex-02-2
 * ./src/components/Color.js
 */

// import modules
import StarRating from "./StarRating";

const Color = ({ title, color, rating }) => 
  <section>
    <h1>{title}</h1>
    <div style={{ backgroundColor: color, height: 50 }} />
    <StarRating selectedStars={rating} />
  </section> 
  
// export module
export default Color;