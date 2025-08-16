from pydantic_settings import BaseSettings, SettingsConfigDict
from pydantic import Field

class SessionSettings(BaseSettings):
    session_token_expires_minutes: str = Field(alias="SESSION_TOKEN_EXPIRES_MINUTES")
    algorithm: str = Field(alias="ALGORITHM")
    session_secret_key: str = Field(alias="SESSION_SECRET_TOKEN")

    model_config = SettingsConfigDict(
        env_file=".env",
        env_file_encoding="utf-8",
        populate_by_name=True,
        env_prefix="",
        extra="ignore",
    )

session_settings = SessionSettings()
