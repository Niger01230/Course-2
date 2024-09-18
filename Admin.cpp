#include "Admin.h"
#include "Registration.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;

//Створити нового менеджера
Void Admin::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	manager_form->admin_login = login;
	manager_form->Show();
	this->Hide();
}

//Створити нового голову департаменту забезпечення
Void Admin::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	support_form->admin_login = login;
	support_form->Show();
	this->Hide();
}

//Відключити акаунт
Void Admin::button3_Click(System::Object^ sender, System::EventArgs^ e) {
	choose_form->change_Disable();
	choose_form->Show();
	this->Hide();
}

//Підключити акаунт
Void Admin::button4_Click(System::Object^ sender, System::EventArgs^ e) {
	choose_form->change_Enable();
	choose_form->Show();
	this->Hide();
}

//Додати новий тип будинку
Void Admin::button6_Click(System::Object^ sender, System::EventArgs^ e) {
	create_buil_form->update_ListBox();
	create_buil_form->Show();
	this->Hide();
}

//Додати новий матеріал
Void Admin::button7_Click(System::Object^ sender, System::EventArgs^ e) {
	create_material_form->Show();
	this->Hide();
}

//Меню запитів
Void Admin::button8_Click(System::Object^ sender, System::EventArgs^ e) {
	requests_menu_form->Show();
	this->Hide();
}


//Назад
Void Admin::button5_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	registration_form->Show();
}