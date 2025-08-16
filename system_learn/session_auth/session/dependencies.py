from fastapi import Request, HTTPException, Depends, status
from app.auth.session.services import SessionService
from app.auth.session.config import session_settings

def get_session(
    request: Request
):
    print(request.cookies.get('session'))
    try:
        username = SessionService.get_user_from_session_cookie(
            request=request,
            secret_key=session_settings.session_secret_key,
            algorithm=[session_settings.algorithm],
        )
        print(username)
        return username
    except Exception as e:
        raise HTTPException(status_code=status.HTTP_401_UNAUTHORIZED, detail=str(e))
        
