/**
* Solution to homework assignment 2
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021 *
* @author Darina Dailova
* @idnumber 62583
* @task 1
* @compiler VC
*/

#pragma once
#include <iostream>
#include <cmath>

class Materials {
	int herbsCount;
	int oresCount;
	int clothCount;
	int essenceCount;
public:
	Materials();
	Materials(const Materials& rhs);
	Materials& operator=(const Materials& rhs);
	
	// getters
	int getSlots() const;
	int getHerbsCount() const;
	int getOresCount() const;
	int getClothCount() const;
	int getEssenceCount() const;

	//setters
	void setHerbsCount(const int& n);
	void setOresCount(const int& n);
	void setClothCount(const int& n);
	void setEssenceCount(const int& n);

	std::ostream& print(std::ostream& out);
};

