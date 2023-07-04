#include <iostream>
#include "EmployerWindow.h"
#include "MainWindow.h"
#include "Vacancies.h"

using namespace std;
using namespace WorkSearch;
 

[STAThreadAttribute()]
int main()
{
    // Running the main window
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    MainWindow form;
    Application::Run(% form);

    // Collecting the database
    string filePath = "";
    //vacancies.readFromJson(filePath);

    char c;
    cin >> c;
    return 0;
}


