/**
 * proj_path: ch06/ex/proj/ex-02-1
 * ./src/components/StarRating.js
 */

// import modules
import { useState } from "react";
import Star from "./Star";

const createArray = length => [...Array(length)];

const StarRating = ({ totalStars = 5 }) => {
  // state variable: selectedStars with default value 3
  const [selectedStars] = useState(3);

  return (
    // Stars : [red, red, red, grey, grey]
    // text: 3 of 5 stars
    <>
      {createArray(totalStars).map((n, i) => 
        <Star key={i} selected={selectedStars > i} />)}
      <p>{selectedStars} of {totalStars} stars</p>
    </>    
  );
}
  
// export module
export default StarRating;