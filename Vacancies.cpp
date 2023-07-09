#include <unordered_map>
#include "Vacancy.h"
#include "InputDataValidator.h"
#include "Vacancies.h"
#include <fstream>
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include <algorithm>
#include <cctype>
#include <string>


using namespace std;

#pragma once
Vacancies::Vacancies() {
	vacancies = unordered_map<int, Vacancy>();
};

#pragma once
bool Vacancies::readFromTXT(string filePath) { 

	std::string line;
	std::ifstream in(filePath);
	if (in.is_open())
	{
		std::getline(in, line);
		nextId = System::Convert::ToInt32(gcnew System::String(line.c_str()));

		while (std::getline(in, line))
		{
			vector<string> vacancyAttrs = InputDataValidator::split(line, ";");

			if (vacancyAttrs.size() == 0) {
				continue;
			}
			int id = System::Convert::ToInt32(gcnew System::String(vacancyAttrs[0].c_str()));
			string company = vacancyAttrs[1];
			string companyLogo = vacancyAttrs[2];
			string vacancyName = vacancyAttrs[3];
			int salary = System::Convert::ToInt32(gcnew System::String(vacancyAttrs[4].c_str()));
			string workingSchedule = vacancyAttrs[5];
			int trialPeriod = System::Convert::ToInt32(gcnew System::String(vacancyAttrs[6].c_str()));
			string phoneNumber = vacancyAttrs[7];
			string email = vacancyAttrs[8];
			vector<string> candidateRequirement = InputDataValidator::split(vacancyAttrs[9], ", ");

			Vacancy newVacancy(id, company, companyLogo, vacancyName,
				salary, workingSchedule, trialPeriod, phoneNumber,
				email, candidateRequirement);

			vacancies[id] = newVacancy;
		}
	}
	in.close();

	cout << vacancies.size();

	return true;
}

#pragma once
bool Vacancies::saveChanges(string filePath) {

	string txt = msclr::interop::marshal_as<std::string>(nextId.ToString()) + "\n";
	for (std::pair<int, Vacancy> element : vacancies) {
		int vacId = element.first;
		Vacancy curVac = element.second;

		txt = txt +
			msclr::interop::marshal_as<std::string>(curVac.id.ToString()) + ";" +
			curVac.company + ";" +
			curVac.companyLogo + ";" +
			curVac.vacancyName + ";" +
			msclr::interop::marshal_as<std::string>(curVac.salary.ToString()) + ";" +
			curVac.workingSchedule + ";" +
			msclr::interop::marshal_as<std::string>(curVac.trialPeriod.ToString()) + ";" +
			curVac.phoneNumber + ";" +
			curVac.email + ";" +
			InputDataValidator::join(curVac.candidateRequirement, ", ") + "\n";
	}

	std::ofstream out;
	out.open(filePath);
	if (out.is_open())
	{
		out << txt << std::endl;
	}
	out.close();
	return true;

	return true;
}

#pragma once
bool Vacancies::deleteVacancy(int id) { 
	if (vacancies.find(id) != vacancies.end()) {
		vacancies.erase(id);
		return true;
	}
	return false;
}

#pragma once
int Vacancies::addVacancy(Vacancy newVacancy) { 
	vacancies[newVacancy.id] = newVacancy; 
	return nextId++;
}

vector<int> Vacancies::findByParams(string vacancyName, int minSalary, int maxSalary, unordered_set<string> scedule) {
	vector<int> ids;
	for (std::pair<int, Vacancy> element : vacancies) {
		int vacId = element.first;
		Vacancy curVac = element.second;

		std::string lowercurVacName = curVac.vacancyName;
		std::transform(lowercurVacName.begin(), lowercurVacName.end(), lowercurVacName.begin(),
			[](unsigned char c) { return std::tolower(c); });
		std::string searchVacName = vacancyName;
		std::transform(searchVacName.begin(), searchVacName.end(), searchVacName.begin(),
			[](unsigned char c) { return std::tolower(c); });

		if  (lowercurVacName.find(searchVacName) != std::string::npos  && (curVac.salary >= minSalary )
			/*&& (curVac.salary <= maxSalary)*/  && scedule.find(curVac.workingSchedule) != scedule.end()) {
			ids.push_back(vacId);
		}
	}
	return ids;
}

Vacancy* Vacancies::findById(int id) {
	if (vacancies.find(id) != vacancies.end()) {
		return &vacancies[id];
	}
	Vacancy* emptyVac = 0;
	return emptyVac;
}

int Vacancies::getNextId() { return nextId;  }

bool Vacancies::containsId(int id) { return vacancies.find(id) != vacancies.end(); }

void Vacancies::updateVacacncy(int id, Vacancy updatedVacancy) {
	vacancies[id] = updatedVacancy;
}

Vacancies vacancies = Vacancies();
string DB_FILE_PATH = "vacanciesData.txt";

