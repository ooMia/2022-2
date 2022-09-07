/**
 * 03-1-dom.js
 */

var target = document.getElementById("target");
var wrapper = document.createElement("div");
var headline = document.createElement("h1");

wrapper.id = "welcome";
headline.innerText = "Hello world";

wrapper.appendChild(headline);
target.appendChild(wrapper);