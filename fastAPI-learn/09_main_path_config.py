from fastapi import FastAPI, status
from fastapi.encoders import jsonable_encoder
from pydantic import BaseModel
from enum import Enum

app = FastAPI(docs_url="/")


class Tags(Enum):
    items = "items"
    users = "users"


class Item(BaseModel):
    name: str
    description: str | None = None
    price: float
    tax: float | None = None
    tags: list[str] = []

items = {
    "foo": {"name": "Foo", "price": 50.2},
    "bar": {"name": "Bar", "description": "The bartenders", "price": 62, "tax": 20.2},
    "baz": {"name": "Baz", "description": None, "price": 50.2, "tax": 10.5, "tags": []},
}


# É possível passar uma tag para subdividir as seções de caminho para OpenAPI
# Caso use a descrição ela sobrescreve a docstring
@app.post(
    "/items/",
    response_model=Item,
    status_code=status.HTTP_201_CREATED,
    tags=[Tags.items],
    summary="Create an item",
    response_description="The created item",
    # description="Create an item with all the information, name, description, price, tax and a set of unique tags",
)
async def create_item(item: Item):
    """
    Create an item with all the information:
    - **name**: each item must have a name
    - **description**: a long description
    - **price**: required
    - **tax**: if the item doesn't have tax, you can omit this
    - **tags**: a set of unique tag strings for this item
    """
    return item


@app.get("/items/", tags=[Tags.items])
async def get_items():
    return ["Portal gun", "Plumbus"]


# Vamos imaginar que você tenha um banco de dados fake_db que recebe apenas dados compatíveis com JSON.
# Por exemplo, ele não recebe objetos datetime, pois estes objetos não são compatíveis com JSON.
# Então, um objeto datetime teria que ser convertido em um str contendo os dados no formato ISO.
# Da mesma forma, este banco de dados não receberia um modelo Pydantic (um objeto com atributos), apenas um dict.
# Você pode usar a função jsonable_encoder para resolver isso.
# A função recebe um objeto, como um modelo Pydantic e retorna uma versão compatível com JSON:

# PUT é usado para receber dados que podem substituir um dado existente.
@app.put("/items/{item_id}", response_model=Item, tags=[Tags.items])
async def update_item(item_id: str, item: Item):
    update_item_encoded = jsonable_encoder(item)
    items[item_id] = update_item_encoded
    return update_item_encoded

@app.patch("/items/{item_id}", response_model=Item, tags=[Tags.items])
async def update_item(item_id: str, item: Item):
    stored_item_data = items[item_id]
    stored_item_model = Item(**stored_item_data)
    update_data = item.model_dump(exclude_unset=True)
    updated_item = stored_item_model.model_copy(update=update_data)
    items[item_id] = jsonable_encoder(updated_item)
    return updated_item

@app.get("/users/", tags=[Tags.users])
async def read_users():
    return ["Rick", "Morty"]

# Se quiser remover uma rota sem excluir basta deprecá-la
@app.get("/elements/", tags=["items"], deprecated=True)
async def read_elements():
    return [{"item_id": "Foo"}]


