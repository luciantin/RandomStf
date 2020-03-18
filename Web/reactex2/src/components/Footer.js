import React from 'react';

function Footer() {

    let tst = new Date();

    return(<div>
       
    <p className="footer">Footer 
    
        {`${tst.getSeconds()}`}
         
        {tst.getMilliseconds()} 

    </p>
      </div>);
}

export default Footer;
