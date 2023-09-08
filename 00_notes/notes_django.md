# Commands

Install django
```
pip install django
```
Create django project
```
django-admin startproject {name-project} .
```
Running local server django
```
py manage.py runserver
```
Apply the changes made to a model, to apply those changes to the database.
```
py manage.py migrate
```
create an app
```
py manage.py startapp {name-app}
```

---
# Understanding django files

- ``Setting.py:`` Controlar as configurações do nosso projeto.
  - Configurações de Banco de Dados.
  - Idioma e Fuso-horário.
  - Configurações de Segurança.
  - Configurações personalizadas.
- ``urls.py:``  diz ao Django quais páginas para construir em resposta a um navegador ou requisição de URL.
  - Mapeamento de URLs para views.
    - Exemplo: Associar "/pagina" a uma função de "view" que exibe uma página específica do site/blog.
  - Manipulação de Parâmetros de URL:
    - Por exemplo, você pode definir uma URL como "/artigo/1/" e extrair o valor "1" para identificar qual artigo deve ser exibido.
  - Organização de URLs:
    - Ele determina como as solicitações HTTP são roteadas para as funções de visualização apropriadas. Por exemplo, quando um usuário acessa uma URL, o Django verifica o arquivo urls.py para encontrar a correspondência e direcionar a solicitação para a função de visualização correspondente.
- ``wsgi.py (Web Server Gateway Interface):`` Ajuda o Django a servir nossas eventuais páginas web.
  - Integração com servidor web.
- ``manage.py:`` Usado para executar vários comandos do Django, como rodar servidor web local, ou criar uma nova aplicação.
  - O Django vem com um servidor web embutido para propósitos de desenvolvimento local que nós podemos iniciar com o comando runserver.

### Apps django

```text
Um único projeto Django contém uma ou mais aplicações dentro dele que trabalham em conjunto para alimentar uma aplicação web.

Por exemplo, um e-commerce Django do mundo real pode ter uma app autenticação de usuários, outra app para pagamentos, e uma terceira app para alimentar detalhes de listagem de itens, cada um foca em uma parte isolada da funcionalidade. 

São três aplicações distintas que vivem todas dentro de um projeto de nível superior.
```
