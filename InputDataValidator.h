#include <string>
#include <unordered_set>
#include <List>

using namespace std;

#pragma once
class InputDataValidator {

public:
	InputDataValidator();

	unordered_set<string> appropriateScedules {"5/2", "2/2", "посуточный", "почасовой"};

	static bool isInt(const std::string s);

	static bool isInt(System::String^ s);

	bool isEmailValid(const std::string& email);

	bool isSceduleValid(const std::string& scedule);

	bool isPhoneValid(const std::string& phoneNumber);

	bool isReqListValid(const std::string& reqs);

	bool isInputDataValid(string company, string vacancy, string salary,
		string scedule, string trialPer, string email, string phoneNumber, string candidateReq, 
		string& errorMessage, System::Collections::Generic::List<System::Windows::Forms::RichTextBox^>% inputFields);

	static string join(vector<string>& strings, string delim);

	static vector<string> split(string str, string token);
};
