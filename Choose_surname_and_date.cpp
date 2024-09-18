#include "Choose_surname_and_date.h"
#include "MyClass.h"
#include "Requests_Menu.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;

//������ ���� � �������
Void Choose_surname_and_date::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBox1->Text == "" ||
		textBox2->Text == "" || 
		textBox3->Text == "")
	{
		MessageBox::Show("����, ��� �� ���� ����. ��������� �� ���.", "�����");
		return;
	}

	DateTime new_Start_date;
	DateTime new_End_date;

	//�������� �� ����������� ����
	if (!DateTime::TryParse(textBox2->Text, new_Start_date) ||
		!DateTime::TryParse(textBox3->Text, new_End_date)) {
		MessageBox::Show("������� ����������� ����. �������: 2012-12-12", "�����");
		return;
	}

	if (new_Start_date.Date > new_End_date.Date)
	{
		MessageBox::Show("������� ��������� ���� ����� �� ������. ��������� �� ���.", "�����");
		return;
	}

	Contract_^ contract_req = gcnew Contract_();

	requests_menu_form->Update_TextBox(contract_req->Request_contract_per_week_by_manager(new_End_date, new_Start_date, textBox1->Text));
}

//�����
Void Choose_surname_and_date::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
}