#include "Choose_Client.h"
#include "MyClass.h"
#include "Requests_Menu.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;

//������ �볺���
Void Choose_Client::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (comboBox1->SelectedIndex == -1)
	{
		MessageBox::Show("������ �볺���.", "�����");
		return;
	}

	Contract_^ contract_req = gcnew Contract_();

	cli::array<String^>^ parts = comboBox1->SelectedItem->ToString()->Split(',');
	int id_client = Convert::ToInt32(parts[0]);

	requests_menu_form->Update_TextBox(contract_req->Request_all_contracts_by_client(id_client));

}

//�����
Void Choose_Client::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
}