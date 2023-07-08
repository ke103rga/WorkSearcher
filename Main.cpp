#include <iostream>
#include "MainWindow.h"
#include "Vacancies.h"

using namespace std;
using namespace WorkSearch;
using namespace Newtonsoft::Json;
 

[STAThreadAttribute()]
int main()
{   
    vacancies.readFromTXT(DB_FILE_PATH);

    // Running the main window
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    MainWindow form;
    Application::Run(% form);

    char c;
    cin >> c;
    return 0;
}


