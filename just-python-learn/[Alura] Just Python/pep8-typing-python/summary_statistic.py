from typing import Union, List, Dict

class SummaryStatistic:
    def __init__(self, day: str, bank_agency: int) -> None:
        self.day = day
        self.bank_agency = bank_agency

    def wheel_statistic(self, customers_served: List[str]) -> dict:
        statistic: Dict[str, Union[List[str], str, int]] = {}
        statistic[f'{self.bank_agency}-{self.day}'] = len(customers_served)
        return statistic
