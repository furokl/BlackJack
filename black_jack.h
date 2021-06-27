#ifndef BLACK_JACK_H
#define BLACK_JACK_H

#include <string>

#include "cards.h"
// + include <vector>

void playBlackJack();

enum Black_Jack_Result
{
	BLACKJACK_PLAYER_WIN,
	BLACKJACK_DEALER_WIN,
	BLACKJACK_DRAW
};

void printBlackJackResult(std::vector<Card>&);

size_t getCardValue(const Card&);
size_t getTotalCardValue(const std::vector<Card>&);
std::string getBlackJackResult(size_t&);

bool playerBlackJackChoice(std::vector<Card>&, std::vector<Card>&, size_t&);
bool repeatBlackJack();

void victoryCondition(const std::vector<Card>&, const std::vector<Card>&, size_t&);

#endif // !BLACK_JACK_H

