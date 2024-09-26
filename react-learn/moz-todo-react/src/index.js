import React from 'react';
import ReactDOM from 'react-dom/client';
import './index.css';
import App from './App';
import reportWebVitals from './reportWebVitals';

const root = ReactDOM.createRoot(document.getElementById('root')); // select root no HTML e cria raiz para arvore de componentes
root.render(
  // O React.StrictMode é uma ferramenta de desenvolvimento que ativa verificações adicionais e avisos para ajudar a identificar problemas em seu código.
  <React.StrictMode> 
    <App subject="Clarice"/>
  </React.StrictMode>
);

// If you want to start measuring performance in your app, pass a function
// to log results (for example: reportWebVitals(console.log))
// or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
reportWebVitals();
