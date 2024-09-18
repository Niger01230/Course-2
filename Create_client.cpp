#include "Create_client.h"
#include "MyClass.h"
#include "Manager.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;

//Створити клієнта
Void Create_client::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBox1->Text == "" ||
		textBox2->Text == "" || 
		textBox3->Text == "" )
	{
		MessageBox::Show("Деякі, або усі поля пусті. Спробуйте ще раз.", "Увага");
		return;
	}

	Client_^ new_client = gcnew Client_();
	new_client->add_client_db(textBox1->Text, textBox2->Text, textBox3->Text, login_manager);

	textBox1->Text = "";
	textBox2->Text = "";
	textBox3->Text = "";
}

//Назад
Void Create_client::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	manager_form->Show();
	this->Hide();
}