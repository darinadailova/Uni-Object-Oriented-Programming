#include "ElectionResultsDatabase.hpp"

ElectionResultsDatabase::ElectionResultsDatabase() : sectionCount(0) {
}

void ElectionResultsDatabase::addResultsFromFile(const char* filename) {
	SectionVotes temp(0, 0, 0);
	std::ifstream inFile(filename);
	if (inFile.is_open()) {
		while (inFile >> temp) {
			votes.push_back(temp);
			sectionCount++;
		}
	}

	inFile.close();
}

int ElectionResultsDatabase::numberOfSections() const { return sectionCount; }

int ElectionResultsDatabase::votesForParty(Party party) const {
	int size = votes.size();
	int count = 0;

	for (int i = 0; i < size; i++) {
	
		if (party == Party::PARTY1) {
			count += votes[i].getVotesParty1();
		}
		else if (party == Party::PARTY2) {
			count += votes[i].getVotesParty2();
		}
		else {
			count += votes[i].getVotesParty3();
		}
	}

	return count;
}

Party ElectionResultsDatabase::winningParty() const {
	int votesForParty1 = votesForParty(Party::PARTY1);
	int votesForParty2 = votesForParty(Party::PARTY2);
	int votesForParty3 = votesForParty(Party::PARTY3);

	if (votesForParty1 >= votesForParty2 && votesForParty1 >= votesForParty3) return Party::PARTY1;
	else if (votesForParty2 > votesForParty1 && votesForParty2 >= votesForParty3) return Party::PARTY2;
	else return Party::PARTY3;
}

std::istream& operator>>(std::istream& in, ElectionResultsDatabase& db) {
	SectionVotes s;
	while (in >> s) {
		db.votes.push_back(s);
		db.sectionCount++;
	}

	return in;
}

std::ostream& operator<<(std::ostream& out, const ElectionResultsDatabase& db) {
	int size = db.votes.size();
	for (int i = 0; i < size; i++) {
		out << db.votes[i];
	}

	return out;
}