#include <unordered_map>
#include <unordered_set>
#include "Vacancy.h"
using namespace std;


#pragma once
class Vacancies {
	unordered_map<int, Vacancy> vacancies;
	int nextId;
public:
	Vacancies();
	bool savedChanges = true;

	Vacancy* findById(int id);//Поиск по идентификатору
	vector<int> findByParams(string vacancyName, int minSalary, int maxSalary, unordered_set<string> scedule);//Поиск по одному или нескольким параметрам

	bool readFromTXT(string filePath);//Чтение данных из файла
	bool saveChanges(string filePath);//Сохранение изменений

	bool deleteVacancy(int id);//Удаление вакансии
	int addVacancy(Vacancy newVacancy);//Добавление вакансии

	int getNextId();
};

#pragma once
extern Vacancies vacancies;
#pragma once
extern string DB_FILE_PATH;
