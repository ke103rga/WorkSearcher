#include <unordered_map>
#include "Vacancy.h"
#include "Vacancies.h"
#include "Change.h"

using namespace std;

#pragma once
Vacancies::Vacancies() {
	vacancies = unordered_map<int, Vacancy*>();
	changes = vector<Change*>();
};
#pragma once
bool Vacancies::readFromJson(string filePath) { return true; }//������ ������ �� �����
#pragma once
bool Vacancies::saveChanges(string filePath) { return true; }//���������� ���������
#pragma once
bool Vacancies::deleteVacancy(int id) { return true; }//�������� ��������
#pragma once
bool Vacancies::addVacancy(Vacancy* newVacancy) { return true; }//���������� ��������


Vacancies vacancies = Vacancies();
