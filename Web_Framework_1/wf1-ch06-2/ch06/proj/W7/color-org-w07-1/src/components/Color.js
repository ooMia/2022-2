/**
 * proj_path: ch06/proj/color-org-w07-1
 * ./src/components/Color.js
 */

import React from "react";
import StarRating from "./StarRating"

const Color = function ({ title, color, rating }) {
  return (
    <section>
      <h1>{title}</h1>
      <div style={{ backgroundColor: color, height: 50 }} />
      <StarRating selectedStars={rating} />
    </section>
  );
}

export default Color;
