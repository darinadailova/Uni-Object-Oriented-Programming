#pragma once
#include "Subscriber.hpp"

class Averager : public Subscriber {
public:
	Averager(std::string id = "");
	Averager(const Averager& rhs);

	virtual void signal(Message) override;
	virtual int read() const override;
	virtual Subscriber* clone() const override;
};