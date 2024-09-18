#include "Choose_Manager.h"
#include "MyClass.h"
#include "Requests_Menu.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;

//Обрати менеджера
Void Choose_Manager::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBox1->Text == "" ||
		textBox2->Text == "" ||
		comboBox1->SelectedIndex == -1)
	{
		MessageBox::Show("Деякі, або усі поля пусті. Спробуйте ще раз.", "Увага");
		return;
	}

	DateTime new_Start_date;
	DateTime new_End_date;

	//Перевірка на правильність дати
	if (!DateTime::TryParse(textBox1->Text, new_Start_date)) {
		MessageBox::Show("Введена неправильна початкова дата. Приклад: 2012-12-12", "Увага");
		return;
	}

	if (!DateTime::TryParse(textBox2->Text, new_End_date)) {
		MessageBox::Show("Введена неправильна кінцева дата. Приклад: 2012-12-12", "Увага");
		return;
	}

	//Перевірка на те, що початкова дата не більша за кінцеву
	if (new_Start_date.Date > new_End_date.Date)
	{
		MessageBox::Show("Введена початкова дата більша за кінцеву. Спробуйте ще раз.", "Увага");
		return;
	}

	cli::array<String^>^ parts = comboBox1->SelectedItem->ToString()->Split(',');
	int id_manager = Convert::ToInt32(parts[0]);

	Contract_^ contract_req = gcnew Contract_();
	requests_menu_form->Update_TextBox(contract_req->Request_contracts_by_manager(id_manager, new_Start_date, new_End_date));
}

//Назад
Void Choose_Manager::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
}