# Commands

Install django
```
pip install django
```
Create django project
```
django-admin startproject {project-name} .
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
py manage.py startapp {app-name}
```

---
# Understanding project files

- ``{project-name}/Setting.py:`` Controlar as configurações do nosso projeto.
  - Configurações de Banco de Dados.
  - Idioma e Fuso-horário.
  - Configurações de Segurança.
  - Configurações personalizadas.
- ``{project-name}/urls.py:``  diz ao Django quais páginas para construir em resposta a um navegador ou requisição de URL.
  - Mapeamento de URLs para views.
    - Exemplo: Associar "/pagina" a uma função de "view" que exibe uma página específica do site/blog.
  - Manipulação de Parâmetros de URL:
    - Por exemplo, você pode definir uma URL como "/artigo/1/" e extrair o valor "1" para identificar qual artigo deve ser exibido.
  - Organização de URLs:
    - Ele determina como as solicitações HTTP são roteadas para as funções de visualização apropriadas. Por exemplo, quando um usuário acessa uma URL, o Django verifica o arquivo urls.py para encontrar a correspondência e direcionar a solicitação para a função de visualização correspondente.
- ``{project-name}/wsgi.py (Web Server Gateway Interface):`` Ajuda o Django a servir nossas eventuais páginas web.
  - Integração com servidor web.
- ``{project-name}/manage.py:`` Usado para executar vários comandos do Django, como rodar servidor web local, ou criar uma nova aplicação.
  - O Django vem com um servidor web embutido para propósitos de desenvolvimento local que nós podemos iniciar com o comando runserver.

# Apps django

```text
Um único projeto Django contém uma ou mais aplicações dentro dele que trabalham em conjunto para alimentar uma aplicação web.

Por exemplo, um e-commerce Django do mundo real pode ter uma app autenticação de usuários, outra app para pagamentos, e uma terceira app para alimentar detalhes de listagem de itens, cada um foca em uma parte isolada da funcionalidade. 

São três aplicações distintas que vivem todas dentro de um projeto de nível superior.
```

Para o projeto django conhecer uma app, é preciso adicionar explicitamente a mesma, adicionando na lista de apps instalados (INSTALLED_APPS) dentro do arquivo ``{project-name}/Setting.py``, essas apps devem sempre serem adicionadas na parte inferior pois o Django executa INSTALLED_APPS, de cima para baixo. Portanto a aplicação interna de administração é carregada primeiro, depois auth, e assim por diante. 

```python
INSTALLED_APPS = [
    'django.contrib.admin',
    'django.contrib.auth',
    'django.contrib.contenttypes',
    'django.contrib.sessions',
    'django.contrib.messages',
    'django.contrib.staticfiles',
    '{app-name}.apps.{AppName-Config}',  # new app
]
```

## Understanding app files

``{project-name}/{app-name}/admin.py:`` É a configuração para o django-admin para o que está embutido na app.
``{project-name}/{app-name}/apps.py:`` Configurações para a própria app.
``{project-name}/{app-name}/migrations/:`` Mantém o registo de quaisquer alterações ao nosso arquivo *models.py* para que a nossa base de dados e
*models.py* fiquem sincronizados.
``{project-name}/{app-name}/models.py:`` É onde definimos nossos modelos de banco de dados que o Django automaticamente traduz em tabelas de base de dados.
``tests.py:`` É um arquivo para os testes específicos da app.
``views.py:`` É onde lidamos com a lógica de request/response para nossa app

# URLs, Views, Models, Templates

No django geralmente pelo menos 4 arquivos separados são necessários para alimentar uma única página, são eles: ``urls.py``, ``views.py``, ``models.py``, template HTML como ``index.html``.

Ciclo HTTP request/response: 
- Digita URL (https://igorswrk.com)
- Projeto Django tem como primeiro objetivo encontrar um URLpattern que combine com a homepage. 
- Após isso o URLpattern especifica uma view que determina o conteúdo da página.
- Este conteúdo geralmente vem de um database model, as vezes não é necessário. por isso que é geralmente.
- E por fim o template define o estilo e lógica básica. 
- O resultado final é enviado de volta ao user como uma HTTP response.

**Django request/response cycle**

*URL -> View -> Model (Tipically) -> Template*

## Templates

Arquivos HTML individuais que podem ser ligados entre si e também incluem a lógica básica do site. Para usar um templete fazemos um link do template a uma view.

Tem duas abordagens para criar os nossos templates, uma é criar um diretório em cada app templates, e dentro do diretório templates, um novo diretório com o nome da app e finalmente criamos o nosso arquivo home.html que diz respeito ao nosso arquivo templates. **E teria que fazer isso para todas as apps, um trabalho um pouco repetitivo.**

Então nosso sistema de arquivos ficaria assim
- ``/{name-app}/templates/{name-app}/home.html``

Por padrão o Django consegue identificar o arquivo como nosso template.

Porém temos outra forma de fazer isso, mais amigável, criamos um diretório com o nome de templates fora da app, na raiz do diretório do projeto.
Para isso precisamos falar para o Django onde está localizado nosso novo diretório templates, para isso temos que mudar uma linha no ``{name-project}/settings.py``.
Adicionando o caminho que indica onde está os nossos arquivos templates: ``os.path.join(BASE_DIR, 'templates')``.

```python
TEMPLATES = [
    {
      ...
        'DIRS': [os.path.join(BASE_DIR, 'templates')],  # new
      ...
    },
]
```
