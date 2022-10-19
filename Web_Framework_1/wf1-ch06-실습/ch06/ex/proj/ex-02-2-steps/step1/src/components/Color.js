/**
 * proj_path: ch06/ex/proj/ex-02-2
 * ./src/components/Color.js
 */

// import modules
import StarRating from "./StarRating";

const Color = ({ colors }) => 
  <section>
    <h1>{colors.title}</h1>
    <div style={{ backgroundColor: colors.color, height: 50 }} />
    <StarRating selectedStars={colors.rating} />
  </section> 
  
// export module
export default Color;