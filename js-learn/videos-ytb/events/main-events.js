const submitButton = document.querySelector("#submit-button");
const nameInput = document.querySelector("#name");
const emailInput = document.querySelector("#email");

/*  Cada evento disponivel possui um manipulador de eventos (event handler), 
    que é um bloco de código (geralmente uma função JavaScript definida pelo usuário) 
    que será executado quando o evento for disparado. */

submitButton.addEventListener("click", function (event) {
    event.preventDefault();
    console.log(event);

    const nameValue = nameInput.value;
    console.log(nameValue);
    const emailValue = emailInput.value;
    console.log(emailValue);
});

// second part

var btn = document.querySelector("#change-color");

function random(number) {
    return Math.floor(Math.random() * (number + 1));
}

function bgChange() {
    var rndCol =
        "rgb(" + random(255) + "," + random(255) + "," + random(255) + ")";
    document.body.style.backgroundColor = rndCol;
}


/*  A propriedade onclick é a propriedade do manipulador de eventos que está 
    sendo usada nesta situação. É essencialmente uma propriedade como qualquer 
    outra disponível no botão (por exemplo, btn.textContent, ou btn.style)
*/

// btn.onclick = function () {
//     var rdnColor = "rgb(" + random(255) + "," + random(255) + "," + random(255) + ")";
//     document.body.style.backgroundColor = rdnColor;
// }

// Pode-se também definir a propriedade handler para ser igual a um nome de função nomeado
// Equivalente a anterior

// btn.onfocus = bgChange;
// btn.onblur = bgChange;
// <button onclick="bgChange()">Press me</button>

// Equivalente a anterior
// btn.addEventListener("click", function () {
//     var rdnColor = "rgb(" + random(255) + "," + random(255) + "," + random(255) + ")";
//     document.body.style.backgroundColor = rdnColor;
//     console.log(rdnColor);
// });

// btn.addEventListener("dblclick", function () {
//     var rdnColor = "rgb(" + random(255) + "," + random(255) + "," + random(255) + ")";
//     document.body.style.backgroundColor = rdnColor;
//     console.log(rdnColor);
// });

// btn.addEventListener("click", bgChange);

// btn.addEventListener("keydown", function (event) {
//     var rdnColor = "rgb(" + random(255) + "," + random(255) + "," + random(255) + ")";
//     if (event.key == "Control") {
//         document.body.style.backgroundColor = rdnColor;
//     }
//     console.log(rdnColor);
// }); // using control

/*  A propriedade target do objeto de evento é sempre uma referência ao elemento 
    em que o evento acabou de ocorrer. Portanto, neste exemplo, estamos definindo
    uma cor de fundo aleatória no botão, não na página. */
    
function bgChange(e) {
    var rndCol =
        "rgb(" + random(255) + "," + random(255) + "," + random(255) + ")";
    e.target.style.backgroundColor = rndCol;
    console.log(e);
}

btn.addEventListener("click", bgChange);