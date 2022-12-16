#include "pch.h"

using namespace System;
using namespace System::Text;
using namespace System::IO;

int main(array<System::String ^> ^args)
{
	String ^dirName = "E:\\";
	if (Directory::Exists(dirName))
	{
		Console::WriteLine("SubDirectory:");
		cli::array<String^, 1>^ dirs = Directory::GetDirectories(dirName);
		
		for (size_t i = 0; i < dirs->Length; i++)
		{
			Console::WriteLine(dirs[i]);
		}
	
	Console::WriteLine("Input name of directory");
	String^ fileDirectory = Console::ReadLine();
	cli::array<String^, 1>^ files = Directory::GetFiles(dirName + "\\" + fileDirectory + "\\");
	for (size_t i = 0; i < files->Length; i++)
	{
		Console::WriteLine(files[i]);
	}
	}
	return 0;
}
