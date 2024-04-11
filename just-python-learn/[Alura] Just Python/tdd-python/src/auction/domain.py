from src.auction.exceptions import InvalidBidding


class User:
    def __init__(self, name, wallet):
        self.__name = name
        self.__wallet = wallet

    @property
    def name(self):
        return self.__name

    @property
    def wallet(self):
        return self.__wallet

    def propose_bidding(self, auction, value):
        if not self.value_is_valid(value):
            raise InvalidBidding('Não pode propor um lance com valor maior que o valor da carteira')
        bidding = Bidding(self, value)
        auction.add_bidding(bidding)

        self.__wallet -= value

    def value_is_valid(self, value):
        return value <= self.__wallet


class Bidding:
    def __init__(self, user, value):
        self.user = user
        self.value = value


class Auction:
    def __init__(self, description):
        self.description = description
        self.__biddings = []
        self.highest_bidding = 0.0
        self.lowest_bidding = 0.0

    def add_bidding(self, bidding: Bidding):
        if self.bidding_is_valid(bidding):
            if not self.have_biddings():
                self.lowest_bidding = bidding.value

            self.highest_bidding = bidding.value

            self.__biddings.append(bidding)

    @property
    def biddings(self):
        return self.__biddings[:]

    def have_biddings(self):
        return self.__biddings

    def different_users(self, bidding):
        if self.__biddings[-1].user != bidding.user:
            return True
        raise InvalidBidding('O mesmo usuário não pode dar dois lances seguidos.')

    def higher_value_than_previous_bid(self, bidding):
        if bidding.value > self.__biddings[-1].value:
            return True
        raise InvalidBidding('O valor do lance deve ser maior que o lance anterior.')

    def bidding_is_valid(self, bidding):
        return not self.have_biddings() or \
               (self.different_users(bidding) and self.higher_value_than_previous_bid(bidding))
