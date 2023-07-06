#include <unordered_map>
#include "Vacancy.h"
#include "Vacancies.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

#pragma once
Vacancies::Vacancies() {
	vacancies = unordered_map<int, Vacancy>();
};

#pragma once
bool Vacancies::readFromJson(string filePath) { 
	std::ifstream i(filePath);
	json j;
	i >> j;

	auto j_vacancies = j["vacancies"];

	for (int i = 0; i != j_vacancies.size(); i++) {
		auto j_vacancy = j_vacancies[i];

		int id = j_vacancy["id"];
		string company = j_vacancy["company"];
		string companyLogo = j_vacancy["companyLogo"];
		string vacancyName = j_vacancy["vacancyName"];
		int salary = j_vacancy["salary"];
		string workingScedule = j_vacancy["workingSchedule"];
		int trialPeriod = j_vacancy["trialPeriod"];
		string phoneNumber = j_vacancy["phoneNumber"];
		string email = j_vacancy["email"];
		vector<string> candidateRequirement = j_vacancy["candidateRequirement"];

		Vacancy newVacancy(id, company, companyLogo, vacancyName,
			salary, workingScedule, trialPeriod, phoneNumber,
			email, candidateRequirement);

		vacancies[j_vacancy["id"]] = newVacancy;
	}

	return true;
}

#pragma once
bool Vacancies::saveChanges(string filePath) {
	json j;

	json j_vacancies = json::array();

	for (std::pair<int, Vacancy> element : vacancies) {
		int vacId = element.first;
		Vacancy curVac = element.second;

		json j_curVacancyData = json({});
		j_curVacancyData["id"] = curVac.id;
		j_curVacancyData["company"] = curVac.company;
		j_curVacancyData["companyLogo"] = curVac.companyLogo;
		j_curVacancyData["vacancyName"] = curVac.vacancyName;
		j_curVacancyData["salary"] = curVac.salary;
		j_curVacancyData["workingSchedule"] = curVac.workingSchedule;
		j_curVacancyData["trialPeriod"] = curVac.trialPeriod;
		j_curVacancyData["phoneNumber"] = curVac.phoneNumber;
		j_curVacancyData["email"] = curVac.email;
		j_curVacancyData["candidateRequirement"] = curVac.candidateRequirement;

		j_vacancies.push_back(j_curVacancyData);
	}

	j["nextId"] = nextId;
	j["vacancies"] = j_vacancies;

	std::ofstream o("vacanciesData.json");
	o << std::setw(4) << j << std::endl;

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
	ids.push_back(1);
	ids.push_back(2);
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

Vacancies vacancies = Vacancies();
string DB_FILE_PATH = "vacanciesData.json";