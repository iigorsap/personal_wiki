from src.auction.domain import User, Bidding, Auction, Evaluator

igor = User('igor')
amanda = User('amanda')

bidding_igor = Bidding(igor, 100.0)
bidding_amanda = Bidding(amanda, 150.0)

auction = Auction('Celular')

auction.biddings.append(bidding_amanda)
auction.biddings.append(bidding_igor)

for i in auction.biddings:
    print(f'O usuario {i.user.name} deu um lance de {i.value}')

evaluator = Evaluator()
evaluator.evaluate(auction)

print(f'O menor lance foi de {evaluator.lowest_bidding} e o maior lance foi de {evaluator.highest_bidding}')