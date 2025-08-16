import json
from urllib.parse import urlparse
from fastapi import Depends, APIRouter, Response, Request

from fastapi.responses import JSONResponse
from urllib.parse import urlencode

from datetime import datetime, timezone, timedelta
from sqlalchemy.ext.asyncio  import AsyncSession
from app.db.dependencies import get_db

from app.user.dependencies import user_authentication, user_authenticated_by_token, get_current_user_with_token, get_current_authenticated_user_by_access_token

from app.auth.session.schemas import LoginRequest
from app.auth.session.services import SessionService
from app.auth.session.config import session_settings

from app.redis import redis_client
from app.auth.authserver.schemas import AuthorizeRequest
from app.auth.session.dependencies import get_session

router = APIRouter(prefix="/auth", tags=["auth"])

@router.post("/token_session")
async def login_for_token_session(request: Request, db: AsyncSession = Depends(get_db)):
    data = await request.json()
    user = await user_authentication(username=data.get('username'), password=data.get('password'), db=db)
    
    data.pop('password', None)
    data.pop('username', None)

    session_token = SessionService.generate_session_token(
        data={
            "sub": user.id,
            "iat": int(datetime.now(timezone.utc).timestamp()),
            "roles": "admin",
            "permissions": f"{user.id}",
            "admin": True,
            "exp": int((datetime.now(tz=timezone.utc) + timedelta(minutes=3)).timestamp()),
        }, 
        expires_at=datetime.now(tz=timezone.utc) + timedelta(minutes=3),
        secret_key=session_settings.session_secret_key, 
        algorithm=session_settings.algorithm,
    )

    query_string = urlencode(data)
    redirect_url = f"/auth/authorize?{query_string}"

    res = JSONResponse({"redirect_url": redirect_url})

    res.set_cookie(
        key="session",
        value=session_token,
        httponly=True,
        secure=True,
        samesite="Lax",
        max_age=session_settings.session_token_expires_minutes*60
    )
    return res
