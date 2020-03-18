import React from 'react';
import TodoList from './TodoList';
import ImgInfoTile from './ImgInfoTile'
import JokeTile from './JokeTile'


function MainContent() {
    return(
    <div>

        <JokeTile content={{joke:"Test1",answer:"Test2"}}/>
        <JokeTile content={{joke:"Test1",answer:"Test2"}}/>
        <JokeTile content={{answer:"Test567567"}}/>

        <ImgInfoTile
            imgSrc="http://www.placekitten.com/g/200/300"
            imgHeader="Test1"
            imgDescr=" LAMBDA "
        />
        <ImgInfoTile
            imgSrc="http://www.placekitten.com/g/200/300"
            imgHeader="Test1"
            imgDescr=" LAMBDA "
        />
        <ImgInfoTile
            imgSrc="http://www.placekitten.com/g/200/300"
            imgHeader="Test1"
            imgDescr=" LAMBDA "
        />

        <TodoList/>
        <TodoList/>
       <p style={{color:'#f0f',backgroundColor:'#00f'}}>adsdas</p>
      </div>);
}

export default MainContent;
