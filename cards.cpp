#include <iostream>
#include <random>

#include "cards.h"
#include "game_rule.h"

void printCard(const Card& card) {
	switch (card.rank)
	{
	case RANK_2:
		std::cout << '2';
		break;

	case RANK_3:
		std::cout << '3';
		break;

	case RANK_4:
		std::cout << '4';
		break;

	case RANK_5:
		std::cout << '5';
		break;

	case RANK_6:
		std::cout << '6';
		break;

	case RANK_7:
		std::cout << '7';
		break;

	case RANK_8:
		std::cout << '8';
		break;

	case RANK_9:
		std::cout << '9';
		break;

	case RANK_10:
		std::cout << "10";
		break;

	case RANK_JACK:
		std::cout << 'J';
		break;

	case RANK_QUEEN:
		std::cout << 'Q';
		break;

	case RANK_KING:
		std::cout << 'K';
		break;

	case RANK_ACE:
		std::cout << 'A';
		break;

	default:
		std::cout << "\n\tDEFAULT CASE: printCard (Card &)";
		std::exit(EXIT_FAILURE);
	}

	switch (card.suit)
	{
	case CLUB:
		std::cout << " <>";
		break;

	case HEART:
		std::cout << " <3";
		break;

	case SPADES:
		std::cout << " >}";
		break;

	case DIAMONDS:
		std::cout << " <>";
		break;

	default:
		std::cout << "\n\tDEFAULT CASE: printCard(Card &)";
		std::exit(EXIT_FAILURE);
	}
}
void printDeck(const std::vector<Card>& deck) {
	for (const auto& card : deck)
	{
		printCard(card);
		std::cout << ' ';
	}
	std::cout << std::endl;
}
void getCard(const std::vector<Card>& deck, std::vector<Card>& player, size_t& lengthPlayer) {
	static size_t nCard{};
	size_t dCard{ game_rule::nPlayers - 1 };
	lengthPlayer++;

	if (nCard < deck.size())
	{
		player.resize(lengthPlayer);
		player[lengthPlayer - 1] = deck[nCard];
		nCard++;
	}
}
void swapCard(Card& first, Card& second) {
	std::swap(first, second);
}
void shuffleDeck(std::vector<Card>& deck) {
	for (size_t card{}; card < game_rule::length_deck; card++)
	{
		size_t rand_card{ randCard(0, game_rule::length_deck) };
		std::swap(deck[rand_card], deck[card]);
	}
}
size_t randCard(size_t min, size_t max)
{
	std::random_device rd;
	std::mt19937 mersenne(rd());

	return mersenne() % max + min;
}