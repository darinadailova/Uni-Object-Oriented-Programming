#include "MovingAverager.hpp"

MovingAverager::MovingAverager(std::string id, size_t windowSize)
    : Subscriber(id), windowSize(windowSize) {
}

MovingAverager::MovingAverager(const MovingAverager& rhs) {
    this->id = rhs.id;
    this->windowSize = rhs.windowSize;
    this->messages = rhs.messages;
}

void MovingAverager::signal(Message message) {
    messages.push_back(message);
}

int MovingAverager::read() const {
    if (messages.size() == 0) {
        return 0;
    } 
    else {
        int average = 0;
        
        size_t i = 0;
        for(size_t j = messages.size() - 1; i < windowSize; j--) {
            average += messages[j].data;
            i++;
            if (j == 0) {
                break;
            }
        }
        if (windowSize > messages.size()) {
            return average / messages.size();
        }
        
        return (average / windowSize);
          
    }
}

Subscriber* MovingAverager::clone() const {
    return new MovingAverager(*this);
}