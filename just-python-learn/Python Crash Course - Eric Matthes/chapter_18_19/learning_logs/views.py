from django.shortcuts import render, redirect
from django.contrib.auth.decorators import login_required
from .models import Topic, Entry
from .forms import TopicForm, EntryForm
from django.http import Http404

def index(request):
    """The home page for Learning log"""
    return render(request, 'index.html')

@login_required
def topics(request):
    """Show all topics."""
    topics = Topic.objects.filter(owner=request.user).order_by('date_added')
    context = {'topics': topics}
    return render(request, 'topics.html', context)

@login_required
def topic(request, topic_id):
    """Show a single topic and all its entries."""
    topic = Topic.objects.get(id=topic_id)
    
    # Make sure the topic belongs to the current user.
    check_topic_owner(topic, request)
    
    entries = topic.entry_set.order_by('-date_added')
    context = {'topic': topic, 'entries': entries}

    return render(request, 'topic.html', context)

"""
Solicitações GET e POST Os dois principais tipos de solicitações que você usará ao criar aplicativos são GET e POST. 
Você usa solicitações GET para páginas que só leem dados do servidor. Normalmente, você usa solicitações POST quando o 
usuário precisa enviar informações por meio de um formulário. Especificaremos o método POST para processar todos os 
nossos formulários. (Existem alguns outros tipos de solicitações, mas não as usaremos neste projeto.) 
A função new_topic() usa o objeto request como um parâmetro. Quando o usuário solicita inicialmente esta página, 
seu navegador enviará uma solicitação GET. Uma vez que o usuário tenha preenchido e enviado o formulário, seu navegador 
enviará uma solicitação POST. Dependendo da solicitação, saberemos se o usuário está solicitando um formulário em branco 
(GET) ou solicitando que processemos um formulário preenchido (POST). Usamos um teste if para determinar se o método de 
solicitação é GET ou POST. Se o método de solicitação não for POST, a solicitação provavelmente será GET, 
então precisamos retornar um formulário em branco. (Se for outro tipo de solicitação, ainda é seguro retornar 
um formulário em branco.) Fazemos uma instância de TopicForm, atribuímos ao formulário variável e enviamos o 
formulário para o modelo no dicionário de contexto. Como não incluímos argumentos ao instanciar o TopicForm, o Django 
cria um formulário em branco que o usuário pode preencher. Se o método de solicitação for POST, o bloco else será 
executado e processará os dados enviados no formulário. Fazemos uma instância do TopicForm e passamos a ela os dados 
inseridos pelo usuário, que são atribuídos a request.POST. O objeto de formulário retornado contém as informações 
enviadas pelo usuário. Não podemos salvar as informações enviadas no banco de dados até verificarmos se elas são válidas.
O método is_valid() verifica se todos os dados necessários foram preenchidos (todos os campos em um formulário são 
obrigatórios por padrão) e se os dados inseridos correspondem aos tipos de campo esperados — por exemplo, se o 
comprimento do texto é inferior a 200 caracteres, conforme especificado em models.py no Capítulo 18. 
Essa validação automática nos poupa muito trabalho. Se tudo for válido, podemos chamar save(), que grava os dados do 
formulário no banco de dados. Depois de salvar os dados, podemos sair desta página. A função redirect() toma o nome de 
uma vista e redireciona o utilizador para a página associada a essa vista. Aqui usamos redirect() para redirecionar o 
navegador do usuário para a página de tópicos, onde o usuário deve ver o tópico que acabou de inserir na lista de 
tópicos. A variável de contexto é definida no final da função de exibição e a página é renderizada usando o modelo 
new_topic.html, que criaremos a seguir. Este código é colocado fora de qualquer bloco if; Ele será executado se um 
formulário em branco tiver sido criado e será executado se um formulário enviado for considerado inválido. Um 
formulário inválido incluirá algumas mensagens de erro padrão para ajudar o usuário a inserir dados aceitáveis
"""

@login_required
def new_topic(request):
    """Add new topic"""
    if request.method != 'POST':
        form = TopicForm()
    else:
        # POST data submitted; process data
        form = TopicForm(request.POST)
        if form.is_valid():
            new_topic = form.save(commit=False)
            new_topic.owner = request.user
            new_topic.save()
            return redirect('learning_logs:topics')
    
    # Display a blank or valid form
    context = {'form': form}
    return render(request, 'new_topic.html', context)

@login_required
def new_entry(request, topic_id):
    """Add a new entry for a particular topic."""
    topic = Topic.objects.get(id=topic_id)

    if request.method != 'POST':
        # No data
        form = EntryForm()
    else:
        form = EntryForm(request.POST)
        if form.is_valid():
            new_entry = form.save(commit=False)
            new_entry.topic = topic
            check_topic_owner(new_entry.topic, request)
            new_entry.save()
            return redirect('learning_logs:topic', topic_id)

    # Display a blank or valid form
    context = {'topic': topic, 'form': form}
    return render(request, 'new_entry.html', context)

@login_required
def edit_entry(request, entry_id):
    """Edit an existing entry"""
    entry = Entry.objects.get(id=entry_id)
    topic = entry.topic

    check_topic_owner(topic, request)
    
    if request.method != 'POST':
        form = EntryForm(instance=entry)
    else:
        form = EntryForm(instance=entry, data=request.POST)
        if form.is_valid():
            form.save()
            return redirect('learning_logs:topic', topic_id=topic.id)

    context = {'entry': entry, 'topic': topic, 'form': form}
    return render(request, 'edit_entry.html', context)

def delete_entry(request, entry_id):
    entry = Entry.objects.get(id=entry_id)
    topic = entry.topic
    
    if request.method == 'POST':
        entry.delete()
        return redirect('learning_logs:topic', topic_id=topic.id)
    
    context = {'entry': entry}
    return render(request, 'delete_entry.html', context)    

def check_topic_owner(topic, request):
    if topic.owner != request.user:
        raise Http404