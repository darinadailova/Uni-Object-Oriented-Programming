#pragma once
#include "SectionVotes.hpp"
#include <vector>
#include <fstream>
#include<iostream>

class ElectionResultsDatabase {
    std::vector<SectionVotes> votes;
    int sectionCount;
public:
    ElectionResultsDatabase();
    void addResultsFromFile(const char* filename);
    int numberOfSections() const;
    int votesForParty(Party party) const;
    Party winningParty() const;
    friend std::istream& operator>>(std::istream& in, ElectionResultsDatabase& db);
    friend std::ostream& operator<<(std::ostream& out, const ElectionResultsDatabase& db);
};