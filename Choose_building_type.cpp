#include "Choose_building_type.h"
#include "Create_contract.h"
#include "MyClass.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;

//Обрати тип будинку
Void Choose_building_type::pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	Building_type_^ get_chooseBuilType = gcnew Building_type_();
	create_contract_form->changeTextBox(get_chooseBuilType->choose_builType(index));
	create_contract_form->bul_index = index;
	MessageBox::Show("Тип будинку успішно обраний.", "Увага");
}

//Вперед до типу будинку
Void Choose_building_type::button3_Click(System::Object^ sender, System::EventArgs^ e) {
	Building_type_^ get_countBuilType = gcnew Building_type_();
	index++;
	index = get_countBuilType->check_count(index);
	UpdateImage();
}

//Назад до типу будинку
Void Choose_building_type::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	Building_type_^ get_countBuilType = gcnew Building_type_();
	index--;
	index = get_countBuilType->check_count(index);
	UpdateImage();
}


//Назад
Void Choose_building_type::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	create_contract_form->Show();
	this->Hide();
}