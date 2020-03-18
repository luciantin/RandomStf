import React from 'react';

function TodoList(){

    let listStyle ={
        color:'#5500ff',
        fontSize:'12vh',
        backgroundColor:'green'
    };

    let listHTML = (
        <div style={listStyle}>
            <label name='Txt1'>tst</label>
            <input type='text' name='Txt1'></input><br></br>
        </div>
    );

    return listHTML;
    
}

export default TodoList;