/**
 * proj_path: ch06/ex/proj/ex-02-2
 * ./src/components/StarRating.js
 */

// import modules
import Star from "./Star";
const createArray = length => [...Array(length)];

const StarRating = ({ 
  totalStars = 5, selectedStars,
  onRate = f => f
}) => (
    // Stars : [red, red, red, grey, grey]
    // define onSelect()
    // text: 3 of 5 stars
    <>
      {createArray(totalStars).map((n, i) => 
        <Star 
          key={i} 
          selected={selectedStars > i} 
          onSelect={() => onRate(i+1)}          
        />)}
      <p>{selectedStars} of {totalStars} stars</p>
    </>    
  );
  
// export module
export default StarRating;