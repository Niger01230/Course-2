#include "Registration.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace Project1;

[STAThreadAttribute]

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project1::Registration form;
	Application::Run(% form);
	return 0;
}