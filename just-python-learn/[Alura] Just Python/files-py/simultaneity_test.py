'''
 Testa os multiplos acessos juntos, caso os arquivos abertos em mode='w'
 o ultimo vai ser sempre o predominante.
'''
contact_igor = '11, igor, igor@igor.com.br\n'
contact_amanda = '12, amanda, amanda@amanda.com.br\n'

with open('font_files/contacts_write.csv',encoding='latin_1', mode='w') as file_01:
    file_01.write(contact_igor)

with open('font_files/contacts_write.csv',encoding='latin_1', mode='a') as file_02:
    file_02.write(contact_amanda)

"""
Escopo do with ajuda a nao precisar fechar arquivo, pois so funciona mexer no arquivo dentro do 
dentro do escopo do with, então é uma forma de gerenciar o contexto de ultilização do arquivo
"""

"""
Além de arquivos, podemos utilizar o with para gerenciar 
processos que precisam de uma pré e pós condição de execução
"""

