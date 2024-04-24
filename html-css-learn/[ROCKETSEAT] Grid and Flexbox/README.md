# CSS GRID

## GRID
- Bimensional
- Divisão de toda a página em linhas e colunas
- Colocar elementos onde quiser nessa divisão

# GRID OU FLEXBOX
- Grid: Duas dimensões (colunas e linhas)
- Flexbox: Uma dimensão (ou coluna ou linha)
- Um complementa o trabalho do outro
- Verificar quais navegadores ainda não estão aceitando o Grid

## PROPRIEDADES
- Vamos separar em 2 grupos: container e item(s)

# CONTAINER
- display: grid; `Iniciar o grid, vai dizer para o conteiner que ele é um grid`
- grid-template-columns; `Vai dizer pro grid quantas colunas ele possui`
- grid-template-rows; `Vai dizer pro grid quantas linhas ele possui`
- grid-gap `Vai dizer o espaçamento entre as linhas e colunas`
    - grid-row-gap `Espaçamento entre as linhas`
    - grid-column-gap `Espaçamento entre as Colunas`
- grid-template-areas; `Demilitar áreas`
... e mais 4 propriedades e alinhamento!

# ITEM(s)
- grid-column `Onde vai ficar o item na coluna do grid`
    - grid-column-start `Começo da coluna`
    - grid-column-end `Final da coluna`
- grid-row `Onde vai ficar o item na linha do grid`
    - grid-row-start `Começo da linha`
    - grid-row-end `Final da linha`
- grid-area `Onde ficaria na area, mas somente se usa o template-areas`
... e mais 2 propriedades de alinhamento!

## Grid: Alinhamento

Existem 6 propriedades para alinhamento:
- justify-content
- align-content
- justify-items
- align-items
- justify-self
- align-self

Vamos separá-los em 2 grupos
- justify e align
- content, items e self

## Justify e Align

Sabendo que o grid é bidimensional, nós temos o eixo x e o y.

O eixo x é o posicionamento horizontal, da esquerda para a direita.

O eixo y é o posicionamento vertical, de cima para baixo

Justify trabalhará o eixo x.

Align trabalhará o eixo y.

## Content, Items e Self

Juntando o justify, ou align, com esses elementos: content, items e self; nós observamos nossas propriedades

### Content

- justify-content(colunas) e align-content(linhas) nos permite alinhar o próprio grid, relativo ao espaço fora do grid.

O uso dessas propriedades são raras, pois só é aplicado caso o grid seja menor que a area definida. (Por exemplo, quando usamos em px o tamanho do grid, poderemos terminar com um grid pequeno, para o tamanho da area do grid)

Podemos usar 7 valores:
- start: `Conteiner coloca o conteudo no começo`
- end: `Conteiner coloca o conteudo no final`
- center: `Conteiner coloca o conteudo no centro`
- stretch: `Default se for flex, quando não tem espaço para se mover`
- space-between: `Espaço igual entre as colunas`
- space-around: `Espaço around coloca um espaço ao redor das colunas`
- space-evenly: `Espaço continuo, mesmo espaço fora e dentro`

### Items

justify-items e align-items vai permitir alinhar os items do nosso grid, em qualquer espaço disponível, na célula que ele habitar.

Podemos usar 4 valores:

- start `Alinha o item no espaço da celula, no começo`
- end `Alinha o item no espaço da celula, no final`
- center `Alinha o item no espaço da celula, no centro`
- stretch `Padrão`

### Self

justify-self e align-self vai nos permitir alinhar o item em si.

Faz a mesma coisa que o justify-items e align-items, porém, aplicado diretamente no item de um grid s