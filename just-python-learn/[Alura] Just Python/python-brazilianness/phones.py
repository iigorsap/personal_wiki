import re


class PhonesBr:
    def __init__(self, phone):
        if self.validate_phone(phone):
            self.number = phone
        else:
            raise ValueError("Incorrect number!")

    def __str__(self):
        return self.format_number()

    def validate_phone(self, phone):
        model = "([0-9]{2,3})?([0-9]{2})([0-9]{4,5})([0-9]{4})"
        response = re.findall(model, phone)
        if response:
            return True
        else:
            return False

    def format_number(self):
        model = "([0-9]{2,3})?([0-9]{2})([0-9]{4,5})([0-9]{4})"
        response = re.search(model, self.number)

        number_formated = f"+{response.group(1)}({response.group(2)}){response.group(3)}-{response.group(4)}"
        return number_formated
    
