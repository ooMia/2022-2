/**
 * proj_path: ch06/proj/color-org-w07-4
 * ./src/components/AddColorForm2.js
 */

import React, { useState } from "react";
const AddColorForm2 = function ({ onNewColor = f => f }) {
  const [title, setTitle] = useState("");
  const [color, setColor] = useState("#000000");

  const submit = e => {
    e.preventDefault();
    onNewColor(title, color);
    setTitle("");
    setColor("");
  };

  return (
    <form onSubmit={submit}>
      <input 
        value={title}
        onChange={event => setTitle(event.target.value)}
        type="text" placeholder="color title..." required />
      <input
        value={color}
        onChange={event => setColor(event.target.value)}
        type="color" required />
      <button>ADD</button>
    </form>
  );
}

export default AddColorForm2;
