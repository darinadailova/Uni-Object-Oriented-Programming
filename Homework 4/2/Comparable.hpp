#pragma once
class Comparable {
public:
	Comparable() = default;
	virtual bool operator==(const Comparable* obj) const = 0;
	virtual bool operator!=(const Comparable* obj) const = 0;
	virtual ~Comparable();
};