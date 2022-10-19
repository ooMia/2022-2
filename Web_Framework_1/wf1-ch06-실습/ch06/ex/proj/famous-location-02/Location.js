/**
 * proj_path: ch06/ex/proj/famous-location-02
 * ./src/components/Location.js
 */

const Location = ({ locations }) => (
  <>
    <h3>Location</h3>
    <ul className="locations">
      {Object.keys(locations).map((obj_prp, i) => (
        <li key={i}>{obj_prp}: {locations[obj_prp]}</li>
      ))}
    </ul>
  </>
);

// export module
// code here