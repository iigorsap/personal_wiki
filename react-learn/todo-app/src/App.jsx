import { useState } from "react";
import { nanoid } from "nanoid";
import Todo from "./components/Todo";
import Form from "./components/Form";
import FilterButton from "./components/FilterButton";

const FILTER_MAP = {
    // The All filter shows all tasks, so we return true for all tasks.
    All: () => true,
    // The Active filter shows tasks whose completed prop is false.
    Active: (task) => !task.completed,
    // The Completed filter shows tasks whose completed prop is true.
    Completed: (task) => task.completed,
};

const FILTER_NAMES = Object.keys(FILTER_MAP);

function App(props) {
    const [tasks, setTasks] = useState(props.tasks);
    const [filter, setFilter] = useState("All");

    const filterList = FILTER_NAMES.map((name) => (
        <FilterButton 
            key={name} 
            name={name} 
            isPressed={name === filter}
            setFilter={setFilter}
        />
    ));

    function editTask(id, newName) {
        const editedTasks = tasks.map((task) => {
            if (id === task.id) {
                // copy the task and update its name
                return { ...task, name: newName };
            }
            return task;
        });
        setTasks(editedTasks);
    }

    function deleteTask(id) {
        const remainingTasks = tasks.filter((task) => id !== task.id);
        setTasks(remainingTasks);
    }

    function toggleTaskCompleted(id) {
        const updatedTasks = tasks.map((task) => { // we define an updatedTasks constant that maps over the original tasks array
            // if this task has the same ID as the edited task
            if (id === task.id) {
                // use object spread to make a new object
                // whose `completed` prop has been inverted
                return { ...task, completed: !task.completed };
            }
            return task; // If it doesn't match, we return the original object.
        });
        setTasks(updatedTasks); // new array in order to update our state.
    }
    
    const taskList = tasks
        .filter(FILTER_MAP[filter])
        .map((task) => (
            <Todo 
                id={task.id} 
                name={task.name} 
                completed={task.completed} 
                key={task.id}
                toggleTaskCompleted={toggleTaskCompleted}
                deleteTask={deleteTask}
                editTask={editTask}
            />
    ));

    const tasksNoun = taskList.length !== 1 ? "tasks" : "task";
    const headingText = `${taskList.length} ${tasksNoun} remaining`;

    {/* without useState
        const taskList = props.tasks?.map((task) => (
            <Todo 
                id={task.id} 
                name={task.name} 
                completed={task.completed} 
                key={task.id}
            />
        ));
    */}

    function addTask(name) {
        const newTask = { id: `todo-${nanoid()}`, name, completed: false };
        setTasks([...tasks, newTask]);
    }
    console.log(taskList);

    return (
        <div className="todoapp stack-large">
            <h1>TodoMatic</h1>
            <Form addTask={addTask} />

            {/* 1 version
            <form>
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
                />
                <button type="submit" className="btn btn__primary btn__lg">
                    Add
                </button>
            </form> */}
            <div className="filters btn-group stack-exception">
                {filterList}
                {/* 1 version
                <button
                    type="button"
                    className="btn toggle-btn"
                    aria-pressed="true">
                    <span className="visually-hidden">Show </span>
                    <span>all</span>
                    <span className="visually-hidden"> tasks</span>
                </button>
                <button
                    type="button"
                    className="btn toggle-btn"
                    aria-pressed="false">
                    <span className="visually-hidden">Show </span>
                    <span>Active</span>
                    <span className="visually-hidden"> tasks</span>
                </button>
                <button
                    type="button"
                    className="btn toggle-btn"
                    aria-pressed="false">
                    <span className="visually-hidden">Show </span>
                    <span>Completed</span>
                    <span className="visually-hidden"> tasks</span>
                </button> */}
            </div>
            <h2 id="list-heading">{headingText}</h2>
            <ul
                role="list"
                className="todo-list stack-large stack-exception"
                aria-labelledby="list-heading">
                {/* 3 version */}
                {taskList}

                {/* 2 version 
                <Todo name="Eat" id="todo-0" completed />
                <Todo name="Sleep" id="todo-1" />
                <Todo name="Repeat" id="todo-2" /> */}

                {/* 1 version

                <li className="todo stack-small">
					<div className="c-cb">
						<input id="todo-0" type="checkbox" defaultChecked={true} />
						<label className="todo-label" htmlFor="todo-0">
							Eat
						</label>
					</div>
					<div className="btn-group">
						<button type="button" className="btn">
							Edit <span className="visually-hidden">Eat</span>
						</button>
						<button type="button" className="btn btn__danger">
							Delete <span className="visually-hidden">Eat</span>
						</button>
					</div>
				</li>
				<li className="todo stack-small">
					<div className="c-cb">
						<input id="todo-1" type="checkbox" />
						<label className="todo-label" htmlFor="todo-1">
							Sleep
						</label>
					</div>
					<div className="btn-group">
						<button type="button" className="btn">
							Edit <span className="visually-hidden">Sleep</span>
						</button>
						<button type="button" className="btn btn__danger">
							Delete{" "}
							<span className="visually-hidden">Sleep</span>
						</button>
					</div>
				</li>
				<li className="todo stack-small">
					<div className="c-cb">
						<input id="todo-2" type="checkbox" />
						<label className="todo-label" htmlFor="todo-2">
							Repeat
						</label>
					</div>
					<div className="btn-group">
						<button type="button" className="btn">
							Edit <span className="visually-hidden">Repeat</span>
						</button>
						<button type="button" className="btn btn__danger">
							Delete{" "}
							<span className="visually-hidden">Repeat</span>
						</button>
					</div>
				</li> */}
            </ul>
        </div>
    );
}

export default App;
