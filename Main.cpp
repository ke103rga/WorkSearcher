#include <iostream>
#include "MainWindow.h"
#include "Vacancies.h"

using namespace std;
using namespace WorkSearch;
 

[STAThreadAttribute()]
int main()
{   vacancies.readFromJson(DB_FILE_PATH);

    // Running the main window
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    MainWindow form;
    Application::Run(% form);

    char c;
    cin >> c;
    return 0;
}


