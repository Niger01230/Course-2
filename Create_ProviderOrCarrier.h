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

	ref class Head_of_Support_Department;

	/// <summary>
	/// Сводка для Create_ProviderOrCarrier
	/// </summary>
	public ref class Create_ProviderOrCarrier : public System::Windows::Forms::Form
	{
	public:
		Create_ProviderOrCarrier(Head_of_Support_Department^ head_of_Support_form_ref)
		{
			InitializeComponent();
			
			head_of_Support_form = head_of_Support_form_ref;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Create_ProviderOrCarrier()
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
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Label^ label4;
		   Head_of_Support_Department^ head_of_Support_form;

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
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button2->Location = System::Drawing::Point(374, 457);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(114, 38);
			this->button2->TabIndex = 50;
			this->button2->Text = L"Створити";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Create_ProviderOrCarrier::button2_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button1->Location = System::Drawing::Point(67, 457);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(114, 38);
			this->button1->TabIndex = 49;
			this->button1->Text = L"Назад";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Create_ProviderOrCarrier::button1_Click);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(76, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(391, 29);
			this->label1->TabIndex = 48;
			this->label1->Text = L"Меню створення постачальника";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(67, 178);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(261, 22);
			this->textBox2->TabIndex = 55;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(65, 159);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(67, 16);
			this->label3->TabIndex = 54;
			this->label3->Text = L"Телефон";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(67, 114);
			this->textBox1->MaxLength = 255;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(261, 22);
			this->textBox1->TabIndex = 53;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(64, 95);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(49, 16);
			this->label2->TabIndex = 52;
			this->label2->Text = L"Назва";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(67, 247);
			this->listBox1->Name = L"listBox1";
			this->listBox1->SelectionMode = System::Windows::Forms::SelectionMode::MultiExtended;
			this->listBox1->Size = System::Drawing::Size(261, 100);
			this->listBox1->TabIndex = 56;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(69, 228);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(362, 16);
			this->label4->TabIndex = 57;
			this->label4->Text = L"Оберіть матеріали (щоб обрати декілька - зажміть Shift)";
			// 
			// Create_ProviderOrCarrier
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(555, 525);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"Create_ProviderOrCarrier";
			this->Text = L"Create_ProviderOrCarrier";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public: int choose;
		public: void MakeChoose() {
			if (choose == 1)
			{
				label1->Text = "Меню створення постачальника";
			}
			else if (choose == 2){
				label1->Text = "Меню створення перевізника";
			}
		}

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
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
};
}
