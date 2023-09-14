#include <iostream>
#include <Windows.h>
//#include <string>

int main()
{
    puts("Cargando...");
    HINSTANCE myDll = LoadLibrary(L"6_DLL.dll");
    if (myDll != NULL)
    {
        puts("Damn");
        typedef const char* (*GetCodeFunc)();
        GetCodeFunc getCodename = reinterpret_cast<GetCodeFunc>(GetProcAddress(myDll, "GetCodename"));

        if (getCodename != NULL)
        {
            const char* msj = getCodename();
            std::cout << "desde la DLL: " << msj << "\n";
        }
        else
        {
            puts("Sssssssssssssssucks");
        }

        typedef double (*sumarFunc)(double a, double b);
        sumarFunc sumar = reinterpret_cast<sumarFunc>(GetProcAddress(myDll, "sumar"));
        if (sumar != NULL)
        {
            //double num = sumar(4, 7);
            std::cout << "desde la DLL: " << sumar(4, 7) << "\n";
        }
        else
        {
            puts("Sssssssssssssssucks");
        }

        typedef std::string (*stringFunc)(const std::string& a, const std::string& b);
        stringFunc strings = reinterpret_cast<stringFunc>(GetProcAddress(myDll, "ojo"));
        if (strings != NULL)
        {
            std::string s = "Holas ";
            std::string f = "*chiflido naco* \n";
            std::cout << "desde la DLL: " << strings(s, f) << "\n";
        }
        else
        {
            puts("Sssssssssssssssucks");
        }

        FreeLibrary(myDll);
    }
    else
    {
        puts("No sirvió xd");
    }

    puts("XD");
    return 0;
}
