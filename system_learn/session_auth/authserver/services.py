from app.redis.redis_client import redis_client
from app.user.schemas import UserBase
from app.auth.authserver.schemas import AuthorizeRequest
from app.auth.authserver.config import auth_settings
from datetime import datetime, timezone, timedelta

import secrets
import json
import base64
import hashlib
import jwt
from uuid import UUID

class AuthCodeService:
    @staticmethod
    def generate_code_challenge(code_verifier: str) -> str:
        code_verifier = hashlib.sha256(code_verifier.encode('ascii')).digest()
        return base64.urlsafe_b64encode(code_verifier).decode('ascii').rstrip('=')

    @staticmethod
    def generate_authorization_code(body: AuthorizeRequest, user_id: str):
        code = secrets.token_urlsafe(32)
        expiration = datetime.now(timezone.utc) + timedelta(minutes=auth_settings.auth_code_expires_minutes)

        redis_key = f"auth_code:{code}"

        redis_value = {
            "user_id": user_id,
            "client_id": body.client_id,
            "redirect_uri": str(body.redirect_uri),
            "state": body.state,
            "scopes": body.scopes,
            "code_challenge": body.code_challenge,
            "code_challenge_method": body.code_challenge_method,
            "expires_at": expiration.isoformat(),
        }

        redis_client.setex(
            name=redis_key,
            time=auth_settings.auth_code_expires_minutes * 60,
            value=json.dumps(redis_value)
        )

        return code