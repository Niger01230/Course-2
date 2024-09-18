#include "Registration.h"
#include "Windows.h"
#include <iostream>
using namespace std;
#include <D:/Programs/C++ My Work/Course �2/Project1/sqlite/sqlite3.h>
#include <stdlib.h>
#include <string.h>
#include <msclr/marshal_cppstd.h> // ��������� ������������ ���� ��� ���������� �����


using namespace System::Runtime::InteropServices; // ��������� ������������ ���� ��� ���������� �����
using namespace msclr;
using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;
using namespace msclr::interop;

//�����
Void Registration::button2_Click(System::Object^ sender, System::EventArgs^ e) {

    Windows::Forms::DialogResult result = MessageBox::Show("�� ����� �� ������ ����� � ��������?", "�����",
        MessageBoxButtons::YesNo,
        MessageBoxIcon::Question);
    
        
    if (result == Windows::Forms::DialogResult::Yes) {
        Application::Exit();
    }
    
	
}
//�����
Void Registration::button1_Click(System::Object^ sender, System::EventArgs^ e) {
    /*String^ login = textBox1->Text;
    String^ password = textBox2->Text;

    SqlDataAdapter^ adapter = gcnew SqlDataAdapter();
    DataTable^ table = gcnew DataTable();

    String^ querystring = "select Id, Login, Password from Account where Login = '{login}' and Password = '{password}'";

    SqlConnection^ sqlConnection = gcnew SqlConnection("Data Source=D:\Programs\C++ My Work\Course �2\Project1\db\Building_database; Initial Catalog = Building_database; Integrated Security = True");

    SqlCommand^ command = gcnew SqlCommand(querystring, sqlConnection);

    adapter->SelectCommand = command;
    adapter->Fill(table);

    if (table->Rows->Count == 1)
    {
        MessageBox::Show("�� ������", "����", MessageBoxButtons::OK, MessageBoxIcon::Information);
        
    }
    else {
        MessageBox::Show("����� �����", "���", MessageBoxButtons::OK, MessageBoxIcon::Information);
        
    }*/

    sqlite3* db; // ������ ���� ������
    sqlite3_stmt* stmt; // ������ �������
    int rc;

    String^ login = textBox1->Text;
    String^ password = textBox2->Text;

    // ����������� � ���� ������
    rc = sqlite3_open("db\\Building_database.db", &db);
    
    if (rc) {
        MessageBox::Show("���� �� ��1", "�����");
    }
    else {
        // SQL ������
        String^ sql = "SELECT * FROM Account WHERE Login='" + login + "' AND Password='" + password + "';";
        string sql_c = marshal_as<string>(sql);

        // ���������� �������
        rc = sqlite3_prepare_v2(db, sql_c.c_str(), -1, &stmt, NULL);
        if (rc == SQLITE_ERROR) {
            MessageBox::Show("SQLITE_ERROR", "�����");
        }

        // ���������� �������
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            int Disconnected = sqlite3_column_int(stmt, 4);

            if (Disconnected == 1)
            {
                MessageBox::Show("��� ������ �����������. �� �� ������ ����� � �������", "�����");
                sqlite3_finalize(stmt);
                sqlite3_close(db);
                return;
            }

            const char* level_of_access = (const char*)sqlite3_column_text(stmt, 3);

            textBox1->Text = "";
            textBox2->Text = "";

            if (strcmp(level_of_access, "0") == 0) {
                admin_form->login = login;
                admin_form->Show();
                this->Hide();
            }
            else if (strcmp(level_of_access, "1") == 0) {
                manager_form->login = login;
                manager_form->Show();
                this->Hide();
            }
            else if (strcmp(level_of_access, "2") == 0) {
                support_form->login = login;
                support_form->Show();
                this->Hide();
            }

        }
        else {
            MessageBox::Show("������ ��� ���� �� �����. ��������� �� ���.", "�����");
        }

        // ������������ ��������
        sqlite3_finalize(stmt);
        sqlite3_close(db);
    }
    
}

//��������� ������ �����
Void Registration::button3_Click(System::Object^ sender, System::EventArgs^ e) {
    check_form->Show();
    this->Hide();
}
