import React from 'react';
import Header from './components/Header'
import NavBar from './components/NavBar'
import MainContent from './components/MainContent'
import Footer from './components/Footer'
import JokesData from './other/JokesData'
import JokeTile from './components/JokeTile';
import ProductsData from './other/ProductsData'
import ProductTile from './components/ProductTile'

function App() {

  const tmp = JokesData.filter(
    (a) => {
      if(a.id > 3) return true;
      else return false;
    }
  );

  const JokeComponents = tmp.map(
    (joke) => { 
      return <JokeTile data={{
        id:joke.id,
        joke:joke.joke,
        answer:joke.answer
      }} />}
  );

  let prodHtml = ProductsData.map(
    (x) => {
      return (<ProductTile data={x}/>);
    }
  );


  return (
    <div>
      {prodHtml}
      {/* {JokeComponents} */}
      {/* <Header/> */}
      {/* <NavBar/> */}
      {/* <MainContent/> */}
      {/* <Footer/> */}
    </div>
  );
}

export default App;
