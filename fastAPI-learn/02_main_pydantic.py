from fastapi import FastAPI, Query, Path
from pydantic import BaseModel, Field
from typing import Annotated


class Item(BaseModel):
    """Pydantic model"""
    name: str
    description: str | None = None
    price: float
    tax: float | None = None

class User(BaseModel):
    """Pydantic model"""
    username: str
    full_name: str | None = None

"""
{
    "name": "Foo",
    "description": "Uma descrição opcional",
    "price": 45.2,
    "tax": 3.5
}
Como description e tax são opcionais (Com um valor padrão de None), 
esse JSON "object" também é válido:
{
    "name": "Foo",
    "price": 45.2
}
"""

app = FastAPI()

@app.post("/items/")
async def create_item(item: Item):
    item_dict = item.dict()
    if item.tax:
        price_width_tax: float = item.price + item.tax
        item_dict.update({"price_width_tax": price_width_tax})
    return item_dict

"""
Request body + path
Declarar path e Request body ao mesmo tempo.

O FastAPI irá reconhecer que os parâmetros da função que combinam com parâmetros 
de rota devem ser retirados da rota, e parâmetros da função que são declarados 
como modelos Pydantic sejam retirados do corpo da requisição.
"""
@app.put("/items/{item_id}")
async def update_item(item_id: int, item: Item):
    return {"item_id": item_id, **item.dict()}

"""
Request body + path + parâmetros de query

Se o parâmetro também é declarado na rota, será utilizado como um parâmetro de rota.

Se o parâmetro é de um tipo único (como int, float, str, bool, etc) será 
interpretado como um parâmetro de query.

Se o parâmetro é declarado como um modelo Pydantic, será interpretado como 
o corpo da requisição.
"""
@app.put("/items/{item_id}")
async def update_item(item_id: int, item: Item, q: str | None = None):
    result = {"item_id": item_id, **item.dict()}
    if q:
        result.update({"q": q})
    return result


# New app.get items with additional error validation 
@app.get("/items/")
async def read_items(q: Annotated[str | None, Query(max_length=50)] = None):
    """
    Annotated[str | None, Query(max_length=50)] : Isso garante o tipo e faz validação
    Porém para dizer que o parametro é opcional precisamos colocar = None
     
    Caso queira explicitar que é necessario declarar o valor do item ao invés de None
    é convencional utilizar = ..., isso é chamado de Ellipsis, o pydantic irá 
    saber que o paramentro é obrigatorio
     
    Old version: q: str | None = Query(default=None, max_length=50)
    """ 
    results = {"items": [{"item_id": "Foo"}, {"item_id": "Bar"}]}
    if q:
        results.update({"q": q})
    return results

# Exemplo mais completo do uso de Annotated - Query para Query Parameters
# @app.get("/items/")
# async def read_items(
#     q: Annotated[
#         str | None,
#         Query(
#             alias="item-query",
#             title="Query string",
#             description="Query string for the items to search in the database that have a good match",
#             min_length=3,
#             max_length=50,
#             pattern="^fixedquery$",
#             deprecated=True,
#         ),
#     ] = None,
# ):
#     results = {"items": [{"item_id": "Foo"}, {"item_id": "Bar"}]}
#     if q:
#         results.update({"q": q})
#     return results


# Metadados sobre parametros de rota

"""
Um parâmetro de rota é sempre obrigatório, como se fizesse parte da rota.
Então, é preciso declará-lo com ... para marcá-lo como obrigatório.
Mesmo que declare-o como None ou defina um valor padrão, isso não teria 
efeito algum, o parâmetro ainda seria obrigatório.

A ordem dos parametros de uma função do endpoint não importa, FastAPI, irá detectar 
e validar pelo tipo e definição padrão (Query, Path, etc)

Query, Path e outras classes são subclasses de uma classe comum Param.
Todas elas compartilham os mesmos parâmetros para validação adicional e metadados.
"""

# Validacoes Numericas

"""
gt: maior que (greater than)
ge: maior que ou igual (greater than or equal)
lt: menor que (less than) 
le: menor que ou igual (less than or equal)

@app.get("/items/{item_id}")
async def read_items(
    *,
    item_id: int = Path(title="The ID of the item to get", ge=0, le=1000),
    q: str,
    size: float = Query(gt=0, lt=10.5),
):
    results = {"item_id": item_id}
    if q:
        results.update({"q": q})
    return results
"""

"""results
{
    "name": "Foo",
    "description": "The pretender",
    "price": 42.0,
    "tax": 3.2
}
"""

# Multiples Params 
@app.put("/items/{item_id}")
async def update_item(item_id: int, item: Item, user: User):
    results = {"item_id": item_id, "item": item, "user": user}
    return results

"""results
{
    "item": {
        "name": "Foo",
        "description": "The pretender",
        "price": 42.0,
        "tax": 3.2
    },
    "user": {
        "username": "dave",
        "full_name": "Dave Grohl"
    }
}
"""

"""
É possivel dizer para o FastAPI com apenas 1 parametro que é preciso 
transformar aquele parametro como parte do body, usando Body ou apenas 1 valor
utilizando importance

@app.put("/items/{item_id}")
async def update_item(
    item_id: int, item: Item = Body(embed=True), importante: int = Body()
):
    results = {"item_id": item_id, "item": item}
    return results

results
{
    "item": {
        "name": "Foo",
        "description": "The pretender",
        "price": 42.0,
        "tax": 3.2
    },
    "user": {
        "username": "dave",
        "full_name": "Dave Grohl"
    },
    "importance": 5
}

"""

# Usando Field do pydantic ao invés de Query, Path, Body, etc do FastAPI para declarar os modelos.

"""
O Field funciona da mesma forma que o Query, Path e Body, tem todos os 
mesmos parâmetros, etc. 

class Item(BaseModel):
    name: str
    description: str | None = Field(
        default=None, title="The description of the item", max_length=300
    )
    price: float = Field(gt=0, description="The price must be greater than zero")
    tax: float | None = None


@app.put("/items/{item_id}")
async def update_item(item_id: int, item: Annotated[Item, Body(embed=True)]):
    results = {"item_id": item_id, "item": item}
    return results

"""
