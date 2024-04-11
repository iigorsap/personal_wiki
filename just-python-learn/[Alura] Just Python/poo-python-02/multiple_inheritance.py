
class Employee():

    def __init__(self, name):
        self.name = name

    def register_hours(self, hours):
        print('Horas Registradas')

    def show_tasks(self):
        print('Fez muita coisa...')


class Caelum(Employee):
    def show_tasks(self):
        print('Fez muita coisa, Caelumer')

    def search_courses_of_month(self, month=None):
        print(f'Mostrando cursos - {month}' if month else 'Mostrando cursos desse mês')


class Alura(Employee):
    def show_tasks(self):
        print('Fez muita coisa, Alurete!')

    def search_unanswered_questions(self):
        print('Mostrando perguntas não respondidas do fórum')


# Mixins
class Hipster:
    def __str__(self):
        return f'Hipster,  {self.name}'


class Junior(Alura):
    pass


class Pleno(Alura, Caelum, Hipster):
    pass


jose = Junior('Jose')
jose.search_unanswered_questions()
jose.show_tasks()

luan = Pleno('Luan')
luan.search_unanswered_questions()
luan.search_courses_of_month()

luan.show_tasks()

print(luan)
