#include "Choose_Day.h"
#include "MyClass.h"
#include "Requests_Menu.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;

//������ ����
Void Choose_Day::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBox1->Text == "")
	{
		MessageBox::Show("������ ����.", "�����");
		return;
	}

	DateTime new_date;

	if (!DateTime::TryParse(textBox1->Text, new_date)) {
		MessageBox::Show("������� ����������� ����. �������: 2012-12-12", "�����");
		return;
	}

	Manager_^ manager_req = gcnew Manager_();

	switch (choose)
	{
	case 11:
		requests_menu_form->Update_TextBox(manager_req->Request_all_managers_whichNoContact_by_day(new_date));
		break;

	case 12:
		requests_menu_form->Update_TextBox(manager_req->Request_all_managers_whichNoAndYesContact_by_day(new_date));
		break;
	}
}

//�����
Void Choose_Day::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
}