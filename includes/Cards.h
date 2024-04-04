#pragma once
#include <iostream>
#include <string>
#include <cstdio>
#include <windows.h>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <random>
#include <deque>

#define MAX_DECK 100
#define MAX_CARDS_FRONTLINE 15
#define MAX_CARDS_BACKLINE 25
#define MAX_HANDCARDS 15
#define MAX_SHOWCARD 5
#define COUNT_PLAYERS 2
#define MAX_CARDSTOCHOSE 5
#define MAX_HANDCARDSTOCHOSE 5
#define ROUNDS_DRAFT_START 4
#define ROUNDS_DRAFT_DURING 1
#define MAX_VICTORY_POINTS 10

#define COLOR_TYP1 White
#define COLOR_TYP2 LightBlue
#define COLOR_TYP3 LightGray
#define COLOR_HIGHLIGHT1 Yellow
#define COLOR_HIGHLIGHT2 Red

#define TEXT_CHOOSE  "Spieler darf seinem Deck eine Karte hinzufügen"
#define TEXT_CHOOSE_HANDCARD  "Spieler hat verloren und darf seinem Deck eine Handkarte hinzufügen"
#define TEXT_ATTACK  "Spieler greift an"
#define TEXT_ATTACK_OR_DRAFT "Spieler entscheidet"
#define TEXT_ASSASSIN "Spieler darf eine Einheit des Gegners meucheln"
#define TEXT_SABOTEUR "Spieler darf eine Maschine des Gegners sabotieren"

#define NAME_SKILL1 "Gemeinsamer Angriff"
#define NAME_SKILL2 "Masseneuphorie"
#define NAME_SKILL3 "Ansturm"
#define NAME_SKILL4 "Speere"
#define NAME_SKILL5 "Durchschlagskraft"
#define NAME_SKILL6 "Goblinhorde"
#define NAME_SKILL7 "Goblinboss"
#define NAME_SKILL8 "Leichenfresser"
#define NAME_SKILL9 "Elfenstolz"
#define NAME_SKILL10 "Massiges Geschoss"
#define NAME_SKILL11 "Geschossener Speer"
#define NAME_SKILL12 "Auferweckung"
#define NAME_SKILL13 "Fernkampf"
#define NAME_SKILL14 "Herr der Toten"
#define NAME_SKILL15 "Anführer"
#define NAME_SKILL16 "Hüter des Lichts"
#define NAME_SKILL17 "Banner"
#define NAME_SKILL18 "Hass"
#define NAME_SKILL19 "Blutdurst"
#define NAME_SKILL20 "Heilung"
#define NAME_SKILL21 "Meuchelmord"
#define NAME_SKILL22 "Sabotage"
#define NAME_SKILL23 ""
#define NAME_SKILL24 ""
#define NAME_SKILL25 ""
#define NAME_SKILL26 ""
#define NAME_SKILL27 ""
#define NAME_SKILL28 ""
#define NAME_SKILL29 ""

#define NAME_TRAIT1 "Mensch"
#define NAME_TRAIT2 "beritten"
#define NAME_TRAIT3 "robust"
#define NAME_TRAIT4 "Goblin"
#define NAME_TRAIT5 "Ork"
#define NAME_TRAIT6 "untot"
#define NAME_TRAIT7 "Elf"
#define NAME_TRAIT8 "Maschine"
#define NAME_TRAIT9 "Oger"
#define NAME_TRAIT10 "dumm"

#define NAME_EFFECT1 "Erste Welle"
#define NAME_EFFECT2 "Letzte Reserve"
#define NAME_EFFECT3 "Jetzt Ihr"
#define NAME_EFFECT4 "Kundschafter"
#define NAME_EFFECT5 "Überblick"
#define NAME_EFFECT6 "In Position"
#define NAME_EFFECT7 "Feldscher"

#define TEXT_EFFECT1 "Bestimme eine Karte, die in der nächsten Partie zu Beginn gezogen wird"
#define TEXT_EFFECT2 "Bestimme eine Karte, die in der nächsten Partie zuletzt gezogen wird"
#define TEXT_EFFECT3 "Decke 2 Karten auf, wähle 1 und lege sie auf dein Deck, lege die andere unter dein Deck"
#define TEXT_EFFECT4 "Siehe dir die oberste Karte deines Gegners an"
#define TEXT_EFFECT5 "Siehe dir die oberste Karte 3 Karten deines Decks an"
#define TEXT_EFFECT6 "Lege 1 Karte der hinteren Reihe vor Begin aus"
#define TEXT_EFFECT7 "Entferne eine beliebige Karte von deinem Ablagestapel"

namespace Cards
{
	ref class Controls
	{
	public:
		static array<System::Windows::Forms::PictureBox^, COUNT_PLAYERS>^ pictureBoxes = gcnew array<System::Windows::Forms::PictureBox^, COUNT_PLAYERS>(COUNT_PLAYERS, MAX_VICTORY_POINTS);
		static array<System::Windows::Forms::Panel^, COUNT_PLAYERS>^ backPanels = gcnew array<System::Windows::Forms::Panel^, COUNT_PLAYERS>(COUNT_PLAYERS, MAX_DECK);

		static array<System::Windows::Forms::Panel^, COUNT_PLAYERS>^ cardPanelsHand = gcnew array<System::Windows::Forms::Panel^, COUNT_PLAYERS>(COUNT_PLAYERS, MAX_HANDCARDS);
		static array<System::Windows::Forms::Label^, COUNT_PLAYERS>^ cardnamesHand = gcnew array<System::Windows::Forms::Label^, COUNT_PLAYERS>(COUNT_PLAYERS, MAX_HANDCARDS);
		static array<System::Windows::Forms::Label^, COUNT_PLAYERS>^ cardeffectsHand = gcnew array<System::Windows::Forms::Label^, COUNT_PLAYERS>(COUNT_PLAYERS, MAX_HANDCARDS);
		
		static array<System::Windows::Forms::Panel^, COUNT_PLAYERS>^ cardPanels = gcnew array<System::Windows::Forms::Panel^, COUNT_PLAYERS>(COUNT_PLAYERS, MAX_CARDS_FRONTLINE);
		static array<System::Windows::Forms::Label^, COUNT_PLAYERS>^ cardnames = gcnew array<System::Windows::Forms::Label^, COUNT_PLAYERS>(COUNT_PLAYERS, MAX_CARDS_FRONTLINE);
		static array<System::Windows::Forms::Label^, COUNT_PLAYERS>^ cardstrengths = gcnew array<System::Windows::Forms::Label^, COUNT_PLAYERS>(COUNT_PLAYERS, MAX_CARDS_FRONTLINE);
		static array<System::Windows::Forms::Label^, COUNT_PLAYERS>^ cardskills = gcnew array<System::Windows::Forms::Label^, COUNT_PLAYERS>(COUNT_PLAYERS, MAX_CARDS_FRONTLINE);
		static array<System::Windows::Forms::Label^, COUNT_PLAYERS>^ cardskill2s = gcnew array<System::Windows::Forms::Label^, COUNT_PLAYERS>(COUNT_PLAYERS, MAX_CARDS_FRONTLINE);
		static array<System::Windows::Forms::Label^, COUNT_PLAYERS>^ cardtraits = gcnew array<System::Windows::Forms::Label^, COUNT_PLAYERS>(COUNT_PLAYERS, MAX_CARDS_FRONTLINE);

		static array<System::Windows::Forms::Panel^, COUNT_PLAYERS>^ cardPanelsBackline = gcnew array<System::Windows::Forms::Panel^, COUNT_PLAYERS>(COUNT_PLAYERS, MAX_CARDS_BACKLINE);
		static array<System::Windows::Forms::Label^, COUNT_PLAYERS>^ cardnamesBackline = gcnew array<System::Windows::Forms::Label^, COUNT_PLAYERS>(COUNT_PLAYERS, MAX_CARDS_BACKLINE);
		static array<System::Windows::Forms::Label^, COUNT_PLAYERS>^ cardstrengthsBackline = gcnew array<System::Windows::Forms::Label^, COUNT_PLAYERS>(COUNT_PLAYERS, MAX_CARDS_BACKLINE);
		static array<System::Windows::Forms::Label^, COUNT_PLAYERS>^ cardskillsBackline = gcnew array<System::Windows::Forms::Label^, COUNT_PLAYERS>(COUNT_PLAYERS, MAX_CARDS_BACKLINE);
		static array<System::Windows::Forms::Label^, COUNT_PLAYERS>^ cardskill2sBackline = gcnew array<System::Windows::Forms::Label^, COUNT_PLAYERS>(COUNT_PLAYERS, MAX_CARDS_BACKLINE);
		static array<System::Windows::Forms::Label^, COUNT_PLAYERS>^ cardtraitsBackline = gcnew array<System::Windows::Forms::Label^, COUNT_PLAYERS>(COUNT_PLAYERS, MAX_CARDS_BACKLINE);

		static array<System::Windows::Forms::Panel^, COUNT_PLAYERS>^ cardPanelsDiscard = gcnew array<System::Windows::Forms::Panel^, COUNT_PLAYERS>(COUNT_PLAYERS, MAX_DECK);
		static array<System::Windows::Forms::Label^, COUNT_PLAYERS>^ cardnamesDiscard = gcnew array<System::Windows::Forms::Label^, COUNT_PLAYERS>(COUNT_PLAYERS, MAX_DECK);
		static array<System::Windows::Forms::Label^, COUNT_PLAYERS>^ cardstrengthsDiscard = gcnew array<System::Windows::Forms::Label^, COUNT_PLAYERS>(COUNT_PLAYERS, MAX_DECK);
		static array<System::Windows::Forms::Label^, COUNT_PLAYERS>^ cardskillsDiscard  = gcnew array<System::Windows::Forms::Label^, COUNT_PLAYERS>(COUNT_PLAYERS, MAX_DECK);
		static array<System::Windows::Forms::Label^, COUNT_PLAYERS>^ cardskill2sDiscard = gcnew array<System::Windows::Forms::Label^, COUNT_PLAYERS>(COUNT_PLAYERS, MAX_DECK);
		static array<System::Windows::Forms::Label^, COUNT_PLAYERS>^ cardtraitsDiscard = gcnew array<System::Windows::Forms::Label^, COUNT_PLAYERS>(COUNT_PLAYERS, MAX_DECK);

		static array<System::Windows::Forms::Panel^>^ cardPanelsShowDeck = gcnew array<System::Windows::Forms::Panel^>(MAX_DECK);
		static array<System::Windows::Forms::Label^>^ cardNamesShowDeck = gcnew array<System::Windows::Forms::Label^>(MAX_DECK);
		static array<System::Windows::Forms::Label^>^ cardStrengthsShowDeck = gcnew array<System::Windows::Forms::Label^>(MAX_DECK);
		static array<System::Windows::Forms::Label^>^ cardSkillsShowDeck = gcnew array<System::Windows::Forms::Label^>(MAX_DECK);
		static array<System::Windows::Forms::Label^>^ cardSkill2sShowDeck = gcnew array<System::Windows::Forms::Label^>(MAX_DECK);
		static array<System::Windows::Forms::Label^>^ cardTraitsShowDeck = gcnew array<System::Windows::Forms::Label^>(MAX_DECK);

		static array<System::Windows::Forms::Panel^>^ cardPanelsShowCard = gcnew array<System::Windows::Forms::Panel^>(MAX_SHOWCARD);
		static array<System::Windows::Forms::Label^>^ cardNamesShowCard = gcnew array<System::Windows::Forms::Label^>(MAX_SHOWCARD);
		static array<System::Windows::Forms::Label^>^ cardStrengthsShowCard = gcnew array<System::Windows::Forms::Label^>(MAX_SHOWCARD);
		static array<System::Windows::Forms::Label^>^ cardSkillsShowCard = gcnew array<System::Windows::Forms::Label^>(MAX_SHOWCARD);
		static array<System::Windows::Forms::Label^>^ cardSkill2sShowCard = gcnew array<System::Windows::Forms::Label^>(MAX_SHOWCARD);
		static array<System::Windows::Forms::Label^>^ cardTraitsShowCard = gcnew array<System::Windows::Forms::Label^>(MAX_SHOWCARD);

		static array<System::Windows::Forms::Panel^>^ cardSelectionPanels = gcnew array<System::Windows::Forms::Panel^>(MAX_CARDSTOCHOSE);
		static array<System::Windows::Forms::Label^>^ cardSelectionNames = gcnew array<System::Windows::Forms::Label^>(MAX_CARDSTOCHOSE);
		static array<System::Windows::Forms::Label^>^ cardSelectionStrengths = gcnew array<System::Windows::Forms::Label^>(MAX_CARDSTOCHOSE);
		static array<System::Windows::Forms::Label^>^ cardSelectionSkills = gcnew array<System::Windows::Forms::Label^>(MAX_CARDSTOCHOSE);
		static array<System::Windows::Forms::Label^>^ cardSelectionSkill2s = gcnew array<System::Windows::Forms::Label^>(MAX_CARDSTOCHOSE);
		static array<System::Windows::Forms::Label^>^ cardSelectionTraits = gcnew array<System::Windows::Forms::Label^>(MAX_CARDSTOCHOSE);

		static array<System::Windows::Forms::Label^>^ cardsRemain = gcnew array<System::Windows::Forms::Label^>(COUNT_PLAYERS);
		static array<System::Windows::Forms::Label^>^ score = gcnew array<System::Windows::Forms::Label^>(COUNT_PLAYERS);
		static array<System::Windows::Forms::Label^>^ messageLabel = gcnew array<System::Windows::Forms::Label^>(COUNT_PLAYERS);
		static array<System::Windows::Forms::Button^, COUNT_PLAYERS>^ buttons = gcnew array<System::Windows::Forms::Button^, COUNT_PLAYERS>(COUNT_PLAYERS, 2);
		static System::Windows::Forms::Button^ button1 = gcnew System::Windows::Forms::Button;
	};
	class Card
	{
	public:
		bool operator==(Card card);
		bool operator<(Card card);
		std::string name;
		int strength;
		int type;
		int skill;
		int skill2;
		std::string traits;
		Card& addTraits(std::string traits);
		std::string writeType(int type);
		std::string writeSkill(int skill);
		Card();
		Card(std::string name, int strength, int type);
		Card(std::string name, int strength, int type, int skill);
		Card(std::string name, int strength, int type, int skill, int skill2);
	private:
	};

	class HandCard
	{
	public:
		std::string name;
		std::string effect;
		HandCard(std::string name, std::string effect);
	};

	struct SortCards
	{
	public:
		bool operator()(Card leftCard, Card rightCard)
		{
			return leftCard < rightCard;
		}
	};

	void eraseCard(std::vector<Card>& Deck, Card card);
	void shuffleDeck(std::vector<Card>& Deck, int offsetFront, int offsetBack);
	void updateScore();
	void updatePiles();
	int drawCard(int player);
	void clearFrontline();
	void clearBackline();
	void gameOver(int winner);
	void gameRestart();
	int discardSearch(int player, bool sumAll, std::string trait);
	void draftCard(std::vector<Card> &Deck);
	void draftHandCard(std::vector<HandCard> &Deck);
	void draftCardOver(std::vector<Card> &Deck);
	void draftHandCardOver(std::vector<HandCard> &DeckofCards);
	void chooseCard(int chosenCard);
	void chooseCardHandCard3(int chosenCard);
	void chooseHandCardDraft(int chosenCard);
	void chooseCardDraft(int chosenCard);
	void chooseCardBackline(int player, int card);
	void chooseCardHand(int player, int card);
	void chooseDeckView(int chosenCard, System::Windows::Forms::Form^ form);
	void chooseCardView(int chosenCard, System::Windows::Forms::Form^ form);
	int maxStrength(std::vector<Card> &Deck);
	void showHandCards();
	void showDeck();
	void showTopCards();
	void randompick(int player, int min, int max);
	void highlightUseableCards();
	void startMatch();
	void showMessage(int player, System::String^ message);
}
