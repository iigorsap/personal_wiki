## Formulario

TAGS

<form action="" method="" target="_blank"> /*tag que cria o formulario*/
    <input type="" > /*entrada de dados*/ /*type =  tipo do formulario*/
    <input type="text" name=""> /* tipo texto
    <input type="submit" value="ok"> /* submit = tipo para enviar algo*/ (botao) /* value = O que escrever no botao como chamada
</form>
----------- target="_blank" ---

- Abrir em outra aba.

----------- name=""   ---------

Diferência o que o formulario representa. 
- NO BACKEND TEM QUE SER O MESMO NOME!!!!!!!!!!!!

<input type="text" name="Email">
<input type="text" name="Senha">

----------- action="" ---------

- Pagina na qual vao ser enviados os dados.

----------- method="" ---------
## METODO GAT E METODO POST

# Metodo gat, poucos dados, nao tem problema de seguracao, nao passa nenhum dado sensivel, como usuario e senha.
- Exemplo: Pesquisa no Google

# Metodo Post, Dados importantes, precisa ter sigilo, não pode deixar aberto pra ninguem ver.
- Exemplo: Usuário e senha.

## SEMANTICA DO FORMULARIO

<form action="" method="" target="_blank"> 
    <label for="txtbusca">Escreva seu nome <label> /* Tag que inseri semântica no formulario. 
    - for identifica qual input ele vai esta ligado.
    <input type="" > 
    <input type="text" name="" id=""> 
    <input type="submit" value="ok"> 
</form>

## FIELDSET

<fieldset> /* Cria grupos logicos, Forma de pagamento, Usario e senha.
    <legend>Login</legend> /* Legenda do grupo logico
</fieldset>