#include "Choose_contract.h"
#include "MyClass.h"
#include "Requests_Menu.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;

//Обрати контракт
Void Choose_contract::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (comboBox1->SelectedIndex == -1)
	{
		MessageBox::Show("Оберіть контракт.", "Увага");
		return;
	}

	Contract_^ contract_req = gcnew Contract_();

	cli::array<String^>^ parts = comboBox1->SelectedItem->ToString()->Split(',');
	int id_contract = Convert::ToInt32(parts[0]);

	switch (choose)
	{
	case 1:
		
		requests_menu_form->Update_TextBox(contract_req->Request_estimate(id_contract));
		break;

	case 7:
		requests_menu_form->Update_TextBox(contract_req->Request_all_materials(id_contract));
		break;
	}
}

//Назад
Void Choose_contract::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
}