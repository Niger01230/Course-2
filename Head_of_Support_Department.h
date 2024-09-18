#pragma once
#include "Create_ProviderOrCarrier.h"
#include "Create_supply.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	ref class Registration;

	/// <summary>
	/// Сводка для Head_of_Support_Department
	/// </summary>
	public ref class Head_of_Support_Department : public System::Windows::Forms::Form
	{
	public:
		Head_of_Support_Department(Registration^ ref_form_ref)
		{
			InitializeComponent();
			
			providerOrCarrier_form = gcnew Create_ProviderOrCarrier(this);
			supply_form = gcnew Create_supply(this);
			reg_form = ref_form_ref;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Head_of_Support_Department()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;



	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
		Create_ProviderOrCarrier^ providerOrCarrier_form;
	private: System::Windows::Forms::Button^ button3;
		   Registration^ reg_form;
		   Create_supply^ supply_form;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button5
			// 
			this->button5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(42, 395);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(86, 38);
			this->button5->TabIndex = 15;
			this->button5->Text = L"Вийти";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Head_of_Support_Department::button5_Click);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(218, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(414, 34);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Меню голови деп. забезпечення";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(42, 148);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(337, 58);
			this->button2->TabIndex = 17;
			this->button2->Text = L"Створити нового перевізника";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Head_of_Support_Department::button2_Click);
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(42, 84);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(336, 58);
			this->button1->TabIndex = 16;
			this->button1->Text = L"Створити нового постачальника";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Head_of_Support_Department::button1_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button3->Location = System::Drawing::Point(42, 212);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(337, 58);
			this->button3->TabIndex = 18;
			this->button3->Text = L"Створити нову поставку";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Head_of_Support_Department::button3_Click);
			// 
			// Head_of_Support_Department
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(836, 452);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label1);
			this->Name = L"Head_of_Support_Department";
			this->Text = L"Head_of_Support_Department";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
	   public: String^ login;
};
}
