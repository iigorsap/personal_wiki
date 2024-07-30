const numbers = [1, 2, 3, 4, 5, 10, 21, 78];

// Map
const numbersTimesTwo = numbers.map(function(number) {
    return number * 2;
});

console.log(numbersTimesTwo);

// Filter
const evenNumbers = numbers.filter(function(number) {
    return number % 2 == 0;
});

console.log(evenNumbers);

// Reduce
const sumNumbers = numbers.reduce(function(number, accumulator) {
    return accumulator + number;
}, 0); // initial value of accumulator : 0

console.log(sumNumbers);