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
Vacancies::Vacancies(int capacity) : capacity(capacity) {
	vacancies.resize(capacity);
} 

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

			//vacancies[id] = newVacancy;
			Add(id, newVacancy);
		}
	}
	in.close();

	cout << vacancies.size();

	return true;
}

#pragma once 
int Vacancies::hashFunction(int key) {
	return key % capacity;
}

#pragma once
void Vacancies::Add(int key, Vacancy value) {
	int index = hashFunction(key);
	Pair pair(key, value);

	vector<Pair>& curBucket = vacancies[index];
	for (int i = 0; i < curBucket.size(); i++) {
		if (curBucket[i].key == key) {
			curBucket[i].value = value;
			return;
		}
	}
	curBucket.push_back(pair);
}

#pragma once
bool Vacancies::saveChanges(string filePath) {

	string txt = msclr::interop::marshal_as<std::string>(nextId.ToString()) + "\n";
	for (int i = 0; i < capacity; i++) {
		vector<Pair>& curBucket = vacancies[i];
		if (curBucket.empty()) { continue; }
		for (int j = 0; j < curBucket.size(); j++) {
			int vacId = curBucket[j].key;
			Vacancy curVac = curBucket[j].value;

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
	int index = hashFunction(id);
	vector<Pair>& curBucket = vacancies[index];
	for (int i = 0; i < curBucket.size(); i++) {
		if (curBucket[i].key == id) {
			curBucket.erase(curBucket.begin() + i);
			return true;
		}
	}
	return false;
}

#pragma once
int Vacancies::addVacancy(Vacancy newVacancy) { 
	Add(newVacancy.id, newVacancy);
	return nextId++;
}

vector<int> Vacancies::findByParams(string vacancyName, int minSalary, int maxSalary, unordered_set<string> scedule) {
	vector<int> ids;
	for (int i = 0; i < capacity; i++) {
		vector<Pair>& curBucket = vacancies[i];
		if (curBucket.empty()) { continue; }
		for (int j = 0; j < curBucket.size(); j++) {
			int vacId = curBucket[j].key;
			Vacancy curVac = curBucket[j].value;

			std::string lowercurVacName = curVac.vacancyName;
			std::transform(lowercurVacName.begin(), lowercurVacName.end(), lowercurVacName.begin(),
				[](unsigned char c) { return std::tolower(c); });
			std::string searchVacName = vacancyName;
			std::transform(searchVacName.begin(), searchVacName.end(), searchVacName.begin(),
				[](unsigned char c) { return std::tolower(c); });

			if (lowercurVacName.find(searchVacName) != std::string::npos && (curVac.salary >= minSalary)
				/*&& (curVac.salary <= maxSalary)*/ && scedule.find(curVac.workingSchedule) != scedule.end()) {
				ids.push_back(vacId);
			}
		}
	}
	//for (std::pair<int, Vacancy> element : vacancies) {
	//	int vacId = element.first;
	//	Vacancy curVac = element.second;

	//	std::string lowercurVacName = curVac.vacancyName;
	//	std::transform(lowercurVacName.begin(), lowercurVacName.end(), lowercurVacName.begin(),
	//		[](unsigned char c) { return std::tolower(c); });
	//	std::string searchVacName = vacancyName;
	//	std::transform(searchVacName.begin(), searchVacName.end(), searchVacName.begin(),
	//		[](unsigned char c) { return std::tolower(c); });

	//	if  (lowercurVacName.find(searchVacName) != std::string::npos  && (curVac.salary >= minSalary )
	//		/*&& (curVac.salary <= maxSalary)*/  && scedule.find(curVac.workingSchedule) != scedule.end()) {
	//		ids.push_back(vacId);
	//	}
	//}
	return ids;
}

Vacancy* Vacancies::findById(int id) {
	int index = hashFunction(id);
	vector<Pair>& curBucket = vacancies[index];
	if (curBucket.empty()) {
		throw std::invalid_argument("Key error");
	}
	else {
		for (int i = 0; i < curBucket.size(); i++) {
			if (curBucket[i].key == id) {
				return &curBucket[i].value;
			}
		}
	}
	Vacancy* emptyVac = 0;
	return emptyVac;
}

int Vacancies::getNextId() { return nextId;  }

bool Vacancies::containsId(int id) {
	int index = hashFunction(id);
	vector<Pair>& curBucket = vacancies[index];
	for (int i = 0; i < curBucket.size(); i++) {
		if (curBucket[i].key == id) {
			return true;
		}
	}
	return false;
}

void Vacancies::updateVacacncy(int id, Vacancy updatedVacancy) {
	Add(updatedVacancy.id, updatedVacancy);
}

Vacancies vacancies = Vacancies(500);
string DB_FILE_PATH = "vacanciesData.txt";

