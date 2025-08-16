from fastapi import HTTPException, status

invalid_auth_code = HTTPException(
    status_code=status.HTTP_400_BAD_REQUEST,
    detail="invalid_auth_code: The provided authorization code is invalid, expired, or revoked"
)

invalid_request = HTTPException(
    status_code=status.HTTP_400_BAD_REQUEST,
    detail="invalid_request: The request is missing a required parameter or is otherwise malformed"
)

invalid_client_id_or_redirect_uri = HTTPException(
    status_code=status.HTTP_401_UNAUTHORIZED,
    detail="Invalid Cliend ID or redirect_ui, locked for security"
)

unsupported_grant_type = HTTPException(
    status_code=status.HTTP_400_BAD_REQUEST,
    detail="Authorization grant expected"
)

verifier_code_mismatch = HTTPException(
    status_code=400,
    detail="Verifier code does not match"
)
