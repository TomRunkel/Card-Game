#pragma once
#include "Cards.h"
#include "Globals.h"

#define MAX_COLS 3
#define MAX_COLS_HAND 6


namespace CardGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ StartButton;
	private: System::Windows::Forms::Panel^ panelL;
	private: System::Windows::Forms::Label^ scoreL;
	private: System::Windows::Forms::Panel^ PanelR;
	private: System::Windows::Forms::Label^ scoreR;
	private: System::Windows::Forms::Label^ MessageLabelL;
	private: System::Windows::Forms::Label^ cardsRemainL;
	private: System::Windows::Forms::Label^ cardsRemainR;
	private: System::Windows::Forms::Label^ MessageLabelR;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->StartButton = (gcnew System::Windows::Forms::Button());
			this->panelL = (gcnew System::Windows::Forms::Panel());
			this->scoreL = (gcnew System::Windows::Forms::Label());
			this->PanelR = (gcnew System::Windows::Forms::Panel());
			this->scoreR = (gcnew System::Windows::Forms::Label());
			this->MessageLabelL = (gcnew System::Windows::Forms::Label());
			this->cardsRemainL = (gcnew System::Windows::Forms::Label());
			this->cardsRemainR = (gcnew System::Windows::Forms::Label());
			this->MessageLabelR = (gcnew System::Windows::Forms::Label());
			this->panelL->SuspendLayout();
			this->PanelR->SuspendLayout();
			this->SuspendLayout();
			// 
			// StartButton
			// 
			this->StartButton->Enabled = false;
			this->StartButton->Location = System::Drawing::Point(860, 5);
			this->StartButton->Name = L"StartButton";
			this->StartButton->Size = System::Drawing::Size(139, 50);
			this->StartButton->TabIndex = 6;
			this->StartButton->UseVisualStyleBackColor = true;
			this->StartButton->Click += gcnew System::EventHandler(this, &MyForm::StartButton_Click);
			// 
			// panelL
			// 
			this->panelL->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->panelL->Controls->Add(this->scoreL);
			this->panelL->ForeColor = System::Drawing::Color::White;
			this->panelL->Location = System::Drawing::Point(800, 5);
			this->panelL->Name = L"panelL";
			this->panelL->Size = System::Drawing::Size(54, 50);
			this->panelL->TabIndex = 7;
			// 
			// scoreL
			// 
			this->scoreL->Dock = System::Windows::Forms::DockStyle::Fill;
			this->scoreL->Location = System::Drawing::Point(0, 0);
			this->scoreL->Name = L"scoreL";
			this->scoreL->Size = System::Drawing::Size(54, 50);
			this->scoreL->TabIndex = 0;
			this->scoreL->Text = L"0";
			this->scoreL->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// PanelR
			// 
			this->PanelR->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->PanelR->Controls->Add(this->scoreR);
			this->PanelR->ForeColor = System::Drawing::Color::White;
			this->PanelR->Location = System::Drawing::Point(1005, 5);
			this->PanelR->Name = L"PanelR";
			this->PanelR->Size = System::Drawing::Size(54, 50);
			this->PanelR->TabIndex = 8;
			// 
			// scoreR
			// 
			this->scoreR->Dock = System::Windows::Forms::DockStyle::Fill;
			this->scoreR->Location = System::Drawing::Point(0, 0);
			this->scoreR->Name = L"scoreR";
			this->scoreR->Size = System::Drawing::Size(54, 50);
			this->scoreR->TabIndex = 0;
			this->scoreR->Text = L"0";
			this->scoreR->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MessageLabelL
			// 
			this->MessageLabelL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MessageLabelL->Location = System::Drawing::Point(12, 73);
			this->MessageLabelL->Name = L"MessageLabelL";
			this->MessageLabelL->Size = System::Drawing::Size(697, 43);
			this->MessageLabelL->TabIndex = 9;
			this->MessageLabelL->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// cardsRemainL
			// 
			this->cardsRemainL->AutoSize = true;
			this->cardsRemainL->BackColor = System::Drawing::Color::IndianRed;
			this->cardsRemainL->Location = System::Drawing::Point(204, 243);
			this->cardsRemainL->Name = L"cardsRemainL";
			this->cardsRemainL->Size = System::Drawing::Size(13, 13);
			this->cardsRemainL->TabIndex = 0;
			this->cardsRemainL->Text = L"0";
			this->cardsRemainL->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// cardsRemainR
			// 
			this->cardsRemainR->AutoSize = true;
			this->cardsRemainR->BackColor = System::Drawing::Color::SeaGreen;
			this->cardsRemainR->Location = System::Drawing::Point(1603, 243);
			this->cardsRemainR->Name = L"cardsRemainR";
			this->cardsRemainR->Size = System::Drawing::Size(13, 13);
			this->cardsRemainR->TabIndex = 1;
			this->cardsRemainR->Text = L"0";
			this->cardsRemainR->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MessageLabelR
			// 
			this->MessageLabelR->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->MessageLabelR->Location = System::Drawing::Point(1151, 73);
			this->MessageLabelR->Name = L"MessageLabelR";
			this->MessageLabelR->Size = System::Drawing::Size(697, 43);
			this->MessageLabelR->TabIndex = 10;
			this->MessageLabelR->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->ClientSize = System::Drawing::Size(1860, 980);
			this->Controls->Add(this->MessageLabelR);
			this->Controls->Add(this->cardsRemainR);
			this->Controls->Add(this->cardsRemainL);
			this->Controls->Add(this->MessageLabelL);
			this->Controls->Add(this->PanelR);
			this->Controls->Add(this->panelL);
			this->Controls->Add(this->StartButton);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Card Game";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panelL->ResumeLayout(false);
			this->PanelR->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void CardSelection_MouseHover_Panel(System::Object^ sender, System::EventArgs^ e) {
		Panel^ senderObject = safe_cast<Panel^>(sender);
		senderObject->BringToFront();
	}
	private: System::Void CardSelection_MouseHover_Label(System::Object^ sender, System::EventArgs^ e) {
		Label^ senderObject = safe_cast<Label^>(sender);
		senderObject->Parent->BringToFront();
	}
	private: System::Void CardSelection_Click_Panel(System::Object^ sender, System::EventArgs^ e) {
		Panel^ senderObject = safe_cast<Panel^>(sender);
		Cards::chooseCard(System::Convert::ToInt16(senderObject->Tag));
	}
	private: System::Void CardSelection_Click_Label(System::Object^ sender, System::EventArgs^ e) {
		Label^ senderObject = safe_cast<Label^>(sender);
		Cards::chooseCard(System::Convert::ToInt16(senderObject->Tag));
	}
	private: System::Void Deck_Click_Panel(System::Object^ sender, System::EventArgs^ e) {
		Panel^ senderObject = safe_cast<Panel^>(sender);
		showDeckPlayer = (System::Convert::ToInt16(senderObject->Tag));
		ShowDeckDeck = &Deck[showDeckPlayer];
		Cards::showDeck();
	}
	private: System::Void Deck_Click_Label(System::Object^ sender, System::EventArgs^ e) {
		Label^ senderObject = safe_cast<Label^>(sender);
		showDeckPlayer = (System::Convert::ToInt16(senderObject->Tag));
		ShowDeckDeck = &Deck[showDeckPlayer];
		Cards::showDeck();
	}
	private: System::Void DiscardPile_Click_Panel(System::Object^ sender, System::EventArgs^ e) {
		Panel^ senderObject = safe_cast<Panel^>(sender);
		showDeckPlayer = (System::Convert::ToInt16(senderObject->Tag));
		ShowDeckDeck = &DiscardPile[showDeckPlayer];
		Cards::showDeck();
	}
	private: System::Void DiscardPile_Click_Label(System::Object^ sender, System::EventArgs^ e) {
		Label^ senderObject = safe_cast<Label^>(sender);
		showDeckPlayer = (System::Convert::ToInt16(senderObject->Tag));
		ShowDeckDeck = &DiscardPile[showDeckPlayer];
		Cards::showDeck();
	}
	private: System::Void StartButton_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Cards::Controls::button1->Text == "Nächste Runde") 
		{
			Cards::gameRestart();
			Cards::showHandCards();
			draftHandCard(DeckH);
			Cards::Controls::button1->Enabled = false;
			Cards::Controls::button1->Text = counter.ToString();
			return;
		}		
		if (Cards::Controls::button1->Text == "Draft") 
		{
			counter = ROUNDS_DRAFT_DURING;
			Cards::highlightUseableCards();
			draftCard(DeckA);
			Cards::Controls::button1->Enabled = false;
			Cards::Controls::button1->Text = counter.ToString();
			return;
		}
		if (turn == 0)
		{
			for (int j = 0; j < COUNT_PLAYERS; j++)
				Cards::shuffleDeck(Deck[j], offsetFront[j] + pos[j], offsetBack[j]);
			Cards::Controls::button1->Text = "Start";
			turn++;
			Cards::highlightUseableCards();
			return;
		}
		if (turn == 1)
		{
			Cards::Controls::button1->Text = "Weiter";
		}
		if (flag_attacker == true
		   && System::Convert::ToInt16(Cards::Controls::score[1 - attacker]->Text) >= System::Convert::ToInt16(Cards::Controls::score[attacker]->Text))
		{
			Cards::clearFrontline();
			attacker = 1 - attacker;
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
		else if (flag_attacker == false)
		{
			if (Cards::drawCard(attacker) == -1)
			{
				if (Cards::drawCard(1 - attacker) == -1)
				{
					Cards::gameOver(-1);
				}
				else
				{
					Cards::gameOver(1 - attacker);
				}
			}
		}
		else 
		{
			flag_defenders = true;
			if (Cards::drawCard(1 - attacker) == -1) Cards::gameOver(attacker);
		}
		Cards::updateScore();
		turn++;
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		Cards::Controls::button1 = this->StartButton;
		Cards::Controls::messageLabel[0] = this->MessageLabelL;
		Cards::Controls::messageLabel[1] = this->MessageLabelR;
		for (int i = 0; i < MAX_CARDSTOCHOSE; i++)
		{
			Panel^ MyPanel = (gcnew Panel());
			Label^ MyPaneltraits = (gcnew System::Windows::Forms::Label());
			Label^ MyPanelskill2 = (gcnew System::Windows::Forms::Label());
			Label^ MyPanelskill = (gcnew System::Windows::Forms::Label());
			Label^ MyPanelstrength = (gcnew System::Windows::Forms::Label());
			Label^ MyPanelname = (gcnew System::Windows::Forms::Label());
			MyPanel->BackColor = System::Drawing::Color::White;
			MyPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			MyPanel->Controls->Add(MyPaneltraits);
			MyPanel->Controls->Add(MyPanelskill2);
			MyPanel->Controls->Add(MyPanelskill);
			MyPanel->Controls->Add(MyPanelstrength);
			MyPanel->Controls->Add(MyPanelname);
			MyPanel->Location = System::Drawing::Point(481 + 180 * i, 200);
			MyPanel->Name = L"SelectionCard" + i;
			MyPanel->Size = System::Drawing::Size(178, 242);
			MyPanel->Visible = false;
			MyPanel->Tag = i;
			this->Controls->Add(MyPanel);

			MyPaneltraits->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.75, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			MyPaneltraits->Location = System::Drawing::Point(-1, 220);
			MyPaneltraits->Name = L"SelectionCard" + i + "traits";
			MyPaneltraits->Size = System::Drawing::Size(178, 62);
			MyPaneltraits->TabIndex = 3;
			MyPaneltraits->Text = L"Traits";
			MyPaneltraits->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			MyPaneltraits->Tag = i;

			MyPanelskill2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			MyPanelskill2->Location = System::Drawing::Point(-1, 139);
			MyPanelskill2->Name = L"SelectionCard" + i + "skill2";
			MyPanelskill2->Size = System::Drawing::Size(178, 62);
			MyPanelskill2->TabIndex = 3;
			MyPanelskill2->Text = L"Skill2";
			MyPanelskill2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			MyPanelskill2->Tag = i;

			MyPanelskill->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			MyPanelskill->Location = System::Drawing::Point(-1, 80);
			MyPanelskill->Name = L"SelectionCard" + i + "skill";
			MyPanelskill->Size = System::Drawing::Size(178, 62);
			MyPanelskill->TabIndex = 2;
			MyPanelskill->Text = L"Skill";
			MyPanelskill->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			MyPanelskill->Tag = i;

			MyPanelstrength->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			MyPanelstrength->Location = System::Drawing::Point(146, 10);
			MyPanelstrength->Name = L"SelectionCard" + i + "strength";
			MyPanelstrength->Size = System::Drawing::Size(27, 28);
			MyPanelstrength->TabIndex = 1;
			MyPanelstrength->Text = L"0";
			MyPanelstrength->Tag = i;

			MyPanelname->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			MyPanelname->Location = System::Drawing::Point(7, 8);
			MyPanelname->Name = L"SelectionCard" + i + "name";
			MyPanelname->Size = System::Drawing::Size(143, 28);
			MyPanelname->TabIndex = 0;
			MyPanelname->Text = L"Card Name";
			MyPanelname->Tag = i;

			Cards::Controls::cardSelectionPanels[i] = MyPanel;
			Cards::Controls::cardSelectionNames[i] = MyPanelname;
			Cards::Controls::cardSelectionStrengths[i] = MyPanelstrength;
			Cards::Controls::cardSelectionSkills[i] = MyPanelskill;
			Cards::Controls::cardSelectionSkill2s[i] = MyPanelskill2;
			Cards::Controls::cardSelectionTraits[i] = MyPaneltraits;

			Cards::Controls::cardSelectionPanels[i]->Click += gcnew System::EventHandler(this, &MyForm::CardSelection_Click_Panel);
			Cards::Controls::cardSelectionNames[i]->Click += gcnew System::EventHandler(this, &MyForm::CardSelection_Click_Label);
			Cards::Controls::cardSelectionStrengths[i]->Click += gcnew System::EventHandler(this, &MyForm::CardSelection_Click_Label);
			Cards::Controls::cardSelectionSkills[i]->Click += gcnew System::EventHandler(this, &MyForm::CardSelection_Click_Label);
			Cards::Controls::cardSelectionSkill2s[i]->Click += gcnew System::EventHandler(this, &MyForm::CardSelection_Click_Label);
			Cards::Controls::cardSelectionTraits[i]->Click += gcnew System::EventHandler(this, &MyForm::CardSelection_Click_Label);
		}
		for (int j = 0; j < COUNT_PLAYERS; j++)
		{
			(j == 0) ? Cards::Controls::cardsRemain[j] = cardsRemainL
					 : Cards::Controls::cardsRemain[j] = cardsRemainR;

			for (int i = 0; i < MAX_VICTORY_POINTS; i++)
			{
				PictureBox^ MyPictureBox = (gcnew PictureBox());
				MyPictureBox->Image = Image::FromFile("krone.png");
				(j == 0) ? MyPictureBox->Location = System::Drawing::Point(719 - 60 * i, 5)
						 : MyPictureBox->Location = System::Drawing::Point(1088 + 60 * i, 5);
				MyPictureBox->Name = L"pictureBox" + i;
				MyPictureBox->Size = System::Drawing::Size(53, 50);
				MyPictureBox->TabIndex = 10;
				MyPictureBox->TabStop = false;
				MyPictureBox->Visible = false;
				this->Controls->Add(MyPictureBox);
				Cards::Controls::pictureBoxes[j, i] = MyPictureBox;
			}

			for (int i = 0; i < MAX_DECK; i++)
			{
				Panel^ MyPanel = (gcnew Panel());
				(j == 0) ? MyPanel->BackColor = System::Drawing::Color::Yellow.IndianRed
						 : MyPanel->BackColor = System::Drawing::Color::Yellow.SeaGreen;
				MyPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				(j == 0) ? MyPanel->Location = System::Drawing::Point(127 - 2 * i, 115 + 2 * i)
						 : MyPanel->Location = System::Drawing::Point(1525 + 2 * i, 115 + 2 * i);
				MyPanel->Name = L"BackPanel" + i;
				MyPanel->Size = System::Drawing::Size(178, 242);
				MyPanel->Visible = false;
				MyPanel->Tag = j;
				this->Controls->Add(MyPanel);

				Cards::Controls::backPanels[j, i] = MyPanel;

				Cards::Controls::backPanels[j, i]->Click += gcnew System::EventHandler(this, &MyForm::Deck_Click_Panel);
			}

			for (int i = 0; i < Deck[j].size(); i++)
			{
				Cards::Controls::backPanels[j, i]->Visible = true;
				Cards::Controls::backPanels[j, i]->SendToBack();
			}

			for (int i = 0; i < MAX_HANDCARDS; i++)
			{
				Panel^ MyPanel = (gcnew Panel());
				Label^ MyPaneleffect = (gcnew System::Windows::Forms::Label());
				Label^ MyPanelname = (gcnew System::Windows::Forms::Label());
				MyPanel->BackColor = System::Drawing::Color::COLOR_TYP3;
				MyPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				MyPanel->Controls->Add(MyPaneleffect);
				MyPanel->Controls->Add(MyPanelname);
				(j == 0) ? MyPanel->Location = System::Drawing::Point(724 - 140 * (i % MAX_COLS_HAND) - 5 * (i / MAX_COLS_HAND), 720 + 30 * (i / MAX_COLS_HAND))
					   	 : MyPanel->Location = System::Drawing::Point(958 + 140 * (i % MAX_COLS_HAND) + 5 * (i / MAX_COLS_HAND), 720 + 30 * (i / MAX_COLS_HAND));
				MyPanel->Name = L"HandPanel" + i;
				MyPanel->Size = System::Drawing::Size(178, 242);
				MyPanel->Visible = false;
				MyPanel->Tag = MAX_CARDSTOCHOSE + MAX_CARDS_BACKLINE * COUNT_PLAYERS + j * MAX_HANDCARDS + i;
				this->Controls->Add(MyPanel);
				MyPanel->BringToFront();

				MyPaneleffect->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				MyPaneleffect->Location = System::Drawing::Point(-1, 80);
				(j == 0) ? MyPaneleffect->Name = L"LH" + i + "effect" : MyPaneleffect->Name = L"RH" + i + "effect";
				MyPaneleffect->Size = System::Drawing::Size(178, 130);
				MyPaneleffect->TabIndex = 2;
				MyPaneleffect->Text = L"Effect";
				MyPaneleffect->TextAlign = System::Drawing::ContentAlignment::TopCenter;
				MyPaneleffect->Tag = MAX_CARDSTOCHOSE + MAX_CARDS_BACKLINE * COUNT_PLAYERS + j * MAX_HANDCARDS + i;

				MyPanelname->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				MyPanelname->Location = System::Drawing::Point(7, 8);
				(j == 0) ? MyPanelname->Name = L"LH" + i + "name" : MyPanelname->Name = L"RH" + i + "name";
				MyPanelname->Size = System::Drawing::Size(143, 28);
				MyPanelname->TabIndex = 0;
				MyPanelname->Text = L"Card Name";
				MyPanelname->TextAlign = System::Drawing::ContentAlignment::TopCenter;
				MyPanelname->Tag = MAX_CARDSTOCHOSE + MAX_CARDS_BACKLINE * COUNT_PLAYERS + j * MAX_HANDCARDS + i;

				Cards::Controls::cardPanelsHand[j, i] = MyPanel;
				Cards::Controls::cardnamesHand[j, i] = MyPanelname;
				Cards::Controls::cardeffectsHand[j, i] = MyPaneleffect;

				Cards::Controls::cardPanelsHand[j, i]->Click += gcnew System::EventHandler(this, &MyForm::CardSelection_Click_Panel);
				Cards::Controls::cardnamesHand[j, i]->Click += gcnew System::EventHandler(this, &MyForm::CardSelection_Click_Label);
				Cards::Controls::cardeffectsHand[j, i]->Click += gcnew System::EventHandler(this, &MyForm::CardSelection_Click_Label);

				Cards::Controls::cardPanelsHand[j, i]->MouseHover += gcnew System::EventHandler(this, &MyForm::CardSelection_MouseHover_Panel);
				Cards::Controls::cardnamesHand[j, i]->MouseHover += gcnew System::EventHandler(this, &MyForm::CardSelection_MouseHover_Label);
				Cards::Controls::cardeffectsHand[j, i]->MouseHover += gcnew System::EventHandler(this, &MyForm::CardSelection_MouseHover_Label);
			}
				
			for (int i = 0; i < MAX_DECK; i++)
			{
				Panel^ MyPanel = (gcnew Panel());
				Label^ MyPaneltraits = (gcnew System::Windows::Forms::Label());
				Label^ MyPanelskill2 = (gcnew System::Windows::Forms::Label());
				Label^ MyPanelskill = (gcnew System::Windows::Forms::Label());
				Label^ MyPanelstrength = (gcnew System::Windows::Forms::Label());
				Label^ MyPanelname = (gcnew System::Windows::Forms::Label());
				MyPanel->BackColor = System::Drawing::Color::White;
				MyPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				MyPanel->Controls->Add(MyPaneltraits);
				MyPanel->Controls->Add(MyPanelskill2);
				MyPanel->Controls->Add(MyPanelskill);
				MyPanel->Controls->Add(MyPanelstrength);
				MyPanel->Controls->Add(MyPanelname);
				(j == 0) ? MyPanel->Location = System::Drawing::Point(60 - 2 * i, 435 + 2 * i)
						 : MyPanel->Location = System::Drawing::Point(1622 + 2 * i, 443 + 2 * i);
				MyPanel->Name = L"BackPanel" + i;
				MyPanel->Size = System::Drawing::Size(178, 242);
				MyPanel->Visible = false;
				MyPanel->Tag = j;
				this->Controls->Add(MyPanel);

				MyPaneltraits->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.75, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				MyPaneltraits->Location = System::Drawing::Point(-1, 220);
				(j == 0) ? MyPaneltraits->Name = L"LF" + i + "traits" : MyPaneltraits->Name = L"RF" + i + "traits";
				MyPaneltraits->Size = System::Drawing::Size(178, 62);
				MyPaneltraits->TabIndex = 3;
				MyPaneltraits->Text = L"Traits";
				MyPaneltraits->TextAlign = System::Drawing::ContentAlignment::TopCenter;
				MyPaneltraits->Tag = j;

				MyPanelskill2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				MyPanelskill2->Location = System::Drawing::Point(-1, 139);
				(j == 0) ? MyPanelskill2->Name = L"LF" + i + "skill2" : MyPanelskill2->Name = L"RF" + i + "skill2";
				MyPanelskill2->Size = System::Drawing::Size(178, 62);
				MyPanelskill2->TabIndex = 3;
				MyPanelskill2->Text = L"Skill2";
				MyPanelskill2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
				MyPanelskill2->Tag = j;

				MyPanelskill->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				MyPanelskill->Location = System::Drawing::Point(-1, 80);
				(j == 0) ? MyPanelskill->Name = L"LF" + i + "skill" : MyPanelskill->Name = L"RF" + i + "skill";
				MyPanelskill->Size = System::Drawing::Size(178, 62);
				MyPanelskill->TabIndex = 2;
				MyPanelskill->Text = L"Skill";
				MyPanelskill->TextAlign = System::Drawing::ContentAlignment::TopCenter;
				MyPanelskill->Tag = j;

				MyPanelstrength->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				MyPanelstrength->Location = System::Drawing::Point(146, 10);
				(j == 0) ? MyPanelstrength->Name = L"LF" + i + "strength" : MyPanelstrength->Name = L"RF" + i + "strength";
				MyPanelstrength->Size = System::Drawing::Size(27, 28);
				MyPanelstrength->TabIndex = 1;
				MyPanelstrength->Text = L"0";
				MyPanelstrength->Tag = j;

				MyPanelname->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				MyPanelname->Location = System::Drawing::Point(7, 8);
				(j == 0) ? MyPanelname->Name = L"LF" + i + "name" : MyPanelname->Name = L"RF" + i + "name";
				MyPanelname->Size = System::Drawing::Size(143, 28);
				MyPanelname->TabIndex = 0;
				MyPanelname->Text = L"Card Name";
				MyPanelname->Tag = j;

				Cards::Controls::cardPanelsDiscard[j, i] = MyPanel;
				Cards::Controls::cardnamesDiscard[j, i] = MyPanelname;
				Cards::Controls::cardstrengthsDiscard[j, i] = MyPanelstrength;
				Cards::Controls::cardskillsDiscard[j, i] = MyPanelskill;
				Cards::Controls::cardskill2sDiscard[j, i] = MyPanelskill2;
				Cards::Controls::cardtraitsDiscard[j, i] = MyPaneltraits;

				Cards::Controls::cardPanelsDiscard[j, i]->Click += gcnew System::EventHandler(this, &MyForm::DiscardPile_Click_Panel);
				Cards::Controls::cardnamesDiscard[j, i]->Click += gcnew System::EventHandler(this, &MyForm::DiscardPile_Click_Label);
				Cards::Controls::cardstrengthsDiscard[j, i]->Click += gcnew System::EventHandler(this, &MyForm::DiscardPile_Click_Label);
				Cards::Controls::cardskillsDiscard[j, i]->Click += gcnew System::EventHandler(this, &MyForm::DiscardPile_Click_Label);
				Cards::Controls::cardskill2sDiscard[j, i]->Click += gcnew System::EventHandler(this, &MyForm::DiscardPile_Click_Label);
				Cards::Controls::cardtraitsDiscard[j, i]->Click += gcnew System::EventHandler(this, &MyForm::DiscardPile_Click_Label);
			}

			for (int i = 0; i < MAX_CARDS_FRONTLINE; i++)
			{
				Panel^ MyPanel = (gcnew Panel());
				Label^ MyPaneltraits = (gcnew System::Windows::Forms::Label());
				Label^ MyPanelskill2 = (gcnew System::Windows::Forms::Label());
				Label^ MyPanelskill = (gcnew System::Windows::Forms::Label());
				Label^ MyPanelstrength = (gcnew System::Windows::Forms::Label());
				Label^ MyPanelname = (gcnew System::Windows::Forms::Label());
				MyPanel->BackColor = System::Drawing::Color::White;
				MyPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				MyPanel->Controls->Add(MyPaneltraits);
				MyPanel->Controls->Add(MyPanelskill2);
				MyPanel->Controls->Add(MyPanelskill);
				MyPanel->Controls->Add(MyPanelstrength);
				MyPanel->Controls->Add(MyPanelname);
				(j == 0) ? MyPanel->Location = System::Drawing::Point(724 - 180 * (i % MAX_COLS) - 5 * (i / MAX_COLS), 115 + 30 * (i / MAX_COLS))
					: MyPanel->Location = System::Drawing::Point(958 + 180 * (i % MAX_COLS) + 5 * (i / MAX_COLS), 115 + 30 * (i / MAX_COLS));
				(j == 0) ? MyPanel->Name = L"LF" + i : MyPaneltraits->Name = L"RF" + i;
				MyPanel->Size = System::Drawing::Size(178, 242);
				MyPanel->Visible = false;
				this->Controls->Add(MyPanel);

				MyPaneltraits->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.75, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				MyPaneltraits->Location = System::Drawing::Point(-1, 220);
				(j == 0) ? MyPaneltraits->Name = L"LF" + i + "traits" : MyPaneltraits->Name = L"RF" + i + "traits";
				MyPaneltraits->Size = System::Drawing::Size(178, 62);
				MyPaneltraits->TabIndex = 3;
				MyPaneltraits->Text = L"Traits";
				MyPaneltraits->TextAlign = System::Drawing::ContentAlignment::TopCenter;

				MyPanelskill2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				MyPanelskill2->Location = System::Drawing::Point(-1, 139);
				(j == 0) ? MyPanelskill2->Name = L"LF" + i + "skill2" : MyPanelskill2->Name = L"RF" + i + "skill2";
				MyPanelskill2->Size = System::Drawing::Size(178, 62);
				MyPanelskill2->TabIndex = 3;
				MyPanelskill2->Text = L"Skill2";
				MyPanelskill2->TextAlign = System::Drawing::ContentAlignment::TopCenter;

				MyPanelskill->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				MyPanelskill->Location = System::Drawing::Point(-1, 80);
				(j == 0) ? MyPanelskill->Name = L"LF" + i + "skill" : MyPanelskill->Name = L"RF" + i + "skill";
				MyPanelskill->Size = System::Drawing::Size(178, 62);
				MyPanelskill->TabIndex = 2;
				MyPanelskill->Text = L"Skill";
				MyPanelskill->TextAlign = System::Drawing::ContentAlignment::TopCenter;

				MyPanelstrength->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				MyPanelstrength->Location = System::Drawing::Point(146, 10);
				(j == 0) ? MyPanelstrength->Name = L"LF" + i + "strength" : MyPanelstrength->Name = L"RF" + i + "strength";
				MyPanelstrength->Size = System::Drawing::Size(27, 28);
				MyPanelstrength->TabIndex = 1;
				MyPanelstrength->Text = L"0";

				MyPanelname->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				MyPanelname->Location = System::Drawing::Point(7, 8);
				(j == 0) ? MyPanelname->Name = L"LF" + i + "name" : MyPanelname->Name = L"RF" + i + "name";
				MyPanelname->Size = System::Drawing::Size(143, 28);
				MyPanelname->TabIndex = 0;
				MyPanelname->Text = L"Card Name";

				Cards::Controls::cardPanels[j, i] = MyPanel;
				Cards::Controls::cardnames[j, i] = MyPanelname;
				Cards::Controls::cardstrengths[j, i] = MyPanelstrength;
				Cards::Controls::cardskills[j, i] = MyPanelskill;
				Cards::Controls::cardskill2s[j, i] = MyPanelskill2;
				Cards::Controls::cardtraits[j, i] = MyPaneltraits;

				Cards::Controls::cardPanels[j, i]->MouseHover += gcnew System::EventHandler(this, &MyForm::CardSelection_MouseHover_Panel);
				Cards::Controls::cardnames[j, i]->MouseHover += gcnew System::EventHandler(this, &MyForm::CardSelection_MouseHover_Label);
				Cards::Controls::cardstrengths[j, i]->MouseHover += gcnew System::EventHandler(this, &MyForm::CardSelection_MouseHover_Label);
				Cards::Controls::cardskills[j, i]->MouseHover += gcnew System::EventHandler(this, &MyForm::CardSelection_MouseHover_Label);
				Cards::Controls::cardskill2s[j, i]->MouseHover += gcnew System::EventHandler(this, &MyForm::CardSelection_MouseHover_Label);
				Cards::Controls::cardtraits[j, i]->MouseHover += gcnew System::EventHandler(this, &MyForm::CardSelection_MouseHover_Label);
			}

			for (int i = 0; i < MAX_CARDS_BACKLINE; i++)
			{
				Panel^ MyPanel = (gcnew Panel());
				Label^ MyPaneltraits = (gcnew System::Windows::Forms::Label());
				Label^ MyPanelskill2 = (gcnew System::Windows::Forms::Label());
				Label^ MyPanelskill = (gcnew System::Windows::Forms::Label());
				Label^ MyPanelstrength = (gcnew System::Windows::Forms::Label());
				Label^ MyPanelname = (gcnew System::Windows::Forms::Label());
				MyPanel->BackColor = System::Drawing::Color::COLOR_TYP2;
				MyPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				MyPanel->Controls->Add(MyPaneltraits);
				MyPanel->Controls->Add(MyPanelskill2);
				MyPanel->Controls->Add(MyPanelskill);
				MyPanel->Controls->Add(MyPanelstrength);
				MyPanel->Controls->Add(MyPanelname);
				(j == 0) ? MyPanel->Location = System::Drawing::Point(624 - 180 * (i % MAX_COLS) - 5 * (i / MAX_COLS), 470 + 30 * (i / MAX_COLS))
					: MyPanel->Location = System::Drawing::Point(1058 + 180 * (i % MAX_COLS) + 5 * (i / MAX_COLS), 470 + 30 * (i / MAX_COLS));
				(j == 0) ? MyPanel->Name = L"LB" + i : MyPaneltraits->Name = L"RB" + i;
				MyPanel->Size = System::Drawing::Size(178, 242);
				MyPanel->Visible = false;
				MyPanel->Tag = MAX_CARDSTOCHOSE + MAX_CARDS_BACKLINE * j + i;
				this->Controls->Add(MyPanel);

				MyPaneltraits->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.75, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				MyPaneltraits->Location = System::Drawing::Point(-1, 220);
				(j == 0) ? MyPaneltraits->Name = L"LB" + i + "traits" : MyPaneltraits->Name = L"RB" + i + "traits";
				MyPaneltraits->Size = System::Drawing::Size(178, 62);
				MyPaneltraits->TabIndex = 3;
				MyPaneltraits->Text = L"Traits";
				MyPaneltraits->TextAlign = System::Drawing::ContentAlignment::TopCenter;
				MyPaneltraits->Tag = MAX_CARDSTOCHOSE + MAX_CARDS_BACKLINE * j + i;

				MyPanelskill2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				MyPanelskill2->Location = System::Drawing::Point(-1, 139);
				(j == 0) ? MyPanelskill2->Name = L"LB" + i + "skill2" : MyPanelskill2->Name = L"RB" + i + "skill2";
				MyPanelskill2->Size = System::Drawing::Size(178, 62);
				MyPanelskill2->TabIndex = 3;
				MyPanelskill2->Text = L"Skill2";
				MyPanelskill2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
				MyPanelskill2->Tag = MAX_CARDSTOCHOSE + MAX_CARDS_BACKLINE * j + i;

				MyPanelskill->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				MyPanelskill->Location = System::Drawing::Point(-1, 80);
				(j == 0) ? MyPanelskill->Name = L"LB" + i + "skill" : MyPanelskill->Name = L"RB" + i + "skill";
				MyPanelskill->Size = System::Drawing::Size(178, 62);
				MyPanelskill->TabIndex = 2;
				MyPanelskill->Text = L"Skill";
				MyPanelskill->TextAlign = System::Drawing::ContentAlignment::TopCenter;
				MyPanelskill->Tag = MAX_CARDSTOCHOSE + MAX_CARDS_BACKLINE * j + i;

				MyPanelstrength->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				MyPanelstrength->Location = System::Drawing::Point(146, 10);
				(j == 0) ? MyPanelstrength->Name = L"LB" + i + "strength" : MyPanelstrength->Name = L"RB" + i + "strength";
				MyPanelstrength->Size = System::Drawing::Size(27, 28);
				MyPanelstrength->TabIndex = 1;
				MyPanelstrength->Text = L"0";
				MyPanelstrength->Tag = MAX_CARDSTOCHOSE + MAX_CARDS_BACKLINE * j + i;

				MyPanelname->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				MyPanelname->Location = System::Drawing::Point(7, 8);
				(j == 0) ? MyPanelname->Name = L"LB" + i + "name" : MyPanelname->Name = L"RB" + i + "name";
				MyPanelname->Size = System::Drawing::Size(143, 28);
				MyPanelname->TabIndex = 0;
				MyPanelname->Text = L"Card Name";
				MyPanelname->Tag = MAX_CARDSTOCHOSE + MAX_CARDS_BACKLINE * j + i;

				Cards::Controls::cardPanelsBackline[j, i] = MyPanel;
				Cards::Controls::cardnamesBackline[j, i] = MyPanelname;
				Cards::Controls::cardstrengthsBackline[j, i] = MyPanelstrength;
				Cards::Controls::cardskillsBackline[j, i] = MyPanelskill;
				Cards::Controls::cardskill2sBackline[j, i] = MyPanelskill2;
				Cards::Controls::cardtraitsBackline[j, i] = MyPaneltraits;

				Cards::Controls::cardPanelsBackline[j, i]->Click += gcnew System::EventHandler(this, &MyForm::CardSelection_Click_Panel);
				Cards::Controls::cardnamesBackline[j, i]->Click += gcnew System::EventHandler(this, &MyForm::CardSelection_Click_Label);
				Cards::Controls::cardstrengthsBackline[j, i]->Click += gcnew System::EventHandler(this, &MyForm::CardSelection_Click_Label);
				Cards::Controls::cardskillsBackline[j, i]->Click += gcnew System::EventHandler(this, &MyForm::CardSelection_Click_Label);
				Cards::Controls::cardskill2sBackline[j, i]->Click += gcnew System::EventHandler(this, &MyForm::CardSelection_Click_Label);
				Cards::Controls::cardtraitsBackline[j, i]->Click += gcnew System::EventHandler(this, &MyForm::CardSelection_Click_Label);

				Cards::Controls::cardPanelsBackline[j, i]->MouseHover += gcnew System::EventHandler(this, &MyForm::CardSelection_MouseHover_Panel);
				Cards::Controls::cardnamesBackline[j, i]->MouseHover += gcnew System::EventHandler(this, &MyForm::CardSelection_MouseHover_Label);
				Cards::Controls::cardstrengthsBackline[j, i]->MouseHover += gcnew System::EventHandler(this, &MyForm::CardSelection_MouseHover_Label);
				Cards::Controls::cardskillsBackline[j, i]->MouseHover += gcnew System::EventHandler(this, &MyForm::CardSelection_MouseHover_Label);
				Cards::Controls::cardskill2sBackline[j, i]->MouseHover += gcnew System::EventHandler(this, &MyForm::CardSelection_MouseHover_Label);
				Cards::Controls::cardtraitsBackline[j, i]->MouseHover += gcnew System::EventHandler(this, &MyForm::CardSelection_MouseHover_Label);
			}

			Cards::Controls::cardsRemain[j]->Text = Deck[j].size().ToString();
			(j == 0) ? Cards::Controls::score[j] = scoreL : Cards::Controls::score[j] = scoreR;
		}
		Cards::updatePiles();
		Cards::draftCard(DeckA);
		Cards::showHandCards();
	}
	};
}