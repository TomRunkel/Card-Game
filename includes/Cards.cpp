#include <iostream>
#include <string>
#include <cstdio>
#include <windows.h>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <random>
#include "Cards.h"
#include "Globals.h"
#include "../MyForm.h"
#include "DeckView.h"
#include "CardView.h"

namespace Cards
{
	bool Card::operator==(Card card)
	{
		return name == card.name;
	}
	bool Card::operator<(Card card) 
	{
		return name < card.name;
	}
	Card& Card::addTraits(std::string traits)
	{
		this->traits = traits;
		return *this;
	}

	std::string Card::writeType(int type)
	{
		std::string identifierType;
		switch (type)
		{
		case 1:
			identifierType = "Front";
			break;
		case 2:
			identifierType = "Hintergrund";
			break;
		default:
			identifierType = "unbekannt";
			break;
		}
		return identifierType;
	}
	 
	std::string Card::writeSkill(int skill)
	{
		switch (skill)
		{
		case 1:
			return NAME_SKILL1 ;
		case 2:
			return NAME_SKILL2;
		case 3:
			return NAME_SKILL3;
		case 4:
			return NAME_SKILL4;
		case 5:
			return NAME_SKILL5;
		case 6:
			return NAME_SKILL6;
		case 7:
			return NAME_SKILL7 ;
		case 8:
			return NAME_SKILL8;
		case 9:
			return NAME_SKILL9;
		case 10:
			return NAME_SKILL10;
		case 11:
			return NAME_SKILL11;
		case 12:
			return NAME_SKILL12;
		case 13:
			return NAME_SKILL13;
		case 14:
			return NAME_SKILL14;
		case 15:
			return NAME_SKILL15;
		case 16:
			return NAME_SKILL16;
		case 17:
			return NAME_SKILL17;
		case 18:
			return NAME_SKILL18;
		case 19:
			return NAME_SKILL19;
		default:
			return "";
		}
	}

	Card::Card() :
		name("unbekannt"),
		strength(0),
		type(0),
		skill(0),
		skill2(0)
	{}

	Card::Card(std::string name, int strength, int type) :
		name(name),
		strength(strength),
		type(type),
		skill(0),
		skill2(0)
	{}

	Card::Card(std::string name, int strength, int type, int skill) :
		name(name),
		strength(strength),
		type(type),
		skill(skill),
		skill2(0)
	{}

	Card::Card(std::string name, int strength, int type, int skill, int skill2) :
		name(name),
		strength(strength),
		type(type),
		skill(skill),
		skill2(skill2)
	{}

	HandCard::HandCard(std::string name, std::string effect) :
		name(name),
		effect(effect)
	{}

	void eraseCard(std::vector<Card>& Deck, Card card)
	{
		auto iterator = std::find(Deck.begin(), Deck.end(), card);
		if (iterator != Deck.end())
		{
			Deck.erase(iterator);
		}
	}

	void shuffleDeck(std::vector<Card>& Deck, int offsetFront, int offsetBack)
	{
		std::random_device rd;
		std::shuffle(Deck.begin() + offsetFront, Deck.end() - offsetBack, rd);
	}

	void shuffleDeckHandCards(std::vector<HandCard>& Deck)
	{
		std::random_device rd;
		std::shuffle(Deck.begin(), Deck.end(), rd);
	}

	void updateScore()
	{
		int score[COUNT_PLAYERS] = { 0, 0 };
		bool firstVisible[COUNT_PLAYERS] = { true, true };
		for (int j = 0; j < COUNT_PLAYERS; j++)
		{
			countCards[j] = 0;
			count_goblinfactor[j] = 0;
			flag_undead[j] = false;
			flag_robust[j] = false;
			flag_cavalry[j] = false;
			flag_humen[j] = false;
			flag_elves[j] = false;
			flag_lich[j] = false;
		}
		for (int j = 0; j < COUNT_PLAYERS; j++)
		{
			for (int i = 0; i < MAX_CARDS_BACKLINE; i++)
			{
				if (Cards::Controls::cardPanelsBackline[j, i]->Visible == true)
				{
					if (Cards::Controls::cardskillsBackline[j, i]->Text == NAME_SKILL9 || Cards::Controls::cardskill2sBackline[j, i]->Text == NAME_SKILL9)								// Elfenschützen
						Cards::Controls::cardstrengthsBackline[j, i]->Text = discardSearch(j, true, NAME_TRAIT7).ToString();
					if (Cards::Controls::cardskillsBackline[j, i]->Text == NAME_SKILL7 || Cards::Controls::cardskill2sBackline[j, i]->Text == NAME_SKILL7) count_goblinfactor[j] += 2;	// Orktreiber
					if (Cards::Controls::cardskillsBackline[j, i]->Text == NAME_SKILL14 || Cards::Controls::cardskill2sBackline[j, i]->Text == NAME_SKILL14) flag_lich[j] = true;		// Lich
				}
			}
		}
		for (int j = 0; j < COUNT_PLAYERS; j++)
		{
			for (int i = 0; i < MAX_CARDS_FRONTLINE; i++)
			{
				if (Cards::Controls::cardPanels[j, i]->Visible == true)
				{
					countCards[j]++; 
					if (FrontlineCards[j].at(i).traits.find(NAME_TRAIT3) != std::string::npos) flag_robust[j] = true;													// robust
					if (FrontlineCards[j].at(i).traits.find(NAME_TRAIT2) != std::string::npos) flag_cavalry[j] = true;													// Kavalerie
					if (FrontlineCards[j].at(i).traits.find(NAME_TRAIT1) != std::string::npos) flag_humen[j] = true;													// Mensch
					if (FrontlineCards[j].at(i).traits.find(NAME_TRAIT7) != std::string::npos) flag_elves[j] = true;													// Elf
					if (FrontlineCards[j].at(i).traits.find(NAME_TRAIT6) != std::string::npos) flag_undead[j] = true;													// untot
					if (Cards::Controls::cardskills[j, i]->Text == NAME_SKILL6 || Cards::Controls::cardskill2s[j, i]->Text == NAME_SKILL6) count_goblinfactor[j]++;		// Goblinhorde
					if (Cards::Controls::cardskills[j, i]->Text == NAME_SKILL7 || Cards::Controls::cardskill2s[j, i]->Text == NAME_SKILL7) count_goblinfactor[j] += 2;	// Goblinboss
				}
			}
		}
		for (int j = 0; j < COUNT_PLAYERS; j++)
		{
			for (int i = 0; i < MAX_CARDS_FRONTLINE; i++)
			{
				if (Cards::Controls::cardPanels[j, i]->Visible == true)
				{
					Cards::Controls::cardstrengths[j, i]->Text = (FrontlineCards[j].at(i).strength).ToString();

					if (flag_robust[1 - j] && (Cards::Controls::cardskills[j, i]->Text == NAME_SKILL5 || Cards::Controls::cardskill2s[j, i]->Text == NAME_SKILL5))		// Durschlagskraft
						Cards::Controls::cardstrengths[j, i]->Text = (FrontlineCards[j].at(i).strength * 2).ToString();
					if (flag_cavalry[1 - j] && (Cards::Controls::cardskills[j, i]->Text == NAME_SKILL4 || Cards::Controls::cardskill2s[j, i]->Text == NAME_SKILL4))		// Speere
						Cards::Controls::cardstrengths[j, i]->Text = (FrontlineCards[j].at(i).strength * 2).ToString();
					if (flag_undead[j] == false && flag_undead[1 - j] && (Cards::Controls::cardskills[j, i]->Text == NAME_SKILL16 || Cards::Controls::cardskill2s[j, i]->Text == NAME_SKILL16))	// Mönche
						Cards::Controls::cardstrengths[j, i]->Text = (FrontlineCards[j].at(i).strength + 4).ToString();
					if (attacker == j  && (Cards::Controls::cardskills[j, i]->Text == NAME_SKILL3 || Cards::Controls::cardskill2s[j, i]->Text == NAME_SKILL3))			// Ansturm
						Cards::Controls::cardstrengths[j, i]->Text = (FrontlineCards[j].at(i).strength * 2).ToString();
					if (FrontlineCards[j].at(i).traits.find(NAME_TRAIT4) != std::string::npos)																			// Goblin
						Cards::Controls::cardstrengths[j, i]->Text = (count_goblinfactor[j] / 2).ToString();
					if (Cards::Controls::cardskills[j, i]->Text == NAME_SKILL2 || Cards::Controls::cardskill2s[j, i]->Text == NAME_SKILL2)								// Masseneuphorie
						Cards::Controls::cardstrengths[j, i]->Text = (FrontlineCards[j].at(i).strength + countCards[j]).ToString();
					if (Cards::Controls::cardskills[j, i]->Text == NAME_SKILL19 || Cards::Controls::cardskill2s[j, i]->Text == NAME_SKILL19)							// Blutdurst
						Cards::Controls::cardstrengths[j, i]->Text = (FrontlineCards[j].at(i).strength + countCards[1 - j]).ToString();
					if (Cards::Controls::cardskills[j, i]->Text == NAME_SKILL18 || Cards::Controls::cardskill2s[j, i]->Text == NAME_SKILL18)							// Hass
						Cards::Controls::cardstrengths[j, i]->Text = (FrontlineCards[j].at(i).strength + flag_humen[1 - j] * 2 + flag_elves[1 - j] * 2).ToString();
					if (Cards::Controls::cardskills[j, i]->Text == NAME_SKILL12 || Cards::Controls::cardskill2s[j, i]->Text == NAME_SKILL12)							// Skelettkrieger
					{
						if (flag_lich[j])
							Cards::Controls::cardstrengths[j, i]->Text = max(maxStrength(DiscardPile[1 - j]), maxStrength(DiscardPile[j])).ToString();
						else
							Cards::Controls::cardstrengths[j, i]->Text = maxStrength(DiscardPile[1 - j]).ToString();
					}
					if (Cards::Controls::cardskills[j, i]->Text == NAME_SKILL9 || Cards::Controls::cardskill2s[j, i]->Text == NAME_SKILL9)								// Elfen
						Cards::Controls::cardstrengths[j, i]->Text = (FrontlineCards[j].at(i).strength + discardSearch(j, true, NAME_TRAIT7)).ToString();
					if (Cards::Controls::cardskills[j, i]->Text == NAME_SKILL8 || Cards::Controls::cardskill2s[j, i]->Text == NAME_SKILL8)								// Ghule
						Cards::Controls::cardstrengths[j, i]->Text = (FrontlineCards[j].at(i).strength
							+ (discardSearch(1 - j, false, NAME_TRAIT1) | (flag_lich[j] & (bool)discardSearch(j, false, NAME_TRAIT1)))
							+ (discardSearch(1 - j, false, NAME_TRAIT4) | (flag_lich[j] & (bool)discardSearch(j, false, NAME_TRAIT4)))
							+ (discardSearch(1 - j, false, NAME_TRAIT5) | (flag_lich[j] & (bool)discardSearch(j, false, NAME_TRAIT5)))
							+ (discardSearch(1 - j, false, NAME_TRAIT7) | (flag_lich[j] & (bool)discardSearch(j, false, NAME_TRAIT7)))
							+ (discardSearch(1 - j, false, NAME_TRAIT9) | (flag_lich[j] & (bool)discardSearch(j, false, NAME_TRAIT9)))).ToString();
					Cards::Controls::cardstrengths[j, i]->Text = (System::Convert::ToInt16(Cards::Controls::cardstrengths[j, i]->Text) + flag_banner[j]).ToString();	// Banner
					if (firstVisible[j])																																	// Fernkampf (always last!)
					{
						Cards::Controls::cardstrengths[j, i]->Text = (System::Convert::ToInt16(Cards::Controls::cardstrengths[j, i]->Text) - count_rangeHits[j]).ToString();
						firstVisible[j] = false;
					}

					score[j] += System::Convert::ToInt16(Cards::Controls::cardstrengths[j, i]->Text);
				}
			}
			Cards::Controls::score[j]->Text = score[j].ToString();
			Cards::Controls::cardsRemain[j]->Text = (Deck[j].size() - pos[j]).ToString();

		}
	}

	void updatePiles()
	{
		updateScore();
		highlightUseableCards();
		for (int j = 0; j < COUNT_PLAYERS; j++)
		{
			for (int i = 0; i < Deck[j].size(); i++)
			{
				if (i < pos[j])
					Cards::Controls::backPanels[j, i]->Visible = false;
				else
					Cards::Controls::backPanels[j, i]->Visible = true;
				if (i < DiscardPile[j].size())
				{
					Cards::Controls::cardnamesDiscard[j, i]->Text = gcnew System::String(DiscardPile[j].back().name.data());
					Cards::Controls::cardstrengthsDiscard[j, i]->Text = DiscardPile[j].back().strength.ToString();
					Cards::Controls::cardskillsDiscard[j, i]->Text = gcnew System::String(DiscardPile[j].back().writeSkill(DiscardPile[j].back().skill).data());
					Cards::Controls::cardskill2sDiscard[j, i]->Text = gcnew System::String(DiscardPile[j].back().writeSkill(DiscardPile[j].back().skill2).data());
					Cards::Controls::cardtraitsDiscard[j, i]->Text = gcnew System::String(DiscardPile[j].back().traits.data());
					Cards::Controls::cardPanelsDiscard[j, i]->Visible = true;
				}
				else
					Cards::Controls::cardPanelsDiscard[j, i]->Visible = false;
			}
			(j == 0) ? Cards::Controls::cardsRemain[j]->Location = System::Drawing::Point(204 - 2 * (pos[j] + 1), 215 + 2 * (pos[j] + 1))
				: Cards::Controls::cardsRemain[j]->Location = System::Drawing::Point(1603 + 2 * (pos[j] + 1), 215 + 2 * (pos[j] + 1));
		}
	}

	int drawCard(int player)
	{
		if (pos[player] == Deck[player].size()) return -1;
		switch (Deck[player].at(pos[player]).type)
		{
		case 1:
			flag_attacker = true;
			for (int i = 0; i < MAX_CARDS_FRONTLINE; i++)
			{
				if (Cards::Controls::cardPanels[player, i]->Visible == true) continue;
				else
				{
					FrontlineCards[player].push_back(Deck[player][pos[player]]);
					Cards::Controls::cardnames[player, i]->Text = gcnew System::String(Deck[player][pos[player]].name.data());								//convert std::string into System::String
					Cards::Controls::cardstrengths[player, i]->Text = Deck[player][pos[player]].strength.ToString();
					Cards::Controls::cardskills[player, i]->Text = gcnew System::String(Deck[player][pos[player]].writeSkill(Deck[player][pos[player]].skill).data());
					Cards::Controls::cardskill2s[player, i]->Text = gcnew System::String(Deck[player][pos[player]].writeSkill(Deck[player][pos[player]].skill2).data());
					Cards::Controls::cardtraits[player, i]->Text = gcnew System::String(Deck[player][pos[player]].traits.data());
					Cards::Controls::cardPanels[player, i]->Visible = true;
					Cards::Controls::cardPanels[player, i]->BringToFront();
					pos[player]++;
					if (player == attacker && Deck[player][pos[player] - 1].skill == 15 || Deck[player][pos[player] - 1].skill2 == 15)						// Anführer
					{
						drawCard(player);
						drawCard(player);
					}
					if (player == attacker && Deck[player][pos[player] - 1].skill == 1 || Deck[player][pos[player] - 1].skill2 == 1)						// Gemeinsamer Angriff
						drawCard(player);
					updatePiles();
					return i;
				}
			}
			break;
			break;
		case 2:
			for (int i = 0; i < MAX_CARDS_BACKLINE; i++)
			{
				if (Cards::Controls::cardPanelsBackline[player, i]->Visible == true) continue;
				else
				{
					BacklineCards[player].push_back(Deck[player][pos[player]]);
					Cards::Controls::cardnamesBackline[player, i]->Text = gcnew System::String(Deck[player][pos[player]].name.data());
					Cards::Controls::cardstrengthsBackline[player, i]->Text = Deck[player][pos[player]].strength.ToString();
					if (Deck[player][pos[player]].strength == 0)
						Cards::Controls::cardstrengthsBackline[player, i]->Visible = false;
					else
						Cards::Controls::cardstrengthsBackline[player, i]->Visible = true;
					Cards::Controls::cardskillsBackline[player, i]->Text = gcnew System::String(Deck[player][pos[player]].writeSkill(Deck[player][pos[player]].skill).data());
					Cards::Controls::cardskill2sBackline[player, i]->Text = gcnew System::String(Deck[player][pos[player]].writeSkill(Deck[player][pos[player]].skill2).data());
					Cards::Controls::cardtraitsBackline[player, i]->Text = gcnew System::String(Deck[player][pos[player]].traits.data());
					Cards::Controls::cardPanelsBackline[player, i]->Visible = true;
					Cards::Controls::cardPanelsBackline[player, i]->BringToFront();
					(player == 0) ? Cards::Controls::cardsRemain[player]->Location = System::Drawing::Point(204 - 2 * (pos[player] + 1), 243 + 2 * (pos[player] + 1))
								  : Cards::Controls::cardsRemain[player]->Location = System::Drawing::Point(1603 + 2 * (pos[player] + 1), 243 + 2 * (pos[player] + 1));
					pos[player]++;
					updatePiles();
					if (whichHandCard != 6) return drawCard(player);			//Karte wird verdoppelt whichhandcard6?!?!?!?
					return i;
				}
			}
			break;
		}
		return -2;
	}

	void clearFrontline()
	{
		flag_defenders = false;
		flag_attacker = false;
		for (int j = 0; j < COUNT_PLAYERS; j++)
		{
			count_rangeHits[j] = 0;
			flag_banner[j] = 0;
			for (int i = 0; i < MAX_CARDS_FRONTLINE; i++)
			{
				if (i < offsetFrontlineCards[j])
				{
					FrontlineCards[j].pop_front();
				}
				if (Cards::Controls::cardPanels[j, i]->Visible == true)
				{
					DiscardPile[j].push_back(FrontlineCards[j].front());
					FrontlineCards[j].pop_front();
					Cards::Controls::cardPanels[j, i]->Visible = false;
				}
			}
			for (int i = 0; i < MAX_CARDS_BACKLINE; i++)
			{
				if (Cards::Controls::cardPanelsBackline[j, i]->Visible == true)
				{
					if (Cards::Controls::cardskillsBackline[j, i]->Text == NAME_SKILL7 || Cards::Controls::cardskill2sBackline[j, i]->Text == NAME_SKILL7)
						count_goblinfactor[j] += 2;
				}
			}
			offsetFrontlineCards[j] = 0;
		}
		updatePiles();
	}

	void clearBackline()
	{
		for (int j = 0; j < COUNT_PLAYERS; j++)
		{
			for (int i = 0; i < MAX_CARDS_BACKLINE; i++)
			{
				if (Cards::Controls::cardPanelsBackline[j, i]->Visible == true)
				{
					DiscardPile[j].push_back(BacklineCards[j].back());
					BacklineCards[j].pop_back();
					Cards::Controls::cardPanelsBackline[j, i]->Visible = false;
				}
			}
		}
		updatePiles();
	}

	void gameOver(int winner)
	{
		phase = 13;
		highlightUseableCards();
		if (winner >= 0)
		{
			victoryPoints[winner]++;
			flag_winner = true;
		}
		(winner >= 0) ? playerChoosing = winner : playerChoosing = 1 - playerChoosing;
		System::String^ stringPart;
		System::String^ message;
		if (winner == 1) stringPart = "Rechter";
		else if (winner == 0) stringPart = "Linker";
		else if (winner == -1)
		{
			message = "Unentschieden!";
			Cards::Controls::button1->Text = "Nächste Runde";
			CardGame::MessageBox::Show(message);
			return;
		}
		int i;
		for (i = 0; i < MAX_VICTORY_POINTS; i++)
		{
			if (Cards::Controls::pictureBoxes[winner, i]->Visible == false)
			{
				(Cards::Controls::pictureBoxes[winner, i]->Visible = true);
				break;
			}
		}
		if (i == 10)
		{
			message = System::String::Concat(stringPart, " Spieler gewinnt das Spiel!\n Herzlichen Glückwunsch!");
			Cards::Controls::button1->Text = "";
		}
		else 
		{
			message = System::String::Concat(stringPart, " Spieler gewinnt!");
			Cards::Controls::button1->Text = "Nächste Runde";
		}
		CardGame::MessageBox::Show(message);
	}

	void gameRestart()
	{
		clearFrontline();
		clearBackline();
		attacker = 0;
		turn = 0;
		for (int j = 0; j < COUNT_PLAYERS; j++)
		{
			offsetFront[j] = 0;
			offsetBack[j] = 0;
			pos[j] = 0;
			Cards::shuffleDeck(Deck[j], offsetFront[j], offsetBack[j]);
			for (auto& element : DiscardPile[j])
				DiscardPile[j].pop_back();
		}
		updatePiles();
	}

	int discardSearch(int player, bool sumAll, std::string trait)
	{
		int value = 0;
		bool found1 = false;
		bool found2 = false;
		bool found3 = false;
		bool found4 = false;
		if (sumAll == false)
		{
			for (int i = 0; i < DiscardPile[player].size(); i++)
			{
				if (DiscardPile[player].at(i).traits.find(trait) != std::string::npos) return 1;
			}
		}
		else
		{
			for (int i = 0; i < DiscardPile[player].size(); i++)
			{
				if (DiscardPile[player].at(i).traits.find(trait) != std::string::npos) value++;
			}
		}
		return value;
	}

	void draftCard(std::vector<Card> &Deck)
	{
		Cards::Controls::button1->Text = counter.ToString();
		if (playerChoosing == 0)
		{
			Cards::Controls::messageLabel[playerChoosing]->Text = LEFT_CHOOSE;
		}
		else
		{
			Cards::Controls::messageLabel[playerChoosing]->Text = RIGHT_CHOOSE;
		}
		Cards::Controls::messageLabel[1 - playerChoosing]->Text = "";
		shuffleDeck(Deck, 0, 0);
		for (int i = 0; i < MAX_CARDSTOCHOSE; i++)
		{
			Cards::Controls::cardSelectionNames[i]->Text = gcnew System::String(Deck.back().name.data());								//convert std::string into System::String
			Cards::Controls::cardSelectionStrengths[i]->Text = Deck.back().strength.ToString();
			Cards::Controls::cardSelectionSkills[i]->Text = gcnew System::String(Deck.back().writeSkill(Deck.back().skill).data());
			Cards::Controls::cardSelectionSkills[i]->Size = System::Drawing::Size(178, 62);
			Cards::Controls::cardSelectionSkill2s[i]->Text = gcnew System::String(Deck.back().writeSkill(Deck.back().skill2).data());
			Cards::Controls::cardSelectionTraits[i]->Text = gcnew System::String(Deck.back().traits.data());
			switch (Deck.back().type)
			{
			case 1:
				Cards::Controls::cardSelectionPanels[i]->BackColor = System::Drawing::Color::COLOR_TYP1;
				break;
			case 2:
				Cards::Controls::cardSelectionPanels[i]->BackColor = System::Drawing::Color::COLOR_TYP2;
				break;
			}
			Cards::Controls::cardSelectionPanels[i]->Visible = true;
			Cards::Controls::cardSelectionPanels[i]->BringToFront();
			CardsToChose.push_back(Deck.back());
			Deck.pop_back();
		}
		//**************************************
		//if (playerChoosing == 1) randompick(1, 0, 4);
		//**************************************
	}

	void draftHandCard(std::vector<HandCard> &Deck)
	{
		counter = 1;
		Cards::Controls::button1->Text = counter.ToString();
		if (1 - playerChoosing == 0)
		{
			Cards::Controls::messageLabel[1 - playerChoosing]->Text = LEFT_CHOOSE_HANDCARD;
		}
		else
		{
			Cards::Controls::messageLabel[1 - playerChoosing]->Text = RIGHT_CHOOSE_HANDCARD;
		}
		Cards::Controls::messageLabel[playerChoosing]->Text = "";
		shuffleDeckHandCards(Deck);
		for (int i = 0; i < MAX_HANDCARDSTOCHOSE; i++)
		{
			Cards::Controls::cardSelectionNames[i]->Text = gcnew System::String(Deck.back().name.data());
			Cards::Controls::cardSelectionSkills[i]->Text = gcnew System::String(Deck.back().effect.data());
			Cards::Controls::cardSelectionSkills[i]->Size = System::Drawing::Size(178, 130);
			Cards::Controls::cardSelectionSkills[i]->BringToFront();
			Cards::Controls::cardSelectionStrengths[i]->Text = "";
			Cards::Controls::cardSelectionSkill2s[i]->Text = "";
			Cards::Controls::cardSelectionTraits[i]->Text = "";
			Cards::Controls::cardSelectionPanels[i]->BackColor = System::Drawing::Color::COLOR_TYP3;
			Cards::Controls::cardSelectionPanels[i]->Visible = true;
			Cards::Controls::cardSelectionPanels[i]->BringToFront();
			HandCardsToChose.push_back(Deck.back());
			Deck.pop_back();
		}
	}

	void draftCardOver(std::vector<Card> &DeckofCards)
	{
		for (int i = 0; i < COUNT_PLAYERS; i++)
		{
			Cards::Controls::messageLabel[i]->Text = "";
		}
		for (int i = 0; i < MAX_CARDSTOCHOSE; i++)
		{
			if (Cards::Controls::cardSelectionPanels[i]->Visible == false) continue;
			Cards::Controls::cardSelectionPanels[i]->Visible = false;
			DeckofCards.push_back(CardsToChose.back());
			CardsToChose.pop_back();
		}
	}

	void draftHandCardOver(std::vector<HandCard> &DeckofCards)
	{
		for (int i = 0; i < COUNT_PLAYERS; i++)
		{
			Cards::Controls::messageLabel[i]->Text = "";
		}
		for (int i = 0; i < MAX_HANDCARDSTOCHOSE; i++)
		{
			if (Cards::Controls::cardSelectionPanels[i]->Visible == false) continue;
			Cards::Controls::cardSelectionPanels[i]->Visible = false;
			DeckofCards.push_back(HandCardsToChose.back());
			HandCardsToChose.pop_back();
		}
	}

	void chooseCard(int chosenCard)
	{
		if (chosenCard < MAX_CARDSTOCHOSE) // Drafting Phase
			chooseCardDraft(chosenCard);
		else if (chosenCard < MAX_CARDSTOCHOSE + COUNT_PLAYERS * MAX_CARDS_BACKLINE) // Backline Cards
		{
			int player = (chosenCard - MAX_CARDSTOCHOSE) / MAX_CARDS_BACKLINE;
			int card = (chosenCard - MAX_CARDSTOCHOSE) % MAX_CARDS_BACKLINE;
			chooseCardBackline(player, card);
		}
		else if (chosenCard < MAX_CARDSTOCHOSE + COUNT_PLAYERS * (MAX_CARDS_BACKLINE + MAX_HANDCARDS)) // Handcards
		{
			int player = ((chosenCard - MAX_CARDSTOCHOSE) - COUNT_PLAYERS * MAX_CARDS_BACKLINE) / MAX_HANDCARDS;
			int card = ((chosenCard - MAX_CARDSTOCHOSE) - COUNT_PLAYERS * MAX_CARDS_BACKLINE) % MAX_HANDCARDS;
			chooseCardHand(player, card);
		}
		updateScore();

		//**************************************
		//if (playerChoosing == 1 && !(counter == 0 && onceChosen == false))
		//	randompick(1, 0, 4);
		//**************************************
	}

	void chooseCardHandCard3(int chosenCard)
	{
		std::rotate(Deck[showDeckPlayer].begin(), Deck[showDeckPlayer].begin() + (1 - chosenCard)+1, Deck[showDeckPlayer].end());
	}

	void chooseCardDraft(int chosenCard)
	{
		if (HandCardsToChose.size() > 0)		// Drafting Handcards
		{
			chooseHandCardDraft(chosenCard);
			return;
		}

		Cards::Controls::button1->Text = counter.ToString();			//Draftíng DeckCards
		Deck[playerChoosing].push_back(CardsToChose.at(chosenCard));
		Cards::Controls::backPanels[playerChoosing, Deck[playerChoosing].size() - 1]->Visible = true;
		Cards::Controls::backPanels[playerChoosing, Deck[playerChoosing].size() - 1]->SendToBack();
		Cards::Controls::cardSelectionPanels[chosenCard]->Visible = false;
		static int firstCard;
		onceChosen = 1 - onceChosen;
		if (onceChosen == true) firstCard = chosenCard;
		playerChoosing = 1 - playerChoosing;
		if (playerChoosing == 0)
		{
			Cards::Controls::messageLabel[playerChoosing]->Text = LEFT_CHOOSE;
			Cards::Controls::messageLabel[1 - playerChoosing]->Text = "";
		}
		else
		{
			Cards::Controls::messageLabel[playerChoosing]->Text = RIGHT_CHOOSE;
			Cards::Controls::messageLabel[1 - playerChoosing]->Text = "";
		}
		if (onceChosen == false)
		{
			CardsToChose.erase(CardsToChose.begin() + max(firstCard, chosenCard));
			CardsToChose.erase(CardsToChose.begin() + min(firstCard, chosenCard));
			playerChoosing = 1 - playerChoosing;
			counter--;
			draftCardOver(DeckA);
			if (counter > 0) draftCard(DeckA);
			if (counter <= 0)
			{
				phase = 20;
				for (int j = 0; j < COUNT_PLAYERS; j++)
					std::sort(Deck[j].begin(), Deck[j].end(), SortCards());
				Cards::Controls::button1->Enabled = true;
				Cards::Controls::button1->Text = "Decks mischen";
				highlightUseableCards();
				if (attacker == 0)
				{
					Cards::Controls::messageLabel[attacker]->Text = LEFT_ATTACK;
					Cards::Controls::messageLabel[1 - attacker]->Text = "";
				}
				else
				{
					Cards::Controls::messageLabel[attacker]->Text = RIGHT_ATTACK;
					Cards::Controls::messageLabel[1 - attacker]->Text = "";
				}
			}
		}
	}

	void chooseHandCardDraft(int chosenCard)
	{
		Cards::Controls::button1->Text = counter.ToString();
		HandCards[1 - playerChoosing].push_back(HandCardsToChose.at(chosenCard));
		HandCardsToChose.erase(HandCardsToChose.begin() + chosenCard);
		Cards::Controls::cardSelectionPanels[chosenCard]->Visible = false;
		showHandCards();
		counter--;
		draftHandCardOver(DeckH);
		if (counter > 0) draftHandCard(DeckH);
		if (counter <= 0)
		{
			flag_winner = false;
			Cards::Controls::button1->Enabled = true;
			Cards::Controls::button1->Text = "Draft";
		}
}

	void chooseCardBackline(int player, int card)
	{
		if (Cards::Controls::cardPanelsBackline[player, card]->BackColor == System::Drawing::Color::COLOR_TYP2) return;
		if (flag_banner[player] == false && flag_attacker == false && (Cards::Controls::cardskillsBackline[player, card]->Text == NAME_SKILL17 || Cards::Controls::cardskill2sBackline[player, card]->Text == NAME_SKILL17))  // Banner
		{
			flag_banner[player] = true;
			Cards::Controls::cardPanelsBackline[player, card]->Visible = false;
			return;
		}
		if ((Cards::Controls::cardskillsBackline[player, card]->Text == NAME_SKILL10 || Cards::Controls::cardskill2sBackline[player, card]->Text == NAME_SKILL10) && Deck[1 - player].size() != pos[1 - player])  // Katapult
		{
			DiscardPile[1 - player].push_back(Deck[1 - player].at(pos[1 - player]));
			Cards::Controls::cardPanelsBackline[player, card]->Visible = false;
			DiscardPile[player].push_back(BacklineCards[player].at(card));
			pos[1 - player]++;
			updatePiles();
			return;
		}
		if ((Cards::Controls::cardskillsBackline[player, card]->Text == NAME_SKILL13 || Cards::Controls::cardskillsBackline[player, card]->Text == NAME_SKILL11
			|| Cards::Controls::cardskill2sBackline[player, card]->Text == NAME_SKILL13 || Cards::Controls::cardskill2sBackline[player, card]->Text == NAME_SKILL11)
			&& player == 1 - attacker && flag_defenders == false)																		// Fernkampf
		{
			for (int i = 0; i < MAX_CARDS_FRONTLINE; i++)
			{
				if (Cards::Controls::cardPanels[1 - player, i]->Visible == true)
				{
					count_rangeHits[1 - player] += System::Convert::ToInt16(Cards::Controls::cardstrengthsBackline[player, card]->Text);
					updateScore();
					if (System::Convert::ToInt16(Cards::Controls::cardstrengths[1 - player, i]->Text) <= 0 || Cards::Controls::cardskillsBackline[player, card]->Text == NAME_SKILL11
						|| Cards::Controls::cardskill2sBackline[player, card]->Text == NAME_SKILL11)
					{
						Cards::Controls::cardPanels[1 - player, i]->Visible = false;
						DiscardPile[1 - player].push_back(FrontlineCards[1 - player].at(offsetFrontlineCards[1 - player]));
						if (FrontlineCards[1 - player].at(offsetFrontlineCards[1 - player]).skill == 6 || FrontlineCards[1 - player].at(offsetFrontlineCards[1 - player]).skill2 == 6)
							count_goblinfactor[1 - player]--;
						if (FrontlineCards[1 - player].at(offsetFrontlineCards[1 - player]).skill == 7 || FrontlineCards[1 - player].at(offsetFrontlineCards[1 - player]).skill2 == 7)
							count_goblinfactor[1 - player] -= 2;
						count_rangeHits[1 - player] = 0;
						offsetFrontlineCards[1 - player]++;
					}
					Cards::Controls::cardPanelsBackline[player, card]->Visible = false;
					DiscardPile[player].push_back(BacklineCards[player].at(card));
					updatePiles();
					return;
				}
			}
		}
	}

	void chooseCardHand(int player, int card)
	{
		if (Cards::Controls::cardPanelsHand[player, card]->BackColor == System::Drawing::Color::COLOR_TYP3) return;
		showDeckPlayer = player;
		showDeckCard = card;
		ShowDeckDeck = &Deck[player];
		if (HandCards[player].at(card).name == NAME_EFFECT1)
		{
			whichHandCard = 1;
			showDeck();
		}
		else if (HandCards[player].at(card).name == NAME_EFFECT2)
		{
			whichHandCard = 2;
			showDeck();
		}
		else if (HandCards[player].at(card).name == NAME_EFFECT3)
		{
			whichHandCard = 3;
			count_showCards = 2;
			showTopCards();
		}
		else if (HandCards[player].at(card).name == NAME_EFFECT4)
		{
			whichHandCard = 4;
			showDeckPlayer = 1 - player;
			count_showCards = 1;
			showTopCards();
		}
		else if (HandCards[player].at(card).name == NAME_EFFECT5)
		{
			whichHandCard = 5;
			showDeckPlayer = player;
			count_showCards = 3;
			showTopCards();
		}
		else if (HandCards[player].at(card).name == NAME_EFFECT6)
		{
			whichHandCard = 6;
			showDeck();
		}
		else if (HandCards[player].at(card).name == NAME_EFFECT7)
		{
			showDeckPlayer = player;
			ShowDeckDeck = &DiscardPile[player];
			flag_showDeckWhole = true;
			whichHandCard = 7;
			showDeck();
			flag_showDeckWhole = false;
		}
	}

	void chooseDeckView(int chosenCard, System::Windows::Forms::Form^ form)
	{
		if (whichHandCard == 1)
		{
			std::rotate(Deck[showDeckPlayer].begin() + offsetFront[showDeckPlayer], Deck[showDeckPlayer].begin() + chosenCard, Deck[showDeckPlayer].end() - offsetBack[showDeckPlayer]);
			offsetFront[showDeckPlayer]++;
			Cards::Controls::cardPanelsHand[showDeckPlayer, showDeckCard]->Visible = false;
			form->Close();
		}
		if (whichHandCard == 2)
		{
			std::rotate(Deck[showDeckPlayer].begin() + offsetFront[showDeckPlayer], Deck[showDeckPlayer].begin() + chosenCard + 1, Deck[showDeckPlayer].end() - offsetBack[showDeckPlayer]);
			offsetBack[showDeckPlayer]++;
			Cards::Controls::cardPanelsHand[showDeckPlayer, showDeckCard]->Visible = false;
			form->Close();
		}
		if (whichHandCard == 6)
		{
			if (Deck[showDeckPlayer].at(chosenCard).type == 2)
			{
				std::rotate(Deck[showDeckPlayer].begin() + pos[showDeckPlayer], Deck[showDeckPlayer].begin() + chosenCard, Deck[showDeckPlayer].end());
				offsetFront[showDeckPlayer]++;
				Cards::Controls::cardPanelsHand[showDeckPlayer, showDeckCard]->Visible = false;
				drawCard(showDeckPlayer);
				std::rotate(Deck[showDeckPlayer].begin() + pos[showDeckPlayer], Deck[showDeckPlayer].end() - chosenCard + pos[showDeckPlayer] - 1, Deck[showDeckPlayer].end());
				whichHandCard = 0;
				form->Close();
			}
		}
		if (whichHandCard == 7)
		{
			DiscardPile[showDeckPlayer].erase(DiscardPile[showDeckPlayer].begin() + chosenCard);
			Cards::Controls::cardPanelsHand[showDeckPlayer, showDeckCard]->Visible = false;
			whichHandCard = 0;
			updatePiles();
			form->Close();
		}
	}

	void chooseCardView(int chosenCard, System::Windows::Forms::Form^ form)
	{
		if (whichHandCard == 3)
		{
			std::rotate(Deck[showDeckPlayer].begin() + pos[showDeckPlayer], Deck[showDeckPlayer].begin() + pos[showDeckPlayer] + (1 - chosenCard) + 1, Deck[showDeckPlayer].end());
			form->Close();
		}
		if (whichHandCard == 4 || whichHandCard == 5)
		{
			form->Close();
		}
	}

	int maxStrength(std::vector<Card> &Deck)
	{
		int max = 0;
		for (int i = 0; i < Deck.size(); i++)
		{
			if (Deck.at(i).strength > max)
				max = Deck.at(i).strength;
		}
		return max;
	}

	void showHandCards()
	{
		for (int j = 0; j < COUNT_PLAYERS; j++)
		{
			for (int i = 0; i < HandCards[j].size(); i++)
			{
				Cards::Controls::cardnamesHand[j, i]->Text = gcnew System::String(HandCards[j].at(i).name.data());
				Cards::Controls::cardeffectsHand[j, i]->Text = gcnew System::String(HandCards[j].at(i).effect.data());
				Cards::Controls::cardPanelsHand[j, i]->Visible = true;
				Cards::Controls::cardPanelsHand[j, i]->BringToFront();
			}
		}
	}
	
	void showDeck()
	{
		std::sort(Deck[showDeckPlayer].begin() + offsetFront[showDeckPlayer], Deck[showDeckPlayer].end() - offsetBack[showDeckPlayer], Cards::SortCards());
		CardGame::DeckView^ form2 = gcnew CardGame::DeckView;
		form2->Show();
	}
	
	void showTopCards()
	{
		CardGame::CardView^ form3 = gcnew CardGame::CardView;
		form3->Show();
	}

	void randompick(int player,int min,  int max)
	{
		std::random_device rd;
		std::mt19937 rng(rd()); 
		std::uniform_int_distribution<std::mt19937::result_type> pick(min, max);
		int number = pick(rng);
		if (Cards::Controls::cardSelectionPanels[number]->Visible == false)
			number = (number + 1) % MAX_CARDSTOCHOSE;
		chooseCard(number);
	}

	void highlightUseableCards()
	{
		if (phase < 20)
		{
			for (int j = 0; j < COUNT_PLAYERS; j++)
			{
				for (int i = 0; i < MAX_CARDS_BACKLINE; i++)
				{
					Cards::Controls::cardPanelsBackline[j, i]->BackColor = System::Drawing::Color::COLOR_TYP2;
				}
				for (int i = 0; i < MAX_HANDCARDS; i++)
				{
					Cards::Controls::cardPanelsHand[j, i]->BackColor = System::Drawing::Color::COLOR_TYP3;
				}
			}
		}
		else
		{
			for (int j = 0; j < COUNT_PLAYERS; j++)
			{
				if (phase > 20)		// nach dem Mischen
				{
					for (int i = 0; i < MAX_CARDS_BACKLINE; i++)
					{
						if (Cards::Controls::cardPanelsBackline[j, i]->Visible == true)
						{
							if (
								((Cards::Controls::cardskillsBackline[j, i]->Text == NAME_SKILL13 || Cards::Controls::cardskillsBackline[j, i]->Text == NAME_SKILL11
									|| Cards::Controls::cardskill2sBackline[j, i]->Text == NAME_SKILL13 || Cards::Controls::cardskill2sBackline[j, i]->Text == NAME_SKILL11)
									&& j == 1 - attacker && flag_defenders == false && flag_attacker == true)			// Fernkampf
								|| (flag_banner[j] == false && flag_attacker == false && (Cards::Controls::cardskillsBackline[j, i]->Text == NAME_SKILL17
									|| Cards::Controls::cardskill2sBackline[j, i]->Text == NAME_SKILL17))				// Banner
								|| ((Cards::Controls::cardskillsBackline[j, i]->Text == NAME_SKILL10 || Cards::Controls::cardskill2sBackline[j, i]->Text == NAME_SKILL10)
									&& Deck[1 - j].size() != pos[1 - j])											 // Katapult
								)
							{
								Cards::Controls::cardPanelsBackline[j, i]->BackColor = System::Drawing::Color::COLOR_HIGHLIGHT;;
							}
							else
								Cards::Controls::cardPanelsBackline[j, i]->BackColor = System::Drawing::Color::COLOR_TYP2;
						}
					}
				}
				for (int i = 0; i < MAX_HANDCARDS; i++)
				{
					if (Cards::Controls::cardPanelsHand[j, i]->Visible == true)
					{
						if (
							((HandCards[j].at(i).name == NAME_EFFECT1 || HandCards[j].at(i).name == NAME_EFFECT2 || HandCards[j].at(i).name == NAME_EFFECT6)
								&& phase == 20)					// Erste Welle & Letzte Reserve & In Position
							||
							(((HandCards[j].at(i).name == NAME_EFFECT3 && Deck[j].size() - pos[j] >= 2)
								|| (HandCards[j].at(i).name == NAME_EFFECT4 && Deck[1 - j].size() - pos[1 - j] >= 1)
								|| (HandCards[j].at(i).name == NAME_EFFECT5 && Deck[j].size() - pos[j] >= 3)
								|| (HandCards[j].at(i).name == NAME_EFFECT7 && DiscardPile[j].size() > 0))
								&& phase > 20 && flag_attacker == false)					// Jetzt ihr & Kundschafter & Überblick & Feldscher
							)
						{
							Cards::Controls::cardPanelsHand[j, i]->BackColor = System::Drawing::Color::COLOR_HIGHLIGHT;;
						}
						else
							Cards::Controls::cardPanelsHand[j, i]->BackColor = System::Drawing::Color::COLOR_TYP3;
					}
				}
			}
		}
	}
}
