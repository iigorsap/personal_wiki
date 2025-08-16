FROM ghcr.io/astral-sh/uv:python3.12-bookworm-slim

WORKDIR /app

COPY . /app/

RUN uv sync

CMD ["uv", "run", "fastapi", "dev", "--host", "0.0.0.0"]
