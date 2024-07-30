// Json : usado para enviar dados do backend para o frontend

const todos = [
    {
        id: 1,
        description: "task 1",
        isCompleted: false,
    },
    {
        id: 2,
        description: "task 2",
        isCompleted: false,
    },
    {
        id: 2,
        description: "task 3",
        isCompleted: false,
    },
];

const todosJSON = JSON.stringify(todos);
const todoList = JSON.parse(todosJSON);

console.log(todoList);
console.log(todosJSON);

// Loops for

cars = ["Ferrari", "Porsche", "Mercedes"];

for (let i = 0; i < cars.length; i++) {
    console.log(cars[i]);
}

for (let car of cars) {
    console.log(car);
}

function carFunc(car, index) { // podemos ter o index, similar ao enumarate no python
    console.log(index);
    console.log(car);
}

cars.forEach(carFunc);

index = 0;
while (index < 10) {
    index += 1;
}

// Para trabalhar com objeto
for (property in todos) { // não é muito perfomático
    console.log(todos[property]);
}

// conditions: javascript tem switch

car = 'mercedes'

switch (car) {
    case 'mercedes':
        console.log("top");
        break;
    default:
        console.log("ok");
        break;
}

// operador ternário
const sum = 1 + 2;
let number = sum === 2 ? 2 : 4;

// TRUE and FALSE

// string vazia, 0, null, undefined são FALSE
// list, object vazia são TRUE

// Functions and arrow functions

function sumFunction(a, b) {
    console.log(a + b);
}

const sumArrow = (a, b) => {
    return a + b;
};

const sumArrow2 = (a, b) => a + b;

console.log(sumFunction(2, 2));
console.log(sumArrow(2, 7));
console.log(sumArrow2(2, 7));

// Classes

class Person {
    constructor(firstName, lastName, age) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.age = age;
    }

    getFullName() {
        console.log(`${this.firstName} ${this.lastName}`);
    }

    // method static
    static speak() {
        console.log("Hello world");
    }
}

const person = new Person("Igor", "Santiago", 23);
console.log(person);
person.getFullName();

// inheritance

class Animal {
    constructor(name) {
        this.name = name;
    }

    speak() {
        console.log(`${this.name} made some noise!`);
    }
}

const bob = new Animal("Mel");
bob.speak();

class Dog extends Animal {
    constructor(name) {
        super(name);
    }

    speak() {
        console.log(`${this.name} barked!`);
    }
}

const dog = new Dog("Pequeno");
dog.speak();

// Working with DOM