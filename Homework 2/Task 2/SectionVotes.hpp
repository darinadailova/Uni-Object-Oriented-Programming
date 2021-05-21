#pragma once
#include <iostream>

enum Party {
    PARTY1 = 0,
    PARTY2 = 1,
    PARTY3 = 2,
};

class SectionVotes {
    int votesParty1;
    int votesParty2;
    int votesParty3;
public:
    SectionVotes();
    SectionVotes(const int& party1Votes, const int& party2Votes, const int& party3Votes);
    SectionVotes(const SectionVotes& rhs);
    SectionVotes& operator=(const SectionVotes& rhs);

    int votesForParty(Party party) const;
    friend std::istream& operator>>(std::istream& in, SectionVotes& sectionVotes);
    friend std::ostream& operator<<(std::ostream& out, const SectionVotes& sectionVotes);

    // getters
    int getVotesParty1() const;
    int getVotesParty2() const;
    int getVotesParty3() const;
};