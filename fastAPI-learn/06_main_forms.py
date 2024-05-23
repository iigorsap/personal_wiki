from fastapi import FastAPI, Form
from typing import Annotated

app = FastAPI()

"""Form is a class that inherits directly from Body."""


@app.post("/login/")
async def login(username: Annotated[str, Form()], password: Annotated[str, Form()]):
    return {"username": username}
