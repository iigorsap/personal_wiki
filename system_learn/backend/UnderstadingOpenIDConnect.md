| Protocolo          | Objetivo Principal                     |
| ------------------ | -------------------------------------- |
| **OAuth 2.0**      | Autorização (dar acesso a recursos)    |
| **OpenID Connect** | Autenticação (provar quem é o usuário) |

---

Como eles se relacionam:

OpenID Connect é uma camada construída sobre o OAuth 2.0.

Ele usa os mesmos fluxos do OAuth 2.0 (authorization code, etc.), mas adiciona um ID Token e outras definições para lidar com autenticação de usuários.

Ou seja:

OAuth 2.0: “O app X pode acessar o recurso Y em nome do usuário?”

OIDC: “Quem é o usuário que está usando o app X?”

Exemplo prático:
Com OAuth 2.0 (sem OIDC):
- Você autentica o usuário no Google e recebe um access_token para acessar a API do Google Drive.
- Você não sabe nada sobre quem é o usuário, só tem permissão para agir em nome dele.

Com OpenID Connect:

Você autentica o usuário no Google e recebe:
- access_token → para acessar recursos (como Gmail, Drive etc.)
- id_token → com as informações de identidade do usuário

Agora você sabe quem é o usuário (ex: nome, e-mail), e pode criar uma sessão no seu app.

# 🧠 O que é **OpenID Connect**?

**OpenID Connect (OIDC)** é um **protocolo de autenticação** construído sobre o OAuth 2.0. Ele permite que aplicativos (clientes) verifiquem a identidade de um usuário com base na autenticação feita por um **provedor de identidade** (como Google, Auth0, AWS Cognito, Okta etc.).

👉 Ele resolve a pergunta:

> "Quem é esse usuário que acabou de fazer login?"

---

## ⚙️ Principais **características** do OIDC

| Característica            | Explicação                                                      |
| ------------------------- | --------------------------------------------------------------- |
| 🔒 Baseado em OAuth 2.0   | Reaproveita seus fluxos e segurança                             |
| 📄 Usa tokens JWT         | Para representar identidade (`id_token`)                        |
| 📤 Envia dados do usuário | Via `id_token` ou endpoint `/userinfo`                          |
| 🌐 Usa URLs bem definidas | Metadata pública via `/.well-known/openid-configuration`        |
| 🧩 Extensível             | Suporta escopos, claims, múltiplos métodos de autenticação etc. |
| 🔐 Seguro                 | Suporta assinaturas digitais, chaves públicas (JWKS) etc.       |

---

## 🔑 Conceitos-chave

| Conceito                        | Definição                                                                |
| ------------------------------- | ------------------------------------------------------------------------ |
| **`id_token`**                  | Token JWT com info de identidade do usuário (ex: `email`, `name`, `sub`) |
| **`access_token`**              | Token para acessar APIs autorizadas                                      |
| **`userinfo_endpoint`**         | Endpoint HTTP onde você pode buscar dados do perfil                      |
| **`scope`**                     | Permissões solicitadas; `openid` é obrigatório para OIDC                 |
| **`client_id / client_secret`** | Identificadores do app cliente                                           |
| **`redirect_uri`**              | Para onde o usuário é redirecionado após login                           |
| **`state`**                     | Token anti-CSRF para proteger a autenticação                             |
| **`nonce`**                     | Token para proteger contra replay attacks                                |

---

## 🔁 Fluxo simplificado (Authorization Code Flow com OIDC)

1. **O usuário clica em “Login com Google”** (por exemplo).
2. O app redireciona para o provedor (`https://accounts.google.com/...`) com:

   * `client_id`, `redirect_uri`, `scope=openid profile email`, etc.
3. O usuário faz login no provedor.
4. O provedor redireciona de volta com um **`code`**.
5. O app troca o `code` por:

   * `access_token`
   * `id_token` ✅
6. O app valida o `id_token` e extrai a identidade do usuário.

---

## 🧩 Exemplos de **claims** no `id_token` (JWT)

```json
{
  "iss": "https://accounts.google.com",
  "aud": "123456.apps.googleusercontent.com",
  "sub": "1029384756",
  "email": "usuario@email.com",
  "name": "Usuário Teste",
  "exp": 1719440000
}
```

---

## 🧰 Casos de uso típicos do OIDC

| Caso                                      | Descrição                                                |
| ----------------------------------------- | -------------------------------------------------------- |
| 🔐 **Login social**                       | Login com Google, Facebook, Apple etc.                   |
| 🧭 **SSO (Single Sign-On)**               | Usuário loga uma vez e acessa vários apps                |
| 🌐 **Web + Mobile auth**                  | Funciona bem com SPA, apps nativos e backends            |
| 🤝 **Integração com provedores externos** | Usar Auth0, Cognito, Keycloak como central de identidade |
| 🧑‍💻 **Criação automática de contas**    | App cria um usuário com base no `id_token` recebido      |

---

OIDC **só faz sentido** quando:

* Você **delegar a autenticação** a um **provedor externo** (ex: Google, Cognito),
* Ou quiser criar um sistema **centralizado de login único (SSO)** entre vários serviços.

---
# 📦 Quando *não* usar OIDC:
| Situação                                       | Usa OIDC? |
| ---------------------------------------------- | --------- |
| Você mesmo cuida do login e senha              | ❌ Não     |
| App simples com login local                    | ❌ Não     |
| App consome APIs próprias e você controla tudo | ❌ Não     |

---

## 📦 Quando *vale a pena* usar OIDC:

| Situação                                                     | Usa OIDC? |
| ------------------------------------------------------------ | --------- |
| Login com Google, Apple, Facebook, Cognito, Auth0, Okta etc. | ✅ Sim     |
| Precisa de login único entre vários apps (SSO)               | ✅ Sim     |
| Não quer gerenciar senhas (delega a outro sistema)           | ✅ Sim     |
