# def statistic(self, day: str, bank_agency: int, flag: str):
#     statistic: Dict[str, Union[List[str], str, int]] = {}
#     if flag != 'detail':
#         statistic[f'{bank_agency}-{day}'] = len(self.customers_served)
#     else:
#         statistic['day'] = day
#         statistic['bank agency'] = bank_agency
#         statistic['customers served'] = self.customers_served
#         statistic['quantity customers served'] = len(self.customers_served)
#         return statistic
