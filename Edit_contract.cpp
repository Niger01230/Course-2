#include "Edit_contract.h"
#include "MyClass.h"
#include "Manager.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;

//Зміна контракту
Void Edit_contract::comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	cli::array<String^>^ parts = comboBox1->SelectedItem->ToString()->Split(',');
	id_contract = Convert::ToInt32(parts[0]);

	Contract_^ get_start_date = gcnew Contract_();
	start_date = get_start_date->get_start_date(id_contract);
	cost = get_start_date->get_cost(id_contract);
	isImprest = get_start_date->get_isImprest(id_contract);
	isPaid = get_start_date->get_isPaid(id_contract);

	if (isImprest)
	{
		checkBox1->Checked = true;
	}
	else {
		checkBox1->Checked = false;
	}

	if (isPaid)
	{
		checkBox2->Checked = true;
	}
	else {
		checkBox2->Checked = false;
	}

}

//Редагувати контракт
Void Edit_contract::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (comboBox1->SelectedIndex == -1)
	{
		MessageBox::Show("Для редагування оберіть контракт.", "Увага");
		return;
	}

	int id;
	DateTime End_date;
	int imprest;
	bool isImprest;
	bool isPaid;
	int Manager_id;

	String^ sql_req = "UPDATE Contract SET ";

	id = id_contract;

	if (textBox1->Text != "")
	{
		DateTime::TryParse(textBox1->Text, End_date);

		if (End_date < start_date)
		{
			MessageBox::Show("Кінцева дата не може бути менша за початкову.", "Увага");
			return;
		}

		sql_req += "[End date] = '" + End_date + "', ";

	}
	
	if (textBox2->Text != "")
	{
		Int32::TryParse(textBox2->Text, imprest);

		if (imprest > cost ||
			imprest <= 0)
		{
			MessageBox::Show("Аванс не може бути більшим за ціну контракту, або бути меншим, або дорівнювати нулю.", "Увага");
			return;
		}

		sql_req += "Imprest = " + imprest + ", ";
	}
	
	isImprest = checkBox1->Checked;
	isPaid = checkBox2->Checked;

	sql_req += "isImprest = " + isImprest + ", isPaid = " + isPaid + "";

	if (comboBox2->SelectedIndex != -1)
	{
		cli::array<String^>^ parts = comboBox2->SelectedItem->ToString()->Split(',');
		Manager_id = Convert::ToInt32(parts[0]);
		sql_req += ", [Id manager] = " + Manager_id + " ";
	}

	sql_req += " WHERE Id = " + id_contract + " ";

	Contract_^ contract_update = gcnew Contract_();
	contract_update->update_contract_db(sql_req);

	MessageBox::Show("Контракт успішно відредаговано.", "Увага");
}

//Назад
Void Edit_contract::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	manager_form->Show();
	this->Hide();
}