#include "Create_manager.h"
#include "Create_head_of_support.h"
#include "Choose_account.h"
#include "Create_building_type.h"
#include "Create_material.h"
#include "Requests_Menu.h"
#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	ref class Registration;

	/// <summary>
	/// Сводка для Admin
	/// </summary>
	public ref class Admin : public System::Windows::Forms::Form
	{
	public:
		Admin(Registration^ registration_form_send)
		{
			InitializeComponent();

			registration_form = registration_form_send;
			manager_form = gcnew Create_manager(this);
			support_form = gcnew Create_head_of_support(this);
			choose_form = gcnew Choose_account(this);
			create_buil_form = gcnew Create_building_type(this);
			create_material_form = gcnew Create_material(this);
			requests_menu_form = gcnew Requests_Menu(this);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Admin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;


	private: System::Windows::Forms::Button^ button5;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
		Registration^ registration_form;
		Create_manager^ manager_form;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
		   Create_head_of_support^ support_form;
	private: System::Windows::Forms::Button^ button6;
		   Choose_account^ choose_form;
	private: System::Windows::Forms::Button^ button7;
		   Create_building_type^ create_buil_form;
	private: System::Windows::Forms::Button^ button8;
		   Create_material^ create_material_form;
		   Requests_Menu^ requests_menu_form;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(210, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(414, 34);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Меню адміністратора";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(47, 80);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(336, 58);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Створити нового менеджера";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Admin::button1_Click);
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(47, 144);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(337, 58);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Створити нового голову\r\n забезпечення";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Admin::button2_Click);
			// 
			// button5
			// 
			this->button5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(34, 385);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(86, 38);
			this->button5->TabIndex = 5;
			this->button5->Text = L"Вийти";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Admin::button5_Click);
			// 
			// button4
			// 
			this->button4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(48, 272);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(336, 58);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Підключення акаунту";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Admin::button4_Click);
			// 
			// button3
			// 
			this->button3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(47, 208);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(336, 58);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Відключення акаунту";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Admin::button3_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button6->Location = System::Drawing::Point(455, 81);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(336, 58);
			this->button6->TabIndex = 6;
			this->button6->Text = L"Додати новий тип будинку";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Admin::button6_Click);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button7->Location = System::Drawing::Point(455, 145);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(336, 58);
			this->button7->TabIndex = 7;
			this->button7->Text = L"Додати новий матеріал";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Admin::button7_Click);
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button8->Location = System::Drawing::Point(455, 208);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(336, 58);
			this->button8->TabIndex = 8;
			this->button8->Text = L"Меню запитів";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Admin::button8_Click);
			// 
			// Admin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(836, 452);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"Admin";
			this->Text = L"Admin";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e);
		   public: String^ login;
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e);
};
}
