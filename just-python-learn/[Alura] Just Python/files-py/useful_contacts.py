from abc import ABCMeta, abstractmethod
import csv, pickle, json

from contact import Contact

class ContactDao(metaclass=ABCMeta):

    @abstractmethod
    def search_all(self, path):
        pass

    @abstractmethod
    def save(self, contacts, path):
        pass

class ContactDaoJson(ContactDao):

    def search_all(self, path):
        contacts = []
        with open(path, mode='r') as file:
            contacts_json = json.load(file)

            for contact in contacts_json:
                c = Contact(id=contact["id"], name=contact["name"], email=contact["email"])
                contacts.append(c)

        return contacts

    def save(self, contacts, path):
        with open(path, mode='w') as file:
            json.dump(contacts, file, default=lambda object: object.__dict__)

class ContactDaoPickle(ContactDao):

    def search_all(self, path):
        with open(path, mode='rb') as file:
            contacts = pickle.load(file)

        return contacts    

    def save(self, contacts, path):
        with open(path, mode='wb') as file:
            pickle.dump(contacts, file)
        

class ContactDaoCsv(ContactDao):

    def search_all(self, path, encoding= 'latin_1'):
        contacts = []
        with open(path, encoding=encoding) as file:
            reader = csv.reader(file)

            for line in reader:
                id = line[0]
                name = line[1]
                email = line[2]

                c = Contact(id, name, email)
                contacts.append(c)
        return contacts

    def save(self, contacts, path):
        pass