#include "Choose_account.h"
#include "Admin.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;

//��������
Void Choose_account::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	switch (choose)
	{

	//�� ����������
	case 0:
		disEnab_manager_form->change_Disable();
		break;

	//�� ����������
	case 1:
		disEnab_manager_form->change_Enable();
		break;
	}

	disEnab_manager_form->update_ListBox();
	disEnab_manager_form->Show();
	this->Hide();
}

//������ ������������ ������������
Void Choose_account::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	switch (choose)
	{

	//�� ����������
	case 0:
		disEnab_head_form->change_Disable();
		break;

	//�� ����������
	case 1:
		disEnab_head_form->change_Enable();
		break;
	}
	disEnab_head_form->update_ListBox();
	disEnab_head_form->Show();
	this->Hide();
}

//�����
Void Choose_account::button3_Click(System::Object^ sender, System::EventArgs^ e) {
	admin_form->Show();
	this->Hide();
}
