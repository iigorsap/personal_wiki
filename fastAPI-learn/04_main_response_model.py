from fastapi import FastAPI, Response
from fastapi.responses import JSONResponse, RedirectResponse
from pydantic import BaseModel, EmailStr
from typing import Any
app = FastAPI()

class Item(BaseModel):
    name: str
    description: str | None = None
    price: float
    tax: float | None = None
    tags: list[str] = []

@app.post("/items/")
async def create_item(item: Item) -> Item:
    return item

@app.get("/items/") 
async def read_items() -> list[Item]:
    return [
        Item(name="Portal Gun", price=42.0),
        Item(name="Plumbus", price=32.0),
    ]


"""response_model 
Há alguns casos em que você precisa ou deseja retornar alguns dados que não são 
exatamente os declarados pelo tipo. Por exemplo, você pode querer retornar 
um dicionário ou um objeto de banco de dados, mas declará-lo como um modelo Pydantic. 

Dessa forma, o modelo Pydantic faria toda a documentação de dados, validação etc. 
para o objeto que você retornou (por exemplo, um dicionário ou objeto de banco de dados).

Se você adicionasse a anotação de tipo de retorno, as ferramentas e os editores 
reclamariam com um erro (correto) informando que sua função está retornando 
um tipo (por exemplo, um dict) diferente do que você declarou (por exemplo, um modelo Pydantic).

Nesses casos, você pode usar path operation decorator parameter response_model em vez do tipo de retorno.

Você pode usar o parâmetro response_model em qualquer uma das operações de caminho:

@app.get()
@app.post()
@app.put()
@app.delete()
etc.

"""

@app.post("/items/", response_model=Item)
async def create_item(item: Item) -> Any:
    return item

@app.get("/items/", response_model=list[Item]) 
async def read_items() -> Any:
    return [
        Item(name="Portal Gun", price=42.0),
        Item(name="Plumbus", price=32.0),
    ]


class UserIn(BaseModel):
    username: str
    password: str
    email: EmailStr
    full_name: str | None = None

class UserOut(BaseModel):
    username: str
    email: EmailStr
    full_name: str | None = None

# Don't do this in production!
@app.post("/user/")
async def create_user(user: UserIn) -> UserIn:
    return user

"""
We can instead create an input model with the 
plaintext password and an output model without it:
""" 
@app.get("/user/", response_model=UserOut) 
async def create_user(user: UserIn) -> Any:
    return user

"""
tivemos que usar o parâmetro response_model. Mas isso também significa que não 
temos o suporte do editor e das ferramentas para verificar o tipo de retorno da função.

Mas, na maioria dos casos em que precisamos fazer algo assim, queremos que 
o modelo apenas filtrar/remover alguns dos dados, como neste exemplo.
"""

class BaseUser(BaseModel):
    username: str
    email: EmailStr
    full_name: str | None = None

class UserIn(BaseUser):
    password: str

@app.post("/user/")
async def create_user(user: UserIn) -> BaseUser:
    return user

"""
Como no exemplo anterior é possivel declarar o retorno da função como um objeto
Response e retornar uma classe que herda de Response, como RedirectResponse e 
JSONResponse, essa anotação de tipo é valida.
"""
@app.get("/portal")
async def get_portal(teleport: bool = False) -> Response:
    if teleport:
        return RedirectResponse(url="https://www.youtube.com/watch?v=dQw4w9WgXcQ")
    return JSONResponse(content={"message": "Here's your interdimensional portal."})

