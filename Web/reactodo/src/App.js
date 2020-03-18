import React from 'react';
import TodoListTile from './components/TodoListTile'
import TodoData from './components/TodoData'

// function App() {

  
// }



class App extends React.Component{

  constructor(){
    super();
    this.state = {
      answer:'Yes',
      question:'Q ???',
      split:'--------------',
    }
  }

  render(){
    let  TodoDataHtml = TodoData.map(
      (x) => {return <TodoListTile data={x} />}
    );
    
    return (
      <div className="App">
        <Header username={"test"}/>
        <Greeting/>
        {TodoDataHtml}
        <p>{this.state.question}</p>
        <p>{this.state.split}</p>
        <p>{this.state.answer}</p>
      </div>
    );
  }

}



class Greeting extends React.Component{
  render(){
    return (
      <header>
        <p>Good Morning!</p>
      </header>
    );
  }
}


class Header extends React.Component{
  render(){
    return (
      <header>
        <p>Welcome, {this.props.username}!</p>
      </header>
    );
  }
}











export default App;