# Commands

```python
# Instalando o django

pip install django
```

```python
# Criando projeto django

django-admin startproject {project-name} .
```

```python
# Rodando o servidor local do django

py manage.py runserver
```

```python
# Aplicando as mudanças feito no arquivo model, para aplicar essas mudando na base de dados.

py manage.py migrate
```

```python
# Criando uma app no Django

py manage.py startapp {app-name}
```

```python
# Arquivo de migrações referência todas as alterações nos modelos de banco de dados, tornando todas as alterações rastreáveis.

python manage.py makemigrations {name-app}
```

```python
# Criando o banco de dados real, executando as instruções do nosso arquivo migrate.

python manage.py migrate
```

```python
# Para criar o superuser precisamos usar o seguinte comando na linha de comando:


python manage.py createsuperuser

# Após a configuração, acessando http://127.0.0.1:8000/admin/, temos nosso painel admin.
```

```python
# Rodar os testes da nossa app:

python manage.py test
```

```python
"""
Você pode simplesmente redefinir o banco de dados em vez de migrar, mas isso perderá todos os dados existentes. 
É uma boa prática aprender a migrar um banco de dados e, ao mesmo tempo, manter a integridade dos dados dos usuários. 
Se quiser começar com um banco de dados novo, execute o comando 
"""
python manage.py flush 
"""
Dessa forma você consegue reconstruir a estrutura do banco de dados. 
Você terá que criar um novo superusuário, e todos os seus dados serão perdidos.
"""

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
    '{app-name}.apps.{AppNameConfig}',  # new app
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

O Django possui algumas views genéricas para conseguir simplificar alguns métodos, views baseadas em classes do python que facilitam a utilização e também estendem as views que resolve alguns problemas comuns.

Para fazer utilização dessa view generica, Built-in, devemos atualizar o arquivo ``{name-project}/{name-app}/views.py``. Ela possui varios métodos que não precisam ser implemetados, como post, get, put, entre outros métodos.

```python
from django.views.generic import TemplateView

class HomePageView(TemplateView):
  template_name = 'home.html'
  context_object_name = 'exemplo' 
  
# Este campo context_object_name é usado para redefinir o nome do context object, por exemplo se quiser usar outro nome ao invés de usar object ou nome padrão do model.   
```

Quando utiliza views baseadas em classes, adiciona sempre as_view() no final do nome da view quando for referenciá-la.

```python
urlpatterns = [
  path('', HomePageView.as_view(), name='home'),
]
```

Podemos criar um template base para evitar repetir por exemplo código de cabeçalho, footer ou algo do tipo, para isso criamos um arquivo ``{name-project}/templates/base.html`` convencionalmente usamos esse nome.

Para fazer isso usamos ``{% block content%}{endblock content}``.

Como por exemplo, dado esse template pai:

```html
...
<head>
    <title>{% block title %}Título Padrão{% endblock title %}</title>
</head>
    ...
    
    <main>
        {% block content %}
        <p>Conteúdo padrão do site.</p>
        {% endblock content %}
    </main>
...
```

Podemos usar em um template filho dessa forma:

```html
{% extends "base.html" %}

{% block title %}Título da Página{% endblock title %}

{% block content %}
<p>Conteúdo específico da página.</p>
<p>Este conteúdo substituirá o conteúdo padrão do site.</p>
{% endblock content %}
```

Dessa forma conseguimos modificar um pouco a página sem precisar repetir todo o código reutilizando o que já está pronto.

Em uma aplicação como essa, nós podemos olhar manualmente e ver que a página inicial e a página sobre existem e contém o conteúdo pretendido. Mas como um projeto Django cresce em tamanho, pode haver centenas, se não milhares de páginas web individuais e a idéia de passar manualmente por cada página não é possível.

## Database Model

Para construir o nosso modelo de banco de dados primeiramente temos que importar o modulo ``models``, isto irá ajudar a construir nosso modelo de banco de dados.
Esse modulo contém os tipos de campos do nosso modelo de dados entre outras funções auxiliares que contribui para nosso modelo de banco de dados. Como por exemplo:

```python
# {name-project}/{name-model}/models.py
from django.db import models

# Create your models here
class NameModel(models.Model):
    text = models.TextField()
```

O django disponibiliza varios tipos de campos como:

```python
models.CharField(max_length=n, ...)
models.ForeignKey(...)
models.DateField(...)
models.IntegerField(...)
```

## Activating models

Quando nosso novo modelo é criado, precisamos ativá-lo. Após isso, sempre que criarmos ou modificarmos um modelo existente, precisaremos atualizar o Django em um processo de duas etapas:

```python

# Arquivo de migrações referência todas as alterações nos modelos de banco de dados, tornando todas as alterações rastreáveis.

python manage.py makemigrations {name-app}

# Criando o banco de dados real, executando as instruções do nosso arquivo migrate.

python manage.py migrate
```

Para administrar nossos modelos é possivel acessar um painel bem completo para admnistração desenvolvido para o Django, como ele podemos inclusive gerenciar nosso banco de dados. Para isso precisamos criar um usuário chamado de super usuário.

Para criar o superuser precisamos usar o seguinte comando na linha de comando:

```python
python manage.py createsuperuser

# Após a configuração, acessando http://127.0.0.1:8000/admin/, temos nosso painel admin.

```

Para que nossa aplicação seja vista no nosso painel admin, precisamos passar para o django explicitamente igual fizemos com nas aplicações INSTALLED_APPS. Para isso precisamos alterar nosso arquivo ``{name-model}/admin.py`` e adicionar uma nova linha onde passamos o nosso model para o nosso admin e mostramos a existência dele.

```python
from django.contrib import admin
from .models import {name-model}


# Register your models here.
admin.site.register({name-model})
```

Agora o Django conhece nossa app, ficando disponível no django admin, podendo adicionar algum conteúdo de acordo com os campos que colocamos no nosso modelo, criando objetos do nosso model.

Podemos renomear cada instância do nosso modelo para não ser criados modelos com nomes genéricos, para isso precisamos adicionar a linha de código para adicionarmos um novo campo no nosso modelo, essa linha vai pegar os primeiros 50 caracteres do nosso modelo, e colocar como nome deixando o objeto mais representativo.

```python
# {name-project}/{name-model}/models.py

class {NameModel}(models.Model):
    ...

    def __str__(self):
      return self.text[:50]
```

### Views/Templates/URLs

Para exibir nosso database no site precisamos fazer o link com as nossas views, templates e urls.

Arquivo view:

```python

# {name-project}/{name-model}/views.py

from django.shortcuts import render
from django.views.generic import ListView
from .models import {NameModel} # class
# Create your views here.


class HomePageView(ListView):
    model = {NameModel}
    template_name = 'home.html'
    context_object_name = {name-object}

```

Arquivo template:

```html

<!-- {name-project}/templates/home.html -->

<h1> HomePage </h1>

<ul>
	{% for {name-model} in {name-object} %}
		<li>{{ {name-model}.text }}</li>
	{% endfor %}
</ul>

```

Arquivo URLs:

```python

# {name-project}/urls.py

from django.contrib import admin
from django.urls import path, include # new

urlpatterns = [
    path('admin/', admin.site.urls),
    path('', include('{name-model}.urls')), # new
]
```

Arquivo URLs do Projeto:

```python
# {name-project}/urls.py
from django.contrib import admin
from django.urls import path, include # new

urlpatterns = [
    path('admin/', admin.site.urls),
    path('', include('{name-app}.urls')), # new
]

```

Criamos também arquivo URLs da app:

```python
from django.urls import path
from .views import HomePageView

urlpatterns = [
    path('', HomePageView.as_view(), name='home'),
]
```

Também é preciso realizar tests para garantir que o objeto criado do nosso modelo está correto, para isso não precisamos referenciar nosso modelo, somente criar uma instância no próprio teste e verificar se está tudo conforme o esperado, assim como no exemplo abaixo:

```python

from django.test import TestCase
from .models import {name-model}


# Create your tests here.
def {{nome-model}ModelTest}(TesteCase):

    # set a name
    def setUp(self):
        {name-model}.objects.create(text='just a test')

    # verifyng the name
    def teste_text_content(self):
        {var-objeto-model} = {name-model}.objects.get(id=1)
        expected_object_name = f"{{var-objeto-model}.text}"
        self.assertEqual(expected_object_name, 'just a test')
```

Para rodar os testes usados o ``manage.py``:

```
python manage.py test
```

## Forms

Para trabalhar com formulário é preciso criar uma link primeiramente, que vai redirecionar para a adição, update ou delete da informação requerida, seja um post, uma receita, um comentário.

```html
<a href="{% url '{name-model}_new' %}">add</a>
<a href="{% url '{name-model}_edit' {name-model}.pk %}">edit</a>
<a href="{% url '{name-model}_delete' {name-model}.pk %}">delete</a>
```

Depois é preciso referenciar uma url para o nosso template, para isso precisamos criar a view que irá ser usada para mostrar a informações na tela. Vamos criar a nossa view usando como super classe views genericas já presente na biblioteca padrão do django. ``django.views.generic.edit`` 

```python
from django.views.generic.edit import CreateView, UpdateView, DeleteView
	
class {name-model}CreateView|UpdateView|DeleteView(CreateView|UpdateView|DeleteView):
	model = {name-model}
	template_name = {name-template}.html
	fields = [] # campos para views [create, update]
	sucess_url = reverse_lazy('home') # Oposto do reverse(), essa função redireciona para uma url como sucesso do delete [delete]
```

Após a criação da view, é preciso agora referenciar em uma URL como mencionado antes.

```python
from .views import (
	{name-app}UpdateView,
	{name-app}CreateView,
	{name-app}DeleteView,
)

urlpatterns = [
	path('{name-model}/<int:pk>/delete/', {nname-app}DeleteView.as_view(), name='{name-model}_delete'),
	path('{name-model}/add/', {name-app}CreateView.as_view(), name='{name-model}_add'),
	path('{name-model}/<int:pk>/edit/', {name-app}UpdateView.as_view(), name='{name-model}_edit'),
]
```

Agora criamos os templates para nossas views.

```html
<!-- add {model}  -->

{% extends 'base.html' %} 

{% block content %}
	<h1>
    	Add {model}
	</h1>
	<form action="" method="post">{% csrf_token %} 
		{{ form.as_p }}
		<input type="submit" value="Update">
	</form>
{% endblock content %}

```

```html
<!-- edit {model}  -->

{% extends 'base.html' %} 

{% block content %}
	<h1>
    	Edit {model}
	</h1>
  	<form action="" method="post">{% csrf_token %} 
			{{ form.as_p }}
			<input type="submit" value="Update">
  	</form>
{% endblock content %}

```

```html
<!-- delete {model} -->

{% extends 'base.html' %} 

{% block content %}
	<h1>
    	Delete {model}
	</h1>
  	<form action="" method="post">{% csrf_token %} 
		<p>Are you sure you want to delete "{{ {model}.title }} ?</p>
    	<input type="submit" value="Confirme">
  	</form>
{% endblock content %}

```

Podemos seguir a sugestão do Django e adicionar um get_absolute_url ao nosso modelo. Essa é uma prática recomendada que você deve sempre fazer. Ela define um URL canônico para um objeto, portanto, mesmo que a estrutura de seus URLs mude no futuro, a referência ao objeto específico específica será a mesma. Em resumo, você deve adicionar um método ``get_absolute_url()`` e ``__str__()`` a em cada modelo que você escrever.

```python
def get_absolute_url(self): # new
	return reverse('post_detail', args=[str(self.id)])
```


