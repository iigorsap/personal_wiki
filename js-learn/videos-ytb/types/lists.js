// List

const names = ["Igor", "Amanda", "Cruzeiro"];

const amanda = names[1]; // Acessando index
console.log(amanda);

names.push("Mel"); // Adicionando elementos no final da lista
names.unshift("Pequeno"); // Adicionando elementos no começo da lista
console.log(names);

names.pop(); // removendo elemento da lista
console.log(names);
console.log(names.indexOf("Pequeno")); // Verificando o index de uma string dentro da lista

const sortedNames = names.sort(); // Ordenando a lista
console.log(sortedNames); 

const names_add = ["Cruzeiro", "Maior"];
names.push(names_add);
console.log(Array.isArray(names[names.length - 1]));