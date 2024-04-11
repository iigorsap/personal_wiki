from normal_queue import NormalQueue
from priority_queue import PriorityQueue
from factory_queue import FactoryQueue
from summary_statistic import SummaryStatistic
from detailed_statistic import DetailedStatistic

# queue_test = NormalQueue()
# queue_test.update_queue()
# queue_test.update_queue()
# queue_test.update_queue()
# print(queue_test.call_customer(10))

# queue_test_2 = PriorityQueue()
# queue_test_2.update_queue()
# queue_test_2.update_queue()
# queue_test_2.update_queue()
# print(queue_test_2.call_customer(10))
# print(queue_test_2.call_customer(1))
# print(queue_test_2.statistic('13/10/2000', 100, 'detail'))

queue = FactoryQueue.get_queue('priority')
queue.update_queue()
queue.update_queue()
queue.update_queue()
print(queue.call_customer(10))
print(queue.statistic(SummaryStatistic('20/03/2025', 1245)))


# Mypy é um verificador de tipagem estatico, ele pesquisa
# dentro dos imports tb
