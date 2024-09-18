#include "Registration.h"
#include "Create_admin.h"
#include <D:/Programs/C++ My Work/Course №2/Project1/sqlite/sqlite3.h>
#include <msclr/marshal_cppstd.h>
#include <string.h>
#include "MyClass.h"

using namespace std;
using namespace System;
using namespace System::Windows::Forms;;
using namespace Project1;
using namespace msclr::interop;

//Створення адміністратора
Void Create_admin::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	//Перевірка на те, що поля пусті
	if ((textBox1->Text == "") || 
		(textBox2->Text == "") || 
		(textBox3->Text == "") ||
		(textBox4->Text == "") || 
		(textBox5->Text == "") || 
		(textBox6->Text == ""))
	{
		MessageBox::Show("Деякі, або усі поля пусті. Спробуйте ще раз.", "Увага");
		return;
	}

	//Перевірка на те, що паролі не співпадають
	if (textBox5->Text != textBox6->Text)
	{
		MessageBox::Show("Паролі не співпадають. Спробуйте ще раз.", "Увага");
		return;
	}

	Account_^ new_account = gcnew Account_();
	int Account_Id;

	if (new_account->add_account_db(textBox4->Text, textBox6->Text, 0, Account_Id) != SQLITE_OK)
	{
		return;
	}
	
	Admin_^ new_manager = gcnew Admin_();
	new_manager->add_admin_db(textBox1->Text, textBox2->Text, textBox3->Text, Account_Id);
	
	textBox1->Text = "";
	textBox2->Text = "";
	textBox3->Text = "";
	textBox4->Text = "";
	textBox5->Text = "";
	textBox6->Text = "";

	
}

//Назад
Void Create_admin::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	reg_form->Show();
	this->Hide();
}