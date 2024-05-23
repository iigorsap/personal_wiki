from fastapi import FastAPI, Body, Cookie, Header
from pydantic import BaseModel, HttpUrl
from typing import Annotated, List, Set, Dict
from datetime import datetime, time, timedelta
import uuid

app = FastAPI()

class Image(BaseModel):
    url: HttpUrl
    name: str

class Item(BaseModel):
    name: str
    description: str | None = None
    price: float
    tax: float | None = None
    tags: Set[str] = set()
    image: List[Image] | None = None
    """
    Ao invés de usar List usar Set mesmo que você receba uma requisição 
    contendo dados duplicados, ela será convertida em um conjunto de itens exclusivos.
    """

class Offer(BaseModel):
    name: str
    description: str | None = None
    price: float
    items: List[Item]


@app.put("/items/{item_id}")
async def update_item(item_id: int, item: Item):
    results = {"item_id": item_id, "item": item}
    return results

@app.post("/offers/")
async def create_offer(offer: Offer):
    return offer

@app.post("/images/multiple/")
async def create_multiple_images(images: List[Image]):
    return images

@app.post("/index-weights/")
async def create_index_weights(weights: Dict[int, float]):
    return weights

"""Extra data types more complex than saw until now"""
@app.put("items/services/{item_id}")
async def read_items(
    item_id: uuid.UUID,
    start_datetime: Annotated[datetime, Body()],
    end_datetime: Annotated[datetime, Body()],
    process_after: Annotated[timedelta, Body()],
    repeat_at: Annotated[time | None, Body()] = None,
):
    start_process = start_datetime + process_after
    duration = end_datetime - start_process
    
    return {
        "item_id": item_id,
        "start_datetime": start_datetime,
        "end_datetime": end_datetime,
        "process_after": process_after,
        "repeat_at": repeat_at,
        "start_process": start_process,
        "duration": duration,
    }

@app.get("/items/services/")
async def read_items(
    ads_id: Annotated[str | None, Cookie()] = None,
    user_agent: Annotated[str | None, Header()] = None,
):
    return {"ads_id": ads_id, "user_agent": user_agent}
