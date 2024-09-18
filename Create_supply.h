#pragma once
#include <Windows.h>
#include <vcclr.h>
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

	ref class Head_of_Support_Department;

	/// <summary>
	/// Сводка для Create_supply
	/// </summary>
	public ref class Create_supply : public System::Windows::Forms::Form
	{
	public:
		Create_supply(Head_of_Support_Department^ support_form_ref)
		{
			InitializeComponent();
			support_form = support_form_ref;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Create_supply()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
		cli::array<ComboBox^>^ supplierComboBoxes;
		cli::array<ComboBox^>^ transporterComboBoxes;
		cli::array<int>^ Materials_id;
		int Contract_id;

		Head_of_Support_Department^ support_form;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(278, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(321, 29);
			this->label1->TabIndex = 46;
			this->label1->Text = L"Меню створення поставки";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(93, 82);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(103, 16);
			this->label2->TabIndex = 47;
			this->label2->Text = L"Дата поставки";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(87, 102);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(261, 22);
			this->textBox1->TabIndex = 48;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(95, 140);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(68, 16);
			this->label8->TabIndex = 63;
			this->label8->Text = L"Контракт";
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(87, 159);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(261, 24);
			this->comboBox1->TabIndex = 62;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Create_supply::comboBox1_SelectedIndexChanged);
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Location = System::Drawing::Point(399, 102);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(427, 332);
			this->panel1->TabIndex = 64;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button2->Location = System::Drawing::Point(698, 452);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(114, 38);
			this->button2->TabIndex = 66;
			this->button2->Text = L"Створити";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Create_supply::button2_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button1->Location = System::Drawing::Point(66, 452);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(114, 38);
			this->button1->TabIndex = 65;
			this->button1->Text = L"Назад";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Create_supply::button1_Click);
			// 
			// Create_supply
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(880, 525);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Create_supply";
			this->Text = L"Create_supply";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);

	   public: Void update_ComboBox() {
		   comboBox1->Items->Clear();
		   sqlite3* db;
		   sqlite3_stmt* stmt;

		   int rc = sqlite3_open("db\\Building_database.db", &db);
		   const char* query = "SELECT Contract.Id, Contract.Address FROM Contract LEFT JOIN Necessary_material ON Contract.Id = Necessary_material.Id_contract WHERE Necessary_material.isExist != 1 GROUP BY Contract.Id";
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
			 public: String^ login;

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
};
}
