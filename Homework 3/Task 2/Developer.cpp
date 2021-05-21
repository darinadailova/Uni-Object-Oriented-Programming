#include "Developer.hpp"
#include "TeamLead.hpp"

Developer::Developer(const std::string name) : name(name), salary(0), teamLeader(nullptr) {
}

std::string Developer::getName() const {
	return name;
}

double Developer::getSalary() const {
	return salary;
}

TeamLead* Developer::getTeamLead() {
	return teamLeader;
}

void Developer::setInitialSalary(double amount) {
	if (salary == 0) salary = amount;
}

void Developer::setSalary(double amount) {
	salary = amount;
}

void Developer::setTeamLead(TeamLead* newLead) {
	if (newLead != nullptr) {
		teamLeader = newLead;
	}
	else {
		teamLeader = nullptr;
	}
}

void Developer::sendLeavingRequest() {
	if (teamLeader != nullptr) {
		LeavingRequest request(name);
		teamLeader->addLeavingRequest(request);
	}
}

void Developer::sendPromotionRequest(double amount) {
	if (teamLeader != nullptr) {
		PromotionRequest request(name, amount);
		teamLeader->addPromotionRequest(request);
	}
}

void Developer::changeSalary(const double& amount) {
	salary += amount;
}