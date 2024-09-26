// import React from "react";
import logo from './logo.svg';
import './App.css'; 

function App(props) { 
  // A função App retrona uma expressão JSX. Essa expressão define o que, no fim, o seu navegador irá renderizar para o DOM.
  const subject = props.subject;
  console.log(props);
  return (
    // BEGIN Expressão JSX
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <p> Hello, {subject}!</p>
      </header>
    </div>
    // END Expressão JSX (É preciso estar dentro de uma div externa, ou uma tag <></> chamada de <Fragment> (<>...</>), lets you group elements without a wrapper node.)
    
  );
}

export default App; // faz o App ser disponível para outros modulos
// App está sendo utilizado no index.js
