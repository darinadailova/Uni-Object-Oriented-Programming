#include "TeamLead.hpp"

TeamLead::TeamLead(const std::string& name, double salary) : Developer(name) {
	setSalary(salary);
	setTeamLead(this);
}

std::vector<Developer*> TeamLead::getTeam() {
	return team;
}

void TeamLead::addDeveloperToTeam(Developer* developer, double salary) {
	if (developer != nullptr) {
		developer->setSalary(salary);
		developer->setTeamLead(this);
		team.push_back(developer);
	}
}

void TeamLead::removeDeveloperFromTeam(const std::string& name) {
	for (int i = team.size() - 1; i >= 0; i--) {
		if (team[i]->getName() == name) {
			team[i]->setTeamLead(nullptr);
			team.erase(team.begin() + i);
			break;
		}
	}
}

void TeamLead::increaseTeamSalariesBy(double amount) {
	for (size_t i = 0; i < team.size(); i++) {
		team[i]->changeSalary(amount);
	}
}

void TeamLead::decreaseTeamSalariesBy(double amount) {
	increaseTeamSalariesBy(-amount);
}

void TeamLead::addLeavingRequest(const LeavingRequest& leavingRequest) {
	leavingRequests.push_back(leavingRequest);
}

void TeamLead::addPromotionRequest(const PromotionRequest& promotionRequest) {
	promotionRequests.push_back(promotionRequest);
}

void TeamLead::fulfillLeavingRequests() {
	for (size_t i = 0; i < leavingRequests.size(); i++) {
		for (size_t j = 0; j < team.size(); j++) {
			if (leavingRequests[i].getSender() == team[j]->getName()) {
				team[j]->setTeamLead(nullptr);
				team.erase(team.begin() + j);
				break;
			}
		}
	}

	leavingRequests.clear();
}

void TeamLead::fulfillPromotionRequests() {
	for (size_t i = 0; i < promotionRequests.size(); i++) {
		for (size_t j = 0; j < team.size(); j++) {
			if (promotionRequests[i].getSender() == team[j]->getName()) {
				team[j]->changeSalary(promotionRequests[i].getAmount());
			}
		}
	}
	
	promotionRequests.clear();
}