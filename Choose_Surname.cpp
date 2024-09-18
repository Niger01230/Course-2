#include "Choose_Surname.h"
#include "MyClass.h"
#include "Requests_Menu.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;

//Обрати прізвище
Void Choose_Surname::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBox1->Text == "")
	{
		MessageBox::Show("Введіть прізвище.", "Увага");
		return;
	}

	Manager_^ manager_req = gcnew Manager_();

	requests_menu_form->Update_TextBox(manager_req->Request_all_managers_by_surname(textBox1->Text));
}

//Назад
Void Choose_Surname::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
}