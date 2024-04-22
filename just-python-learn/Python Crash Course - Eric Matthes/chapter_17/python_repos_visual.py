import requests
import plotly.express as px

# Make an API call anc check the response.


"""
Esta é uma URL longa, então nós a dividimos em duas linhas. 
A primeira linha é a parte principal da URL e a segunda 
linha é a cadeia de caracteres de consulta.
"""
url = "https://api.github.com/search/repositories"
url += "?q=language:python+sort:stars+stars:>10000"

"""
O GitHub está atualmente na terceira versão de sua API, portanto, 
definimos cabeçalhos para a chamada de API que pedem explicitamente 
para usar essa versão da API e retornamos os resultados no 
formato JSON
"""
headers = {"Accept": "application/vnd.github.v3+json"}
"""
Chamamos get() e passamos a URL e o cabeçalho que definimos, 
e atribuímos o objeto de resposta à variável r. 
"""
r = requests.get(url, headers=headers)

"""
O objeto de resposta tem um atributo chamado status_code, que nos 
informa se a solicitação foi bem-sucedida. 
(Um código de status de 200 indica uma resposta bem-sucedida.) 
"""
print(f"Status code: {r.status_code}")

# Convert the response object to a dictionary.

"""
Pedimos à API que retornasse as informações no formato JSON, 
então usamos o método json() para converter as informações
em um dicionário Python. Atribuímos o dicionário resultante a response_dict. 
"""
response_dict = r.json()

# Process results.
# Finalmente, imprimimos as chaves de response_dict e vemos o seguinte
print(response_dict.keys())
print(response_dict['items'][0])
print(response_dict['total_count'])
repo_dict = response_dict['items'][0]
for key in sorted(repo_dict.keys()):
    print(key)

"""
Aqui, imprimimos os valores de várias chaves do dicionário do primeiro repositório. 
Começamos com o nome do projeto. Um dicionário inteiro representa o proprietário do projeto, 
então usamos o proprietário da chave para acessar o dicionário que representa o proprietário e, 
em seguida, usamos o login da chave para obter o nome de login do proprietário.
Em seguida, imprimimos quantas estrelas o projeto ganhou e a URL para o repositório GitHub do projeto. 
Em seguida, mostramos quando foi criado e quando foi atualizado pela última vez. 
Finalmente, imprimimos a descrição do repositório.

"""
print("\nSelected information about first repository:")
print(f"Name: {repo_dict['name']}")
print(f"Owner: {repo_dict['owner']['login']}")
print(f"Stars: {repo_dict['stargazers_count']}")
print(f"Repository: {repo_dict['html_url']}")
print(f"Created: {repo_dict['created_at']}")
print(f"Updated: {repo_dict['updated_at']}")
print(f"Description: {repo_dict['description']}")

repo_dicts = response_dict['items']

for i, repo_dict in enumerate(repo_dicts):
    if i == 10:
        break 
    print("\nSelected information about each repository:")
    print(f"Name: {repo_dict['name']}")
    print(f"Owner: {repo_dict['owner']['login']}")
    print(f"Stars: {repo_dict['stargazers_count']}")
    print(f"Repository: {repo_dict['html_url']}")
    print(f"Description: {repo_dict['description']}")

# Quantidade de requisições limite.
# https://api.github.com/rate_limit

"""
Many APIs require you to register and obtain an API key or access token to make API 
calls. As of this writing, GitHub has no such requirement, but if you obtain an access 
token, your limits will be much higher.
"""

repo_links, stars, hover_texts = [], [], []

for repo_dict in repo_dicts:
    # repo_names.append(repo_dict['name'])
    # Transformando repo names em links ativos.
    repo_name = repo_dict['name']
    repo_url = repo_dict['html_url']
    repo_link = f"<a href='{repo_url}'>{repo_name}</a>"
    repo_links.append(repo_link)
    stars.append(repo_dict['stargazers_count'])

    owner = repo_dict['owner']['login']
    description = repo_dict['description']
    hover_text = f"{owner}<br />{description}"
    hover_texts.append(hover_text)

# Make vizualization
title = "Most-Stared Python Projects on GitHub"
labels = {'x': 'Repository', 'y': 'Stars'}
fig = px.bar(x=repo_links, y=stars, title=title, labels=labels,
        hover_name=hover_texts)

fig.update_layout(
    title_font_size=28, 
    xaxis_title_font_size=20, 
    yaxis_title_font_size=20
)

fig.update_traces(marker_color='SteelBlue', marker_opacity=0.6)

fig.show()

