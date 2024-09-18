#include "Registration.h"
#include "Windows.h"
#include <iostream>
using namespace std;
#include <D:/Programs/C++ My Work/Course №2/Project1/sqlite/sqlite3.h>
#include <stdlib.h>
#include <string.h>
#include <msclr/marshal_cppstd.h> // Добавляем заголовочный файл для маршалинга строк


using namespace System::Runtime::InteropServices; // Добавляем пространство имен для маршалинга строк
using namespace msclr;
using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;
using namespace msclr::interop;

//Вийти
Void Registration::button2_Click(System::Object^ sender, System::EventArgs^ e) {

    Windows::Forms::DialogResult result = MessageBox::Show("Чи дійсно ви хочете вийти з програми?", "Увага",
        MessageBoxButtons::YesNo,
        MessageBoxIcon::Question);
    
        
    if (result == Windows::Forms::DialogResult::Yes) {
        Application::Exit();
    }
    
	
}
//Увійти
Void Registration::button1_Click(System::Object^ sender, System::EventArgs^ e) {
    /*String^ login = textBox1->Text;
    String^ password = textBox2->Text;

    SqlDataAdapter^ adapter = gcnew SqlDataAdapter();
    DataTable^ table = gcnew DataTable();

    String^ querystring = "select Id, Login, Password from Account where Login = '{login}' and Password = '{password}'";

    SqlConnection^ sqlConnection = gcnew SqlConnection("Data Source=D:\Programs\C++ My Work\Course №2\Project1\db\Building_database; Initial Catalog = Building_database; Integrated Security = True");

    SqlCommand^ command = gcnew SqlCommand(querystring, sqlConnection);

    adapter->SelectCommand = command;
    adapter->Fill(table);

    if (table->Rows->Count == 1)
    {
        MessageBox::Show("Ви увійшли", "Успіх", MessageBoxButtons::OK, MessageBoxIcon::Information);
        
    }
    else {
        MessageBox::Show("Пашол нахуй", "Хуй", MessageBoxButtons::OK, MessageBoxIcon::Information);
        
    }*/

    sqlite3* db; // Объект базы данных
    sqlite3_stmt* stmt; // Объект запроса
    int rc;

    String^ login = textBox1->Text;
    String^ password = textBox2->Text;

    // Подключение к базе данных
    rc = sqlite3_open("db\\Building_database.db", &db);
    
    if (rc) {
        MessageBox::Show("Чето не то1", "Увага");
    }
    else {
        // SQL запрос
        String^ sql = "SELECT * FROM Account WHERE Login='" + login + "' AND Password='" + password + "';";
        string sql_c = marshal_as<string>(sql);

        // Подготовка запроса
        rc = sqlite3_prepare_v2(db, sql_c.c_str(), -1, &stmt, NULL);
        if (rc == SQLITE_ERROR) {
            MessageBox::Show("SQLITE_ERROR", "Увага");
        }

        // Выполнение запроса
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            int Disconnected = sqlite3_column_int(stmt, 4);

            if (Disconnected == 1)
            {
                MessageBox::Show("Ваш акаунт відключенний. Ви не можете увійти у систему", "Увага");
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
            MessageBox::Show("Пароль або логін не вірний. Спробуйте ще раз.", "Увага");
        }

        // Освобождение ресурсов
        sqlite3_finalize(stmt);
        sqlite3_close(db);
    }
    
}

//Створення нового адміна
Void Registration::button3_Click(System::Object^ sender, System::EventArgs^ e) {
    check_form->Show();
    this->Hide();
}
