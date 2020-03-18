import React from 'react';

function ProductTile(prop){
    return(
        <div>
            <h3>{prop.data.name}</h3>
            <p style={{display:'inline'}}>{prop.data.price}</p>
            <h5 style={{color:'#00f'}}>{prop.data.name}</h5>
        </div>
    );
}

export default ProductTile;