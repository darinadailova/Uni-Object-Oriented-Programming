#pragma once
#include "LeavingRequest.hpp"
#include "PromotionRequest.hpp"
#include <string>

class TeamLead;

class Developer {
	std::string name;
	double salary;
	TeamLead* teamLeader;
public:
	Developer(const std::string name);

	std::string getName() const;
	double getSalary() const;
	TeamLead* getTeamLead();
	
	void setInitialSalary(double amount);
	void setSalary(double amount);
	void setTeamLead(TeamLead* newLead);
	void changeSalary(const double& amount);

	void sendLeavingRequest();
	void sendPromotionRequest(double amount);
};