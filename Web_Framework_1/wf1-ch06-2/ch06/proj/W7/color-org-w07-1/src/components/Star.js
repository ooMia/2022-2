/**
 * proj_path: ch06/proj/color-org-w07-1
 * ./src/components/Star.js
 */

import { FaStar } from "react-icons/fa";

const Star = ({ selected = false }) => (
    <FaStar 
        color={selected ? "red" : "grey"}
    />
);

export default Star;