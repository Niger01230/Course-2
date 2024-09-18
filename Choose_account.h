#pragma once
#include "DisEnab_manager.h"
#include "DisEnab_headOfSupport.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	ref class Admin;

	/// <summary>
	/// Сводка для Choose_account
	/// </summary>
	public ref class Choose_account : public System::Windows::Forms::Form
	{
	public:
		Choose_account(Admin^ admin_ref)
		{
			InitializeComponent();
			
			disEnab_manager_form = gcnew DisEnab_manager(this);
			disEnab_head_form = gcnew DisEnab_headOfSupport(this);
			admin_form = admin_ref;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Choose_account()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
		DisEnab_manager^ disEnab_manager_form;
		DisEnab_headOfSupport^ disEnab_head_form;
		Admin^ admin_form;
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
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(59, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(418, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Оберіть, кого потрібно відключити";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button1->Location = System::Drawing::Point(29, 117);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(484, 97);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Менеджер";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Choose_account::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button2->Location = System::Drawing::Point(29, 246);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(484, 97);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Голова департаменту забезпечення";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Choose_account::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button3->Location = System::Drawing::Point(29, 410);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(86, 38);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Назад";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Choose_account::button3_Click);
			// 
			// Choose_account
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(544, 478);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"Choose_account";
			this->Text = L"Choose_account";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);

	   public: int choose;
	   public: Void change_Disable() {
		   label1->Text = "Оберіть, кого потрібно відключити";
		   choose = 0;
	   }
	public: Void change_Enable() {
		label1->Text = "Оберіть, кого потрібно підключити";
		choose = 1;
	}
};



}
