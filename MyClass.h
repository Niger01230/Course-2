#pragma once
#include <string>
#include <D:/Programs/C++ My Work/Course №2/Project1/sqlite/sqlite3.h>
#include <Windows.h>
#include <vcclr.h>
#include <iostream>
#include <fstream>
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace msclr::interop;
using namespace std;

namespace Project1 {

	public ref class DatabaseHelper {
	public:
		static sqlite3* open_database(String^ db_path) {
			sqlite3* db;
			int rc = sqlite3_open(marshal_as<string>(db_path).c_str(), &db);
			if (rc) {
				MessageBox::Show("Error opening database", "Warning");
				return nullptr;
			}
			return db;
		}

		static void close_database(sqlite3* db) {
			if (db != nullptr) {
				sqlite3_close(db);
			}
		}
	};

	public ref class Employee {
	protected:
		String^ Company;
		String^ Full_name;
		String^ Phone;
		int Id_of_account;

	public:
	};

	public ref class Admin_ : public Employee {

	public:
		void add_admin_db(
			String^ new_Company,
			String^ new_Full_name,
			String^ new_Phone,
			int Account_Id) {

			int rc;

			DatabaseHelper^ db_help = gcnew DatabaseHelper();
			sqlite3* db = db_help->open_database("db\\Building_database.db");

			Company = new_Company;
			Full_name = new_Full_name;
			Phone = new_Phone;

			String^ insertSqlAdmin = "INSERT INTO Admin (Company, Full_name, Phone, 'Id account') VALUES ('" + Company + "', '" + Full_name + "', '" + Phone + "', " + Account_Id + "); ";
			string insertSqlAdmin_c = marshal_as<string>(insertSqlAdmin);

			rc = sqlite3_exec(db, insertSqlAdmin_c.c_str(), NULL, NULL, NULL);

			//Перевірка на те, що дані успішно вставились
			if (rc != SQLITE_OK) {
				MessageBox::Show("Failed to insert data into Admin", "Warning");
				return;
			}
			else {
				MessageBox::Show("Акаунт адміністратора успішно створений. Дані збережено.", "Увага");
			}
			
			db_help->close_database(db);

		}
	};

	public ref class Manager_ : public Employee {
	protected:
		int Id_of_admin;

	public:
		void add_manager_db(
			String^ new_Company,
			String^ new_Full_name,
			String^ new_Phone,
			int Account_Id,
			String^ admin_login) {

			int rc;
			int admin_accountId;

			Company = new_Company;
			Full_name = new_Full_name;
			Phone = new_Phone;

			DatabaseHelper^ db_help = gcnew DatabaseHelper();
			sqlite3* db = db_help->open_database("db\\Building_database.db");
			sqlite3_stmt* stmt;

			//Знаходимо айді аккаунту, який зареєстрував менеджера
			String^ find_account_Id = "SELECT Id FROM Account WHERE Login = '" + admin_login + "';";
			string find_account_Id_str = marshal_as<string>(find_account_Id);

			rc = sqlite3_prepare_v2(db, find_account_Id_str.c_str(), -1, &stmt, NULL);
			//Перевіряємо, чи є помилка у запросі
			if (rc == SQLITE_ERROR) {
				MessageBox::Show("SQLITE_ERROR", "Warning");
			}

			if (sqlite3_step(stmt) == SQLITE_ROW) {
				admin_accountId = sqlite3_column_int(stmt, 0);
				sqlite3_finalize(stmt);
			}

			//Знаходимо айді адміна, який зареєстрував менеджера
			String^ find_adminID = "SELECT Id FROM Admin WHERE [Id account] = " + admin_accountId + "; ";
			string find_adminID_str = marshal_as<string>(find_adminID);

			rc = sqlite3_prepare_v2(db, find_adminID_str.c_str(), -1, &stmt, NULL);
			if (rc == SQLITE_ERROR) {
				MessageBox::Show("SQLITE_ERROR", "Warning");
			}

			if (sqlite3_step(stmt) == SQLITE_ROW) {
				Id_of_admin = sqlite3_column_int(stmt, 0);
				sqlite3_finalize(stmt);
			}

			String^ insertSqlManager = "INSERT INTO Manager (Company, Full_name, Phone, 'Id account', 'Id admin') VALUES ('" + Company + "', '" + Full_name + "', '" + Phone + "', " + Account_Id + ", " + Id_of_admin + "); ";
			string insertSqlManager_c = marshal_as<string>(insertSqlManager);

			rc = sqlite3_exec(db, insertSqlManager_c.c_str(), NULL, NULL, NULL);

			//Перевірка на те, що дані успішно вставились
			if (rc != SQLITE_OK) {
				MessageBox::Show("Failed to insert data into Admin", "Warning");
				return;
			}
			else {
				MessageBox::Show("Акаунт менеджера успішно створений. Дані збережено.", "Увага");
			}

			db_help->close_database(db);

		}

		int get_DisEnab_account(int id) {
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ sql = "SELECT [Id account] FROM Manager WHERE Id=" + id + ";";
			string sql_c = marshal_as<string>(sql);

			rc = sqlite3_prepare_v2(db, sql_c.c_str(), -1, &stmt, NULL);


			int account_id;

			if (sqlite3_step(stmt) == SQLITE_ROW) {
				account_id = sqlite3_column_int(stmt, 0);
			}

			sqlite3_finalize(stmt);
			sqlite3_close(db);

			return account_id;
		}

		String^ Request_all_managers_by_surname(String^ surname) {
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ selectSql = "SELECT *" +
				" FROM Manager" +
				" WHERE Full_name LIKE '" + surname + "%'";

			string selectSqlStr = marshal_as<string>(selectSql);

			rc = sqlite3_prepare_v2(db, selectSqlStr.c_str(), -1, &stmt, nullptr);

			String^ Request;
			String^ Info = "Усі менеджери з прізвищем " + surname + Environment::NewLine;

			while (sqlite3_step(stmt) == SQLITE_ROW) {
				int Id = sqlite3_column_int(stmt, 0);

				const unsigned char* cCompany = sqlite3_column_text(stmt, 1);
				string strCompany(reinterpret_cast<const char*>(cCompany));
				String^ Company = marshal_as<String^>(strCompany);

				const unsigned char* cName = sqlite3_column_text(stmt, 2);
				string strName(reinterpret_cast<const char*>(cName));
				String^ Name = marshal_as<String^>(strName);

				const unsigned char* cPhone = sqlite3_column_text(stmt, 3);
				string strPhone(reinterpret_cast<const char*>(cPhone));
				String^ Phone = marshal_as<String^>(strPhone);

				Request += "Id: " + Id + Environment::NewLine +
					"Company: " + Company + Environment::NewLine +
					"Name: " + Name + Environment::NewLine +
					"Phone: " + Phone + Environment::NewLine +
					Environment::NewLine;
			}

			if (Request == nullptr)
			{
				Request = "Менеджери не знайдені";
				sqlite3_finalize(stmt);
				sqlite3_close(db);
				return Request;
			}

			Request = Info + Request;

			sqlite3_finalize(stmt);
			sqlite3_close(db);
			return Request;
		}

		String^ Request_all_managers_whichNoContact_by_day(DateTime day) {
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ selectSql = "SELECT M.*" +
				" FROM Manager AS M" +
				" LEFT JOIN Contract AS C ON M.Id = C.[Id manager] AND C.[Start date] == '" + day + "'" +
				" WHERE C.[Id] IS NULL;";

			string selectSqlStr = marshal_as<string>(selectSql);

			rc = sqlite3_prepare_v2(db, selectSqlStr.c_str(), -1, &stmt, nullptr);

			String^ Request;
			String^ Info = "Усі менеджери, які не створювали контракти в обраний день: " + Environment::NewLine;

			while (sqlite3_step(stmt) == SQLITE_ROW) {
				int Id = sqlite3_column_int(stmt, 0);

				const unsigned char* cCompany = sqlite3_column_text(stmt, 1);
				string strCompany(reinterpret_cast<const char*>(cCompany));
				String^ Company = marshal_as<String^>(strCompany);

				const unsigned char* cName = sqlite3_column_text(stmt, 2);
				string strName(reinterpret_cast<const char*>(cName));
				String^ Name = marshal_as<String^>(strName);

				const unsigned char* cPhone = sqlite3_column_text(stmt, 3);
				string strPhone(reinterpret_cast<const char*>(cPhone));
				String^ Phone = marshal_as<String^>(strPhone);

				Request += "Id: " + Id + Environment::NewLine +
					"Company: " + Company + Environment::NewLine +
					"Name: " + Name + Environment::NewLine +
					"Phone: " + Phone + Environment::NewLine +
					Environment::NewLine;
			}

			if (Request == nullptr)
			{
				Request = "Менеджери не знайдені";
				sqlite3_finalize(stmt);
				sqlite3_close(db);
				return Request;
			}

			Request = Info + Request;

			sqlite3_finalize(stmt);
			sqlite3_close(db);
			return Request;
		}

		String^ Request_all_managers_whichNoAndYesContact_by_day(DateTime day) {
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ selectSql = "SELECT Id, Company, Full_name, Phone, 'Не створював контракти в обраний день' AS Comment" +
				" FROM Manager AS M" +
				" WHERE NOT EXISTS(" +
				" SELECT 1" +
				" FROM Contract AS C" +
				" WHERE C.[Id manager] = M.Id" +
				" AND C.[Start date] = '" + day + "'" +
				" )" +
				" UNION" +
				" SELECT Id, Company, Full_name, Phone, 'Створював контракти в обраний день' AS Comment" +
				" FROM Manager AS M" +
				" WHERE EXISTS(" +
				" SELECT 1" +
				" FROM Contract AS C" +
				" WHERE C.[Id manager] = M.Id" +
				" AND C.[Start date] = '" + day + "'" +
				" );";

			string selectSqlStr = marshal_as<string>(selectSql);

			rc = sqlite3_prepare_v2(db, selectSqlStr.c_str(), -1, &stmt, nullptr);

			String^ Request;
			String^ Info = "Усі менеджери, які створювали та не створювали контракти в обраний день: " + Environment::NewLine;

			while (sqlite3_step(stmt) == SQLITE_ROW) {
				int Id = sqlite3_column_int(stmt, 0);

				const unsigned char* cCompany = sqlite3_column_text(stmt, 1);
				string strCompany(reinterpret_cast<const char*>(cCompany));
				String^ Company = marshal_as<String^>(strCompany);

				const unsigned char* cName = sqlite3_column_text(stmt, 2);
				string strName(reinterpret_cast<const char*>(cName));
				String^ Name = marshal_as<String^>(strName);

				const unsigned char* cPhone = sqlite3_column_text(stmt, 3);
				string strPhone(reinterpret_cast<const char*>(cPhone));
				String^ Phone = marshal_as<String^>(strPhone);

				const unsigned char* cComment = sqlite3_column_text(stmt, 4);
				string strComment(reinterpret_cast<const char*>(cComment));
				String^ Comment = marshal_as<String^>(strComment);

				Request += "Id: " + Id + Environment::NewLine +
					"Company: " + Company + Environment::NewLine +
					"Name: " + Name + Environment::NewLine +
					"Phone: " + Phone + Environment::NewLine +
					"Comment: " + Comment + Environment::NewLine +
					Environment::NewLine;
			}

			if (Request == nullptr)
			{
				Request = "Менеджери не знайдені";
				sqlite3_finalize(stmt);
				sqlite3_close(db);
				return Request;
			}

			Request = Info + Request;

			sqlite3_finalize(stmt);
			sqlite3_close(db);
			return Request;
		}
	};

	public ref class Head_of_support_ : public Employee {
	protected:
		int Id_of_admin;

	public:
		void add_support_db(
			String^ new_Company,
			String^ new_Full_name,
			String^ new_Phone,
			int Account_Id,
			String^ admin_login) {

			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;
			int admin_accountId;

			Company = new_Company;
			Full_name = new_Full_name;
			Phone = new_Phone;

			rc = sqlite3_open("db\\Building_database.db", &db);

			//Перевіряємо підключення до БД
			if (rc) {
				MessageBox::Show("Something went wrong", "Warning");
				return;
			}

			//Знаходимо айді аккаунту, який зареєстрував голову забезпечення
			String^ find_account_Id = "SELECT Id FROM Account WHERE Login = '" + admin_login + "';";
			string find_account_Id_str = marshal_as<string>(find_account_Id);

			rc = sqlite3_prepare_v2(db, find_account_Id_str.c_str(), -1, &stmt, NULL);
			//Перевіряємо, чи є помилка у запросі
			if (rc == SQLITE_ERROR) {
				MessageBox::Show("SQLITE_ERROR", "Warning");
			}

			if (sqlite3_step(stmt) == SQLITE_ROW) {
				admin_accountId = sqlite3_column_int(stmt, 0);
				sqlite3_finalize(stmt);
			}

			//Знаходимо айді адміна, який зареєстрував голову забезпечення
			String^ find_adminID = "SELECT Id FROM Admin WHERE [Id account] = " + admin_accountId + "; ";
			string find_adminID_str = marshal_as<string>(find_adminID);

			rc = sqlite3_prepare_v2(db, find_adminID_str.c_str(), -1, &stmt, NULL);
			if (rc == SQLITE_ERROR) {
				MessageBox::Show("SQLITE_ERROR", "Warning");
			}

			if (sqlite3_step(stmt) == SQLITE_ROW) {
				Id_of_admin = sqlite3_column_int(stmt, 0);
				sqlite3_finalize(stmt);
			}

			String^ insertSqlManager = "INSERT INTO Head_of_Support (Company, Full_name, Phone, 'Id account', 'Id admin') VALUES ('" + Company + "', '" + Full_name + "', '" + Phone + "', " + Account_Id + ", " + Id_of_admin + "); ";
			string insertSqlManager_c = marshal_as<string>(insertSqlManager);

			rc = sqlite3_exec(db, insertSqlManager_c.c_str(), NULL, NULL, NULL);

			//Перевірка на те, що дані успішно вставились
			if (rc != SQLITE_OK) {
				MessageBox::Show("Failed to insert data into Admin", "Warning");
				return;
			}
			else {
				MessageBox::Show("Акаунт голови департаменту забезпечення успішно створений. Дані збережено.", "Увага");
			}

			sqlite3_close(db);

		}

		int get_DisEnab_account(int id) {
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ sql = "SELECT [Id account] FROM Head_of_Support WHERE Id=" + id + ";";
			string sql_c = marshal_as<string>(sql);

			rc = sqlite3_prepare_v2(db, sql_c.c_str(), -1, &stmt, NULL);


			int account_id;

			if (sqlite3_step(stmt) == SQLITE_ROW) {
				account_id = sqlite3_column_int(stmt, 0);
			}

			sqlite3_finalize(stmt);
			sqlite3_close(db);

			return account_id;
		}
	};


	public ref class Account_ {
	protected:
		String^ Login;
		String^ Password;
		int Level_of_access;
		int isDisconected;

	public:
		int add_account_db(String^ new_Login, String^ new_Password, int new_Level_of_access, int& Account_Id) {
			Login = new_Login;
			Password = new_Password;
			Level_of_access = new_Level_of_access;

			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			//Перевірка підключення до БД
			if (rc) {
				MessageBox::Show("Something went wrong", "Warning");
				return rc;
			}

			String^ sql = "SELECT * FROM Account WHERE Login='" + Login + "';";
			string sql_c = marshal_as<string>(sql);

			rc = sqlite3_prepare_v2(db, sql_c.c_str(), -1, &stmt, NULL);
			//Перевірка на помилку у запросі
			if (rc == SQLITE_ERROR) {
				MessageBox::Show("SQLITE_ERROR", "Warning");
				sqlite3_finalize(stmt);
				sqlite3_close(db);
				return rc;
			}

			//Перевірка на те, що такий логін вже є
			if (sqlite3_step(stmt) == SQLITE_ROW) {
				MessageBox::Show("Такий логін вже є. Спробуйте ще раз.", "Увага");
				sqlite3_finalize(stmt);
				sqlite3_close(db);
				return SQLITE_ERROR;

			}

			String^ insertSql_Account = "INSERT INTO Account (Login, Password, Level_of_access) VALUES ('" + Login + "', '" + Password + "', " + Level_of_access + "); ";
			string insertSql_Account_str = marshal_as<string>(insertSql_Account);

			rc = sqlite3_exec(db, insertSql_Account_str.c_str(), NULL, NULL, NULL);

			//Перевірка на те, що дані успішно вставились
			if (rc != SQLITE_OK) {
				MessageBox::Show("Failed to insert data", "Warning");
			}
			

			Account_Id = sqlite3_last_insert_rowid(db);

			sqlite3_finalize(stmt);
			sqlite3_close(db);

			return rc;
		}

		void disEnab_manager_account_db(int choose, int id) {
			Manager_^ manager;
			int id_account = manager->get_DisEnab_account(id);
			sqlite3* db;
			int rc = sqlite3_open("db\\Building_database.db", &db);
			String^ query;

			switch (choose)
			{
			//На відключення
			case 0:
				query = "UPDATE Account SET Disconnected = 1 WHERE Id =" + id_account + ";";
				MessageBox::Show("Менеджер успішно відключенний.", "Увага");
				break;

			//На підключення
			case 1:
				query = "UPDATE Account SET Disconnected = 0 WHERE Id =" + id_account + ";";
				MessageBox::Show("Менеджер успішно підключенний.", "Увага");
				break;
			}
			
			string query_str = marshal_as<string>(query);

			// Выполняем SQL-запрос
			rc = sqlite3_exec(db, query_str.c_str(), nullptr, nullptr, nullptr);
			sqlite3_close(db);
		}

		void disEnab_headOfSupport_account_db(int choose, int id) {
			Head_of_support_^ headOfSupport;
			int id_account = headOfSupport->get_DisEnab_account(id);
			sqlite3* db;
			int rc = sqlite3_open("db\\Building_database.db", &db);
			String^ query;

			switch (choose)
			{
				//На відключення
			case 0:
				query = "UPDATE Account SET Disconnected = 1 WHERE Id =" + id_account + ";";
				MessageBox::Show("Голова забезпечення успішно відключенний.", "Увага");
				break;

				//На підключення
			case 1:
				query = "UPDATE Account SET Disconnected = 0 WHERE Id =" + id_account + ";";
				MessageBox::Show("Голова забезпечення успішно підключенний.", "Увага");
				break;
			}

			string query_str = marshal_as<string>(query);

			// Выполняем SQL-запрос
			rc = sqlite3_exec(db, query_str.c_str(), nullptr, nullptr, nullptr);
			sqlite3_close(db);
		}
	};


	public ref class Client_ {
	protected:
		String^ Full_name;
		String^ Address;
		String^ Phone;

	public:
		void add_client_db(
			String^ new_Full_name,
			String^ new_Address,
			String^ new_Phone,
			String^ login_manager) {

			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			Full_name = new_Full_name;
			Address = new_Address;
			Phone = new_Phone;

			rc = sqlite3_open("db\\Building_database.db", &db);
		
			//Знаходимо айді аккаунту, який зареєстрував клієнта
			String^ find_account_Id = "SELECT Id FROM Account WHERE Login = '" + login_manager + "';";
			string find_account_Id_str = marshal_as<string>(find_account_Id);

			rc = sqlite3_prepare_v2(db, find_account_Id_str.c_str(), -1, &stmt, NULL);
			//Перевіряємо, чи є помилка у запросі
			if (rc == SQLITE_ERROR) {
				MessageBox::Show("SQLITE_ERROR", "Warning");
			}

			int account_manager_id;

			if (sqlite3_step(stmt) == SQLITE_ROW) {
				account_manager_id = sqlite3_column_int(stmt, 0);
				sqlite3_finalize(stmt);
			}

			//Знаходимо айді менеджера, який зареєстрував клієнта
			String^ find_managerID = "SELECT Id FROM Manager WHERE [Id account] = " + account_manager_id + "; ";
			string find_managerID_str = marshal_as<string>(find_managerID);

			rc = sqlite3_prepare_v2(db, find_managerID_str.c_str(), -1, &stmt, NULL);
			if (rc == SQLITE_ERROR) {
				MessageBox::Show("SQLITE_ERROR", "Warning");
			}
			
			int manager_id;

			if (sqlite3_step(stmt) == SQLITE_ROW) {
				manager_id = sqlite3_column_int(stmt, 0);
				sqlite3_finalize(stmt);
			}

			String^ insertSqlClient = "INSERT INTO Client (Full_name, Address, Phone, [Id manager]) VALUES ('" + Full_name + "', '" + Address + "', '" + Phone + "', " + manager_id + ");";
			string insertSqlClient_c = marshal_as<string>(insertSqlClient);

			rc = sqlite3_exec(db, insertSqlClient_c.c_str(), NULL, NULL, NULL);

			//Перевірка на те, що дані успішно вставились
			if (rc != SQLITE_OK) {
				MessageBox::Show("Failed to insert data into Client", "Warning");
				return;
			}
			else {
				MessageBox::Show("Дані клієнта успішно збережено.", "Увага");
			}
			sqlite3_close(db);

		}
	};

	public ref class Contract_ {
	protected:
		String^ Address;
		int Area_of_site;
		int Area_of_building;
		int Number_of_floors;
		DateTime Start_date;
		DateTime End_date;
		DOUBLE Cost;
		DOUBLE Imprest;
		BOOLEAN isImprest;
		BOOLEAN isPaid;
		int Id_building;
		int Id_manager;
		int Id_client;

	public:

		void add_contract_db(
			String^ new_Address,
			int new_Area_of_site,
			int new_Area_of_building,
			int new_Number_of_floors,
			DateTime new_Start_date,
			int type,
			String^ client,
			String^ login_manager,
			int& Contract_id) {
		
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			Address = new_Address;
			Area_of_site = new_Area_of_site;
			Area_of_building = new_Area_of_building;
			Number_of_floors = new_Number_of_floors;
			Start_date = new_Start_date;

			cli::array<String^>^ parts = client->Split(',');
			int id_client = Convert::ToInt32(parts[0]);

			rc = sqlite3_open("db\\Building_database.db", &db);

			//Знаходимо айді аккаунту, який зареєстрував контракт
			String^ find_account_Id = "SELECT Id FROM Account WHERE Login = '" + login_manager + "';";
			string find_account_Id_str = marshal_as<string>(find_account_Id);

			rc = sqlite3_prepare_v2(db, find_account_Id_str.c_str(), -1, &stmt, NULL);
			//Перевіряємо, чи є помилка у запросі
			if (rc == SQLITE_ERROR) {
				MessageBox::Show("SQLITE_ERROR", "Warning");
			}

			int account_manager_id;

			if (sqlite3_step(stmt) == SQLITE_ROW) {
				account_manager_id = sqlite3_column_int(stmt, 0);
				sqlite3_finalize(stmt);
			}

			//Знаходимо айді менеджера, який зареєстрував контракт
			String^ find_managerID = "SELECT Id FROM Manager WHERE [Id account] = " + account_manager_id + "; ";
			string find_managerID_str = marshal_as<string>(find_managerID);

			rc = sqlite3_prepare_v2(db, find_managerID_str.c_str(), -1, &stmt, NULL);
			if (rc == SQLITE_ERROR) {
				MessageBox::Show("SQLITE_ERROR", "Warning");
			}

			int manager_id;

			if (sqlite3_step(stmt) == SQLITE_ROW) {
				manager_id = sqlite3_column_int(stmt, 0);
				sqlite3_finalize(stmt);
			}

			DateTime End_date = Start_date.AddYears(1);

			String^ insertSqlContract = 
				"INSERT INTO Contract (Address, [Area of site], [Area of building], [Number of floors], [Start date], [End date], Cost, Imprest, isImprest, isPaid, [Id building], [Id manager], [Id client])" +
				"VALUES ('" + Address + "', " + Area_of_site + ", " + Area_of_building + ", " + Number_of_floors + ", '" + Start_date + "', '" + End_date + "', " + 10000 + ", " + 1000 + ", " + false + ", " + false + ", " + type + ", " + manager_id + ", " + id_client + "); ";
			string insertSqlContract_c = marshal_as<string>(insertSqlContract);

			rc = sqlite3_exec(db, insertSqlContract_c.c_str(), NULL, NULL, NULL);

			//Перевірка на те, що дані успішно вставились
			if (rc != SQLITE_OK) {
				MessageBox::Show("Failed to insert data into Contract", "Warning");
				return;
			}
			else {
				MessageBox::Show("Дані контракта успішно збережено.", "Увага");
			}

			Contract_id = sqlite3_last_insert_rowid(db);

			sqlite3_close(db);
		}

		void update_price_db(int Contract_id, int Contract_price) {
			sqlite3* db;
			int rc;

			int Imprest = Contract_price * 0.2;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ updateSqlPrice = "UPDATE Contract SET Cost = " + Contract_price + ", Imprest = " + Imprest + " WHERE Id = " + Contract_id + "";
			string updateSqlPrice_c = marshal_as<string>(updateSqlPrice);

			// Выполняем SQL запрос
			rc = sqlite3_exec(db, updateSqlPrice_c.c_str(), NULL, NULL, NULL);

			//Перевірка на те, що дані успішно вставились
			if (rc != SQLITE_OK) {
				MessageBox::Show("Failed to update data in the Contract", "Warning");
				return;
			}

			sqlite3_close(db);
		}

		void update_contract_db(String^ sql_req) {
			sqlite3* db;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			string updateSqlContract_c = marshal_as<string>(sql_req);

			// Выполняем SQL запрос
			rc = sqlite3_exec(db, updateSqlContract_c.c_str(), NULL, NULL, NULL);

			//Перевірка на те, що дані успішно вставились
			if (rc != SQLITE_OK) {
				MessageBox::Show("Failed to update data in the Contract", "Warning");
				return;
			}

			sqlite3_close(db);
		}

		DateTime get_start_date(int Contract_id) {
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ find_start_date = "SELECT [Start date] FROM Contract WHERE Id = " + Contract_id + ";";
			string find_start_date_str = marshal_as<string>(find_start_date);

			rc = sqlite3_prepare_v2(db, find_start_date_str.c_str(), -1, &stmt, NULL);
			//Перевіряємо, чи є помилка у запросі
			if (rc == SQLITE_ERROR) {
				MessageBox::Show("SQLITE_ERROR", "Warning");
			}

			DateTime return_date;
			String^ str_date;

			if (sqlite3_step(stmt) == SQLITE_ROW) {
				const unsigned char* name = sqlite3_column_text(stmt, 0);
				string Text = reinterpret_cast<const char*>(name);
				str_date = marshal_as<String^>(Text);
				DateTime::TryParse(str_date, return_date);
			}

			sqlite3_finalize(stmt);
			sqlite3_close(db);

			return return_date;
		}

		int get_cost(int Contract_id) {
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ find_Cost = "SELECT Cost FROM Contract WHERE Id = " + Contract_id + ";";
			string find_Cost_str = marshal_as<string>(find_Cost);

			rc = sqlite3_prepare_v2(db, find_Cost_str.c_str(), -1, &stmt, NULL);
			//Перевіряємо, чи є помилка у запросі
			if (rc == SQLITE_ERROR) {
				MessageBox::Show("SQLITE_ERROR", "Warning");
			}

			int Cost;

			if (sqlite3_step(stmt) == SQLITE_ROW) {
				Cost = sqlite3_column_int(stmt, 0);

			}

			sqlite3_finalize(stmt);
			sqlite3_close(db);

			return Cost;
		}

		bool get_isImprest(int Contract_id) {
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ find_isImprest = "SELECT isImprest FROM Contract WHERE Id = " + Contract_id + ";";
			string find_isImprest_str = marshal_as<string>(find_isImprest);

			rc = sqlite3_prepare_v2(db, find_isImprest_str.c_str(), -1, &stmt, NULL);
			//Перевіряємо, чи є помилка у запросі
			if (rc == SQLITE_ERROR) {
				MessageBox::Show("SQLITE_ERROR", "Warning");
			}

			bool isImprest;

			if (sqlite3_step(stmt) == SQLITE_ROW) {
				isImprest = sqlite3_column_int(stmt, 0);
				
			}

			sqlite3_finalize(stmt);
			sqlite3_close(db);

			return isImprest;
		}

		bool get_isPaid(int Contract_id) {
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ find_isPaid = "SELECT isPaid FROM Contract WHERE Id = " + Contract_id + ";";
			string find_isPaid_str = marshal_as<string>(find_isPaid);

			rc = sqlite3_prepare_v2(db, find_isPaid_str.c_str(), -1, &stmt, NULL);
			//Перевіряємо, чи є помилка у запросі
			if (rc == SQLITE_ERROR) {
				MessageBox::Show("SQLITE_ERROR", "Warning");
			}

			bool isPaid;

			if (sqlite3_step(stmt) == SQLITE_ROW) {
				isPaid = sqlite3_column_int(stmt, 0);

			}

			sqlite3_finalize(stmt);
			sqlite3_close(db);

			return isPaid;
		}

		void delete_contract_db(int Contract_id) {
			sqlite3* db;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ deleteContract = "DELETE FROM Contract WHERE Id == " + Contract_id + ";";
			string deleteContract_c = marshal_as<string>(deleteContract);

			// Выполняем SQL запрос
			rc = sqlite3_exec(db, deleteContract_c.c_str(), NULL, NULL, NULL);

			//Перевірка на те, що дані успішно вставились
			if (rc != SQLITE_OK) {
				MessageBox::Show("Failed to delete data in the Contract", "Warning");
				return;
			}

			MessageBox::Show("Контракт успішно видалено.", "Увага");

			sqlite3_close(db);
		}


		String^ Request_estimate(int Contract_id) {
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ selectSql = "SELECT" +
				" SUM(NM.Quantity * M.Price_per_piece) AS TotalMaterialCost," +
				" C.Cost," +
				" C.Imprest," +
				" M.Name" +
				" FROM" +
				" Necessary_material AS NM" +
				" INNER JOIN" +
				" Material AS M ON NM.Id_material = M.Id" +
				" INNER JOIN" +
				" Contract AS C ON NM.Id_contract = C.Id" +
				" WHERE" +
				" NM.Id_contract = " + Contract_id +
				" GROUP BY" +
				" NM.Id_material; ";

			string selectSqlStr = marshal_as<string>(selectSql);

			rc = sqlite3_prepare_v2(db, selectSqlStr.c_str(), -1, &stmt, nullptr);

			String^ Request;

			if (rc != SQLITE_OK) {
				MessageBox::Show("SQLITE_ERROR", "Warning");
			}


			if (sqlite3_step(stmt) == SQLITE_ROW)
			{
				int cost = sqlite3_column_int(stmt, 1);
				int imprest = sqlite3_column_int(stmt, 2);
				Request += "	Складання кошторису контракту №" + Contract_id + Environment::NewLine +
							"Ціна контракту: " + cost + "$" + Environment::NewLine +
							"Аванс: " + imprest + "$" + Environment::NewLine;

				const unsigned char* cName_mat = sqlite3_column_text(stmt, 3);
				string strName_mat(reinterpret_cast<const char*>(cName_mat));
				String^ Name_mat = marshal_as<String^>(strName_mat);
				int cost_mat = sqlite3_column_int(stmt, 0);

				Request += "Ціна матеріалу " + Name_mat + " - " + cost_mat + "$" + Environment::NewLine;
			}

			while (sqlite3_step(stmt) == SQLITE_ROW) {
				const unsigned char* cName_mat = sqlite3_column_text(stmt, 3);
				string strName_mat(reinterpret_cast<const char*>(cName_mat));
				String^ Name_mat = marshal_as<String^>(strName_mat);
				int cost_mat = sqlite3_column_int(stmt, 0);

				Request += "Ціна матеріалу " + Name_mat + " - " + cost_mat + "$" + Environment::NewLine;

			}

			sqlite3_finalize(stmt);
			sqlite3_close(db);
			return Request;
		}

		String^ Request_bigger_average() {
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ selectSql = "SELECT C.[Id], C.[Address], C.[Area of site], C.[Area of building], C.[Number of floors], C.[Start date], C.[End date], C.[Cost], C.[Imprest], C.[isImprest], C.[isPaid], Type_of_house.Name_of_type, Manager.Id, Manager.Full_name, Client.Id, Client.Full_name" +
				" FROM Contract AS C" +
				" JOIN Type_of_house ON C.[Id building] = Type_of_house.Id" +
				" JOIN Manager ON C.[Id manager] = Manager.Id" +
				" JOIN Client ON C.[Id client] = Client.Id" +
				" WHERE C.[Cost] > (" +
				" SELECT AVG(C2.[Cost])" +
				" FROM Contract AS C2" +
				" WHERE C2.[Id manager] = C.[Id manager]" +
				" );";

			string selectSqlStr = marshal_as<string>(selectSql);

			rc = sqlite3_prepare_v2(db, selectSqlStr.c_str(), -1, &stmt, nullptr);

			String^ Request;

			if (rc != SQLITE_OK) {
				MessageBox::Show("SQLITE_ERROR", "Warning");
			}

			Request += "Контракти, які коштують більше ніж середня ціна усіх контрактів:" + Environment::NewLine;

			while (sqlite3_step(stmt) == SQLITE_ROW) {
				const unsigned char* cName_mat = sqlite3_column_text(stmt, 3);
				string strName_mat(reinterpret_cast<const char*>(cName_mat));
				String^ Name_mat = marshal_as<String^>(strName_mat);
				
				int Id = sqlite3_column_int(stmt, 0);

				const unsigned char* cAddress = sqlite3_column_text(stmt, 1);
				string strAddress(reinterpret_cast<const char*>(cAddress));
				String^ Address = marshal_as<String^>(strAddress);

				int Area_of_site = sqlite3_column_int(stmt, 2);
				int Area_of_building = sqlite3_column_int(stmt, 3);
				int Number_of_floors = sqlite3_column_int(stmt, 4);

				const unsigned char* cStartDate = sqlite3_column_text(stmt, 5);
				string strStartDate(reinterpret_cast<const char*>(cStartDate));
				String^ StartDate = marshal_as<String^>(strStartDate);

				const unsigned char* cEndDate = sqlite3_column_text(stmt, 6);
				string strEndDate(reinterpret_cast<const char*>(cEndDate));
				String^ EndDate = marshal_as<String^>(strEndDate);

				int Cost = sqlite3_column_int(stmt, 7);
				int Imprest = sqlite3_column_int(stmt, 8);
				bool isImprest = sqlite3_column_int(stmt, 9);
				bool isPaid = sqlite3_column_int(stmt, 10);

				const unsigned char* cBulType = sqlite3_column_text(stmt, 11);
				string strBulType(reinterpret_cast<const char*>(cBulType));
				String^ BulType = marshal_as<String^>(strBulType);

				int Id_manager = sqlite3_column_int(stmt, 12);

				const unsigned char* cNameManager = sqlite3_column_text(stmt, 13);
				string strNameManager(reinterpret_cast<const char*>(cNameManager));
				String^ NameManager = marshal_as<String^>(strNameManager);

				int Id_client = sqlite3_column_int(stmt, 14);

				const unsigned char* cNameClient = sqlite3_column_text(stmt, 15);
				string strNameClient(reinterpret_cast<const char*>(cNameClient));
				String^ NameClient = marshal_as<String^>(strNameClient);

				Request += Environment::NewLine +
					"Id: " + Id + Environment::NewLine +
					"Адреса: " + Address + Environment::NewLine +
					"Площа ділянки: " + Area_of_site + " метрів квадратних" + Environment::NewLine + 
					"Площа будівлі: " + Area_of_building + " метрів квадратних" + Environment::NewLine +
					"Кількість поверхів: " + Number_of_floors + Environment::NewLine +
					"Дата початку будівництва: " + StartDate + Environment::NewLine +
					"Дата закінчення будівництва: " + EndDate + Environment::NewLine +
					"Ціна контракту: " + Cost + "$" + Environment::NewLine + 
					"Розмір авансу: " + Imprest + "$" + Environment::NewLine +
					"Чи внесено аванс: " + isImprest + Environment::NewLine +
					"Чи повністю оплачено: " + isPaid + Environment::NewLine +
					"Менеджер, який відповідає за цей контракт: " + Id_manager + "," + NameManager + Environment::NewLine +
					"Клієнт, якому належить цей контракт: " + Id_client + "," + NameClient + Environment::NewLine +
					Environment::NewLine;
			}

			sqlite3_finalize(stmt);
			sqlite3_close(db);
			return Request;
		}

		String^ Request_contract_per_week() {
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			DateTime new_End_date = DateTime::Today;
			DateTime new_Start_date = new_End_date.AddDays(-7);

			String^ formated_End_date = new_End_date.ToString("yyyy-MM-dd");
			String^ formated_Start_date = new_Start_date.ToString("yyyy-MM-dd");;

			String^ selectSql = "SELECT 'Total' AS Name_of_type, COUNT(*) AS ContractCount" +
				" FROM Contract c" +
				" WHERE date(substr(c.[Start date], 7, 4) || '-' || substr(c.[Start date], 4, 2) || '-' || substr(c.[Start date], 1, 2))" +
				" BETWEEN date('" + formated_Start_date + "')" +
				" AND date('" + formated_End_date + "')" +

				" UNION ALL" +

				" SELECT th.Name_of_type, COUNT(*) AS ContractCount" +
				" FROM Contract c" +
				" JOIN Type_of_house th ON c.[Id building] = th.Id" +
				" WHERE date(substr(c.[Start date], 7, 4) || '-' || substr(c.[Start date], 4, 2) || '-' || substr(c.[Start date], 1, 2))" +
				" BETWEEN date('" + formated_Start_date + "')" +
				" AND date('" + formated_End_date + "')" +
				" GROUP BY th.Name_of_type;";

			string selectSqlStr = marshal_as<string>(selectSql);

			rc = sqlite3_prepare_v2(db, selectSqlStr.c_str(), -1, &stmt, nullptr);

			String^ Request;

			int quantity;

			if (sqlite3_step(stmt) == SQLITE_ROW) {
				quantity = sqlite3_column_int(stmt, 1);
			}

			Request += "Кількість контрактів за тиждень - " + quantity + Environment::NewLine;

			while (sqlite3_step(stmt) == SQLITE_ROW) {
				const unsigned char* cName_of_type = sqlite3_column_text(stmt, 0);
				string strName_of_type(reinterpret_cast<const char*>(cName_of_type));
				String^ Name_of_type = marshal_as<String^>(strName_of_type);

				quantity = sqlite3_column_int(stmt, 1);
				Request += "Кількість контрактів із типом будівлі " + Name_of_type + " за тиждень - " + quantity + Environment::NewLine;
			}

			sqlite3_finalize(stmt);
			sqlite3_close(db);
			return Request;
		}

		String^ Request_contract_per_week_by_manager(DateTime new_End_date, DateTime new_Start_date, String^ surname) {
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ formated_End_date = new_End_date.ToString("yyyy-MM-dd");
			String^ formated_Start_date = new_Start_date.ToString("yyyy-MM-dd");;

			String^ selectSql = "SELECT Contract.[Id manager], Manager.Full_name, COUNT(*) AS ContractCount" +
				" FROM Contract" +
				" JOIN Manager ON Contract.[Id manager] = Manager.Id" +
				" WHERE Full_name LIKE '" + surname + "%'" +
				" AND date(substr(Contract.[Start date], 7, 4) || '-' || substr(Contract.[Start date], 4, 2) || '-' || substr(Contract.[Start date], 1, 2))" +
				" BETWEEN date('" + formated_Start_date + "')" +
				" AND date('" + formated_End_date + "')" +
				" GROUP BY Contract.[Id manager];";

			string selectSqlStr = marshal_as<string>(selectSql);

			rc = sqlite3_prepare_v2(db, selectSqlStr.c_str(), -1, &stmt, nullptr);

			String^ Request;
			String^ info = "Кількість контрактів кожного менеджера за обраний період:" + Environment::NewLine;

			while (sqlite3_step(stmt) == SQLITE_ROW) {
				int Id = sqlite3_column_int(stmt, 0);

				const unsigned char* cName = sqlite3_column_text(stmt, 1);
				string strName(reinterpret_cast<const char*>(cName));
				String^ Name = marshal_as<String^>(strName);

				int Quantity = sqlite3_column_int(stmt, 2);

				Request += "Id: " + Id + Environment::NewLine +
					"Повне ім'я: " + Name + Environment::NewLine +
					"Кількість контрактів: " + Quantity + Environment::NewLine +
					Environment::NewLine;
			}

			if (Request == nullptr)
			{
				Request = "Менеджери не знайдені.";
			}
			else {
				Request = info + Request;
			}

			sqlite3_finalize(stmt);
			sqlite3_close(db);
			return Request;
		}

		String^ Request_contracts_by_manager(int Id_manager, DateTime Start_date, DateTime End_date) {
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ formated_End_date = End_date.ToString("yyyy-MM-dd");
			String^ formated_Start_date = Start_date.ToString("yyyy-MM-dd");;

			String^ selectSql = "SELECT C.[Id], C.[Address], C.[Area of site], C.[Area of building], C.[Number of floors], C.[Start date], C.[End date], C.[Cost], C.[Imprest], C.[isImprest], C.[isPaid], Type_of_house.Name_of_type, Manager.Id, Manager.Full_name, Client.Id, Client.Full_name" +
				" FROM Contract AS C" +
				" JOIN Type_of_house ON C.[Id building] = Type_of_house.Id" +
				" JOIN Manager ON C.[Id manager] = Manager.Id" +
				" JOIN Client ON C.[Id client] = Client.Id" +
				" WHERE date(substr(C.[Start date], 7, 4) || '-' || substr(C.[Start date], 4, 2) || '-' || substr(C.[Start date], 1, 2))" +
				" BETWEEN date('" + formated_Start_date + "')" +
				" AND date('" + formated_End_date + "')" +
				" AND Manager.Id == " + Id_manager + ";";

			string selectSqlStr = marshal_as<string>(selectSql);

			rc = sqlite3_prepare_v2(db, selectSqlStr.c_str(), -1, &stmt, nullptr);

			String^ Request;
			String^ Info = "Усі контракти менеджера №" + Id_manager + Environment::NewLine;

			while (sqlite3_step(stmt) == SQLITE_ROW) {
				int Id = sqlite3_column_int(stmt, 0);

				const unsigned char* cAddress = sqlite3_column_text(stmt, 1);
				string strAddress(reinterpret_cast<const char*>(cAddress));
				String^ Address = marshal_as<String^>(strAddress);

				int Area_of_site = sqlite3_column_int(stmt, 2);
				int Area_of_building = sqlite3_column_int(stmt, 3);
				int Number_of_floors = sqlite3_column_int(stmt, 4);

				const unsigned char* cStartDate = sqlite3_column_text(stmt, 5);
				string strStartDate(reinterpret_cast<const char*>(cStartDate));
				String^ StartDate = marshal_as<String^>(strStartDate);

				const unsigned char* cEndDate = sqlite3_column_text(stmt, 6);
				string strEndDate(reinterpret_cast<const char*>(cEndDate));
				String^ EndDate = marshal_as<String^>(strEndDate);

				int Cost = sqlite3_column_int(stmt, 7);
				int Imprest = sqlite3_column_int(stmt, 8);
				bool isImprest = sqlite3_column_int(stmt, 9);
				bool isPaid = sqlite3_column_int(stmt, 10);

				const unsigned char* cBulType = sqlite3_column_text(stmt, 11);
				string strBulType(reinterpret_cast<const char*>(cBulType));
				String^ BulType = marshal_as<String^>(strBulType);

				int Id_manager = sqlite3_column_int(stmt, 12);

				const unsigned char* cNameManager = sqlite3_column_text(stmt, 13);
				string strNameManager(reinterpret_cast<const char*>(cNameManager));
				String^ NameManager = marshal_as<String^>(strNameManager);

				int Id_client = sqlite3_column_int(stmt, 14);

				const unsigned char* cNameClient = sqlite3_column_text(stmt, 15);
				string strNameClient(reinterpret_cast<const char*>(cNameClient));
				String^ NameClient = marshal_as<String^>(strNameClient);

				Request += Environment::NewLine +
					"Id: " + Id + Environment::NewLine +
					"Адреса: " + Address + Environment::NewLine +
					"Площа ділянки: " + Area_of_site + " метрів квадратних" + Environment::NewLine +
					"Площа будівлі: " + Area_of_building + " метрів квадратних" + Environment::NewLine +
					"Кількість поверхів: " + Number_of_floors + Environment::NewLine +
					"Дата початку будівництва: " + StartDate + Environment::NewLine +
					"Дата закінчення будівництва: " + EndDate + Environment::NewLine +
					"Ціна контракту: " + Cost + "$" + Environment::NewLine +
					"Розмір авансу: " + Imprest + "$" + Environment::NewLine +
					"Чи внесено аванс: " + isImprest + Environment::NewLine +
					"Чи повністю оплачено: " + isPaid + Environment::NewLine +
					"Менеджер, який відповідає за цей контракт: " + Id_manager + "," + NameManager + Environment::NewLine +
					"Клієнт, якому належить цей контракт: " + Id_client + "," + NameClient + Environment::NewLine +
					Environment::NewLine;
			}

			if (Request == nullptr)
			{
				Request = "Контракти не знайдені";
				sqlite3_finalize(stmt);
				sqlite3_close(db);
				return Request;
			}

			Request = Info + Request;

			sqlite3_finalize(stmt);
			sqlite3_close(db);
			return Request;
		}

		String^ Request_all_materials(int Contract_id) {
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ selectSql = "SELECT Necessary_material.Id_material, Material.Name, Necessary_material.Quantity,  Necessary_material.isExist" +
				" FROM Contract AS C" +
				" JOIN Necessary_material ON Necessary_material.Id_contract = C.Id" +
				" JOIN Material ON Material.Id = Necessary_material.Id_material" +
				" WHERE C.Id == " + Contract_id + ";";

			string selectSqlStr = marshal_as<string>(selectSql);

			rc = sqlite3_prepare_v2(db, selectSqlStr.c_str(), -1, &stmt, nullptr);

			String^ Request = "Список необхідних матеріалів для контракту №" + Contract_id + Environment::NewLine + Environment::NewLine;

			if (rc != SQLITE_OK) {
				MessageBox::Show("SQLITE_ERROR", "Warning");
			}

			while (sqlite3_step(stmt) == SQLITE_ROW) {
				int Id = sqlite3_column_int(stmt, 0);

				const unsigned char* cName_mat = sqlite3_column_text(stmt, 1);
				string strName_mat(reinterpret_cast<const char*>(cName_mat));
				String^ Name_mat = marshal_as<String^>(strName_mat);

				int Quantity = sqlite3_column_int(stmt, 2);
				bool isExist = sqlite3_column_int(stmt, 3);

				Request += "Id матеріалу: " + Id + Environment::NewLine + 
					"Назва матеріалу: " + Name_mat + Environment::NewLine +
					"Необхідна кількість матеріалу: " + Quantity + Environment::NewLine +
					"Наявність: " + isExist + Environment::NewLine +
					Environment::NewLine;
			}

			sqlite3_finalize(stmt);
			sqlite3_close(db);
			return Request;
		}

		String^ Request_all_contracts_by_client(int Id_client) {
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ selectSql = "SELECT Contract.[Id], Contract.[Address], Contract.[Area of site], Contract.[Area of building], Contract.[Number of floors], Contract.[Start date], Contract.[End date], Contract.[Cost], Contract.[Imprest], Contract.[isImprest], Contract.[isPaid], Type_of_house.Name_of_type, Manager.Id AS Manager_id, Manager.Full_name AS Manager_name" +
				" FROM Contract" +
				" JOIN Type_of_house ON Contract.[Id building] = Type_of_house.Id" +
				" JOIN Manager ON Contract.[Id manager] = Manager.Id" +
				" JOIN Client ON Client.Id = Contract.[Id client]" +
				" WHERE Client.Id == " + Id_client + ";";

			string selectSqlStr = marshal_as<string>(selectSql);

			rc = sqlite3_prepare_v2(db, selectSqlStr.c_str(), -1, &stmt, nullptr);

			String^ Request;
			String^ Info = "Усі контракти клієнта №" + Id_client + Environment::NewLine;

			while (sqlite3_step(stmt) == SQLITE_ROW) {
				int Id = sqlite3_column_int(stmt, 0);

				const unsigned char* cAddress = sqlite3_column_text(stmt, 1);
				string strAddress(reinterpret_cast<const char*>(cAddress));
				String^ Address = marshal_as<String^>(strAddress);

				int Area_of_site = sqlite3_column_int(stmt, 2);
				int Area_of_building = sqlite3_column_int(stmt, 3);
				int Number_of_floors = sqlite3_column_int(stmt, 4);

				const unsigned char* cStartDate = sqlite3_column_text(stmt, 5);
				string strStartDate(reinterpret_cast<const char*>(cStartDate));
				String^ StartDate = marshal_as<String^>(strStartDate);

				const unsigned char* cEndDate = sqlite3_column_text(stmt, 6);
				string strEndDate(reinterpret_cast<const char*>(cEndDate));
				String^ EndDate = marshal_as<String^>(strEndDate);

				int Cost = sqlite3_column_int(stmt, 7);
				int Imprest = sqlite3_column_int(stmt, 8);
				bool isImprest = sqlite3_column_int(stmt, 9);
				bool isPaid = sqlite3_column_int(stmt, 10);

				const unsigned char* cBulType = sqlite3_column_text(stmt, 11);
				string strBulType(reinterpret_cast<const char*>(cBulType));
				String^ BulType = marshal_as<String^>(strBulType);

				int Id_manager = sqlite3_column_int(stmt, 12);

				const unsigned char* cNameManager = sqlite3_column_text(stmt, 13);
				string strNameManager(reinterpret_cast<const char*>(cNameManager));
				String^ NameManager = marshal_as<String^>(strNameManager);

				Request += Environment::NewLine +
					"Id: " + Id + Environment::NewLine +
					"Адреса: " + Address + Environment::NewLine +
					"Площа ділянки: " + Area_of_site + " метрів квадратних" + Environment::NewLine +
					"Площа будівлі: " + Area_of_building + " метрів квадратних" + Environment::NewLine +
					"Кількість поверхів: " + Number_of_floors + Environment::NewLine +
					"Дата початку будівництва: " + StartDate + Environment::NewLine +
					"Дата закінчення будівництва: " + EndDate + Environment::NewLine +
					"Ціна контракту: " + Cost + "$" + Environment::NewLine +
					"Розмір авансу: " + Imprest + "$" + Environment::NewLine +
					"Чи внесено аванс: " + isImprest + Environment::NewLine +
					"Чи повністю оплачено: " + isPaid + Environment::NewLine +
					"Менеджер, який відповідає за цей контракт: " + Id_manager + "," + NameManager + Environment::NewLine +
					Environment::NewLine;
			}

			if (Request == nullptr)
			{
				Request = "Контракти не знайдені";
				sqlite3_finalize(stmt);
				sqlite3_close(db);
				return Request;
			}

			Request = Info + Request;

			sqlite3_finalize(stmt);
			sqlite3_close(db);
			return Request;
		}

		String^ Request_most_exspensive_contract() {
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ selectSql = "SELECT C.[Id], C.[Address], C.[Area of site], C.[Area of building], C.[Number of floors], C.[Start date], C.[End date], C.[Cost], C.[Imprest], C.[isImprest], C.[isPaid], Type_of_house.Name_of_type, Manager.Id, Manager.Full_name, Client.Id, Client.Full_name" +
				" FROM Contract AS C" +
				" JOIN Type_of_house ON C.[Id building] = Type_of_house.Id" +
				" JOIN Manager ON C.[Id manager] = Manager.Id" +
				" JOIN Client ON C.[Id client] = Client.Id" +
				" WHERE C.[Cost] >= (SELECT MAX(Contract.[Cost]) FROM Contract);";

			string selectSqlStr = marshal_as<string>(selectSql);

			rc = sqlite3_prepare_v2(db, selectSqlStr.c_str(), -1, &stmt, nullptr);

			String^ Request = "Найдорожчі контракти:" + Environment::NewLine;

			while (sqlite3_step(stmt) == SQLITE_ROW) {
				int Id = sqlite3_column_int(stmt, 0);

				const unsigned char* cAddress = sqlite3_column_text(stmt, 1);
				string strAddress(reinterpret_cast<const char*>(cAddress));
				String^ Address = marshal_as<String^>(strAddress);

				int Area_of_site = sqlite3_column_int(stmt, 2);
				int Area_of_building = sqlite3_column_int(stmt, 3);
				int Number_of_floors = sqlite3_column_int(stmt, 4);

				const unsigned char* cStartDate = sqlite3_column_text(stmt, 5);
				string strStartDate(reinterpret_cast<const char*>(cStartDate));
				String^ StartDate = marshal_as<String^>(strStartDate);

				const unsigned char* cEndDate = sqlite3_column_text(stmt, 6);
				string strEndDate(reinterpret_cast<const char*>(cEndDate));
				String^ EndDate = marshal_as<String^>(strEndDate);

				int Cost = sqlite3_column_int(stmt, 7);
				int Imprest = sqlite3_column_int(stmt, 8);
				bool isImprest = sqlite3_column_int(stmt, 9);
				bool isPaid = sqlite3_column_int(stmt, 10);

				const unsigned char* cBulType = sqlite3_column_text(stmt, 11);
				string strBulType(reinterpret_cast<const char*>(cBulType));
				String^ BulType = marshal_as<String^>(strBulType);

				int Id_manager = sqlite3_column_int(stmt, 12);

				const unsigned char* cNameManager = sqlite3_column_text(stmt, 13);
				string strNameManager(reinterpret_cast<const char*>(cNameManager));
				String^ NameManager = marshal_as<String^>(strNameManager);

				int Id_client = sqlite3_column_int(stmt, 14);

				const unsigned char* cNameClient = sqlite3_column_text(stmt, 15);
				string strNameClient(reinterpret_cast<const char*>(cNameClient));
				String^ NameClient = marshal_as<String^>(strNameClient);

				Request += Environment::NewLine +
					"Id: " + Id + Environment::NewLine +
					"Адреса: " + Address + Environment::NewLine +
					"Площа ділянки: " + Area_of_site + " метрів квадратних" + Environment::NewLine +
					"Площа будівлі: " + Area_of_building + " метрів квадратних" + Environment::NewLine +
					"Кількість поверхів: " + Number_of_floors + Environment::NewLine +
					"Дата початку будівництва: " + StartDate + Environment::NewLine +
					"Дата закінчення будівництва: " + EndDate + Environment::NewLine +
					"Ціна контракту: " + Cost + "$" + Environment::NewLine +
					"Розмір авансу: " + Imprest + "$" + Environment::NewLine +
					"Чи внесено аванс: " + isImprest + Environment::NewLine +
					"Чи повністю оплачено: " + isPaid + Environment::NewLine +
					"Менеджер, який відповідає за цей контракт: " + Id_manager + "," + NameManager + Environment::NewLine +
					"Клієнт, якому належить цей контракт: " + Id_client + "," + NameClient + Environment::NewLine +
					Environment::NewLine;
			}

			sqlite3_finalize(stmt);
			sqlite3_close(db);
			return Request;
		}

	};


	public ref class Building_type_ {
	protected:
		String^ Name;
		String^ Image;

	public:
		int add_builType_db(String^ new_Name, String^ new_Image) {
			Name = new_Name;
			Image = new_Image;

			ifstream file("images\\" + marshal_as<string>(new_Image));
			if (!file) {
				MessageBox::Show("Картинка не знайдена.", "Увага");
				return 0;
			}

			System::Drawing::Bitmap^ bitmap = gcnew System::Drawing::Bitmap("images\\" + Image);
			System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream();
			bitmap->Save(ms, System::Drawing::Imaging::ImageFormat::Jpeg);
			cli::array<System::Byte>^ imageBytes = ms->ToArray();

			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ sql = "SELECT * FROM Type_of_house WHERE Name_of_type='" + Name + "';";
			string sql_c = marshal_as<string>(sql);

			rc = sqlite3_prepare_v2(db, sql_c.c_str(), -1, &stmt, NULL);

			//Перевірка на те, що такий тип будинку вже є
			if (sqlite3_step(stmt) == SQLITE_ROW) {
				MessageBox::Show("Такий тип будинку вже є. Спробуйте ще раз.", "Увага");
				sqlite3_finalize(stmt);
				sqlite3_close(db);
				return 0;

			}

			String^ insertSql_BuilType = "INSERT INTO Type_of_house (Name_of_type, Image) VALUES (?, ?)";
			string insertSql_BuilType_str = marshal_as<string>(insertSql_BuilType);

			rc = sqlite3_prepare_v2(db, insertSql_BuilType_str.c_str(), -1, &stmt, NULL);
			if (rc != SQLITE_OK) {
				MessageBox::Show("Failed to prepare statement", "Error");
				sqlite3_close(db);
				return 0;
			}
			string nameStr = marshal_as<string>(new_Name);
			sqlite3_bind_text(stmt, 1, nameStr.c_str(), -1, SQLITE_STATIC);
			pin_ptr<unsigned char> pinnedBytes = &imageBytes[0];
			sqlite3_bind_blob(stmt, 2, pinnedBytes, imageBytes->Length, SQLITE_STATIC);

			rc = sqlite3_step(stmt);
			if (rc != SQLITE_DONE) {
				MessageBox::Show("Failed to insert data", "Error");
			}
			else {
				MessageBox::Show("Дані успішно збережено.", "Увага");
			}

			int id = sqlite3_last_insert_rowid(db);

			sqlite3_finalize(stmt);
			sqlite3_close(db);

			return id;
		}

		cli::array<System::Byte>^ get_Image_db(int id)
		{
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ selectSql = "SELECT hex(Image) FROM Type_of_house WHERE Id = " + id + ";";
			string selectSqlStr = msclr::interop::marshal_as<std::string>(selectSql);

			cli::array<System::Byte>^ imageBytes = nullptr;

			rc = sqlite3_prepare_v2(db, selectSqlStr.c_str(), -1, &stmt, nullptr);
			if (rc == SQLITE_OK) {
				rc = sqlite3_step(stmt);
				if (rc == SQLITE_ROW) {
					const unsigned char* hexData = sqlite3_column_text(stmt, 0);
					if (hexData != nullptr) {
						std::string hexString(reinterpret_cast<const char*>(hexData));
						int hexStringLength = hexString.length();
						int byteCount = hexStringLength / 2;
						imageBytes = gcnew cli::array<System::Byte>(byteCount);
						for (int i = 0; i < byteCount; i++) {
							std::string byteString = hexString.substr(i * 2, 2);
							int byteValue = std::stoi(byteString, nullptr, 16);
							imageBytes[i] = static_cast<System::Byte>(byteValue);
						}
					}
				}
			}

			sqlite3_finalize(stmt);
			sqlite3_close(db);
			return imageBytes;
		}

		void get_Name_db(int id, String^& text) {
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ selectNameSql = "SELECT Name_of_type FROM Type_of_house WHERE Id = " + id + ";";
			string selectNameSqlStr = marshal_as<string>(selectNameSql);

			rc = sqlite3_prepare_v2(db, selectNameSqlStr.c_str(), -1, &stmt, NULL);
			//Перевіряємо, чи є помилка у запросі
			if (rc == SQLITE_ERROR) {
				MessageBox::Show("SQLITE_ERROR", "Warning");
				return;
			}

			if (sqlite3_step(stmt) == SQLITE_ROW) {
				const char* charData = (const char*)sqlite3_column_text(stmt, 0);
				text = marshal_as<String^>(charData);
			}

			sqlite3_finalize(stmt);
			sqlite3_close(db);
		}

		int check_count(int index) {
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			int count = 0;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ selectCountSql = "SELECT COUNT(*) FROM Type_of_house;";
			string selectCountSqlStr = marshal_as<string>(selectCountSql);

			rc = sqlite3_prepare_v2(db, selectCountSqlStr.c_str(), -1, &stmt, nullptr);
			if (rc == SQLITE_OK) {
				rc = sqlite3_step(stmt);
				if (rc == SQLITE_ROW) {
					count = sqlite3_column_int(stmt, 0);
				}
			}

			if (index > count)
			{
				index = 1;
			}
			else if (index < 1) {
				index = count;
			}

			// Закрываем выражение
			sqlite3_finalize(stmt);
			sqlite3_close(db);

			return index;
		}

		String^ choose_builType(int index) {
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			String^ Name;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ selectNameSql = "SELECT Name_of_type FROM Type_of_house WHERE Id = " + index + ";";
			string selectNameSqlStr = marshal_as<string>(selectNameSql);

			rc = sqlite3_prepare_v2(db, selectNameSqlStr.c_str(), -1, &stmt, NULL);
			//Перевіряємо, чи є помилка у запросі
			if (rc == SQLITE_ERROR) {
				MessageBox::Show("SQLITE_ERROR", "Warning");
			}

			if (sqlite3_step(stmt) == SQLITE_ROW) {
				const char* charData = (const char*)sqlite3_column_text(stmt, 0);
				Name = marshal_as<String^>(charData);
			}

			sqlite3_finalize(stmt);
			sqlite3_close(db);

			return Name;
		}
	};

	public ref class Provider_ {
	protected:
		String^ Name;
		String^ Phone;

	public:
		int add_provider_db(String^ new_Name, String^ new_Phone) {
			Name = new_Name;
			Phone = new_Phone;

			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ insertSqlProvider = "INSERT INTO Provider (Name, Phone) VALUES ('" + Name + "', '" + Phone + "'); ";
			string insertSqlProvider_c = marshal_as<string>(insertSqlProvider);

			rc = sqlite3_exec(db, insertSqlProvider_c.c_str(), NULL, NULL, NULL);

			//Перевірка на те, що дані успішно вставились
			if (rc != SQLITE_OK) {
				MessageBox::Show("Failed to insert data into Provider", "Warning");
			}
			else {
				MessageBox::Show("Дані постачальника успішно збережено.", "Увага");
			}

			int id = sqlite3_last_insert_rowid(db);

			sqlite3_close(db);

			return id;
		}

		void add_material_to_provider_db(int id_provider, int id_material, String^ name_provider, String^ name_material) {
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ insertSqlMaterialProvider = "INSERT INTO Material_Provider(Id_provider, Id_material, Name_provider, Name_material)" +
				"VALUES(" + id_provider + ", " + id_material + ", '" + name_provider + "', '" + name_material + "'); ";
			string insertSqlMaterialProvider_c = marshal_as<string>(insertSqlMaterialProvider);

			rc = sqlite3_exec(db, insertSqlMaterialProvider_c.c_str(), NULL, NULL, NULL);

			//Перевірка на те, що дані успішно вставились
			if (rc != SQLITE_OK) {
				MessageBox::Show("Failed to insert data into MaterialProvider", "Warning");
				return;
			}
			
			sqlite3_close(db);
		}

		cli::array<String^>^ get_provider_by_material(int Material_id) {
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ find_provider = "SELECT Id_provider, Name_provider FROM Material_Provider WHERE Id_material = " + Material_id + ";";
			string find_provider_str = marshal_as<string>(find_provider);

			rc = sqlite3_prepare_v2(db, find_provider_str.c_str(), -1, &stmt, NULL);
			//Перевіряємо, чи є помилка у запросі
			if (rc == SQLITE_ERROR) {
				MessageBox::Show("SQLITE_ERROR", "Warning");
			}

			int provider_quan = 0;

			while (sqlite3_step(stmt) == SQLITE_ROW) {
				provider_quan++;
			}

			cli::array<String^>^ rows = gcnew cli::array<String^>(provider_quan);
			int i = 0;
			while (sqlite3_step(stmt) == SQLITE_ROW) {
				const unsigned char* id = sqlite3_column_text(stmt, 0);
				const unsigned char* name = sqlite3_column_text(stmt, 1);

				string Text_id = reinterpret_cast<const char*>(id);
				string Text_name = reinterpret_cast<const char*>(name);

				String^ row = marshal_as<String^>(Text_id) + ", " + marshal_as<String^>(Text_name);
				rows[i] = row;
				i++;
			}

			sqlite3_finalize(stmt);
			sqlite3_close(db);

			return rows;
		}

		String^ Request_all_payments(int Id_provider, DateTime Start_date, DateTime End_date) {
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ formated_End_date = End_date.ToString("yyyy-MM-dd");
			String^ formated_Start_date = Start_date.ToString("yyyy-MM-dd");;

			String^ selectSql = "SELECT *" +
				" FROM Payment_provider" +
				" WHERE Payment_provider.Id_provider == " + Id_provider + " AND date(substr(Payment_provider.[Date], 7, 4) || '-' || substr(Payment_provider.[Date], 4, 2) || '-' || substr(Payment_provider.[Date], 1, 2))" +
				" BETWEEN date('" + formated_Start_date + "')  AND date('" + formated_End_date + "')";

			string selectSqlStr = marshal_as<string>(selectSql);

			rc = sqlite3_prepare_v2(db, selectSqlStr.c_str(), -1, &stmt, nullptr);

			String^ Request;

			if (rc != SQLITE_OK) {
				MessageBox::Show("SQLITE_ERROR", "Warning");
			}

			while (sqlite3_step(stmt) == SQLITE_ROW) {
				int Id = sqlite3_column_int(stmt, 0);

				const unsigned char* cDate = sqlite3_column_text(stmt, 1);
				string strDate(reinterpret_cast<const char*>(cDate));
				String^ Date = marshal_as<String^>(strDate);

				int Amount = sqlite3_column_int(stmt, 2);

				Request += "Id: " + Id + Environment::NewLine +
					"Дата: " + Date + Environment::NewLine + 
					"Сума: " + Amount + "$" + Environment::NewLine;
			}

			if (Request == nullptr)
			{
				Request += "Виплати не знайдено";
				sqlite3_finalize(stmt);
				sqlite3_close(db);
				return Request;
			}

			String^ info = "Усі виплати постачальника №" + Id_provider + " за обраний період: " + Environment::NewLine;
			Request = info + Request;

			sqlite3_finalize(stmt);
			sqlite3_close(db);
			return Request;
		}

	};

	public ref class Carrier_ {
	protected:
		String^ Name;
		String^ Phone;
	public:
		int add_carrier_db(String^ new_Name, String^ new_Phone) {
			Name = new_Name;
			Phone = new_Phone;

			sqlite3* db;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ insertSqlCarrier = "INSERT INTO Carrier (Name, Phone) VALUES ('" + Name + "', '" + Phone + "'); ";
			string insertSqlCarrier_c = marshal_as<string>(insertSqlCarrier);

			rc = sqlite3_exec(db, insertSqlCarrier_c.c_str(), NULL, NULL, NULL);

			//Перевірка на те, що дані успішно вставились
			if (rc != SQLITE_OK) {
				MessageBox::Show("Failed to insert data into Carrier", "Warning");
			}
			else {
				MessageBox::Show("Дані перевізника успішно збережено.", "Увага");
			}

			int id = sqlite3_last_insert_rowid(db);

			sqlite3_close(db);

			return id;
		}

		void add_material_to_carrier_db(int id_carrier, int id_material, String^ name_carrier, String^ name_material) {
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ insertSqlMaterialProvider = "INSERT INTO Material_Carrier(Id_carrier, Id_material, Name_carrier, Name_material)" +
				"VALUES(" + id_carrier + ", " + id_material + ", '" + name_carrier + "', '" + name_material + "'); ";
			string insertSqlMaterialProvider_c = marshal_as<string>(insertSqlMaterialProvider);

			rc = sqlite3_exec(db, insertSqlMaterialProvider_c.c_str(), NULL, NULL, NULL);

			//Перевірка на те, що дані успішно вставились
			if (rc != SQLITE_OK) {
				MessageBox::Show("Failed to insert data into MaterialCarrier", "Warning");
				return;
			}

			sqlite3_close(db);
		}

		cli::array<String^>^ get_carrier_by_material(int Material_id) {
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ find_carrier = "SELECT Id_carrier, Name_carrier FROM Material_Carrier WHERE Id_material = " + Material_id + ";";
			string find_carrier_str = marshal_as<string>(find_carrier);

			rc = sqlite3_prepare_v2(db, find_carrier_str.c_str(), -1, &stmt, NULL);
			//Перевіряємо, чи є помилка у запросі
			if (rc == SQLITE_ERROR) {
				MessageBox::Show("SQLITE_ERROR", "Warning");
			}

			int carrier_quan = 0;

			while (sqlite3_step(stmt) == SQLITE_ROW) {
				carrier_quan++;
			}

			cli::array<String^>^ rows = gcnew cli::array<String^>(carrier_quan);
			int i = 0;
			while (sqlite3_step(stmt) == SQLITE_ROW) {
				const unsigned char* id = sqlite3_column_text(stmt, 0);
				const unsigned char* name = sqlite3_column_text(stmt, 1);

				string Text_id = reinterpret_cast<const char*>(id);
				string Text_name = reinterpret_cast<const char*>(name);

				String^ row = marshal_as<String^>(Text_id) + ", " + marshal_as<String^>(Text_name);
				rows[i] = row;
				i++;
			}

			sqlite3_finalize(stmt);
			sqlite3_close(db);

			return rows;
		}
	};

	public ref class Material_ {
	protected:
		String^ Name;
		int Price_per_piece;

	public:
		void add_material_db(String^ new_Name, int new_Price_per_piece) {
			Name = new_Name;
			Price_per_piece = new_Price_per_piece;

			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ sql = "SELECT Name FROM Material WHERE Name='" + new_Name + "';";
			string sql_c = marshal_as<string>(sql);

			rc = sqlite3_prepare_v2(db, sql_c.c_str(), -1, &stmt, NULL);

			//Перевірка на помилку у запросі
			if (rc == SQLITE_ERROR) {
				MessageBox::Show("SQLITE_ERROR", "Warning");
				sqlite3_finalize(stmt);
				sqlite3_close(db);
				return;
			}

			//Перевірка на те, що такий матеріал вже є
			if (sqlite3_step(stmt) == SQLITE_ROW) {
				MessageBox::Show("Такий матеріал вже є. Спробуйте ще раз.", "Увага");
				sqlite3_finalize(stmt);
				sqlite3_close(db);
				return;
			}

			String^ insertSqlMaterial = "INSERT INTO Material (Name, Price_per_piece) VALUES ('" + Name + "', " + Price_per_piece + "); ";
			string insertSqlMaterial_c = marshal_as<string>(insertSqlMaterial);

			rc = sqlite3_exec(db, insertSqlMaterial_c.c_str(), NULL, NULL, NULL);

			//Перевірка на те, що дані успішно вставились
			if (rc != SQLITE_OK) {
				MessageBox::Show("Failed to insert data into Material", "Warning");
				return;
			}
			else {
				MessageBox::Show("Дані матеріалу успішно збережено.", "Увага");
			}

			sqlite3_finalize(stmt);
			sqlite3_close(db);
		}

		String^ get_material_name_db(int Material_id) {
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ find_mat_name = "SELECT Name FROM Material WHERE Id = " + Material_id + ";";
			string find_mat_name_str = marshal_as<string>(find_mat_name);

			rc = sqlite3_prepare_v2(db, find_mat_name_str.c_str(), -1, &stmt, NULL);
			//Перевіряємо, чи є помилка у запросі
			if (rc == SQLITE_ERROR) {
				MessageBox::Show("SQLITE_ERROR", "Warning");
			}

			String^ return_text;

			if (sqlite3_step(stmt) == SQLITE_ROW) {
				const unsigned char* name = sqlite3_column_text(stmt, 0);
				string Text = reinterpret_cast<const char*>(name);
				return_text = marshal_as<String^>(Text);
			}

			sqlite3_finalize(stmt);
			sqlite3_close(db);

			return return_text;
		}

		int get_price_per_piece(int Material_id) {
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ find_mat_price = "SELECT Price_per_piece FROM Material WHERE Id = " + Material_id + ";";
			string find_mat_price_str = marshal_as<string>(find_mat_price);

			rc = sqlite3_prepare_v2(db, find_mat_price_str.c_str(), -1, &stmt, NULL);
			//Перевіряємо, чи є помилка у запросі
			if (rc == SQLITE_ERROR) {
				MessageBox::Show("SQLITE_ERROR", "Warning");
			}

			int price;

			if (sqlite3_step(stmt) == SQLITE_ROW) {
				price = sqlite3_column_int(stmt, 0);
			}
			
			sqlite3_finalize(stmt);
			sqlite3_close(db);

			return price;
		}
	};

	public ref class Necessary_material_ {
	protected:
		int Id_contract;
		int Id_material;
		int Quantity;
		bool isExist;

	public:
		void add_necessary_material_db(int new_Id_contract, int new_Id_material, int new_Quantity, int rc, sqlite3* db) {
			Id_contract = new_Id_contract;
			Id_material = new_Id_material;
			Quantity = new_Quantity;

			String^ insertSqlNecessary_material = "INSERT INTO Necessary_material (Id_contract, Id_material, Quantity, isExist) VALUES (" + Id_contract + ", " + Id_material + ", " + Quantity + ", " + 0 + "); ";
			string insertSqlNecessary_material_c = marshal_as<string>(insertSqlNecessary_material);

			rc = sqlite3_exec(db, insertSqlNecessary_material_c.c_str(), NULL, NULL, NULL);

			//Перевірка на те, що дані успішно вставились
			if (rc != SQLITE_OK) {
				MessageBox::Show("Failed to insert data into Necessary_material", "Warning");
				return;
			}
			//sqlite3_close(db);
		}

		cli::array<int>^ get_material_ids_db(int Contract_id) {
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ find_mat_Ids = "SELECT Id_material FROM Necessary_material WHERE Id_contract = " + Contract_id + ";";
			string find_mat_Ids_str = marshal_as<string>(find_mat_Ids);

			rc = sqlite3_prepare_v2(db, find_mat_Ids_str.c_str(), -1, &stmt, NULL);
			//Перевіряємо, чи є помилка у запросі
			if (rc == SQLITE_ERROR) {
				MessageBox::Show("SQLITE_ERROR", "Warning");
			}

			int mat_ids = 0;

			while (sqlite3_step(stmt) == SQLITE_ROW) {
				mat_ids++;
			}

			cli::array<int>^ Materials_id = gcnew cli::array<int>(mat_ids);
			int i = 0;
			while (sqlite3_step(stmt) == SQLITE_ROW) {
				Materials_id[i] = sqlite3_column_int(stmt, 0);
				i++;
			}

			sqlite3_finalize(stmt);
			sqlite3_close(db);

			return Materials_id;
		}

		void set_isExist_db(int new_Id_contract, int new_Id_material) {
			Id_contract = new_Id_contract;
			Id_material = new_Id_material;

			sqlite3* db;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ updateSqlNecessary_material = "UPDATE Necessary_material SET isExist = 1 WHERE Id_contract = " + Id_contract + " AND Id_material = " + Id_material;
			string updateSqlNecessary_material_c = marshal_as<string>(updateSqlNecessary_material);

			// Выполняем SQL запрос
			rc = sqlite3_exec(db, updateSqlNecessary_material_c.c_str(), NULL, NULL, NULL);

			//Перевірка на те, що дані успішно вставились
			if (rc != SQLITE_OK) {
				MessageBox::Show("Failed to update data in the Necessary_material", "Warning");
				return;
			}

			sqlite3_close(db);
		}

		int get_quantity(int Contract_id, int Material_id) {
			Id_contract = Contract_id;
			Id_material = Material_id;

			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ find_quantity = "SELECT Quantity FROM Necessary_material WHERE Id_contract = " + Id_contract + " AND Id_material = " + Id_material + ";";
			string find_quantity_str = marshal_as<string>(find_quantity);

			rc = sqlite3_prepare_v2(db, find_quantity_str.c_str(), -1, &stmt, NULL);
			//Перевіряємо, чи є помилка у запросі
			if (rc == SQLITE_ERROR) {
				MessageBox::Show("SQLITE_ERROR", "Warning");
			}

			int quantity;

			if (sqlite3_step(stmt) == SQLITE_ROW) {
				quantity = sqlite3_column_int(stmt, 0);
			}

			sqlite3_finalize(stmt);
			sqlite3_close(db);

			return quantity;
		}
	};

	public ref class BuildingType_Material_ {
	protected:
		int Id_building;
		int Id_material;

	public:
		void add_material_to_building_db(int new_Id_building, int new_Id_material) {
			Id_building = new_Id_building;
			Id_material = new_Id_material;

			sqlite3* db;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ insertSqlMaterial = "INSERT INTO Material_TypeOfHouse (Id_typeOfHouse, Id_material) VALUES (" + Id_building + ", " + Id_material + "); ";
			string insertSqlMaterial_c = marshal_as<string>(insertSqlMaterial);

			rc = sqlite3_exec(db, insertSqlMaterial_c.c_str(), NULL, NULL, NULL);

			//Перевірка на те, що дані успішно вставились
			if (rc != SQLITE_OK) {
				MessageBox::Show("Failed to insert data into Material_TypeOfHouse", "Warning");
				return;
			}
			sqlite3_close(db);
		}

		void get_and_add_NecesMat_Build_db(int Building_id, int Contract_id, int mat_quan) {
			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;
			Necessary_material_^ new_necessary_material = gcnew Necessary_material_();
			rc = sqlite3_open("db\\Building_database.db", &db);

			int mats_quan = 0;

			//Отримуємо айді матеріалу для типу будівлі
			String^ find_mat_From_build_Id = "SELECT * FROM Material_TypeOfHouse WHERE Id_typeOfHouse = " + Building_id + ";";
			string find_mat_From_build_Id_str = marshal_as<string>(find_mat_From_build_Id);

			rc = sqlite3_prepare_v2(db, find_mat_From_build_Id_str.c_str(), -1, &stmt, NULL);
			//Перевіряємо, чи є помилка у запросі
			if (rc == SQLITE_ERROR) {
				MessageBox::Show("SQLITE_ERROR", "Warning");
			}

			while (sqlite3_step(stmt) == SQLITE_ROW) {
				mats_quan++;
			}

			while (sqlite3_step(stmt) == SQLITE_ROW) {
				new_necessary_material->add_necessary_material_db(Contract_id, sqlite3_column_int(stmt, 1), mat_quan / mats_quan, rc, db);
				
			}

			sqlite3_finalize(stmt);
			sqlite3_close(db);
		}
	};

	public ref class Supply_ {
	protected:
		DateTime Date;
		int id_head_of_support;

	public:
		void add_supply_db(DateTime new_Date, String^ head_of_support_login, int& Supply_id) {
			Date = new_Date;

			sqlite3* db;
			sqlite3_stmt* stmt;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			//Знаходимо айді аккаунту, який зареєстрував поставку
			String^ find_account_Id = "SELECT Id FROM Account WHERE Login = '" + head_of_support_login + "';";
			string find_account_Id_str = marshal_as<string>(find_account_Id);

			rc = sqlite3_prepare_v2(db, find_account_Id_str.c_str(), -1, &stmt, NULL);
			//Перевіряємо, чи є помилка у запросі
			if (rc == SQLITE_ERROR) {
				MessageBox::Show("SQLITE_ERROR", "Warning");
			}

			int account_support_id;

			if (sqlite3_step(stmt) == SQLITE_ROW) {
				account_support_id = sqlite3_column_int(stmt, 0);
				sqlite3_finalize(stmt);
			}

			//Знаходимо айді менеджера, який зареєстрував контракт
			String^ find_supportID = "SELECT Id FROM Head_of_Support WHERE [Id account] = " + account_support_id + "; ";
			string find_supportID_str = marshal_as<string>(find_supportID);

			rc = sqlite3_prepare_v2(db, find_supportID_str.c_str(), -1, &stmt, NULL);
			if (rc == SQLITE_ERROR) {
				MessageBox::Show("SQLITE_ERROR", "Warning");
			}

			if (sqlite3_step(stmt) == SQLITE_ROW) {
				id_head_of_support = sqlite3_column_int(stmt, 0);
				sqlite3_finalize(stmt);
			}

			String^ insertSqlSupply = "INSERT INTO Supply ([Date], Id_of_head_support) VALUES ('" + Date + "', " + id_head_of_support + "); ";
			string insertSqlSupply_c = marshal_as<string>(insertSqlSupply);

			rc = sqlite3_exec(db, insertSqlSupply_c.c_str(), NULL, NULL, NULL);

			//Перевірка на те, що дані успішно вставились
			if (rc != SQLITE_OK) {
				MessageBox::Show("Failed to insert data into Supply", "Warning");
				return;
			}
			else {
				MessageBox::Show("Дані поставки успішно збережені.", "Увага");
			}

			Supply_id = sqlite3_last_insert_rowid(db);

			sqlite3_close(db);
		}
	};

	public ref class Mat_Sup_Prov_Car {
	protected:
		int Id_material;
		int Id_supply;
		int Id_provider;
		int Id_carrier;

	public:
		void add_Mat_Sup_Prov_Car_db(int new_Id_material, int new_Id_supply, int new_Id_provider, int new_Id_carrier) {
			Id_material = new_Id_material;
			Id_supply = new_Id_supply;
			Id_provider = new_Id_provider;
			Id_carrier = new_Id_carrier;

			sqlite3* db;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);


			String^ insertSqlMat_Sup_Prov_Car = "INSERT INTO Material_Supply_Provider_Carrier (Id_material, Id_supply, Id_provider, Id_carrier) VALUES (" + Id_material + ", " + Id_supply + ", " + Id_provider + ", " + Id_carrier + "); ";
			string insertSqlMat_Sup_Prov_Car_c = marshal_as<string>(insertSqlMat_Sup_Prov_Car);

			rc = sqlite3_exec(db, insertSqlMat_Sup_Prov_Car_c.c_str(), NULL, NULL, NULL);

			//Перевірка на те, що дані успішно вставились
			if (rc != SQLITE_OK) {
				MessageBox::Show("Failed to insert data into Mat_Sup_Prov_Car", "Warning");
				return;
			}
			sqlite3_close(db);
		}
	};

	public ref class Payment_provider {
	protected:
		DateTime Date;
		int Payment;
		int Id_provider;

	public:
		void add_Payment_provider_db(DateTime new_Date, int new_Payment, int new_Id_provider) {
			Date = new_Date;
			Payment = new_Payment;
			Id_provider = new_Id_provider;

			sqlite3* db;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ insertSqlPayment_provider = "INSERT INTO Payment_provider ([Date], Payment, Id_provider) VALUES ('" + Date + "', " + Payment + ", " + Id_provider + "); ";
			string insertSqlPayment_provider_c = marshal_as<string>(insertSqlPayment_provider);

			rc = sqlite3_exec(db, insertSqlPayment_provider_c.c_str(), NULL, NULL, NULL);

			//Перевірка на те, що дані успішно вставились
			if (rc != SQLITE_OK) {
				MessageBox::Show("Failed to insert data into Payment_provider", "Warning");
				return;
			}

			sqlite3_close(db);
		}
	};

	public ref class Payment_carrier {
	protected:
		DateTime Date;
		int Payment;
		int Id_carrier;

	public:
		void add_Payment_carrier_db(DateTime new_Date, int new_Payment, int new_Id_carrier) {
			Date = new_Date;
			Payment = new_Payment;
			Id_carrier = new_Id_carrier;

			sqlite3* db;
			int rc;

			rc = sqlite3_open("db\\Building_database.db", &db);

			String^ insertSqlPayment_carrier = "INSERT INTO Payment_carrier ([Date], Payment, Id_carrier) VALUES ('" + Date + "', " + Payment + ", " + Id_carrier + "); ";
			string insertSqlPayment_carrier_c = marshal_as<string>(insertSqlPayment_carrier);

			rc = sqlite3_exec(db, insertSqlPayment_carrier_c.c_str(), NULL, NULL, NULL);

			//Перевірка на те, що дані успішно вставились
			if (rc != SQLITE_OK) {
				MessageBox::Show("Failed to insert data into Payment_carrier", "Warning");
				return;
			}

			sqlite3_close(db);
		}
	};
}