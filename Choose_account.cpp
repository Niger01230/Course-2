#include "Choose_account.h"
#include "Admin.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;

//Менеджер
Void Choose_account::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	switch (choose)
	{

	//На відключення
	case 0:
		disEnab_manager_form->change_Disable();
		break;

	//На підключення
	case 1:
		disEnab_manager_form->change_Enable();
		break;
	}

	disEnab_manager_form->update_ListBox();
	disEnab_manager_form->Show();
	this->Hide();
}

//Голова департаменту забезпечення
Void Choose_account::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	switch (choose)
	{

	//На відключення
	case 0:
		disEnab_head_form->change_Disable();
		break;

	//На підключення
	case 1:
		disEnab_head_form->change_Enable();
		break;
	}
	disEnab_head_form->update_ListBox();
	disEnab_head_form->Show();
	this->Hide();
}

//Назад
Void Choose_account::button3_Click(System::Object^ sender, System::EventArgs^ e) {
	admin_form->Show();
	this->Hide();
}
