#pragma once
#include "MyClass.h"
#include <D:/Programs/C++ My Work/Course �2/Project1/sqlite/sqlite3.h>

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	ref class Create_contract;

	/// <summary>
	/// ������ ��� Choose_building_type
	/// </summary>
	public ref class Choose_building_type : public System::Windows::Forms::Form
	{
	public:
		Choose_building_type(Create_contract^ create_contract_form_ref)
		{
			InitializeComponent();
			
			create_contract_form = create_contract_form_ref;
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~Choose_building_type()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label1;
	protected:

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

		Create_contract^ create_contract_form;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBox1->Location = System::Drawing::Point(83, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(527, 431);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Choose_building_type::pictureBox1_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button1->Location = System::Drawing::Point(12, 475);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(88, 38);
			this->button1->TabIndex = 47;
			this->button1->Text = L"�����";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Choose_building_type::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button2->Location = System::Drawing::Point(237, 475);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(88, 38);
			this->button2->TabIndex = 48;
			this->button2->Text = L"�����";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Choose_building_type::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->button3->Location = System::Drawing::Point(359, 475);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(88, 38);
			this->button3->TabIndex = 49;
			this->button3->Text = L"���";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Choose_building_type::button3_Click);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label1->Location = System::Drawing::Point(237, 446);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(210, 26);
			this->label1->TabIndex = 50;
			this->label1->Text = L"�����";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Choose_building_type
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(706, 525);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Choose_building_type";
			this->Text = L"Choose_building_type";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e);
		   public: int index = 1;

		   public: void UpdateImage() {
			   String^ text;
			   Building_type_^ get_builType = gcnew Building_type_();

			   cli::array<System::Byte>^ imageBytes = get_builType->get_Image_db(index);
			   if (imageBytes != nullptr && imageBytes->Length > 0)
			   {
				   System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream(imageBytes);
				   System::Drawing::Image^ image = System::Drawing::Image::FromStream(ms);
				   pictureBox1->Image = image;
				   get_builType->get_Name_db(index, text);
				   label1->Text = index + ": " + text;
			   }
			   else
			   {
				   // ����� ��������� �� ������ ��� ���������� ������ ��������, ���� ����������� �� ���� �������
				   MessageBox::Show("����������� �� �������", "������");
			   }
		   }
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
};
}
