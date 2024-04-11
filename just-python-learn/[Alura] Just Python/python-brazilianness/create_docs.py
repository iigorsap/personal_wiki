from validate_docbr import CPF
from validate_docbr import CNPJ


class Document:
    @staticmethod
    def create_new(document):
        if len(document) == 11:
            return DocCpf(document)
        elif len(document) == 14:
            return DocCnpj(document)
        else:
            raise ValueError("Quantidade de digitos invalida!")

class DocCnpj:
    def __init__(self, document):
        document = str(document)
        if self.valid(document):
            self.cnpj = document
        else:
            raise ValueError("CNPJ inválido!")

    def valid(self, document):
        document_ = CNPJ()
        return document_.validate(document)

    def format_cnpj(self):
        mask_ = CNPJ()
        return mask_.mask(self.cnpj)

    def __str__(self):
        return self.format_cnpj()


class DocCpf:
    def __init__(self, document):
        document = str(document)
        if self.valid(document):
            self.cpf = document
        else:
            raise ValueError("CPF inválido!")

    def valid(self, document):
        document_ = CPF()
        return document_.validate(document)

    def format_cpf(self):
        mask_ = CPF()
        return mask_.mask(self.cpf)

    def __str__(self):
        return self.format_cpf()
