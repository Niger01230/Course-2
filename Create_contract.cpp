#include "Create_contract.h"
#include "MyClass.h"
#include "Manager.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;

//�������� ��������
Void Create_contract::button2_Click(System::Object^ sender, System::EventArgs^ e) {

	//�������� �� ��������� �����
	if (textBox1->Text == "" ||
		textBox2->Text == "" ||
		textBox3->Text == "" ||
		textBox4->Text == "" ||
		textBox5->Text == "" ||
		textBox6->Text == "" ||
		comboBox1->SelectedIndex == -1)
	{
		MessageBox::Show("����, ��� �� ���� ����. ��������� �� ���.", "�����");
		return;
	}
	int area_building;
	int area_site;
	int number_floors;
	int mat_quan;
	//�������� �� ����������� �����
	if (!Int32::TryParse(textBox2->Text, area_site) ||
		!Int32::TryParse(textBox3->Text, area_building) ||
		!Int32::TryParse(textBox4->Text, number_floors) ||
		area_building <= 0 ||
		area_site <= 0 ||
		number_floors <= 0 ||
		number_floors > 24)
	{
		MessageBox::Show("��� ������� �� ����. ��������� �� ���.", "�����");
		return;
	}

	DateTime new_Start_date;

	//�������� �� ����������� ����
	if (!DateTime::TryParse(textBox5->Text, new_Start_date)) {
		MessageBox::Show("������� ����������� ����. �������: 2012-12-12", "�����");
		return;
	}
	
	//�������� �� ��, �� ��������� ���� �� ����� �� �������
	if (new_Start_date.Date < DateTime::Today)
	{
		MessageBox::Show("������� ��������� ���� ����� �� �������. ��������� �� ���.", "�����");
		return;
	}

	//�������� �� ����� ������ � �������
	if (Convert::ToInt32(textBox3->Text) > Convert::ToInt32(textBox2->Text))
	{
		MessageBox::Show("����� ������� �� ���� ���� ������ �� ����� ������. ��������� �� ���.", "�����");
		return;
	}

	//MessageBox::Show("Date: " + new_Start_date.ToString()->Substring(0, new_Start_date.ToString()->IndexOf(' ')), "�����");

	mat_quan = (((area_building * area_building) * (number_floors + 1)) + (sqrt(area_building) * 4 * 2 * number_floors)) * 1.1;

	int Contract_id;
	Contract_^ new_contract = gcnew Contract_();
	new_contract->add_contract_db(textBox1->Text, 
		Convert::ToInt32(textBox2->Text), 
		Convert::ToInt32(textBox3->Text), 
		Convert::ToInt32(textBox4->Text), 
		new_Start_date,
		bul_index, 
		comboBox1->SelectedItem->ToString(), 
		login_manager,
		Contract_id);

	int Contract_price = 0;
	Necessary_material_^ get_ids = gcnew Necessary_material_();
	Material_^ get_price = gcnew Material_();

	BuildingType_Material_^ get_and_add_NecesMat_Build = gcnew BuildingType_Material_();
	get_and_add_NecesMat_Build->get_and_add_NecesMat_Build_db(bul_index, Contract_id, mat_quan);

	cli::array<int>^ Materials_id = get_ids->get_material_ids_db(Contract_id);

	for (int i = 0; i < Materials_id->Length; i++)
	{
		int price_per_piece = get_price->get_price_per_piece(Materials_id[i]);
		int quantity = get_ids->get_quantity(Contract_id, Materials_id[i]);
		int price_provider = price_per_piece * quantity;
		int price_carrier = sqrt(sqrt(quantity)) * 30 * 1.1;

		Contract_price = Contract_price + price_provider + price_carrier;
	}

	Contract_price = Contract_price * 1.5;
	new_contract->update_price_db(Contract_id, Contract_price);

	MessageBox::Show("ֳ�� ��������� - " + Contract_price + "$" + Environment::NewLine +
		"����� - " + Contract_price * 0.2 + "$" + Environment::NewLine +
		"����� ��������� - 1 ��", "�����");
}

//������ ��� �������
Void Create_contract::button3_Click(System::Object^ sender, System::EventArgs^ e) {
	choose_builType_Form->UpdateImage();
	choose_builType_Form->Show();
	this->Hide();
}

//�����
Void Create_contract::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	manager_form->Show();
	this->Hide();
}