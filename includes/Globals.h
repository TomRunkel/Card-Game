#pragma once
#include "Cards.h"

inline std::vector<Cards::Card>* ShowDeckDeck;
inline std::vector<Cards::Card> DeckA;
inline std::vector<Cards::HandCard> DeckH;
inline std::vector<Cards::Card> Deck[COUNT_PLAYERS];
inline std::vector<Cards::Card> DiscardPile[COUNT_PLAYERS];
inline std::vector<Cards::Card> BacklineCards[COUNT_PLAYERS];
inline std::deque<Cards::Card> FrontlineCards[COUNT_PLAYERS];
inline std::vector<Cards::Card> CardsToChose;
inline std::vector<Cards::HandCard> HandCardsToChose;
inline std::vector<Cards::HandCard> HandCards[COUNT_PLAYERS];
inline int pos[COUNT_PLAYERS] = { 0, 0 };
inline int offsetFront[COUNT_PLAYERS] = { 0, 0 };
inline int offsetBack[COUNT_PLAYERS] = { 0, 0 };
inline int offsetFrontlineCards[COUNT_PLAYERS] = { 0, 0 };
inline int victoryPoints[COUNT_PLAYERS] = { 0, 0 };
inline int turn = 0;
inline bool onceChosen = false;
inline int attacker = 0;
inline int showDeckPlayer = 0;
inline int playerChoosing = 0;
inline int whichHandCard = 0;
inline int counter = ROUNDS_DRAFT_START;
inline bool flag_cavalry[COUNT_PLAYERS] = { 0, 0 };
inline bool flag_lich[COUNT_PLAYERS] = { 0, 0 };
inline bool flag_undead[COUNT_PLAYERS] = { 0, 0 };
inline bool flag_banner[COUNT_PLAYERS] = { 0, 0 };
inline bool flag_humen[COUNT_PLAYERS] = { 0, 0 };
inline bool flag_elves[COUNT_PLAYERS] = { 0, 0 };
inline bool flag_defenders = false;
inline bool flag_attacker = false;
inline bool flag_robust[COUNT_PLAYERS] = { 0, 0 };
inline int countCards[COUNT_PLAYERS] = { 0, 0 };
inline int count_goblins[COUNT_PLAYERS] = { 0, 0 };
inline int count_goblinfactor[COUNT_PLAYERS] = { 0, 0 };
inline int count_rangeHits[COUNT_PLAYERS] = { 0, 0 };
inline int count_showCards = 0;
