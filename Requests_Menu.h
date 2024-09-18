#pragma once
#include "Choose_contract.h"
#include "Choose_Provider.h"
#include "Choose_Manager.h"
#include "Choose_Client.h"
#include "Choose_Surname.h"
#include "Choose_Day.h"
#include "Choose_surname_and_date.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	ref class Admin;

	/// <summary>
	/// Сводка для Requests_Menu
	/// </summary>
	public ref class Requests_Menu : public System::Windows::Forms::Form
	{
	public:
		Requests_Menu(Admin^ admin_form_ref)
		{
			InitializeComponent();
			
			choose_contract_form = gcnew Choose_contract(this);
			choose_provider_form = gcnew Choose_Provider(this);
			choose_manager_form = gcnew Choose_Manager(this);
			choose_client_form = gcnew Choose_Client(this);
			choose_surname_form = gcnew Choose_Surname(this);
			choose_day_form = gcnew Choose_Day(this);
			choose_surname_and_date_form = gcnew Choose_surname_and_date(this);
			admin_form = admin_form_ref;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Requests_Menu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button11;
	private: System::Windows::Forms::Button^ button12;
	private: System::Windows::Forms::Button^ button13;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
		Choose_contract^ choose_contract_form;
		Choose_Provider^ choose_provider_form;
		Choose_Manager^ choose_manager_form;
		Choose_Client^ choose_client_form;
		Choose_Surname^ choose_surname_form;
		Choose_Day^ choose_day_form;
		Choose_surname_and_date^ choose_surname_and_date_form;

		Admin^ admin_form;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(246, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(414, 34);
			this->label1->TabIndex = 15;
			this->label1->Text = L"Меню запитів";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(33, 62);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(420, 394);
			this->textBox1->TabIndex = 16;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(33, 469);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(86, 38);
			this->button1->TabIndex = 17;
			this->button1->Text = L"Назад";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Requests_Menu::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(470, 62);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(201, 60);
			this->button2->TabIndex = 18;
			this->button2->Text = L"Складання кошторису контракту";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Requests_Menu::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(470, 128);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(201, 60);
			this->button3->TabIndex = 19;
			this->button3->Text = L"Контракти, які коштують більше ніж середня ціна усіх контрактів";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Requests_Menu::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(470, 198);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(201, 60);
			this->button4->TabIndex = 20;
			this->button4->Text = L"Усі виплати постачальника за обраний період";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Requests_Menu::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(470, 264);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(201, 60);
			this->button5->TabIndex = 21;
			this->button5->Text = L"Кількість створених контрактів за тиждень";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Requests_Menu::button5_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6->Location = System::Drawing::Point(470, 330);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(201, 60);
			this->button6->TabIndex = 22;
			this->button6->Text = L"Кількість створених контрактів кожним менеджером за період";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Requests_Menu::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(470, 396);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(201, 60);
			this->button7->TabIndex = 23;
			this->button7->Text = L"Усі контракти створені конкретним менеджером за обраний період";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Requests_Menu::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(684, 62);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(201, 60);
			this->button8->TabIndex = 24;
			this->button8->Text = L"Усі необхідні матеріали та їх кількість для реалізації конкретного контракту";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Requests_Menu::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(684, 128);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(201, 60);
			this->button9->TabIndex = 25;
			this->button9->Text = L"Усі контракти конкретного клієнта";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &Requests_Menu::button9_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(684, 198);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(201, 60);
			this->button10->TabIndex = 26;
			this->button10->Text = L"Усі менеджери з визначеним прізвищем";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Requests_Menu::button10_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(684, 264);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(201, 60);
			this->button11->TabIndex = 27;
			this->button11->Text = L"Знайти найдорожчі контракти.";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &Requests_Menu::button11_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(684, 330);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(201, 60);
			this->button12->TabIndex = 28;
			this->button12->Text = L"Кто з менеджерів не створював контракти в конкретний день";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &Requests_Menu::button12_Click);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(684, 396);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(201, 60);
			this->button13->TabIndex = 29;
			this->button13->Text = L"Кто створював та кто не створював контракти в конкретний день";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &Requests_Menu::button13_Click);
			// 
			// Requests_Menu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(906, 519);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"Requests_Menu";
			this->Text = L"Requests_Menu";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);

		   public: Void Update_TextBox(String^ Text) {
			   textBox1->Text = Text;
		   }
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button12_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
};
}
