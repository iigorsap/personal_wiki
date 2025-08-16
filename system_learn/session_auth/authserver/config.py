from pydantic_settings import BaseSettings, SettingsConfigDict
from pydantic import Field

class AuthSettings(BaseSettings):
    auth_code_algorithm: str = Field(alias="AUTH_CODE_ALGORITHM")
    auth_code_expires_minutes: int = Field(alias="AUTH_CODE_EXPIRES_MINUTES")

    model_config = SettingsConfigDict(
        env_file=".env",
        env_file_encoding="utf-8",
        populate_by_name=True,
        env_prefix="",
        extra="ignore",
    )


auth_settings = AuthSettings()
