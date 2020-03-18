import React from 'react';

function ImgInfoTile(props){

    return(
        <div>
            <img src={props.imgSrc} alt="sdad"></img>
            <h3>{props.imgHeader}</h3>
            <p>{props.imgDescr}</p>
        </div>
    );

}


export default ImgInfoTile;