import React from 'react';
import TodoListTile from './components/TodoListTile'
import TodoData from './data/TodoData'
import ButtonTile from './components/ButtonTile'
import ClickerTile from './components/ClickerTile'

class App extends React.Component {

  constructor(){
    super();
    this.state = {
      isLoggedIn : true,
      todos : TodoData,
    }
  }

  render(){

  let  TodoDataHtml = this.state.todos.map(
    (x) => {return <TodoListTile data={x} />}
  );

  let wordDisplay = this.state.isLoggedIn ? "in" : "out";

  return (
    <div className="App">
      <ClickerTile/>
      {/* <ButtonTile /> */}
      {/* <h3>You are currently logged {wordDisplay}</h3> */}
      {/* {TodoDataHtml} */}
    </div>
  );
}
}

export default App;
