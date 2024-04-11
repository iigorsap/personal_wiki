from useful_contacts import ContactDaoPickle, ContactDaoCsv, ContactDaoJson

try:

    contacts = ContactDaoCsv().search_all('font_files/contacts.csv')

    # ContactDaoPickle().save(contacts, 'font_files/contacts.pickle')
    # contacts = ContactDaoPickle().search_all('font_files/contacts.pickle')
    """ 
    Caso queira testar conversão para Pickle só comentar as duas linhas seguintes e descomentar as 2 anteriores
    """
    ContactDaoJson().save(contacts, 'font_files/contacts.json') 
    contacts = ContactDaoJson().search_all('font_files/contacts.json')

    for contact in contacts:
        print(f'{contact.id} - {contact.name} - {contact.email}')

except FileNotFoundError:
    print("file not found")
except PermissionError:
    print("no write permission")

"""
contacts_file.readlines() -> ler todas as linhas do arquivo
contacts_file.readline() -> ler 1 linha por vez do arquivo

"""

