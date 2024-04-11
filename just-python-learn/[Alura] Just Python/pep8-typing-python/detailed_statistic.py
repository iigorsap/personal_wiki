from typing import Union, List, Dict

class DetailedStatistic:
    def __init__(self, day: str, bank_agency: int) -> None:
        self.day = day
        self.bank_agency = bank_agency

    def wheel_statistic(self, customers_served: List[str]) -> dict:
        statistic: Dict[str, Union[List[str], str, int]] = {}
        statistic['day'] = self.day
        statistic['bank agency'] = self.bank_agency
        statistic['customers served'] = customers_served
        statistic['quantity customers served'] = len(customers_served)
        return statistic
