#include <unordered_map>
#include "Vacancy.h"
#include "Change.h"
using namespace std;


#pragma once
class Vacancies {
	unordered_map<int, Vacancy*> vacancies;
	vector<Change*> changes;
public:
	bool savedChanges;
	Vacancy* findById(int id);//Поиск по идентификатору
	Vacancy* findByParams(string vacancyName = "*", int salary = 0, string scedule = "*");//Поиск по одному или нескольким параметрам

	bool readFromJson(string filePath);//Чтение данных из файла
	bool saveChanges(string filePath);//Сохранение изменений

	bool deleteVacancy(int id);//Удаление вакансии
	bool addVacancy(Vacancy* newVacancy);//Добавление вакансии
};
