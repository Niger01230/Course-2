#include "DisEnab_manager.h"
#include "Choose_account.h"
#include "MyClass.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;

//³��������\ϳ��������
Void DisEnab_manager::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (listBox1->SelectedIndex == -1)
	{
		MessageBox::Show("���� �����, ������ �������.", "�����");
		return;
	}

	String^ selectedItem = listBox1->SelectedItem->ToString();
	cli::array<String^>^ parts = selectedItem->Split(',');
	int id = Convert::ToInt32(parts[0]);

	Account_^ up_account = gcnew Account_();

	switch (choose)
	{
	//�� ����������
	case 0:
		up_account->disEnab_manager_account_db(choose, id);
		break;

	//�� ����������
	case 1:
		up_account->disEnab_manager_account_db(choose, id);
		break;
	}
}

//�����
Void DisEnab_manager::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	choose_form->Show();
	this->Hide();
}
