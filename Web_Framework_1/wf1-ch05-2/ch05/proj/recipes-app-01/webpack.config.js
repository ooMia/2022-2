/**
 * ch05/recipes-app/webpack.config.js
 */

/**
 * entry file from package.json is index.js
 *  >> index.js requires for React, ReactDOM, components/Menu, data/recipes.json
 * target file
 *  >> _dirname/dist/assets/bundle.js
 * define modules
 */

const path = require("path");

module.exports = {
    entry: "./src/index.js",
    output: {
        path: path.join(__dirname, "dist", "assets"),
        filename: "bundle.js",
    },
    module: {
        rules: [{ 
            test: /\.js$/, 
            exclude: /node_modules/, 
            loader: "babel-loader"
        }]
    },
    devtool: 'source-map'    
}