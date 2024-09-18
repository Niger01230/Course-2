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

	ref class Requests_Menu;

	/// <summary>
	/// Сводка для Choose_contract
	/// </summary>
	public ref class Choose_contract : public System::Windows::Forms::Form
	{
	public:
		Choose_contract(Requests_Menu^ requests_menu_form_ref)
		{
			InitializeComponent();
			
			requests_menu_form = requests_menu_form_ref;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Choose_contract()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button2;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
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
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(45, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(414, 34);
			this->label1->TabIndex = 16;
			this->label1->Text = L"Оберіть контракт";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(12, 208);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(103, 38);
			this->button1->TabIndex = 18;
			this->button1->Text = L"Назад";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Choose_contract::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(81, 95);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(333, 24);
			this->comboBox1->TabIndex = 19;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label2->Location = System::Drawing::Point(77, 72);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(104, 20);
			this->label2->TabIndex = 20;
			this->label2->Text = L"Контракти:";
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(382, 208);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(103, 38);
			this->button2->TabIndex = 21;
			this->button2->Text = L"Обрати";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Choose_contract::button2_Click);
			// 
			// Choose_contract
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(497, 258);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"Choose_contract";
			this->Text = L"Choose_contract";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		public: Void update_ComboBox() {
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
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
		   public: int choose;
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
};
}
