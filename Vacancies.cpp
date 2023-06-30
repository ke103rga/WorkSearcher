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
bool Vacancies::readFromJson(string filePath) { return true; }//Чтение данных из файла
#pragma once
bool Vacancies::saveChanges(string filePath) { return true; }//Сохранение изменений
#pragma once
bool Vacancies::deleteVacancy(int id) { return true; }//Удаление вакансии
#pragma once
bool Vacancies::addVacancy(Vacancy* newVacancy) { return true; }//Добавление вакансии


Vacancies vacancies = Vacancies();
