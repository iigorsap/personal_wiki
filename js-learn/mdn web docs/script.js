// function: create a new paragraph and insert it at the end of HTML file.

function createParagraph() {
    let para = document.createElement("p");
    para.textContent = "Vc clicou no botao";
    document.body.appendChild(para);
}

/*
  1. Captura referências de todos os botões na página e armazena isso em um array.
  2. Vai até todos os botões e adiciona um event listener click a cada um deles.

  Quando cada botão é clicado, a função criarParagrafo() será executada.
*/

const buttons = document.querySelectorAll("button");

for (var i = 0; i < buttons.length; i++) {
    buttons[i].addEventListener("click", createParagraph);
}

// document.addEventListener("DOMContentLoaded", function() {
//     ...
// }); 

// Garante que o conteudo js seja carregado somente após o DOM esteja 100% carregado

// Uma solução à moda antiga para esse problema era colocar o elemento script bem no final do body da página (antes da tag </body>). 
// Com isso, os scripts iriam carregar logo após todo o conteúdo HTML Uma solução à moda antiga para esse 
// problema era colocar o elemento script bem no final do body da página (antes da tag </body>). Com isso, os scripts iriam carregar logo após todo o conteúdo HTML
// Em sites maiores poderia causar lentidão.

// async e defer

// async para multiplos scripts independentes em uma página.
// por exemplo:
{/* 
    <script async src="js/vendor/jquery.js"></script>

    <script async src="js/script2.js"></script>

    <script async src="js/script3.js"></script> 

    Você não pode garantir que o script. jquery.js carregará antes ou depois do script2.js e script3.js 
    async deve ser usado quando houver muitos scripts rodando no background, e você precisa que estejam disponíveis o mais rápido possível. 
    
    - Se os seus scripts precisam rodar imediatamente, sem que dependam de outros para serem executados, use async.

*/}

// defer
{/*
    <script defer src="js/vendor/jquery.js"></script>

    <script defer src="js/script2.js"></script>

    <script defer src="js/script3.js"></script> 
    Todos os scripts com o atributo defer irão carregar na ordem que aparecem na página. 
    No segundo exemplo, podemos ter a certeza que o script jquery.js irá carregar antes 
    do script2.js e script3.js e o script2.js irá carregar antes do script3.js. 
    Os scripts não irão rodar sem que antes todo o conteúdo da página seja carregado

    - Se seus scripts dependem de outros scripts ou do DOM completamente disponível em tela, carregue-os usando defer e 
    coloque os elementos <script> na ordem exata que deseja que sejam carregados.
*/}

// async e defer istruem o browser a baixar os scripts numa thread (processo) à parte, 
// enquanto o resto da página (o DOM, etc.) está sendo baixado e disponibilizado de forma 
// não bloqueante.


