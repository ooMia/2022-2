/**
 * proj_path: ch06/proj/color-org-w07-4
 * ./src/components/StarRating.js
 */

import React from "react";
import Star from "./Star";

const createArray = length => [...Array(length)];

const StarRating = function( { 
        totalStars = 5, 
        selectedStars = 0,
        onRate = f => f
    }){
    return (
        <>
            {createArray(totalStars).map( (n, i) => (
                <Star 
                    key={i} 
                    selected={selectedStars > i} 
                    onSelect={() => onRate(i+1)}
                /> )) 
            }
            <p>
                {selectedStars} of {totalStars} stars
            </p>
        </>
    );
}

export default StarRating;