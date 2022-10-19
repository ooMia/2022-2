/**
 * proj_path: ch06/proj/color-org-w07-2
 * ./src/components/StarRating.js
 */

import React from "react";
import Star from "./Star";

const createArray = length => [...Array(length)];

const StarRating = function( { totalStars = 5, selectedStars = 0 }){
    return (
        <>
            {createArray(totalStars).map( (n, i) => (
                <Star 
                    key={i} 
                    selected={selectedStars > i} 
                /> )) 
            }
            <p>
                {selectedStars} of {totalStars} stars
            </p>
        </>
    );
}

export default StarRating;