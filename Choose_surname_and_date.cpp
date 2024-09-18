#include "Choose_surname_and_date.h"
#include "MyClass.h"
#include "Requests_Menu.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;

//Обрати дату і прізвище
Void Choose_surname_and_date::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBox1->Text == "" ||
		textBox2->Text == "" || 
		textBox3->Text == "")
	{
		MessageBox::Show("Деякі, або усі поля пусті. Спробуйте ще раз.", "Увага");
		return;
	}

	DateTime new_Start_date;
	DateTime new_End_date;

	//Перевірка на правильність дати
	if (!DateTime::TryParse(textBox2->Text, new_Start_date) ||
		!DateTime::TryParse(textBox3->Text, new_End_date)) {
		MessageBox::Show("Введена неправильна дата. Приклад: 2012-12-12", "Увага");
		return;
	}

	if (new_Start_date.Date > new_End_date.Date)
	{
		MessageBox::Show("Введена початкова дата більша за кінцеву. Спробуйте ще раз.", "Увага");
		return;
	}

	Contract_^ contract_req = gcnew Contract_();

	requests_menu_form->Update_TextBox(contract_req->Request_contract_per_week_by_manager(new_End_date, new_Start_date, textBox1->Text));
}

//Назад
Void Choose_surname_and_date::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
}