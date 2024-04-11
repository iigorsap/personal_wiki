import re

address = "Rua da Flores 72, apartamento 1002, laranjeiras, Rio de Janeiro, 23440-120"

# 5 digitos + hifen (opcional) + 3 digitos
padrao_cep = re.compile('[0-9]{5}(-)?[0-9]{3}')
busca = padrao_cep.search(address)

if busca:
    cep = busca.group()
    print(cep)
