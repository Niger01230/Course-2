#include "Create_supply.h"
#include "MyClass.h"
#include "Head_of_Support_Department.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;

//Якщо контракт змінився
Void Create_supply::comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	panel1->Controls->Clear();
	delete supplierComboBoxes;
	delete transporterComboBoxes;

	String^ Contract = comboBox1->SelectedItem->ToString();
	cli::array<String^>^ parts = Contract->Split(',');
	Contract_id = Convert::ToInt32(parts[0]);

	cli::array<String^>^ Providers;
	cli::array<String^>^ Carriers;

	Necessary_material_^ get_materials = gcnew Necessary_material_();
	Material_^ get_mat_name = gcnew Material_();
	Provider_^ get_provider = gcnew Provider_();
	Carrier_^ get_carrier = gcnew Carrier_();

	Materials_id = get_materials->get_material_ids_db(Contract_id);

	// Мітка для стовпця "Матеріал:"
	Label^ materialTitleLabel = gcnew Label();
	materialTitleLabel->Text = "Матеріал:";
	materialTitleLabel->Location = Point(20, 0);
	panel1->Controls->Add(materialTitleLabel);

	// Мітка для стовпця "Постачальник:"
	Label^ supplierTitleLabel = gcnew Label();
	supplierTitleLabel->Text = "Постачальник:";
	supplierTitleLabel->Location = Point(120, 0);
	panel1->Controls->Add(supplierTitleLabel);

	// Мітка для стовпця "Перевізник:"
	Label^ transporterTitleLabel = gcnew Label();
	transporterTitleLabel->Text = "Перевізник:";
	transporterTitleLabel->Location = Point(250, 0);
	panel1->Controls->Add(transporterTitleLabel);

	supplierComboBoxes = gcnew cli::array<ComboBox^>(Materials_id->Length);
	transporterComboBoxes = gcnew cli::array<ComboBox^>(Materials_id->Length);

	for (int i = 0; i < Materials_id->Length; i++)
	{

		String^ label_text = get_mat_name->get_material_name_db(Materials_id[i]);
		Label^ materialLabel = gcnew Label();
		materialLabel->Text = Materials_id[i] + ", " + label_text;
		materialLabel->Location = Point(20, 30 + 50 * i);
		panel1->Controls->Add(materialLabel);

		// Providers ComboBox
		supplierComboBoxes[i] = gcnew ComboBox();
		supplierComboBoxes[i]->Location = Point(120, 30 + 50 * i);
		supplierComboBoxes[i]->DropDownStyle = ComboBoxStyle::DropDownList;
		Providers = get_provider->get_provider_by_material(Materials_id[i]);
		for (int j = 0; j < Providers->Length; j++)
		{
			supplierComboBoxes[i]->Items->Add(Providers[j]);
		}
		panel1->Controls->Add(supplierComboBoxes[i]);

		// Carriers ComboBox
		transporterComboBoxes[i] = gcnew ComboBox();
		transporterComboBoxes[i]->Location = Point(250, 30 + 50 * i);
		transporterComboBoxes[i]->DropDownStyle = ComboBoxStyle::DropDownList;
		Carriers = get_carrier->get_carrier_by_material(Materials_id[i]);
		for (int j = 0; j < Carriers->Length; j++)
		{
			transporterComboBoxes[i]->Items->Add(Carriers[j]);
		}
		panel1->Controls->Add(transporterComboBoxes[i]);
	}
}

//Створити поставку
Void Create_supply::button2_Click(System::Object^ sender, System::EventArgs^ e) {
	//Перевірки на порожність
	if (textBox1->Text == "" ||
		comboBox1->SelectedIndex == -1)
	{
		MessageBox::Show("Деякі, або усі поля пусті. Спробуйте ще раз.", "Увага");
		return;
	}

	for (int i = 0; i < supplierComboBoxes->Length; i++)
	{
		if (supplierComboBoxes[i]->SelectedIndex == -1)
		{
			MessageBox::Show("Деякі, або усі поля пусті. Спробуйте ще раз.", "Увага");
			return;
		}
	}

	for (int i = 0; i < transporterComboBoxes->Length; i++)
	{
		if (transporterComboBoxes[i]->SelectedIndex == -1)
		{
			MessageBox::Show("Деякі, або усі поля пусті. Спробуйте ще раз.", "Увага");
			return;
		}
	}

	DateTime new_Start_date;

	//Перевірка на правильність дати
	if (!DateTime::TryParse(textBox1->Text, new_Start_date)) {
		MessageBox::Show("Введена неправильна дата. Приклад: 2012-12-12", "Увага");
		return;
	}

	//Перевірка на те, що початкова дата не менша за поточну
	if (new_Start_date.Date < DateTime::Today)
	{
		MessageBox::Show("Введена початкова дата менша за поточну. Спробуйте ще раз.", "Увага");
		return;
	}

	Supply_^ new_supply = gcnew Supply_();

	int Supply_id;
	new_supply->add_supply_db(new_Start_date, login, Supply_id);

	Mat_Sup_Prov_Car^ new_Mat_Sup_Prov_Car = gcnew Mat_Sup_Prov_Car();
	Necessary_material_^ update_necessary_material = gcnew Necessary_material_();
	Material_^ get_material_price = gcnew Material_();

	Payment_provider^ new_payment_provider = gcnew Payment_provider();
	Payment_carrier^ new_payment_carrier = gcnew Payment_carrier();

	for (int i = 0; i < Materials_id->Length; i++)
	{
		String^ provider = supplierComboBoxes[i]->SelectedItem->ToString();
		String^ carrier = transporterComboBoxes[i]->SelectedItem->ToString();

		cli::array<String^>^ parts_1 = provider->Split(',');
		int Id_provider = Convert::ToInt32(parts_1[0]);

		cli::array<String^>^ parts_2 = carrier->Split(',');
		int Id_carrier = Convert::ToInt32(parts_2[0]);

		new_Mat_Sup_Prov_Car->add_Mat_Sup_Prov_Car_db(Materials_id[i], Supply_id, Id_provider, Id_carrier);
		update_necessary_material->set_isExist_db(Contract_id, Materials_id[i]);

		int mat_quantity = update_necessary_material->get_quantity(Contract_id, Materials_id[i]);
		int mat_price = get_material_price->get_price_per_piece(Materials_id[i]);

		int total_price_provider = mat_quantity * mat_price;
		int total_price_carrier = sqrt(sqrt(mat_quantity)) * 30 * 1.1;

		new_payment_provider->add_Payment_provider_db(new_Start_date, total_price_provider, Id_provider);
		new_payment_carrier->add_Payment_carrier_db(new_Start_date, total_price_carrier, Id_carrier);
		update_ComboBox();
	}
	

}

//Назад
Void Create_supply::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	support_form->Show();
	this->Hide();
}
