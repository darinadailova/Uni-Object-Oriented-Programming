#include "Document.hpp"

Document::Document(const std::string& name, const std::string& location, const std::string& extension)
	: Object(name, location, extension), currentLine(0) {
}

Document::Document(const Document& rhs) {
	this->name = rhs.name;
	this->location = rhs.location;
	this->extension = rhs.extension;
	this->setPath();
	this->lines = rhs.lines;
}

Document& Document::operator=(const Document& rhs) {
	if (this != &rhs) {
		this->name = rhs.name;
		this->location = rhs.location;
		this->extension = rhs.extension;
		this->setPath();
		this->lines.clear();
		this->lines = rhs.lines;
	}

	return *this;
}

void Document::write_line(const std::string& line) {
	lines.push_back(line);
}

std::string Document::read_line() {
	if (currentLine + 1 <= lines.size()) {
		currentLine++;
		return lines[currentLine - 1];
	}

	throw std::out_of_range("End of file\n");
}

std::string Document::read_line(const unsigned line) {
	if (line <= lines.size() && line > 0) {
		currentLine = line;
		return lines[line - 1];
	}

	throw std::out_of_range("Invalid line number\n");
}

bool Document::operator==(const Comparable* obj) const {
	const Document* document = static_cast<const Document*>(obj);
	if (document) {
		if (document->lines.size() != this->lines.size()) {
			return false;
		}

		for (size_t i = 0; i < this->lines.size(); i++) {
			if (document->lines[i] != this->lines[i]) {
				return false;
			}
		}

		return true;
	} 

	return false;
}

bool Document::operator!=(const Comparable* obj) const {
	if (operator==(obj)) return false;
	return true;
}

std::string Document::to_string() const {
	std::string str = "";
	str.append(name);
	str.append("\n");
	str.append(location);
	str.append("\n");
	str.append(extension);
	str.append("\n");
	for (size_t i = 0; i < lines.size(); i++) {
		str.append(lines[i]);
		str.append("\n");
	}

	return str;
}

void Document::from_string(const std::string& str1) {
	std::string str = str1;
	int find = str.find("\n");
	name = str.substr(0, find);
	
	std::string str2 = str.substr(find + 1, str.size());
	find = str2.find("\n");
	location = str2.substr(0, find);

	str = str2.substr(find + 1, str2.size());
	find = str.find("\n");
	extension = str.substr(0, find);

	setPath();
	str2 = str.substr(find + 1, str.size());
	lines.clear();
	while (str2.size() > 1) {
		find = str2.find('\n');
		lines.push_back(str2.substr(0, find));

		str = str2.substr(find + 1, str2.size());
		str2 = str;
	}
}

std::string Document::debug_print() const {
	std::string str = "";
	for (size_t i = 0; i < lines.size(); i++) {
		str.append("Line ");
		str.append(std::to_string(i + 1));
		str.append(":");
		str.append(lines[i]);
		str.append("\n");
	}

	return str;
}

Object* Document::clone() const {
	return new Document(*this);
}
