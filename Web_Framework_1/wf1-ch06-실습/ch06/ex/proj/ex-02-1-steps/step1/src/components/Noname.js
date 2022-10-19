/**
 * proj_path: ch06/ex/proj/ex-02-1
 * ./src/components/Noname.js
 */

// import module

const Noname = props => (
  <div>
    <header>
      <h1>{props.title}</h1>
    </header>
    <article className="noname">
      {props.title}
    </article>
  </div>
);

// export module
export default Noname;