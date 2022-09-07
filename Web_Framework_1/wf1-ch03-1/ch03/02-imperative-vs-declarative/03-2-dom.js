/**
 * 03-2-dom.js
 */

const { render } = ReactDOM;

const Welcome = () => (
    <div id="welcome">
        <h1>Hello world</h1>
    </div>
);

render(<Welcome />,
    document.getElementById('target'));