from base_queue import BaseQueue
from constants import PRIORITY_CODE
from typing import Union

from summary_statistic import SummaryStatistic
from detailed_statistic import DetailedStatistic

Types_ = Union[SummaryStatistic, DetailedStatistic]

class PriorityQueue(BaseQueue):
    def generate_current_password(self) -> None:
        self.current_password = f'{PRIORITY_CODE}{self.code}'

    def call_customer(self, cashier: int) -> str:
        current_customer = self.queue.pop(0)
        self.customers_served.append(current_customer)
        return f'Current customer: {current_customer}, go to cashier {cashier}'

    def statistic(self, return_statistic: Types_) -> dict:
        return return_statistic.wheel_statistic(self.customers_served)
