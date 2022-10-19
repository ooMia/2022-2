/**
 * proj_path: ch06/ex/proj/ex-02-1
 * ./src/components/StarRating.js
 */

// import module
import Star from "./Star";

const createArray = length => [...Array(length)];

const StarRating = ({ totalStars = 5 }) => 
  createArray(totalStars).map((n, i) =>
    <Star key={i} />
  )
  
// export module
export default StarRating;