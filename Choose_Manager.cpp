#include "Choose_Manager.h"
#include "MyClass.h"
#include "Requests_Menu.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;

//������ ���������
Void Choose_Manager::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBox1->Text == "" ||
		textBox2->Text == "" ||
		comboBox1->SelectedIndex == -1)
	{
		MessageBox::Show("����, ��� �� ���� ����. ��������� �� ���.", "�����");
		return;
	}

	DateTime new_Start_date;
	DateTime new_End_date;

	//�������� �� ������������ ����
	if (!DateTime::TryParse(textBox1->Text, new_Start_date)) {
		MessageBox::Show("������� ����������� ��������� ����. �������: 2012-12-12", "�����");
		return;
	}

	if (!DateTime::TryParse(textBox2->Text, new_End_date)) {
		MessageBox::Show("������� ����������� ������ ����. �������: 2012-12-12", "�����");
		return;
	}

	//�������� �� ��, �� ��������� ���� �� ����� �� ������
	if (new_Start_date.Date > new_End_date.Date)
	{
		MessageBox::Show("������� ��������� ���� ����� �� ������. ��������� �� ���.", "�����");
		return;
	}

	cli::array<String^>^ parts = comboBox1->SelectedItem->ToString()->Split(',');
	int id_manager = Convert::ToInt32(parts[0]);

	Contract_^ contract_req = gcnew Contract_();
	requests_menu_form->Update_TextBox(contract_req->Request_contracts_by_manager(id_manager, new_Start_date, new_End_date));
}

//�����
Void Choose_Manager::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
}