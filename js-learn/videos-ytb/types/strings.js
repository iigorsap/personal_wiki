// Strings

const message_string = "Hello world"; // Declarando uma string
console.log(message_string.length); // verificando o tamanho

const message_pt2 = "das americas";
console.log(message_pt2 + ' ' + message_string); // Concatenando strings
console.log(`meu nome é ${message_string.toUpperCase()} ${message_pt2.toLowerCase()}`); // Lower and Upper Case

const names = "Igor, Amanda, Bia";
console.log(names.split(",")); // Split string