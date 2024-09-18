#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	ref class Requests_Menu;

	/// <summary>
	/// ������ ��� Choose_surname_and_date
	/// </summary>
	public ref class Choose_surname_and_date : public System::Windows::Forms::Form
	{
	public:
		Choose_surname_and_date(Requests_Menu^ requests_menu_form_ref)
		{
			InitializeComponent();

			requests_menu_form = requests_menu_form_ref;
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~Choose_surname_and_date()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label4;

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;
		Requests_Menu^ requests_menu_form;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(81, 97);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(328, 22);
			this->textBox1->TabIndex = 32;
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(382, 210);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(103, 38);
			this->button2->TabIndex = 31;
			this->button2->Text = L"������";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Choose_surname_and_date::button2_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label2->Location = System::Drawing::Point(77, 74);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(94, 20);
			this->label2->TabIndex = 30;
			this->label2->Text = L"�������:";
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(12, 210);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(103, 38);
			this->button1->TabIndex = 29;
			this->button1->Text = L"�����";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Choose_surname_and_date::button1_Click);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(45, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(414, 34);
			this->label1->TabIndex = 28;
			this->label1->Text = L"������ ������� �� ����";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(81, 149);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(158, 22);
			this->textBox2->TabIndex = 34;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label3->Location = System::Drawing::Point(77, 126);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(153, 20);
			this->label3->TabIndex = 33;
			this->label3->Text = L"��������� ����:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(251, 149);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(158, 22);
			this->textBox3->TabIndex = 36;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label4->Location = System::Drawing::Point(247, 126);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(126, 20);
			this->label4->TabIndex = 35;
			this->label4->Text = L"ʳ����� ����:";
			// 
			// Choose_surname_and_date
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(497, 258);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"Choose_surname_and_date";
			this->Text = L"Choose_surname_and_date";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
};
}
