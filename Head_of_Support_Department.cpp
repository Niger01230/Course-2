#include "Head_of_Support_Department.h"
#include "MyClass.h"
#include "Registration.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;

//Створити нового постачальника
Void Head_of_Support_Department::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	providerOrCarrier_form->choose = 1;
	providerOrCarrier_form->update_ListBox();
	providerOrCarrier_form->MakeChoose();
	providerOrCarrier_form->Show();
	this->Hide();
}

//Створити нового перевізника
Void Head_of_Support_Department::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	providerOrCarrier_form->choose = 2;
	providerOrCarrier_form->update_ListBox();
	providerOrCarrier_form->MakeChoose();
	providerOrCarrier_form->Show();
	this->Hide();
}

//Створити нову поставку
Void Head_of_Support_Department::button3_Click(System::Object^ sender, System::EventArgs^ e) {
	supply_form->login = login;
	supply_form->update_ComboBox();
	supply_form->Show();
	this->Hide();
}

//Назад
Void Head_of_Support_Department::button5_Click(System::Object^ sender, System::EventArgs^ e) {
	reg_form->Show();
	this->Hide();
}
