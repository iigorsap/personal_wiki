"""Fornece todas as funcionalidades para constrir API""" 
from fastapi import FastAPI
from enum import Enum
"""
Cria uma instância do objeto FastAPI, 
não quer dizer que é um APP igual no Django
"""
app = FastAPI() 

"""
Define um endpoint. (ROTA URL)
Define a operação do método HTTP a ser utilizada como:
No OpenAPI, cada um dos métodos são chamados de operação.
- POST
- GET
- UPDATE
- DELETE

O decorator @app.get("/") diz que a função para tratar as requisiçoes
que vao para rota "/" usando o operador get;

Decorator: Informa ao FastAPI qual a função do método criado.
usamos também:
- app.put
- app.post
- app.delete

É livre para usar cada operação (método HTTP) como desejar.
O FastAPI não impõe nenhum significado específico.
"""

@app.get("/") 
async def root():
    return {"message": "I'm Igor"}

@app.get("/items/{item_id}") 
async def read_item(item_id):
    """Parâmetros da rota da URL¶"""
    return {"item_id": item_id}

@app.get("/items/{item_id}")
async def read_item(item_id: int):
    """Parâmetros da rota com tipos"""
    return {"item_id": item_id}

"""Valores pré definidos"""
class ModelName(str, Enum):
    """Valores constantes"""
    alexnet = "alexnet"
    resnet = "resnet"
    lenet = "lenet"

@app.get("/items/models/{model_name}")
async def get_model(model_name: ModelName): # tem que ser um daqueles
    if model_name is ModelName.alexnet:
        return {
            "model_name": model_name,
            "message": "Deep Learning FTW!"
        }

    if model_name is ModelName.lenet:
        return {
            "model_name": model_name,
            "message": "LeCNN all the images"
        }

    if model_name.value == "resnet":
        return {
            "model_name": model_name,
            "message": "Have some residuals"
        }

@app.get("/files/{file_path:path}")
async def read_file(file_path: str):
    """
        Parâmetros de rota que contém caminhos

        Você poderia precisar que o parâmetro contivesse /home/johndoe/myfile.txt, 
        com uma barra no inicio (/). Neste caso, a URL deveria ser: 
        /files//home/johndoe/myfile.txt, com barra dupla (//) entre files e home.
    """
    return {"file_path": file_path}

"""
Quando você declara outros parâmetros na função que não fazem parte dos parâmetros da rota, 
esses parâmetros são automaticamente interpretados como parâmetros de "query".
"""

fake_items_db = [{"item_name": "Foo"}, {"item_name": "Bar"}, {"item_name": "Baz"}]

@app.get("/items/")
async def read_item(skip: int = 0, limit: int = 10):
    return fake_items_db[skip : skip + limit]

"""
A query é o conjunto de pares chave-valor que vai depois de ? na URL, separado pelo caractere &.
Por exemplo:
    http://127.0.0.1:8000/items/?skip=0&limit=10
    skip: com o valor 0
    limit: com o valor 10
"""

"""
Parâmetros opcionais
"""
@app.get("/items/opcitem/{item_id}")
async def read_item(item_id: str, q: str | None = None):
    if q:
        return {"item_id": item_id, "q": q}
    return {"item_id": item_id}

"""Conversão dos tipos de parâmetros de query"""
@app.get("/items/convtype/{item_id}")
async def read_item(item_id: str, q: str | None = None, short: bool = False):
    item = {"item_id": item_id}
    if q:
        item.update({"q": q})
    if not short:
        item.update(
            {"description": "This is an amazing item that has a long description"}
        )
    return item

"""Parâmetros de querys obrigatórios
Quando quiser fazer com que o parâmetro de query seja obrigatório, pode 
simplesmente não declarar nenhum valor como padrão.
"""
@app.get("/items/needy/{item_id}")
async def read_user_item(item_id: str, needy: str):
    item = {"item_id": item_id, "needy": needy}
    return item

"""É possivel mesclar valores obrigatórios que recebem também valores None"""
@app.get("/items/needy/{item_id}")
async def read_user_item(
    item_id: str, needy: str, skip: int = 0, limit: int | None = None
):
    item = {"item_id": item_id, "needy": needy, "skip": skip, "limit": limit}
    return item
