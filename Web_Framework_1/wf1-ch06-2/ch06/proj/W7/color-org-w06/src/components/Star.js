/**
 * proj_path: ch06/proj/color-org-w06
 * ./src/components/Star.js
 */

import { FaStar } from "react-icons/fa";

const Star = ({ selected = false, onSelect = f => f }) => (
    <FaStar 
        color={selected ? "red" : "grey"}
        onClick={onSelect}
    />
);

export default Star;