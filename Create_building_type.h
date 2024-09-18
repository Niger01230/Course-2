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

	ref class Admin;

	/// <summary>
	/// Сводка для Create_building_type
	/// </summary>
	public ref class Create_building_type : public System::Windows::Forms::Form
	{
	public:
		Create_building_type(Admin^ admin_ref_form)
		{
			InitializeComponent();
			
			admin_form = admin_ref_form;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Create_building_type()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ListBox^ listBox1;
		   Admin^ admin_form;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(148, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(355, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Меню додавання типу будівлі";
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(92, 66);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 23);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Назва";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button1->Location = System::Drawing::Point(12, 318);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(119, 38);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Назад";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Create_building_type::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoEllipsis = true;
			this->label3->Location = System::Drawing::Point(92, 125);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(397, 34);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Картинка (додайте картинку у папку \"images\" та напишіть її назву, наприклад \"imag"
				L"e.png\")";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button2->Location = System::Drawing::Point(507, 318);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(119, 38);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Створити";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Create_building_type::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(95, 85);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(305, 22);
			this->textBox1->TabIndex = 6;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(95, 162);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(304, 22);
			this->textBox2->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(97, 193);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(362, 16);
			this->label4->TabIndex = 59;
			this->label4->Text = L"Оберіть матеріали (щоб обрати декілька - зажміть Shift)";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(95, 212);
			this->listBox1->Name = L"listBox1";
			this->listBox1->SelectionMode = System::Windows::Forms::SelectionMode::MultiExtended;
			this->listBox1->Size = System::Drawing::Size(261, 68);
			this->listBox1->TabIndex = 58;
			// 
			// Create_building_type
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(638, 368);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"Create_building_type";
			this->Text = L"Create_building_type";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);

	   public: Void update_ListBox() {
		   listBox1->Items->Clear();
		   sqlite3* db;
		   sqlite3_stmt* stmt;

		   int rc = sqlite3_open("db\\Building_database.db", &db);
		   const char* query = "SELECT Id, Name FROM Material";
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

			   listBox1->Items->Add(gcnew String(itemText.c_str()));
		   }

		   // Освобождаем ресурсы
		   sqlite3_finalize(stmt);
		   sqlite3_close(db);

	   }
};
}
