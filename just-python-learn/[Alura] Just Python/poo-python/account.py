class Account:
    def __init__(self, number, user, balance, limit):
        print(f'building object {self}')
        self.__number = number  # Atributos
        self.__user = user
        self.__balance = balance
        self.__limit = limit

    def deposit(self, value):
        self.__balance += value

    def withdraw(self, value):
        if(self.__can_draw(value)):
            self.__balance -= value
        else:
            print(f"The value {value} exceeds the limit")

    def __can_draw(self, value):
        balance_available_to_withdraw = self.__balance + self.__limit
        return value <= balance_available_to_withdraw

    def statement(self):
        print(f"balance {self.__balance} of the user {self.__user}")

    def transfer(self, value, destiny_account):
        self.withdraw(value)
        destiny_account.deposit(value)

    @property
    def balance(self):
        return self.__balance

    @property
    def user(self):
        return self.__user

    @property
    def limit(self):
        return self.__limit

    @limit.setter
    def limit(self, new_limit):
        self.__limit = new_limit

    @staticmethod
    def bank_code():
        return "001"

    @staticmethod
    def bank_codes():
        return {'BB': '001', 'Caixa': '104', 'Bradesco': '237'}
