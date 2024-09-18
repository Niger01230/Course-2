#include "Create_building_type.h"
#include "MyClass.h"
#include "Admin.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;

//Створити новий тип будинку
Void Create_building_type::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBox1->Text == "" ||
		textBox2->Text == "" ||
		listBox1->SelectedIndex == -1)
	{
		MessageBox::Show("Деякі, або усі поля пусті. Спробуйте ще раз.", "Увага");
		return;
	}

	Building_type_^ new_bul_type = gcnew Building_type_();
	BuildingType_Material_^ new_bul_mat = gcnew BuildingType_Material_();

	int id_bul_type = new_bul_type->add_builType_db(textBox1->Text, textBox2->Text);

	if (id_bul_type == 0)
	{
		return;
	}

	for (int i = 0; i < listBox1->Items->Count; i++)
	{
		if (listBox1->SelectedIndices->Contains(i))
		{
			String^ selectedText = listBox1->Items[i]->ToString();
			cli::array<String^>^ parts = selectedText->Split(',');
			int id_material = Convert::ToInt32(parts[0]);
			new_bul_mat->add_material_to_building_db(id_bul_type, id_material);
		}
	}
}

//Назад
Void Create_building_type::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	admin_form->Show();
	this->Hide();
}