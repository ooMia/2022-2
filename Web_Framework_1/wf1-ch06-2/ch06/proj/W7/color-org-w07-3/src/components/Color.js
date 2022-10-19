/**
 * proj_path: ch06/proj/color-org-w07-3
 * ./src/components/Color.js
 */

import React from "react";
import { FaTrash } from "react-icons/fa";
import StarRating from "./StarRating"

const Color = function ({ 
    id, title, color, rating, 
    onRemove = f => f,
    onRate = f => f
  }) {
  return (
    <section>
      <h1>{title}</h1>
      <button onClick={ () => onRemove(id) }>
        <FaTrash />
      </button>
      <div style={{ backgroundColor: color, height: 50 }} />
      <StarRating 
        selectedStars={rating}
        onRate={rating => onRate(id, rating)}
      />
    </section>
  );
}

export default Color;
