#include <unordered_map>
#include "Vacancy.h"
#include "Vacancies.h"

using namespace std;

#pragma once
Vacancies::Vacancies() {
	vacancies = unordered_map<int, Vacancy*>();
};
#pragma once
bool Vacancies::readFromJson(string filePath) { return true; }//������ ������ �� �����
#pragma once
bool Vacancies::saveChanges(string filePath) { return true; }//���������� ���������
#pragma once
bool Vacancies::deleteVacancy(int id) { return true; }//�������� ��������
#pragma once
bool Vacancies::addVacancy(Vacancy* newVacancy) { return true; }//���������� ��������

vector<int> Vacancies::findByParams(string vacancyName, int minSalary, int maxSalary, unordered_set<string> scedule) {
	vector<int> ids;
	ids.push_back(1);
	ids.push_back(2);
	return ids;
}

Vacancy* Vacancies::findById(int id) {
	return vacancies[id];
}

Vacancies vacancies = Vacancies();
