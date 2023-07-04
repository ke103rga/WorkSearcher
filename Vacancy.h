
#include <string>
#include <vector>
using namespace std;

#pragma once
class Vacancy {
public:
	/*Vacancy(int id=0, string company="", string companyLogo = "", string vacancyName = "",
	        int salary = 0, string workingSchedule = "", int trialPeriod = 0, string phoneNumber = "",
	        string email = "", vector<string> candidateRequirement = vector<string>()):
		id(id), company(company), companyLogo(companyLogo), vacancyName(vacancyName), salary(salary), 
		workingSchedule(workingSchedule), trialPeriod(trialPeriod), phoneNumber(phoneNumber), 
		email(email) {
		std::vector<string> v(2);
		v = { "1", "2"};
		candidateRequirement = v;
	}*/

	int id;
	string company;
	string companyLogo;
	string vacancyName;
	int salary;
	string workingSchedule;
	int trialPeriod;
	string phoneNumber;
	string email;
	vector<string> candidateRequirement;
};

