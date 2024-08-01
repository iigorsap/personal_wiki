import { useState } from "react";


function Form (props) {
    const [name, setName] = useState(""); {/*
        useState() returns an array containing two items. 
        The first item is the current value of the state; 
        the second item is a function that can be used to update the state. 

        We are defining a name constant with the value "" empty.
        We are defining a function whose job it is to modify name, called setName().
        useState() returns these two things in an array, so we are using array destructuring to capture them both in separate variables.

    */}

    function handleChange(event) {
        setName(event.target.value);
    }

    function handleSubmit(event) {
        event.preventDefault();
        props.addTask(name);
        setName(""); // clear the input after submit
    }

    return (
        <form onSubmit={handleSubmit}>
            <h2 className="label-wrapper">
                <label htmlFor="new-todo-input" className="label__lg">
                    What needs to be done?
                </label>
            </h2>
            <input
                type="text"
                id="new-todo-input"
                className="input input__lg"
                name="text"
                autoComplete="off"
                value={name}
                onChange={handleChange}
            />
            <button type="submit" className="btn btn__primary btn__lg">
                Add
            </button>
        </form>
    );
}

export default Form;