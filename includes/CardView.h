#pragma once
#include "Cards.h"
#include "Globals.h"

#define MAX_COLS_SHOWDECK 10

namespace CardGame {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CardView
	/// </summary>
	public ref class CardView : public System::Windows::Forms::Form
	{
	public:
		CardView(void)
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
		~CardView()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->SuspendLayout();
			// 
			// CardView
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->ClientSize = System::Drawing::Size(1200, 250);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"CardView";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CardView";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &CardView::CardView_FormClosing);
			this->Load += gcnew System::EventHandler(this, &CardView::CardView_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	public: System::Void Card_Click_Panel(System::Object^ sender, System::EventArgs^ e) {
		Panel^ senderObject = safe_cast<Panel^>(sender);
		Cards::chooseCardView(System::Convert::ToInt16(senderObject->Tag), this);
	}
	public: System::Void Card_Click_Label(System::Object^ sender, System::EventArgs^ e) {
		Label^ senderObject = safe_cast<Label^>(sender);
		Cards::chooseCardView(System::Convert::ToInt16(senderObject->Tag), this);
	}
	private: System::Void CardView_Load(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < count_showCards; i++)
		{
			Panel^ MyPanel = (gcnew Panel());
			Label^ MyPaneltraits = (gcnew System::Windows::Forms::Label());
			Label^ MyPanelskill2 = (gcnew System::Windows::Forms::Label());
			Label^ MyPanelskill = (gcnew System::Windows::Forms::Label());
			Label^ MyPanelstrength = (gcnew System::Windows::Forms::Label());
			Label^ MyPanelname = (gcnew System::Windows::Forms::Label());
			switch (Deck[showDeckPlayer].at(pos[showDeckPlayer] + i).type)
			{
			case 1:
				MyPanel->BackColor = System::Drawing::Color::COLOR_TYP1;
				break;
			case 2:
				MyPanel->BackColor = System::Drawing::Color::COLOR_TYP2;
				break;
			default:
				MyPanel->BackColor = System::Drawing::Color::COLOR_TYP1;
				break;
			}
			MyPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			MyPanel->Controls->Add(MyPaneltraits);
			MyPanel->Controls->Add(MyPanelskill2);
			MyPanel->Controls->Add(MyPanelskill);
			MyPanel->Controls->Add(MyPanelstrength);
			MyPanel->Controls->Add(MyPanelname);
			MyPanel->Location = System::Drawing::Point(5 + 180 * (i % MAX_COLS_SHOWDECK) - 5 * (i / MAX_COLS_SHOWDECK), 5 + 244 * (i / MAX_COLS_SHOWDECK));
			MyPanel->Name = L"Card" + i;
			MyPanel->Size = System::Drawing::Size(178, 242);
			MyPanel->Tag = i;
			this->Controls->Add(MyPanel);

			MyPaneltraits->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.75, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			MyPaneltraits->Location = System::Drawing::Point(-1, 220);
			MyPaneltraits->Name = L"Card" + i + "traits";
			MyPaneltraits->Size = System::Drawing::Size(178, 62);
			MyPaneltraits->TabIndex = 3;
			MyPaneltraits->Text = gcnew System::String(Deck[showDeckPlayer].at(pos[showDeckPlayer] + i).traits.data());
			MyPaneltraits->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			MyPaneltraits->Tag = i;

			MyPanelskill2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			MyPanelskill2->Location = System::Drawing::Point(-1, 139);
			MyPanelskill2->Name = L"Card" + i + "skill2";
			MyPanelskill2->Size = System::Drawing::Size(178, 62);
			MyPanelskill2->TabIndex = 3;
			MyPanelskill2->Text = gcnew System::String(Deck[showDeckPlayer].at(pos[showDeckPlayer] + i).writeSkill(Deck[showDeckPlayer].at(pos[showDeckPlayer] + i).skill2).data());
			MyPanelskill2->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			MyPanelskill2->Tag = i;

			MyPanelskill->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			MyPanelskill->Location = System::Drawing::Point(-1, 80);
			MyPanelskill->Name = L"Card" + i + "skill";
			MyPanelskill->Size = System::Drawing::Size(178, 62);
			MyPanelskill->TabIndex = 2;
			MyPanelskill->Text = gcnew System::String(Deck[showDeckPlayer].at(pos[showDeckPlayer] + i).writeSkill(Deck[showDeckPlayer].at(pos[showDeckPlayer] + i).skill).data());
			MyPanelskill->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			MyPanelskill->Tag = i;

			MyPanelstrength->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			MyPanelstrength->Location = System::Drawing::Point(146, 10);
			MyPanelstrength->Name = L"Card" + i + "strength";
			MyPanelstrength->Size = System::Drawing::Size(27, 28);
			MyPanelstrength->TabIndex = 1;
			MyPanelstrength->Text = Deck[showDeckPlayer].at(pos[showDeckPlayer] + i).strength.ToString();
			MyPanelstrength->Tag = i;

			MyPanelname->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			MyPanelname->Location = System::Drawing::Point(7, 8);
			MyPanelname->Name = L"Card" + i + "name";
			MyPanelname->Size = System::Drawing::Size(143, 28);
			MyPanelname->TabIndex = 0;
			MyPanelname->Text = gcnew System::String(Deck[showDeckPlayer].at(pos[showDeckPlayer] + i).name.data());
			MyPanelname->Tag = i;

			Cards::Controls::cardPanelsShowCard[i] = MyPanel;
			Cards::Controls::cardNamesShowCard[i] = MyPanelname;
			Cards::Controls::cardStrengthsShowCard[i] = MyPanelstrength;
			Cards::Controls::cardSkillsShowCard[i] = MyPanelskill;
			Cards::Controls::cardSkill2sShowCard[i] = MyPanelskill2;
			Cards::Controls::cardTraitsShowCard[i] = MyPaneltraits;

			Cards::Controls::cardPanelsShowCard[i]->Click += gcnew System::EventHandler(this, &CardView::Card_Click_Panel);
			Cards::Controls::cardNamesShowCard[i]->Click += gcnew System::EventHandler(this, &CardView::Card_Click_Label);
			Cards::Controls::cardStrengthsShowCard[i]->Click += gcnew System::EventHandler(this, &CardView::Card_Click_Label);
			Cards::Controls::cardSkillsShowCard[i]->Click += gcnew System::EventHandler(this, &CardView::Card_Click_Label);
			Cards::Controls::cardSkill2sShowCard[i]->Click += gcnew System::EventHandler(this, &CardView::Card_Click_Label);
			Cards::Controls::cardTraitsShowCard[i]->Click += gcnew System::EventHandler(this, &CardView::Card_Click_Label);
		}
	}
	private: System::Void CardView_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		Cards::highlightUseableCards();
	}
};
}

