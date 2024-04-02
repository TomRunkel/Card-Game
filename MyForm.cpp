#include <Windows.h>
#include "MyForm.h"
#include "Globals.h"
#include "Cards.h"

using namespace System;
using namespace System::Windows::Forms;

int main(array<String^>^ args)
{
//***************** INITIATING CARDS ******************
	std::string und = ", ";
	Cards::Card Bauern("Bauern", 1, 1, 1);
				Bauern.addTraits(NAME_TRAIT1);
	Cards::Card Keulentraeger("Keulenträger", 1, 1, 2);
				Keulentraeger.addTraits(NAME_TRAIT1);
	Cards::Card Reiter("Reiter", 2, 1, 3);
				Reiter.addTraits(NAME_TRAIT1 + und + NAME_TRAIT2);
	Cards::Card Speertraeger("Speerträger", 2, 1, 4);
				Speertraeger.addTraits(NAME_TRAIT1);
	Cards::Card Schwertkaempfer("Schwertkämpfer", 3, 1);
				Schwertkaempfer.addTraits(NAME_TRAIT1);
	Cards::Card Axtkaempfer("Axtkämpfer", 2, 1, 5);
				Axtkaempfer.addTraits(NAME_TRAIT1);
	Cards::Card Goblins("Goblins", 0, 1, 1, 6);
				Goblins.addTraits(NAME_TRAIT4);
	Cards::Card Goblinhaeuptling("Goblinhäuptling", 0, 1, 7);
				Goblinhaeuptling.addTraits(NAME_TRAIT4);
	Cards::Card Orktreiber("Orktreiber", 0, 2, 7);
				Orktreiber.addTraits(NAME_TRAIT5);
	Cards::Card Ghule("Ghule", 0, 1, 8);
				Ghule.addTraits(NAME_TRAIT6);
	Cards::Card Elfenkrieger("Elfenkrieger", 1, 1, 9);
				Elfenkrieger.addTraits(NAME_TRAIT7);
	Cards::Card Katapult("Katapult", 0, 2, 10);
				Katapult.addTraits(NAME_TRAIT8);
	Cards::Card Balliste("Balliste", 0, 2, 11);
				Balliste.addTraits(NAME_TRAIT8);
	Cards::Card Skelettkrieger("Skelettkrieger", 0, 1, 12);
				Skelettkrieger.addTraits(NAME_TRAIT6);
	Cards::Card Elfenreiter("Elfenreiter", 1, 1, 9, 3);
				Elfenreiter.addTraits(NAME_TRAIT7 + und + NAME_TRAIT2);
	Cards::Card Bogenschuetzen("Bogenschützen", 2, 2, 13);
				Bogenschuetzen.addTraits(NAME_TRAIT1);
	Cards::Card Elfenschuetzen("Elfenschützen", 1, 2, 13, 9);
				Elfenschuetzen.addTraits(NAME_TRAIT7);
	Cards::Card Oger("Oger", 4, 1);
				Oger.addTraits(NAME_TRAIT9 + und + NAME_TRAIT3 + und + NAME_TRAIT10);
	Cards::Card Lich("Lich", 0, 2, 14);
				Lich.addTraits(NAME_TRAIT6);
	Cards::Card Hauptmann("Hauptmann", 0, 1, 15, 2);
				Hauptmann.addTraits(NAME_TRAIT1);
	Cards::Card Moenche("Mönche", 1, 1, 16);
				Moenche.addTraits(NAME_TRAIT1);
	Cards::Card Bannertraeger("Bannerträger", 0, 2, 17);
				Bannertraeger.addTraits(NAME_TRAIT1);
	Cards::Card Orkkrieger("Orkkrieger", 1, 1, 18);
				Orkkrieger.addTraits(NAME_TRAIT5);
	Cards::Card Orkberserker("Orkberserker", 1, 1, 19);
				Orkberserker.addTraits(NAME_TRAIT5);
//*****************************************************

	for (int i = 0; i < 8; i++) DeckA.push_back(Bauern);
	for (int i = 0; i < 6; i++) DeckA.push_back(Keulentraeger);
	for (int i = 0; i < 5; i++) DeckA.push_back(Reiter);
	for (int i = 0; i < 5; i++) DeckA.push_back(Speertraeger);
	for (int i = 0; i < 5; i++) DeckA.push_back(Schwertkaempfer);
	for (int i = 0; i < 5; i++) DeckA.push_back(Axtkaempfer);
	for (int i = 0; i < 5; i++) DeckA.push_back(Goblins);
	for (int i = 0; i < 3; i++) DeckA.push_back(Goblinhaeuptling);
	for (int i = 0; i < 5; i++) DeckA.push_back(Ghule);
	for (int i = 0; i < 5; i++) DeckA.push_back(Elfenkrieger);
	for (int i = 0; i < 4; i++) DeckA.push_back(Orktreiber);
	for (int i = 0; i < 4; i++) DeckA.push_back(Katapult);
	for (int i = 0; i < 4; i++) DeckA.push_back(Balliste);
	for (int i = 0; i < 5; i++) DeckA.push_back(Skelettkrieger);
	for (int i = 0; i < 3; i++) DeckA.push_back(Elfenreiter);
	for (int i = 0; i < 6; i++) DeckA.push_back(Bogenschuetzen);
	for (int i = 0; i < 4; i++) DeckA.push_back(Elfenschuetzen);
	for (int i = 0; i < 2; i++) DeckA.push_back(Lich);
	for (int i = 0; i < 2; i++) DeckA.push_back(Hauptmann);
	for (int i = 0; i < 5; i++) DeckA.push_back(Moenche);
	for (int i = 0; i < 2; i++) DeckA.push_back(Bannertraeger);
	for (int i = 0; i < 6; i++) DeckA.push_back(Orkkrieger);
	for (int i = 0; i < 4; i++) DeckA.push_back(Orkberserker);

	//*************** INITIATING HANDCARDS ****************
	Cards::HandCard ErsteWelle(NAME_EFFECT1, TEXT_EFFECT1);
	Cards::HandCard LetzteReserve(NAME_EFFECT2, TEXT_EFFECT2);
	Cards::HandCard JetztIhr(NAME_EFFECT3, TEXT_EFFECT3);
	Cards::HandCard Kundschafter(NAME_EFFECT4, TEXT_EFFECT4);
	Cards::HandCard Ueberblick(NAME_EFFECT5, TEXT_EFFECT5);
	Cards::HandCard InPosition(NAME_EFFECT6, TEXT_EFFECT6);
	Cards::HandCard Feldscher(NAME_EFFECT7, TEXT_EFFECT7);
	//*****************************************************

	for (int i = 0; i < 5; i++) DeckH.push_back(ErsteWelle);
	for (int i = 0; i < 5; i++) DeckH.push_back(LetzteReserve);
	for (int i = 0; i < 5; i++) DeckH.push_back(JetztIhr);
	for (int i = 0; i < 5; i++) DeckH.push_back(Kundschafter);
	for (int i = 0; i < 5; i++) DeckH.push_back(Ueberblick);
	for (int i = 0; i < 5; i++) DeckH.push_back(InPosition);
	for (int i = 0; i < 5; i++) DeckH.push_back(Feldscher);
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	CardGame::MyForm form;
	Application::Run(% form);
	return 0;
}
