#include <iostream>

#include "black_jack.h"
#include "game_rule.h"

void playBlackJack() {
	do
	{
		std::vector<Card> deck;
		deck.resize(game_rule::length_deck);

		size_t card{};
		for (int rank{}; rank < MAX_RANKS; rank++)
			for (int suit{}; suit < MAX_SUITS; suit++)
			{
				deck[card].rank = static_cast<Card_Rank>(rank);
				deck[card].suit = static_cast<Card_Suit>(suit);
				card++;
			}

		std::vector<Card> dealer;
		std::vector<Card> player;
		size_t lengthDealer{};
		size_t lengthPlayer{};

		shuffleDeck(deck);

		getCard(deck, dealer, lengthDealer);
		printDeck(dealer);

		getCard(deck, dealer, lengthDealer);
		getCard(deck, player, lengthPlayer);
		getCard(deck, player, lengthPlayer);
		printDeck(player);

		while (playerBlackJackChoice(deck, player, lengthPlayer))	// hit or stand
		{
			printDeck(player);

			if (getTotalCardValue(dealer) < 17)
			{
				getCard(deck, dealer, lengthDealer);
			}
		}

		while (getTotalCardValue(dealer) < 17)
		{
			getCard(deck, dealer, lengthDealer);
		}

		printBlackJackResult(dealer);
		printBlackJackResult(player);

		size_t result{};
		victoryCondition(player, dealer, result);

		std::cout << getBlackJackResult(result);

	} while (repeatBlackJack());
}
void printBlackJackResult(std::vector<Card>& player) {
	std::cout << "\nCard's:\t";
	printDeck(player);

	std::cout << "\ttotal:\t" << getTotalCardValue(player);
}

size_t getCardValue(const Card& card) {
	switch (card.rank)
	{
	case RANK_2:
		return 2;

	case RANK_3:
		return 3;

	case RANK_4:
		return 4;

	case RANK_5:
		return 5;

	case RANK_6:
		return 6;

	case RANK_7:
		return 7;

	case RANK_8:
		return 8;

	case RANK_9:
		return 9;

	case RANK_10:
		return 10;

	case RANK_JACK:
		return 10;

	case RANK_QUEEN:
		return 10;

	case RANK_KING:
		return 10;

	case RANK_ACE:
		return 11;

	default:
		std::cout << "\n\tDEFAULT CASE: getCardValue(const Card &)";
		std::exit(EXIT_FAILURE);
	}
}
size_t getTotalCardValue(const std::vector<Card>& player) {
	size_t temp{};
	for (size_t card{}; card < player.size(); card++)
	{
		temp += getCardValue(player[card]);
	}

	return temp;
}
std::string getBlackJackResult(size_t& result) {
	switch (result)
	{
	case BLACKJACK_PLAYER_WIN:
		return "\n\n\t*you winner!!! GG";

	case BLACKJACK_DEALER_WIN:
		return "\n\n\t*you looser :(";

	case BLACKJACK_DRAW:
		return "\n\n\t*nope.";

	default:
		std::cout << "\n\tDEFAULT CASE: getBlackJackResult(size_t &)";
		std::exit(EXIT_FAILURE);
	}
}

bool playerBlackJackChoice(std::vector<Card>& deck, std::vector<Card>& player, size_t& lengthPlayer) {
	std::cout << "Make a choice: hit or stand: ";
	std::string choice;
	while (true)
	{
		std::cin >> choice;
		if (choice == "hit")
		{
			getCard(deck, player, lengthPlayer);
			return true;
		}

		else if (choice == "stand")
		{
			return false;
		}

		else
		{
			std::cout << "\n!!!\tUnknown value, try again: ";
		}
	}
}
bool repeatBlackJack() {
	std::cout << "\nDo you want to play again? (y / n): ";
	while (true)
	{
		char repeat;
		std::cin >> repeat;
		if (repeat == 'y')
		{
			return true;
		}

		else if (repeat == 'n')
		{
			return false;
		}

		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\n!!!\tUnknown value, try again: ";
		}
	}
}

void victoryCondition(const std::vector<Card>& player, const std::vector<Card>& dealer, size_t& result) {
	bool max_value_condition((getTotalCardValue(player) <= game_rule::max_value) && (getTotalCardValue(dealer) <= (game_rule::max_value)));
	bool max_value_condition_player((getTotalCardValue(player) <= game_rule::max_value));
	bool max_value_condition_dealer((getTotalCardValue(dealer) <= game_rule::max_value));

	if (max_value_condition && (getTotalCardValue(player) > getTotalCardValue(dealer)))
	{
		result = BLACKJACK_PLAYER_WIN;
	}

	else if (max_value_condition && (getTotalCardValue(dealer) > getTotalCardValue(player)))
	{
		result = BLACKJACK_DEALER_WIN;
	}

	else if (max_value_condition && (getTotalCardValue(player) == getTotalCardValue(dealer)))
	{
		result = BLACKJACK_DRAW;
	}

	else if (max_value_condition_player && (!max_value_condition_dealer))
	{
		result = BLACKJACK_PLAYER_WIN;
	}

	else if (max_value_condition_dealer && (!max_value_condition_player))
	{
		result = BLACKJACK_DEALER_WIN;
	}

	else if (!max_value_condition_player && (!max_value_condition_dealer))
	{
		result = BLACKJACK_DRAW;
	}
}