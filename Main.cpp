#include <iostream>
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/filewritestream.h"
#include <fstream>
#include "rapidjson/writer.h"

#include "EmployerWindow.h"
#include "MainWindow.h"
#include "Vacancies.h"

using namespace std;
using namespace rapidjson;
using namespace WorkSearch;
 

int main()
{
    // Running the main window
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    MainWindow form;
    Application::Run(% form);

    // Collecting the databes
    string filePath = "";
    vacancies.readFromJson(filePath);

    char c;
    cin >> c;
    return 0;
}


