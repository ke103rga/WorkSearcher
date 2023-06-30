#include "MainWindow.h"
#include "EmployerWindow.h"


//namespace WorkSearch {
//    public ref class MainWindow : public System::Windows::Forms::Form {
//    private: System::Void candidateButton_Click(System::Object^ sender, System::EventArgs^ e) {
//        EmployerWindow form;
//        Application::Run(% form);
//    }
//    };
//}
namespace WorkSearch {
	System::Void candidateButton_Click(System::Object^ sender, System::EventArgs^ e) {
		CandidateWindow^ form = gcnew CandidateWindow();
		form->ShowDialog();
	}
}