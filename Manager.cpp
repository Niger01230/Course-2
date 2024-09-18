#include "Manager.h"
#include "Registration.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;

//Створити клієнта
Void Manager::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	create_client_form->login_manager = login;
	create_client_form->Show();
	this->Hide();
}

//Створити контракт
Void Manager::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	create_contract_form->login_manager = login;
	create_contract_form->update_ComboBox();
	create_contract_form->Show();
	this->Hide();
}

//Редагувати контракт
Void Manager::button3_Click(System::Object^ sender, System::EventArgs^ e) {
	edit_contract_form->update_ComboBox_1();
	edit_contract_form->update_ComboBox_2();
	edit_contract_form->Show();
	this->Hide();
}

//Видалити контракт
Void  Manager::button4_Click(System::Object^ sender, System::EventArgs^ e) {
	delete_contract_form->update_ComboBox();
	delete_contract_form->Show();
	this->Hide();
}

//Назад
Void Manager::button5_Click(System::Object^ sender, System::EventArgs^ e) {
	reg_form->Show();
	this->Hide();
}