#include "Check_password.h"
#include "Registration.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;

//Назад
Void Check_password::button1_Click(System::Object ^ sender, System::EventArgs ^ e){
	textBox1->Text = "";
	reg_form->Show();
	this->Hide();
}

//Вхід до меню створення адміну
Void Check_password::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBox1->Text == "1243")
	{
		textBox1->Text = "";
		create_ad_form->Show();
		this->Hide();
	}
	else {
		MessageBox::Show("Пароль не вірний", "Увага");
	}
}