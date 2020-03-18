import React from 'react'

class ButtonTile extends React.Component {

    constructor(){
        super();
        this.state = {
            name : "btuu1",
        }
    }

    render(){
        return (
                <div>
                    <img src="http://www.placekitten.com/300/200" alt="" onMouseOver={() => { console.log(' Ove Img '); }}></img>
                    <button onClick={() => { console.log(' RTest');}} >{this.state.name}</button>
                </div>
        )
    }

}

export default ButtonTile;