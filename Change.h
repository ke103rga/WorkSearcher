#include "Vacancy.h"

#pragma once
class Change {
public:
	Change(Vacancy& vacancy, int vacancyId, string action) {}
	Vacancy* vacancy;
	int vacancyId;
	string action;
};
