from src.auction.domain import User, Auction
import pytest

from src.auction.exceptions import InvalidBidding


@pytest.fixture
def igor():
    return User('Igor', 100.0)

@pytest.fixture
def auction():
    return Auction('Celular')

def test_must_subtract_value_from_the_user_wallet_when_add_bidding(igor, auction):
    igor.propose_bidding(auction, 50.0)
    assert igor.wallet == 50.0

def test_must_permitted_add_bidding_when_the_value_is_lower_than_the_value_is_wallet(igor, auction):
    igor.propose_bidding(auction, 1.0)
    assert igor.wallet == 99.0

def test_must_permitted_add_bidding_when_the_value_is_same_than_the_value_is_wallet(igor, auction):
    igor.propose_bidding(auction, 100.0)
    assert igor.wallet == 0.0

def test_must_permitted_add_bidding_when_the_value_is_higher_than_the_value_is_wallet(igor, auction):
    with pytest.raises(InvalidBidding):
        igor.propose_bidding(auction, 200.0)