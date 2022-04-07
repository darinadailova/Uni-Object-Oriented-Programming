#pragma once
#include "Object.hpp"
#include <vector>
#include <stdexcept>

class Document : public Object {
	std::vector<std::string> lines;
	size_t currentLine;
public:
	Document(const std::string& name = "", const std::string& location = "", const std::string& extension = "");
	Document(const Document& rhs);
	Document& operator=(const Document& rhs);

	void write_line(const std::string& line);

	std::string read_line();
	std::string read_line(const unsigned line);

	virtual bool operator==(const Comparable* obj) const override;
	virtual bool operator!=(const Comparable* obj) const override;

	std::string to_string() const override;
	void from_string(const std::string& str1) override;

	std::string debug_print() const override;

	virtual Object* clone() const override;
};