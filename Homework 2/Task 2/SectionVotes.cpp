#include "SectionVotes.hpp"

SectionVotes::SectionVotes() : votesParty1(0), votesParty2(0), votesParty3(0) {
}

SectionVotes::SectionVotes(const int& party1Votes, const int& party2Votes, const int& party3Votes)
	: votesParty1(party1Votes), votesParty2(party2Votes), votesParty3(party3Votes) {
}

int SectionVotes::votesForParty(Party party) const {
	if (party == Party::PARTY1) return votesParty1;
	else if (party == Party::PARTY2) return votesParty2;
	else return votesParty3;
}

SectionVotes::SectionVotes(const SectionVotes& rhs) {
	this->votesParty1 = rhs.votesParty1;
	this->votesParty2 = rhs.votesParty2;
	this->votesParty3 = rhs.votesParty3;
}

SectionVotes& SectionVotes::operator=(const SectionVotes& rhs) {
	if (this != &rhs) {
		this->votesParty1 = rhs.votesParty1;
		this->votesParty2 = rhs.votesParty2;
		this->votesParty3 = rhs.votesParty3;
	}

	return *this;
}

int SectionVotes::getVotesParty1() const { return votesParty1; }

int SectionVotes::getVotesParty2() const { return votesParty2; }

int SectionVotes::getVotesParty3() const { return votesParty3; }

std::istream& operator>>(std::istream& in, SectionVotes& sectionVotes) {
	in >> sectionVotes.votesParty1 >> sectionVotes.votesParty2 >> sectionVotes.votesParty3;

	return in;
}

std::ostream& operator<<(std::ostream& out, const SectionVotes& sectionvotes) {
	out << sectionvotes.votesParty1 << ' ' << sectionvotes.votesParty2 << ' ' << sectionvotes.votesParty3 << '\n';

	return out;
}