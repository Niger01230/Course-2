#pragma once
#include <D:/Programs/C++ My Work/Course №2/Project1/sqlite/sqlite3.h>
#include <string>

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
	/// Сводка для Edit_contract
	/// </summary>
	public ref class Edit_contract : public System::Windows::Forms::Form
	{
	public:
		Edit_contract(Manager^ manager_form_ref)
		{
			InitializeComponent();
			
			manager_form = manager_form_ref;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Edit_contract()
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
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
		int id_contract;
		DateTime start_date;
		int cost;
		bool isImprest;
		bool isPaid;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button2->Location = System::Drawing::Point(273, 475);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(142, 38);
			this->button2->TabIndex = 50;
			this->button2->Text = L"Редагувати";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Edit_contract::button2_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button1->Location = System::Drawing::Point(12, 475);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(114, 38);
			this->button1->TabIndex = 49;
			this->button1->Text = L"Назад";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Edit_contract::button1_Click);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(52, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(354, 29);
			this->label1->TabIndex = 48;
			this->label1->Text = L"Меню редагування контракту";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(28, 157);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(194, 22);
			this->textBox1->TabIndex = 51;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(28, 215);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(193, 22);
			this->textBox2->TabIndex = 52;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(28, 260);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(146, 20);
			this->checkBox1->TabIndex = 53;
			this->checkBox1->Text = L"Чи внесено аванс";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(28, 286);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(175, 20);
			this->checkBox2->TabIndex = 54;
			this->checkBox2->Text = L"Чи повністю оплачено";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(28, 100);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(194, 24);
			this->comboBox1->TabIndex = 55;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Edit_contract::comboBox1_SelectedIndexChanged);
			// 
			// comboBox2
			// 
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(28, 343);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(194, 24);
			this->comboBox2->TabIndex = 56;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(38, 81);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(68, 16);
			this->label2->TabIndex = 57;
			this->label2->Text = L"Контракт";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(38, 138);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(92, 16);
			this->label3->TabIndex = 58;
			this->label3->Text = L"Кінцева дата";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(38, 196);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(47, 16);
			this->label4->TabIndex = 59;
			this->label4->Text = L"Аванс";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(38, 324);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(75, 16);
			this->label5->TabIndex = 60;
			this->label5->Text = L"Менеджер";
			// 
			// label6
			// 
			this->label6->Location = System::Drawing::Point(256, 81);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(133, 79);
			this->label6->TabIndex = 61;
			this->label6->Text = L"Залиште поле порожнім, якщо не хочете його змінювати*";
			// 
			// Edit_contract
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(427, 525);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"Edit_contract";
			this->Text = L"Edit_contract";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);

	   public: Void update_ComboBox_1() {
		   comboBox1->Items->Clear();
		   sqlite3* db;
		   sqlite3_stmt* stmt;

		   int rc = sqlite3_open("db\\Building_database.db", &db);
		   const char* query = "SELECT Id, Address FROM Contract";
		   rc = sqlite3_prepare_v2(db, query, -1, &stmt, nullptr);

		   if (rc != SQLITE_OK) {
			   MessageBox::Show("SQLITE_ERROR", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Error);
			   sqlite3_close(db);
			   return;
		   }

		   while (sqlite3_step(stmt) == SQLITE_ROW) {
			   const unsigned char* id = sqlite3_column_text(stmt, 0);
			   const unsigned char* address = sqlite3_column_text(stmt, 1);

			   string itemText = reinterpret_cast<const char*>(id);
			   itemText += ", ";
			   itemText += reinterpret_cast<const char*>(address);

			   comboBox1->Items->Add(gcnew String(itemText.c_str()));
		   }

		   // Освобождаем ресурсы
		   sqlite3_finalize(stmt);
		   sqlite3_close(db);

	   }
			 public: Void update_ComboBox_2() {
				 comboBox2->Items->Clear();
				 sqlite3* db;
				 sqlite3_stmt* stmt;

				 int rc = sqlite3_open("db\\Building_database.db", &db);
				 const char* query = "SELECT Id, Full_name FROM Manager";
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

					 comboBox2->Items->Add(gcnew String(itemText.c_str()));
				 }

				 // Освобождаем ресурсы
				 sqlite3_finalize(stmt);
				 sqlite3_close(db);

			 }
};
}
