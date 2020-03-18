import React from 'react';

function JokeTile(props){
    return(
        <div>
            <h3 style={{display: props.content.joke ? "block" : "none"}}>{props.content.joke}</h3>
            <h2 style={{color: !props.content.joke && "#00f"}}>{props.content.answer}</h2>
        </div>
    );
}

export default JokeTile;