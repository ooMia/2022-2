
/**
 * closure.js
 */

function makeAdder(x){
    var y=1;
    return function(z){
        y=100;
        return x+y+z;
    };
}

var add5 = makeAdder(5);
var add10 = makeAdder(10);

console.log(add5(2));
console.log(add10(2));

function makeFunc(){
    const name = 'Mozilla';
    function displayName(){
        console.log(name);
    }
    return displayName;
}

const myFunc = makeFunc();
myFunc();

function init(){
    const init_name = 'init_Mozilla';
    function init_displayName(){
        console.log(init_name);
    }
    init_displayName();
}

init();