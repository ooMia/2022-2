/**
 * proj_path: ch06/ex/proj/famous-location-02
 * ./src/components/Famous.js
 */

// import module
// code here

const Famous = props => (
  <div>
    <header>
      <h1>{props.title}</h1>
    </header>
    <article className="places">
      {
        props.famous.map((item, i) => (
          <Place
            key={i}
            name={item.name}
            locations={item.locations}
            majors={item.majors}
          />
        ))
      }
    </article>
  </div>
);

// export module
// code here