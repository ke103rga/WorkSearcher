#include <string>
#include <regex>
#include <msclr\marshal_cppstd.h>
#include "InputDataValidator.h"

using namespace std;

InputDataValidator::InputDataValidator() {};

bool InputDataValidator::isInt(const std::string s){
	//Check if the string contains only digits 
	//and it's length smaller than 10
	if (strspn(s.c_str(), "0123456789") == s.size()) {
		return s.size() < 10;
	}
	return false;
}

bool InputDataValidator::isInt(System::String^ s) {
	if (strspn(msclr::interop::marshal_as<std::string>(s).c_str(), "0123456789") == s->Length) {
		return s->Length < 10;
	}
	return false;
}

bool InputDataValidator::isEmailValid(const std::string& email){
	//Check if the email adress follows the pattern
	const std::regex pattern
	("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	return std::regex_match(email, pattern);
}

bool InputDataValidator::isSceduleValid(const std::string& scedule){
	std::locale loc;
	//return appropriateScedules.find(std::tolower(scedule, loc)) != appropriateScedules.end();
	// Check if scedule matches with one of the appropriate scedules 
	return appropriateScedules.find(scedule) != appropriateScedules.end();
}

bool InputDataValidator::isPhoneValid(const std::string& phoneNumber){
	// Check if the phone number follows the pattern
	return phoneNumber.size() == 11 && phoneNumber[0] == '8' && phoneNumber[1] == '9';
}

bool InputDataValidator::isReqListValid(const std::string& reqs) {
	//Check if split function will works fine
	try {
		split(reqs, ", ");
	}
	catch (const char* error_message) {
		return false;
	}
	return true;
}

bool InputDataValidator::isInputDataValid(string company, string vacancy, string salary,
	string scedule, string trialPer, string email, string phoneNumber, string candidateReq,
	string& errorMessage, System::Collections::Generic::List<System::Windows::Forms::RichTextBox^>% inputFields) {
	//Check all input fields and in case of incorrect input function will builds 
	//the error message and insert the instructions into input fields which contains mistakes

	bool res = true;
	int errorCounter = 1;

	if (!isInt(salary)) {
		errorMessage += "* Величина заработной платы должна составлять целое положительное число\n\n";
		inputFields[2]->Text = "Сотрите этот текст и введите целое число";
		res = false;
	}

	if (!isInt(trialPer)) {
		errorMessage += "* Длительность испытательного срока должна составлять целое число дней или 0, в случае его отсутствия\n\n";
		inputFields[4]->Text = "Сотрите этот текст и введите целое число или ноль в случае отсутствия срока";
		res = false;
	}

	if (!isSceduleValid(scedule)) {
		string newMessage = "* Рабочий график должен соответствовать одному из вариантов:\n";
		for (const auto& elem : appropriateScedules) {
			newMessage = newMessage + "*\t" + elem +  "\n";
		}
		errorMessage = errorMessage + newMessage + "\n\n";
		inputFields[3]->Text = "Сотрите этот текст и укажите один из графиков работы";
		res = false;
	}

	if (!(isEmailValid(email))) {
		errorMessage += "* Проверьте введенный адрес электронной почты.\n\n";
		inputFields[5]->Text = "Сотрите этот текст и введите корректный адрес электронной почты";
		res = false;
	}

	if (!(isPhoneValid(phoneNumber))) {
		errorMessage += "* Проверьте введенный номер телефона.\n\n";
		inputFields[6]->Text = "Сотрите этот текст и введите корректный номер телефона";
		res = false;
	}

	if (!(isReqListValid(candidateReq))) {
		errorMessage += "Введите список требований в правильном формате.\n";
		inputFields[7]->Text = "Сотрите этот текст и введите список требований в соответствии с указанным в подсказке форматом";
		res = false;
	}

	return res;
}

string InputDataValidator::join(vector<string>& strings, string delim) {
	//Function that concatenates all strings from vector of strings into one string 

	if (strings.size() == 0) {
		return "empty vector";
	}
	if (strings.size() == 1) {
		return strings[0];
	}
	string res;
	for (int i = 0; i < strings.size() - 1; i++) {
		res = res + strings[i] + delim;
	}
	res += strings[strings.size() - 1];
	return res;
}

vector<string> InputDataValidator::split(string str, string token) {
	//Function that separates original string by the separator 
	//and creates a vector of part of original strings 

	vector<string>result;
	while (str.size()) {
		int index = str.find(token);
		if (index != string::npos) {
			result.push_back(str.substr(0, index));
			str = str.substr(index + token.size());
			if (str.size() == 0)result.push_back(str);
		}
		else {
			result.push_back(str);
			str = "";
		}
	}
	return result;
}