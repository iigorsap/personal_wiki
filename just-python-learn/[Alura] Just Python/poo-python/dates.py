class Date:
    def __init__(self, day, month, year):
        self.__day = day
        self.__month = month
        self.__year = year

    def formated(self):
        print(f"{self.__day}/{self.__month}/{self.__year}")
