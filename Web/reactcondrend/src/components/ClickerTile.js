import React from 'react';

class ClickerTile extends React.Component {

    constructor(){
        super();
        this.state = {
            counter : 0,
        }

        this.ClickHandler = this.ClickHandler.bind(this);
    }

    ClickHandler(type){
        this.setState((prevState) =>{
            return { counter : prevState.counter + 1,}
        });
    }

    render(){
        return (
            <div>
                <h3>{this.state.counter}</h3>
                <button onClick={this.ClickHandler}>Incr</button>
                <button onClick={this.ClickHandler}>Decr</button>
            </div>
        );
    }

}

export default ClickerTile;