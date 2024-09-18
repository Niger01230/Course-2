#include "Create_material.h"
#include "MyClass.h"
#include "Admin.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;

//�������� �������
Void Create_material::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBox1->Text == "" ||
		textBox2->Text == "") 
	{
		MessageBox::Show("����, ��� �� ���� ����. ��������� �� ���.", "�����");
		return;
	}

	int int_number;

	if (!Int32::TryParse(textBox2->Text, int_number) ||
		int_number <= 0)
	{
		MessageBox::Show("��� ������� �� ����. ��������� �� ���.", "�����");
		return;
	}
	
	Material_^ new_material = gcnew Material_();
	new_material->add_material_db(textBox1->Text, int_number);
}

//�����
Void Create_material::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	admin_ref_form->Show();
	this->Hide();
}