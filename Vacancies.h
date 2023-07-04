#include <unordered_map>
#include <unordered_set>
#include "Vacancy.h"
using namespace std;


#pragma once
class Vacancies {
	unordered_map<int, Vacancy*> vacancies;
public:
	Vacancies();
	bool savedChanges;

	Vacancy* findById(int id);//Поиск по идентификатору
	vector<int> findByParams(string vacancyName, int minSalary, int maxSalary, unordered_set<string> scedule);//Поиск по одному или нескольким параметрам

	bool readFromJson(string filePath);//Чтение данных из файла
	bool saveChanges(string filePath);//Сохранение изменений

	bool deleteVacancy(int id);//Удаление вакансии
	bool addVacancy(Vacancy* newVacancy);//Добавление вакансии
};

#pragma once
extern Vacancies vacancies;
