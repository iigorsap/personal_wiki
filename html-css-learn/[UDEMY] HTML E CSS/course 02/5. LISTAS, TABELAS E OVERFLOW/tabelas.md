## Principais tags

<table></table>
<tr></tr>
<td></td>

- tr (linha)
- td (coluna)

- Exemplos

1 linha e 1 coluna
<table>
    <tr>
        <td></td>
    </tr>
</table>

3 Linhas e 2 Colunas
<table>
    <tr>
        <td>1A</td> <td>1B</td>
    </tr>
    <tr>
        <td>2A</td> <td>2B</td>
    </tr>
    <tr>
        <td>3A</td> <td>3B</td>
    </tr>
</table>

## Colspan - Mesclagem de colunas
## rowspan - Mesclagem de Linhas

Exemplo - 1

<table>
    <tr>
       <td colspan="2">1A</td>
    </tr>
    <tr>
        <td>2A</td> <td>2B</td>
    </tr>
    <tr>
        <td>3A</td> <td>3B</td>
    </tr>
</table>

Exemplo - 2

<table>
    <tr>
        <td rowspan="2">1A</td> <td>1B</td>
    </tr>
    <tr>
        <td>2B</td>
    </tr>
    <tr>
        <td>3A</td> <td>3B</td>
    </tr>
</table>

Exemplo - 3

<table>
    <tr>
        <td>1A</td> 
        <td rowspan="2">1B</td>
    </tr>
    <tr>
        <td>2A</td>
    </tr>
    <tr>
        <td>3A</td> <td>3B</td>
    </tr>
</table>

## Semantica

- Table header (Cabecalho da tabela)

<th></th>
<thead></thead>

- Table footer 
**Rodape na sintaxe vem antes de body**

<tfoot></tfoot>

- Table body

<tbody></tbody>

## Border-collapse
- Separate (Default)
- Collapse

