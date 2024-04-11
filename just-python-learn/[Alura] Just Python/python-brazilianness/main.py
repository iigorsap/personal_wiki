import requests

from acess_cep import SearchAddress

cep = "01001000"
obj_cep = SearchAddress(cep)

bairro, cidade, uf = obj_cep.acess_viacep()
print(bairro, cidade, uf)


def return_address(cep):
    url = 'https://viacep.com.br/ws/{}/json'.format(cep)
    r = requests.get(url)
    dados = r.json()
    bairro = dados.get('bairro')
    cidade = dados.get('localidade')
    uf = dados.get('uf')
    return bairro, cidade, uf


bairro1, cidade1, uf1 = return_address(cep)
print(bairro1, cidade1, uf1)
