from datetime import datetime, timedelta


class Dates:
    def __init__(self):
        self.registration_moment = datetime.today()

    def __str__(self):
        return self.format_date()

    def month_registration(self):
        year_months = [
            "Janeiro", "Fevereiro", "Marco",
            "Abril", "Maio", "Junho",
            "Julho", "Agosto", "Setembro",
            "Outubro", "Novembro", "Dezembro",
        ]

        month_registration = self.registration_moment.month - 1
        return year_months[month_registration]

    def week_day(self):
        week_days = [
            "Segunda", "Terça", "Quarta",
            "Quinta", "Sexta"
        ]

        week_registration = self.registration_moment.weekday()
        return week_days[week_registration - 1]

    def format_date(self):
        date_formated = self.registration_moment.strftime("%d/%m/%Y %H:%M")
        return date_formated

    def registration_time(self):
        registration_time = datetime.today() - self.registration_moment
        return registration_time


class Register:
    def __init__(self):
        self.register_date = datetime.today()

    def registered_days(self):
        now = datetime.today() + timedelta(days=15, minutes=20, seconds=30)
        return now - self.register_date
