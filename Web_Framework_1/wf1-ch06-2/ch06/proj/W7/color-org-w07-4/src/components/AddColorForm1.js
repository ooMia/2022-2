/**
 * proj_path: ch06/proj/color-org-w07-4
 * ./src/components/AddColorForm1.js
 */

import React, { useRef } from "react";
const AddColorForm1 = function ({ onNewColor = f => f }) {
  const txtTitle = useRef();
  const hexColor = useRef();

  const submit = e => {
    e.preventDefault();
    const title = txtTitle.current.value;
    const color = hexColor.current.value;
    onNewColor(title, color);
    txtTitle.current.value = "";
    hexColor.current.value = "";
  };

  return (
    <form onSubmit={submit}>
      <input 
        ref={txtTitle}
        type="text" placeholder="color title..." required />
      <input 
        ref={hexColor}
        type="color" required />
      <button>ADD</button>
    </form>
  );
}

export default AddColorForm1;
