#include <iostream>
#include "MainWindow.h"
#include "Vacancies.h"

using namespace std;
using namespace WorkSearch;
using namespace Newtonsoft::Json;
 

[STAThreadAttribute()]
int main()
{   
    //Check if file of database exists and contains valid data
    if(!vacancies.readFromTXT(DB_FILE_PATH)){
        cout << "Invalid file path\nThr database is empty";
    }

    // Running the main window
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    MainWindow form;
    Application::Run(% form);

    char c;
    cin >> c;
    return 0;
}


