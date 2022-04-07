#pragma once
#include "Averager.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include <string>
#include <vector>

class Repository {
	std::vector<Subscriber*> subscribers;
public:
	Repository() = default;
	Repository(const Repository& rhs);
	Repository& operator=(const Repository& rhs);
	~Repository();

	void add(Subscriber*);
	Subscriber* get(std::string id) const;
};