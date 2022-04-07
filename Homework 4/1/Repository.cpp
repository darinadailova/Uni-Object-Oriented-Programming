#include "Repository.hpp"

Repository::Repository(const Repository& rhs) {
    for ( auto x : rhs.subscribers) {
        this->subscribers.push_back(x->clone());
    }
}

Repository& Repository::operator=(const Repository& rhs) {
    if (this != &rhs) {
        for (auto x : this->subscribers) {
            delete x;
        }
        this->subscribers.clear();

        for ( auto x : rhs.subscribers) {
            this->subscribers.push_back(x->clone());
        }
    }

    return *this;
}

Repository::~Repository() {
    for (auto x : this->subscribers) {
        delete x;
    }
    this->subscribers.clear();
}

void Repository::add(Subscriber* subscriber) {
    subscribers.push_back(subscriber->clone());
}

Subscriber* Repository::get(std::string id) const {
    for (auto x : subscribers) {
        if(x->id == id) {
            return x;
        }
    }

    return nullptr;
}