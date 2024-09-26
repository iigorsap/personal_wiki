import React from 'react' // listed as dependencies in our package.json
import ReactDOM from 'react-dom/client' // listed as dependencies in our package.json
import App from './App.jsx'
import './index.css' // holds global styles 

ReactDOM.createRoot(document.getElementById('root')).render(
  <React.StrictMode>
    <App subject="Santiago" greeting="Awesome"/>
  </React.StrictMode>,
)
