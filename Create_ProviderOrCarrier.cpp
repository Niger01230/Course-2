#include "Create_ProviderOrCarrier.h"
#include "Head_of_Support_Department.h"
#include "MyClass.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;

//Створити постачальника або перевізника
Void Create_ProviderOrCarrier::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBox1->Text == "" ||
		textBox2->Text == "" ||
		listBox1->SelectedIndex == -1)
	{
		MessageBox::Show("Деякі, або усі поля пусті. Спробуйте ще раз.", "Увага");
		return;
	}

	Provider_^ new_provider = gcnew Provider_();
	Carrier_^ new_carrier = gcnew Carrier_();
	int id_provider = 1;
	int id_carrier = 1;

	switch (choose)
	{
		//Для постачальника
	case 1:
		id_provider = new_provider->add_provider_db(textBox1->Text, textBox2->Text);

		for (int i = 0; i < listBox1->Items->Count; i++)
		{
			if (listBox1->SelectedIndices->Contains(i))
			{
				String^ selectedText = listBox1->Items[i]->ToString();
				cli::array<String^>^ parts = selectedText->Split(',');
				int id_material = Convert::ToInt32(parts[0]);
				String^ name_material = parts[1]->ToString();
				new_provider->add_material_to_provider_db(id_provider, id_material, textBox1->Text, name_material);
			}
		}

		break;

		//Для перевізника
	case 2:
		id_carrier = new_carrier->add_carrier_db(textBox1->Text, textBox2->Text);

		for (int i = 0; i < listBox1->Items->Count; i++)
		{
			if (listBox1->SelectedIndices->Contains(i))
			{
				String^ selectedText = listBox1->Items[i]->ToString();
				cli::array<String^>^ parts = selectedText->Split(',');
				int id_material = Convert::ToInt32(parts[0]);
				String^ name_material = parts[1]->ToString();
				new_carrier->add_material_to_carrier_db(id_carrier, id_material, textBox1->Text, name_material);
			}
		}

		break;
	}
}

//Назад
Void Create_ProviderOrCarrier::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	head_of_Support_form->Show();
	this->Hide();
}