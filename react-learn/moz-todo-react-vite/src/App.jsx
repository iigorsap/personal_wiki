import { useState } from 'react' // useState hook: Hooks are a way of using React's features insides a component.
import './App.css'

const subject = "React";
function App(props) {
    const [count, setCount] = useState(0);
    
    return ( // JSX expression, react have to return a single JSX element, for this use <></> tag fragment.
        <>
            <header>
                <h1>Hello, {props.subject}! {props.greeting}</h1>
                <h2>counts {2 + 2}</h2>
                <button type="button" className="primary">
                    Click me!
                </button>
            </header>
        </>
    );
}

export default App; // Turn function available to other modules.
