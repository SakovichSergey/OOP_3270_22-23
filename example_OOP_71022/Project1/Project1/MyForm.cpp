#include "MyForm.h"
#include <Windows.h>

using namespace Project1;


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Form1);
	return 0;
}