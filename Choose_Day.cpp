#include "Choose_Day.h"
#include "MyClass.h"
#include "Requests_Menu.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;

//Обрати день
Void Choose_Day::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBox1->Text == "")
	{
		MessageBox::Show("Введіть дату.", "Увага");
		return;
	}

	DateTime new_date;

	if (!DateTime::TryParse(textBox1->Text, new_date)) {
		MessageBox::Show("Введена неправильна дата. Приклад: 2012-12-12", "Увага");
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

//Назад
Void Choose_Day::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
}