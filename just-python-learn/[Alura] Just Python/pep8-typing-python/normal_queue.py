from base_queue import BaseQueue

from constants import NORMAL_CODE


class NormalQueue(BaseQueue):
    def generate_current_password(self) -> None:
        self.current_password = f'{NORMAL_CODE}{self.code}'

    def call_customer(self, cashier: int) -> str:
        current_customer = self.queue.pop(0)
        self.customers_served.append(current_customer)

        return f'Current customer: {current_customer}, go to cashier {cashier}'
