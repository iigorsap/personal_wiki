from unittest import TestCase

from src.auction.domain import Bidding, Auction, User
from src.auction.exceptions import InvalidBidding


class TestAuction(TestCase):

    def setUp(self):
        self.igor = User('igor', 500.0)
        self.bidding_igor = Bidding(self.igor, 150.0)
        self.auction = Auction('Celular')

    def test_should_return_the_highest_and_lowest_biddings_when_added_in_ascending_order(self):
        amanda = User('amanda', 500.0)
        bidding_amanda = Bidding(amanda, 100.0)

        self.auction.add_bidding(bidding_amanda)
        self.auction.add_bidding(self.bidding_igor)

        lowest_expected_value = 100.0
        highest_expected_value = 150.0

        self.assertEqual(lowest_expected_value, self.auction.lowest_bidding)
        self.assertEqual(highest_expected_value, self.auction.highest_bidding)

    def test_should_not_allow_add_bidding_in_descending_order(self):
        with self.assertRaises(InvalidBidding):
            amanda = User('amanda', 500.0)
            bidding_amanda = Bidding(amanda, 100.0)

            self.auction.add_bidding(self.bidding_igor)
            self.auction.add_bidding(bidding_amanda)

    def test_should_return_the_same_value_for_highest_and_lowest_bidding_when_auction_has_only_one_bidding(self):
        self.auction.add_bidding(self.bidding_igor)

        self.assertEqual(150.0, self.auction.lowest_bidding)
        self.assertEqual(150.0, self.auction.highest_bidding)

    def test_should_return_the_same_value_for_highest_and_lowest_bidding_when_auction_has_only_three_bidding(self):
        amanda = User('amanda', 500.0)
        mel = User('mel', 500.0)

        bidding_amanda = Bidding(amanda, 100.0)
        bidding_mel = Bidding(mel, 200.0)

        self.auction.add_bidding(bidding_amanda)
        self.auction.add_bidding(self.bidding_igor)
        self.auction.add_bidding(bidding_mel)

        lowest_expected_value = 100.0
        highest_expected_value = 200.0

        self.assertEqual(lowest_expected_value, self.auction.lowest_bidding)
        self.assertEqual(highest_expected_value, self.auction.highest_bidding)

    def test_should_allow_add_bidding_if_the_auction_has_no_biddings(self):
        self.auction.add_bidding(self.bidding_igor)
        qtt_biddings_received = len(self.auction.biddings)
        self.assertEqual(1, qtt_biddings_received)

    def test_should_allow_add_bidding_if_the_last_user_is_different(self):
        amanda = User('amanda', 500.0)
        bidding_amanda = Bidding(amanda, 100.0)

        self.auction.add_bidding(bidding_amanda)
        self.auction.add_bidding(self.bidding_igor)

        qtt_biddings_received = len(self.auction.biddings)
        self.assertEqual(2, qtt_biddings_received)

    def test_should_not_allow_add_bidding_if_the_last_user_is_the_same(self):
        bidding_igor_200 = Bidding(self.igor, 200.0)

        with self.assertRaises(InvalidBidding):
            self.auction.add_bidding(self.bidding_igor)
            self.auction.add_bidding(bidding_igor_200)
