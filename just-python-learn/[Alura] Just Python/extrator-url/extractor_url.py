import re

class ExtractURL:
    def __init__(self, url):
        self.url = self.sanitize_url(url)
        self.validate_url()

    def sanitize_url(self, url):
        if type(url) == str:
            return url.strip()
        else:
            return ""

    def validate_url(self):
        if not self.url:
            raise ValueError("A URL está vazia")

        template = re.compile("(http(s)?://)?(www.)?bytebank.com(.br)?/cambio")
        match = template.match(self.url)
        if not match:
            raise ValueError("A URL não é válida.")

    def get_base_url(self):
        index_query = self.url.find('?')
        base_url = self.url[:index_query]
        return base_url

    def get_parameters_url(self):
        index_query = self.url.find('?')
        parameters_url = self.url[index_query + 1:]
        return parameters_url

    def get_parameters_value(self, search_parameter):
        index_parameter = self.get_parameters_url().find(search_parameter)
        index_value = index_parameter + len(search_parameter) + 1
        index_ampersand = self.get_parameters_url().find('&', index_value)
        if index_ampersand == -1:
            value = self.get_parameters_url()[index_value:]
        else:
            value = self.get_parameters_url()[index_value:index_ampersand]
        return value

    def __len__(self):
        return len(self.url)

    def __str__(self):
        return "URL: " + self.url + "\n" + "Parametros: " + self.get_parameters_url() + "\n" + "URL_BASE: " + self.get_base_url()

    def __eq__(self, other):
        return self.url == other.url


url = "bytebank.com/cambio?quantidade=100&moedaOrigem=real&moedaDestino=dolar"

extractor_url = ExtractURL(url)

# Desafio conversao Real para o Dolar
VALOR_DOLAR = 5.50

coin_origin = extractor_url.get_parameters_value("moedaOrigem")
print(f"Moeda Origem: {coin_origin.title()}")

coin_destiny = extractor_url.get_parameters_value("moedaDestino")
print(f"Moeda Destino: {coin_destiny.title()}")

value_qtd = extractor_url.get_parameters_value("quantidade")
print(f"Valor: R$ {value_qtd}")

conversion = float(value_qtd) * VALOR_DOLAR
print(f"R$ {value_qtd} = $ {conversion}")

# extractor_url_2 = ExtractURL(url)

# print(extractor_url == extractor_url_2)  # extractor_url.__eq__(extractor_url_2)

# print("O tamanho da URL:", len(extractor_url))
# print(extractor_url)

# print(id(extractor_url_2))
# print(id(extractor_url))

# 'is' deve ser usado sempre e somente quando queremos comparar a identidade de um objeto, isto é, seu endereço na memória.
# O '==', por sua vez, deve ser usado quando quisermos comparar valores (ou, na verdade, qualquer outra coisa!) de objetos.

