import React from 'react';
import ReactDOM from 'react-dom';
import App from './App';

function Render(){
    ReactDOM.render(<App />, document.getElementById('root'));
}

Render();

// setInterval(Render,1);
