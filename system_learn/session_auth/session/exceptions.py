from fastapi import HTTPException, status

invalid_session_code = HTTPException(
    status_code=status.HTTP_400_BAD_REQUEST,
    detail="Invalid Session Token: The provided session token doesn't exists"
)

session_code_not_found = HTTPException(
    status_code=status. HTTP_404_NOT_FOUND,
    detail="Session Token Not Found"
)

expired_token_exception = HTTPException(
    status_code=status.HTTP_401_UNAUTHORIZED,
    detail="Expired Token",
    headers={"WWW-Authenticate": "Bearer"},
)

missing_sub_exception = HTTPException(
    status_code=status.HTTP_401_UNAUTHORIZED,
    detail="Invalid Token: 'sub' not found",
    headers={"WWW-Authenticate": "Bearer"},
)

jwt_error_exception = HTTPException(
    status_code=status.HTTP_401_UNAUTHORIZED,
    detail="Invalid Token",
    headers={"WWW-Authenticate": "Bearer"},
)