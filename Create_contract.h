#pragma once
#include <D:/Programs/C++ My Work/Course №2/Project1/sqlite/sqlite3.h>
#include <string>
#include "Choose_building_type.h"

namespace Project1 {
	
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	ref class Manager;

	/// <summary>
	/// Сводка для Create_contract
	/// </summary>
	public ref class Create_contract : public System::Windows::Forms::Form
	{
	public:
		Create_contract(Manager^ manager_form_ref)
		{
			InitializeComponent();
			
			choose_builType_Form = gcnew Choose_building_type(this);
			manager_form = manager_form_ref;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Create_contract()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button2;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ button3;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

		Choose_building_type^ choose_builType_Form;
		Manager^ manager_form;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button2->Location = System::Drawing::Point(698, 452);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(114, 38);
			this->button2->TabIndex = 47;
			this->button2->Text = L"Створити";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Create_contract::button2_Click);
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button1->Location = System::Drawing::Point(66, 452);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(114, 38);
			this->button1->TabIndex = 46;
			this->button1->Text = L"Назад";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Create_contract::button1_Click);
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(278, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(330, 29);
			this->label1->TabIndex = 45;
			this->label1->Text = L"Меню створення контракту";
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(109, 90);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(55, 16);
			this->label2->TabIndex = 48;
			this->label2->Text = L"Адреса";
			this->textBox1->Location = System::Drawing::Point(112, 109);
			this->textBox1->MaxLength = 255;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(261, 22);
			this->textBox1->TabIndex = 49;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(110, 154);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(102, 16);
			this->label3->TabIndex = 50;
			this->label3->Text = L"Площа ділянки";
			this->textBox2->Location = System::Drawing::Point(112, 173);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(261, 22);
			this->textBox2->TabIndex = 51;
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(113, 218);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(99, 16);
			this->label4->TabIndex = 52;
			this->label4->Text = L"Площа будівлі";
			this->textBox3->Location = System::Drawing::Point(113, 237);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(260, 22);
			this->textBox3->TabIndex = 53;
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(113, 282);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(124, 16);
			this->label5->TabIndex = 54;
			this->label5->Text = L"Кількість поверхів";
			this->textBox4->Location = System::Drawing::Point(113, 301);
			this->textBox4->MaxLength = 2;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(260, 22);
			this->textBox4->TabIndex = 55;
			this->textBox5->Location = System::Drawing::Point(523, 109);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(261, 22);
			this->textBox5->TabIndex = 56;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &Create_contract::textBox5_TextChanged);
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(520, 90);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(133, 16);
			this->label6->TabIndex = 57;
			this->label6->Text = L"Дата початку робіт";
			this->label6->Click += gcnew System::EventHandler(this, &Create_contract::label6_Click);
			this->label7->Location = System::Drawing::Point(520, 154);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(90, 16);
			this->label7->TabIndex = 58;
			this->label7->Text = L"Тип будинку";
			this->textBox6->Location = System::Drawing::Point(523, 173);
			this->textBox6->Name = L"textBox6";
			this->textBox6->ReadOnly = true;
			this->textBox6->Size = System::Drawing::Size(136, 22);
			this->textBox6->TabIndex = 59;
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(523, 239);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(261, 24);
			this->comboBox1->TabIndex = 60;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Create_contract::comboBox1_SelectedIndexChanged);
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(531, 220);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(49, 16);
			this->label8->TabIndex = 61;
			this->label8->Text = L"Клієнт";
			this->label8->Click += gcnew System::EventHandler(this, &Create_contract::label8_Click);
			this->button3->Location = System::Drawing::Point(675, 172);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(109, 23);
			this->button3->TabIndex = 62;
			this->button3->Text = L"обрати ->";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Create_contract::button3_Click);
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(880, 525);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"Create_contract";
			this->Text = L"Create_contract";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
	   public: String^ login_manager;
		public: int bul_index;
	public: Void update_ComboBox() {
		comboBox1->Items->Clear();
		sqlite3* db;
		sqlite3_stmt* stmt;

		int rc = sqlite3_open("db\\Building_database.db", &db);
		const char* query = "SELECT Id, Full_name FROM Client";
		rc = sqlite3_prepare_v2(db, query, -1, &stmt, nullptr);

		if (rc != SQLITE_OK) {
			MessageBox::Show("SQLITE_ERROR", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Error);
			sqlite3_close(db);
			return;
		}

		while (sqlite3_step(stmt) == SQLITE_ROW) {
			const unsigned char* id = sqlite3_column_text(stmt, 0);
			const unsigned char* name = sqlite3_column_text(stmt, 1);

			string itemText = reinterpret_cast<const char*>(id);
			itemText += ", ";
			itemText += reinterpret_cast<const char*>(name);

			comboBox1->Items->Add(gcnew String(itemText.c_str()));
		}

		// Освобождаем ресурсы
		sqlite3_finalize(stmt);
		sqlite3_close(db);

	}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);

	  public: void changeTextBox(String^ text) {
		   textBox6->Text = text;
	   }

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
};
}
