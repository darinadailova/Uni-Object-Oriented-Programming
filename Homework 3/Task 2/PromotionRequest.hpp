#pragma once
#include "Request.hpp"

class PromotionRequest : public Request {
	double amount;
public:
	PromotionRequest(const std::string& sender, double amount);
	double getAmount() const;
};