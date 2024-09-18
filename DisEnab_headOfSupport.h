#pragma once
#include <D:/Programs/C++ My Work/Course �2/Project1/sqlite/sqlite3.h>
#include <string>

namespace Project1 {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	ref class Choose_account;

	/// <summary>
	/// ������ ��� DisEnab_headOfSupport
	/// </summary>
	public ref class DisEnab_headOfSupport : public System::Windows::Forms::Form
	{
	public:
		DisEnab_headOfSupport(Choose_account^ choose_ref)
		{
			InitializeComponent();
			
			choose_form = choose_ref;
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~DisEnab_headOfSupport()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button2;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Label^ label1;

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;
		Choose_account^ choose_form;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button2->Location = System::Drawing::Point(453, 195);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(127, 38);
			this->button2->TabIndex = 7;
			this->button2->Text = L"³��������";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &DisEnab_headOfSupport::button2_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button1->Location = System::Drawing::Point(34, 195);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(127, 38);
			this->button1->TabIndex = 6;
			this->button1->Text = L"�����";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &DisEnab_headOfSupport::button1_Click);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(34, 77);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(546, 84);
			this->listBox1->TabIndex = 5;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->label1->Location = System::Drawing::Point(12, 33);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(580, 29);
			this->label1->TabIndex = 4;
			this->label1->Text = L"������, ����� ������ ������������ ���������";
			// 
			// DisEnab_headOfSupport
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(618, 259);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label1);
			this->Name = L"DisEnab_headOfSupport";
			this->Text = L"DisEnab_headOfSupport";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
		   int choose;

		public: Void change_Disable() {
			choose = 0;
			label1->Text = "������, ����� ������ ������������ ���������";
			button2->Text = "³��������";
		}

		public: Void change_Enable() {
			choose = 1;
			label1->Text = "������, ����� ������ ������������ ���������";
			button2->Text = "ϳ��������";
		}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);

	   public: Void update_ListBox() {
		   listBox1->Items->Clear();

		   sqlite3* db;
		   sqlite3_stmt* stmt;

		   int rc = sqlite3_open("db\\Building_database.db", &db);
		   const char* query = "SELECT Id, Full_name FROM Head_of_Support";
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

		   // ����������� �������
		   sqlite3_finalize(stmt);
		   sqlite3_close(db);

	   }
};
}
