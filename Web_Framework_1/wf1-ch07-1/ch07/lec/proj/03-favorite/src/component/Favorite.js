/**
 * proj/03-favorite
 * /src/component/Favorite.js
 */

import React, {useState, useEffect} from "react";

const Favorite = () => {
  const [typed, setTyped] = useState("");
  const [phrase, setPhrase] = useState("example phrase");

  const createPhrase = () => {
    setPhrase(typed);
    setTyped("");
  }

  useEffect(() => {
    console.log(`typing: "${typed}"`);
  });

  useEffect(() => {
    console.log(`saved phrase: "${phrase}"`);
  });

  return (
    <>
      <label>Favorite phrase:</label>
      <input
        value={typed}
        placeholder={phrase}
        onChange={e => setTyped(e.target.value)}
      />
      <button onClick={createPhrase}>send</button>
    </>
  );
}

export default Favorite;