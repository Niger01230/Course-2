#include "Requests_Menu.h"
#include "MyClass.h"
#include "Admin.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;

//Складання кошторису контракту
Void Requests_Menu::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	
	choose_contract_form->choose = 1;
	choose_contract_form->update_ComboBox();
	choose_contract_form->Show();
}

//Контракти, які коштують більше ніж середня ціна усіх контрактів
Void Requests_Menu::button3_Click(System::Object^ sender, System::EventArgs^ e) {
	Contract_^ contract_req = gcnew Contract_();
	Update_TextBox(contract_req->Request_bigger_average());
}

//Усі виплати постачальника за обраний період
Void Requests_Menu::button4_Click(System::Object^ sender, System::EventArgs^ e) {
	choose_provider_form->update_ComboBox();
	choose_provider_form->Show();
}

//Кількість створених контрактів за тиждень
Void Requests_Menu::button5_Click(System::Object^ sender, System::EventArgs^ e) {
	Contract_^ contract_req = gcnew Contract_();
	Update_TextBox(contract_req->Request_contract_per_week());
}

//Кількість створених контрактів кожним менеджером за тиждень
Void Requests_Menu::button6_Click(System::Object^ sender, System::EventArgs^ e) {
	choose_surname_and_date_form->Show();
}

//Усі контракти створені конкретним менеджером за обраний період
Void Requests_Menu::button7_Click(System::Object^ sender, System::EventArgs^ e) {
	choose_manager_form->update_ComboBox();
	choose_manager_form->Show();
}

//Усі необхідні матеріали та їх кількість для реалізації конкретного контракту
Void Requests_Menu::button8_Click(System::Object^ sender, System::EventArgs^ e) {
	choose_contract_form->choose = 7;
	choose_contract_form->update_ComboBox();
	choose_contract_form->Show();
}

//Усі контракти конкретного клієнта
Void Requests_Menu::button9_Click(System::Object^ sender, System::EventArgs^ e) {
	choose_client_form->update_ComboBox();
	choose_client_form->Show();
}

//Усі менеджери з визначеним прізвищем
Void Requests_Menu::button10_Click(System::Object^ sender, System::EventArgs^ e) {
	choose_surname_form->Show();
}

//Найдорожчі контракти
Void Requests_Menu::button11_Click(System::Object^ sender, System::EventArgs^ e) {
	Contract_^ contract_req = gcnew Contract_();

	Update_TextBox(contract_req->Request_most_exspensive_contract());
}

//Кто з менеджерів не створював контракти в конкретний день
Void Requests_Menu::button12_Click(System::Object^ sender, System::EventArgs^ e) {
	choose_day_form->choose = 11;
	choose_day_form->Show();
}

//Кто створював та кто не створював контракти в конкретний день
Void Requests_Menu::button13_Click(System::Object^ sender, System::EventArgs^ e) {
	choose_day_form->choose = 12;
	choose_day_form->Show();
}

//Назад
Void Requests_Menu::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	choose_contract_form->Hide();
	choose_provider_form->Hide();
	choose_manager_form->Hide();
	choose_client_form->Hide();
	choose_surname_form->Hide();
	choose_day_form->Hide();
	admin_form->Show();
	this->Hide();
}