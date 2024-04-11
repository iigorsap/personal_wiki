import abc
from abc import ABCMeta
from typing import List, Union

from constants import MAXIMUM_STANDARD_SIZE, MINIMUM_STANDARD_SIZE
from detailed_statistic import DetailedStatistic
from summary_statistic import SummaryStatistic

Types_ = Union[SummaryStatistic, DetailedStatistic]

class BaseQueue(metaclass=ABCMeta):
    code: int = 0
    queue: List[str] = []
    customers_served: List[str] = []
    current_password: str = ''

    def reset_queue(self) -> None:
        if self.code >= MAXIMUM_STANDARD_SIZE:
            self.code = MINIMUM_STANDARD_SIZE
        else:
            self.code += 1

    def customer_insert(self):
        self.queue.append(self.current_password)

    def update_queue(self) -> None:
        self.reset_queue()
        self.generate_current_password()
        self.customer_insert()

    @abc.abstractmethod
    def call_customer(self, cashier: int) -> str:
        pass

    @abc.abstractmethod
    def generate_current_password(self) -> None:
        pass

    @abc.abstractmethod
    def statistic(self, return_statistic: Types_) -> dict:
        pass
