from pydantic import BaseModel, AnyHttpUrl, EmailStr
from fastapi import Request
from typing import Literal

class AuthorizeRequest(BaseModel):
    response_type: str
    client_id: str
    redirect_uri: AnyHttpUrl
    code_challenge: str
    code_challenge_method: Literal["S256"]
    scopes: str
    state: str

class LoginRequest(BaseModel):
    username: EmailStr
    password: str
    auth_params: AuthorizeRequest
