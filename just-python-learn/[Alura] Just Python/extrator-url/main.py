url = "bytebank.com/cambio?quantidade=100&moedaOrigem=real&moedaDestino=dolar"
# Strings no Python são objetos imutáveis!

# Separa base e parametros
index_query = url.find('?')
url_base = url[:index_query]
url_parameters = url[index_query+1:]
print(url_parameters)

# Busca valor de um parametro
search_parameter = 'moedaDestino'
index_parameter = url_parameters.find(search_parameter)
index_value = index_parameter + len(search_parameter) + 1
index_ampersand = url_parameters.find('&', index_value)

if index_ampersand == -1:
    value = url_parameters[index_value:]
else:
    value = url_parameters[index_value: index_ampersand]


print(value)
