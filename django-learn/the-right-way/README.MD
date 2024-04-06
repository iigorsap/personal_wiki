A view is a Python function that takes a Web request and returns a Web response.

```py
# views.py
"""A view recebe um HttpRequest e retorna um HttpResponse como a seguir."""
from django.http import HttpResponse

def hello_world(request):
    return HttpResponse('Hello world!')

# urls.py
"""URLconf, só precisamos referenciar a view para um path, passar como parametro a view que queremos chamar, e o nome dela para usar por exemplo em um reverse(), esse nome precisa ser unico no projeto"""

from django.urls import path

from . import views

urlpatterns = [
    path('hello/', views.hello_world, name='hello_world'),
]
```

```py
"""Se possui o interesse em criar uma view que vai necessitar de uma familia de urls, como por exemplo, utilizando um id para acessar o detalhe de uma página é preciso passar o argumento para a view e alterar a URLconfig"""  

# views.py
def hello_world(request, my_arg):
    ...

# urls.py
urlpatterns = [
    path('hello/<str:my_arg>/', views.hello_world, name='hello_world'),
]
```

```py
# templates/
"""Os exemplos de antes está passando pagina html para a view, mas como precisamos de sites dinamicos onde há a necessidade de servir alguns dados na página, onde queremos também incluir navegação, usamos os templates, que facilita essa comunicação e permite que informações dinâmicas apareçam na pagina, para usar os templates usamos o django.template.loader para carregar nosso template"""

# views.py 
from django.http import HttpResponse
from django.template import loader


def hello_world(request, my_arg):
    template = loader.get_template('hello_world.html')
    context = {}
    return HttpResponse(template.render(context, request))

"""O modelo não é uma parte essencial de uma exibição do Django - as request e response HTTP são as partes essenciais, Os templates são apenas uma forma de construir o corpo da response."""

"""Existe um atalho para esse processo de carregar um modelo, renderizá-lo e colocá-lo em um response - render(). Com isso, podemos condensar nossa visualização da seguinte forma"""

from django.shortcuts import render

def hello_world(request, my_arg):
    return render(request, 'hello_world.html', {})

"""Esse é um ótimo padrão para escrever visualizações. No entanto, o Django tem mais um truque na manga: TemplateResponse.

Pelo fato de que a resposta dele é mais completa, ele guarda na memória qual template veio, armazena o valor da response, o que ajuda nos tests.
"""

from django.template.response import TemplateResponse

def example_view(request, arg):
    return TemplateResponse(request, 'example.html', {})

"""Caso queira passar alguns dados para o TemplateResponse, usamos da seguinte forma:"""
def home(request):
    today = date.today()
    context = {
        'today': today,
    }
    if today.weekday() == 0:
        context['special_message'] = 'Happy Monday!'
    return TemplateResponse(request, "home.html", context)

"""Outro exemplo é se tem interesse em retornar a view de acordo com uma caracteristica especifica de contexto, é possivel usar funções para fazer isto"""

def checkout_start(request):
    context = {
        # etc
    } | checkout_pages_context_data(request.user)
    return TemplateResponse(request, "shop/checkout/start.html", context)


def checkout_pages_context_data(user):
    context = {}
    if not user.is_anonymous:
        context["user_addresses"] = list(user.addresses.order_by("primary", "first_line"))
    return context

```

```py

```
