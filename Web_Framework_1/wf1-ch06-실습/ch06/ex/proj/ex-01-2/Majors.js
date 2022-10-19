/**
 * proj_path: ch06/ex/proj/famous-location-02
 * ./src/components/Majors.js
 */

const Majors = ({ majors }) => (
  <>
    <h3>Majors</h3>
    <ul className="majors">
      {majors.map((major, i) => (
        <li key={i}>{major}</li>
      ))}
    </ul>
  </>
);

// export module
// code here