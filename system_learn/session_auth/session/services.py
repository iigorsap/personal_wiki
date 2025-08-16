from fastapi import Request
from app.auth.session.exceptions import (
    session_code_not_found,
    missing_sub_exception,
    expired_token_exception,
    jwt_error_exception
)
from app.auth.session.config import session_settings
from datetime import datetime, timezone, timedelta
import jwt
from jwt.exceptions import PyJWTError, ExpiredSignatureError

class SessionService:
    @staticmethod
    def generate_session_token(data: dict, expires_at: str, secret_key: str, algorithm: list) -> str:
        to_encode = data.copy()
        to_encode.update({"exp": int(expires_at.timestamp())})
        encoded_jwt = jwt.encode(payload=to_encode, key=secret_key, algorithm=algorithm)
        return encoded_jwt

    @staticmethod
    def get_user_from_session_cookie(request: Request, secret_key: str, algorithm: list):
        token = request.cookies.get("session")
        print("token", token)
        
        if not token:
            raise session_code_not_found

        try:
            payload = jwt.decode(token, key=secret_key, algorithms=algorithm, options={"verify_exp": True})
            
            if "sub" not in payload:
                raise missing_sub_exception
            username = payload.get('sub')

        except ExpiredSignatureError:
            raise expired_token_exception
        except PyJWTError:
            raise jwt_error_exception
        
        return username

