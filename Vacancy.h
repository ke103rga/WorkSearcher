#pragma once
#include <string>
#include <vector>
using namespace std;

class Vacancy {
public:
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

