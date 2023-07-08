#include <string>
#include <regex>
#include <msclr\marshal_cppstd.h>
#include "InputDataValidator.h"

using namespace std;

InputDataValidator::InputDataValidator() {};

bool InputDataValidator::isInt(const std::string s){
	return(strspn(s.c_str(), "0123456789") == s.size());
}

bool InputDataValidator::isInt(System::String^ s) {
	return(strspn(msclr::interop::marshal_as<std::string>(s).c_str(), "0123456789") == s->Length);
}

bool InputDataValidator::isEmailValid(const std::string& email){
	const std::regex pattern
	("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	return std::regex_match(email, pattern);
}

bool InputDataValidator::isSceduleValid(const std::string& scedule){
	std::locale loc;
	//return appropriateScedules.find(std::tolower(scedule, loc)) != appropriateScedules.end();
	return appropriateScedules.find(scedule) != appropriateScedules.end();
}

bool InputDataValidator::isPhoneValid(const std::string& phoneNumber){
	return phoneNumber.size() == 11 && phoneNumber[0] == '8' && phoneNumber[1] == '9';
}

bool InputDataValidator::isReqListValid(const std::string& reqs) {
	return true;
}

bool InputDataValidator::isInputDataValid(string company, string vacancy, string salary,
	string scedule, string trialPer, string email, string phoneNumber, string candidateReq,
	string& errorMessage, System::Collections::Generic::List<System::Windows::Forms::RichTextBox^>% inputFields) {
	bool res = true;
	int errorCounter = 1;

	if (!isInt(salary)) {
		errorMessage += "* �������� ���������� ����� ������ ���������� ����� ������������� �����\n\n";
		inputFields[2]->Text = "������� ���� ����� � ������� ����� �����";
		res = false;
	}

	if (!isInt(trialPer)) {
		errorMessage += "* ������������ �������������� ����� ������ ���������� ����� ����� ���� ��� 0, � ������ ��� ����������\n\n";
		inputFields[3]->Text = "������� ���� ����� � ������� ����� ����� ��� ���� � ������ ���������� �����";
		res = false;
	}

	if (!isSceduleValid(scedule)) {
		string newMessage = "* ������� ������ ������ ��������������� ������ �� ���������:\n";
		for (const auto& elem : appropriateScedules) {
			newMessage = newMessage + "*\t" + elem +  "\n";
		}
		errorMessage = errorMessage + newMessage + "\n\n";
		inputFields[4]->Text = "������� ���� ����� � ������� ����� ����� ��� ���� � ������ ���������� �����";
		res = false;
	}

	if (!(isEmailValid(email))) {
		errorMessage += "* ��������� ��������� ����� ����������� �����.\n\n";
		inputFields[5]->Text = "������� ���� ����� � ������� ���������� ����� ����������� �����";
		res = false;
	}

	if (!(isPhoneValid(phoneNumber))) {
		errorMessage += "* ��������� ��������� ����� ��������.\n\n";
		inputFields[6]->Text = "������� ���� ����� � ������� ���������� ����� ��������";
		res = false;
	}

	if (!(isReqListValid(candidateReq))) {
		errorMessage += "������� ������ ���������� � ���������� �������.\n";
		inputFields[7]->Text = "������� ���� ����� � ������� ������ ���������� � ������������ � ��������� � ��������� ��������";
		res = false;
	}

	return res;
}

string InputDataValidator::join(vector<string>& strings, string delim) {
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