const person = {
    firstName: "Igor",
    lastName: "Santiago",
    age: 23,
    hobbies: ['Cruzeiro', 'Disc', 'Others']
};

// adding property to person
person.dog = {
    name: "little",
    age: 3,
};

console.log(person.dog.age);

// const firstName = person.firstName;
// const lastName = person.lastName;
// const age = person.age;
// const hobbies = person.hobbies;

// Destructing : mesma coisa de atribuir da forma anterior
const { 
    firstName: PrimeiroNome,
    lastName, 
    age, 
    hobbies, 
    dog: {name: dogName},
} = person;

console.log(PrimeiroNome);
console.log(lastName);
console.log(age);
console.log(hobbies);
console.log(dogName);
console.log(person.hobbies[2]);

// List of objects

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

const descriptionLastTodo = todos[2].description
console.log(descriptionLastTodo)