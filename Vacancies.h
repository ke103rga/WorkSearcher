#include <unordered_map>
#include <unordered_set>
#include "Vacancy.h"

using namespace std;

#pragma once
class Pair {
public:
	Pair(int key, Vacancy value) : key(key), value(value) {}

	int key;
	Vacancy value;
};


#pragma once
class Vacancies {
	vector<vector<Pair>> vacancies;
	int capacity;
	int nextId;

public:
	Vacancies(int capacity);

	bool savedChanges = true;

	int hashFunction(int key);
	void Add(int key, Vacancy value);

	Vacancy* findById(int id);//����� �� ��������������
	vector<int> findByParams(string vacancyName, int minSalary, int maxSalary, unordered_set<string> scedule);//����� �� ������ ��� ���������� ����������

	bool readFromTXT(string filePath);//������ ������ �� �����
	bool saveChanges(string filePath);//���������� ���������

	bool deleteVacancy(int id);//�������� ��������
	int addVacancy(Vacancy newVacancy);//���������� ��������

	int getNextId();
	bool containsId(int id);

	void updateVacacncy(int id, Vacancy updatedVacancy);
};

#pragma once
extern Vacancies vacancies;
#pragma once
extern string DB_FILE_PATH;
