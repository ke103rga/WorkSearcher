#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/filewritestream.h"
#include <fstream>
#include "rapidjson/writer.h"
#include "EmployerWindow.h"
#include "MainWindow.h"

using namespace std;
using namespace rapidjson;
using namespace WorkSearch;


int main()
{
    /*Vacancies vacancies = Vacancies();
    string filePath = "";
    vacancies.readFromJson(filePath);*/

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    MainWindow form;
    Application::Run(% form);
    
    char c;
    cin >> c;
    return 0;
}
