from typing import Union

from normal_queue import NormalQueue
from priority_queue import PriorityQueue

from constants import TYPE_NORMAL_QUEUE, TYPE_PRIORITY_QUEUE

class FactoryQueue:

    @staticmethod
    def get_queue(type_queue) -> Union[NormalQueue, PriorityQueue]:
        if type_queue == TYPE_NORMAL_QUEUE:
            return NormalQueue()
        elif type_queue == TYPE_PRIORITY_QUEUE:
            return PriorityQueue()
        else:
            raise NotImplementedError('Unregistered type')