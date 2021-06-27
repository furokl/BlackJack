#ifndef CARDS_H
#define CARDS_H

#include <vector>

enum Card_Rank
{
	RANK_2,
	RANK_3,
	RANK_4,
	RANK_5,
	RANK_6,
	RANK_7,
	RANK_8,
	RANK_9,
	RANK_10,
	RANK_JACK,
	RANK_QUEEN,
	RANK_KING,
	RANK_ACE,
	MAX_RANKS
};

enum Card_Suit
{
	CLUB,
	HEART,
	SPADES,
	DIAMONDS,
	MAX_SUITS
};

struct Card
{
	Card_Rank rank;
	Card_Suit suit;
};

void printCard(const Card&);
void printDeck(const std::vector<Card>&);

void getCard(const std::vector<Card>&, std::vector<Card>&, size_t&);

void swapCard(Card&, Card&);
void shuffleDeck(std::vector<Card>&);

size_t randCard(size_t, size_t);


#endif // !CARDS_H