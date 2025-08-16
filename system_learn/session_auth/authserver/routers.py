from fastapi import APIRouter, Depends, HTTPException, Request
from fastapi.templating import Jinja2Templates
from fastapi.responses import RedirectResponse
from app.auth.authserver.schemas import AuthorizeRequest

from app.auth.authserver.services import AuthCodeService
from app.auth.session.config import session_settings
from app.auth.session.services import SessionService

from urllib.parse import urlencode

templates = Jinja2Templates(directory="app/templates/")

router = APIRouter(prefix='/auth', tags=['auth'])

@router.get('/authorize_session')
async def get_authorize_by_session(
    request: Request,
):
    print(request.query_params)
    
    try:
        body = AuthorizeRequest(**dict(request.query_params))
        print(body)
    except Exception as e:
        print(e)

    try:
        user = SessionService.get_user_from_session_cookie(request=request, secret_key=session_settings.session_secret_key, algorithm=[session_settings.algorithm])
        print("User autenticado via cookie: ", user)
        
        auth_code = AuthCodeService.generate_authorization_code(body=body)
        redirect_url = f"{body.redirect_uri}callback?code={auth_code}&state={body.state}"

        print("redirect_url", redirect_url)

        return RedirectResponse(
            url=redirect_url,
            status_code=302,
        )
    except HTTPException:
        print("Sem sessão: redirecionando para login")
        query_string = urlencode(body.dict(exclude_unset=True))
        return RedirectResponse(url=f"{body.redirect_uri}/login?{query_string}", status_code=302)

@router.post('/login-debug')
async def login_debug(request: Request):
    body = await request.body()
    headers = dict(request.headers)
    print("Body:", body.decode())
    print("Headers:", headers)
    return {"received": "ok"}