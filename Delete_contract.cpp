#include "Delete_contract.h"
#include "MyClass.h"
#include "Manager.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;

//Обрати контракт
Void Delete_contract::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (comboBox1->SelectedIndex == -1)
	{
		MessageBox::Show("Оберіть контракт.", "Увага");
		return;
	}

	Contract_^ contract_delete = gcnew Contract_();

	cli::array<String^>^ parts = comboBox1->SelectedItem->ToString()->Split(',');
	int id_contract = Convert::ToInt32(parts[0]);

	contract_delete->delete_contract_db(id_contract);
	update_ComboBox();
}

//Назад
Void Delete_contract::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	manager_form->Show();
	this->Hide();
}