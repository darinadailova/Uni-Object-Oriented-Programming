#include "KeyValueDatabase.hpp"

KeyValueDatabase::KeyValueDatabase(const std::string& name, const std::string& location, const std::string& extension)
	: Object(name, location, extension) {
}

KeyValueDatabase::KeyValueDatabase(const KeyValueDatabase& rhs) {
	this->name = rhs.name;
	this->location = rhs.location;
	this->extension = rhs.extension;
	this->setPath();
	this->data = rhs.data;
}

KeyValueDatabase& KeyValueDatabase::operator=(const KeyValueDatabase& rhs) {
	if (this != &rhs) {
		this->name = rhs.name;
		this->location = rhs.location;
		this->extension = rhs.extension;
		this->setPath();
		this->data.clear();
		this->data = rhs.data;
	}

	return *this;
}

void KeyValueDatabase::add_entry(const std::pair<std::string, int>& entry) {
	for (size_t i = 0; i < data.size(); i++) {
		if (data[i].first == entry.first) {
			throw std::invalid_argument("invalid_argument");
		}
	}

	data.push_back(entry);
}

int KeyValueDatabase::get_value(const std::string& key) const {
	for (size_t i = 0; i < data.size(); i++) {
		if (data[i].first == key) {
			return data[i].second;
		}
	}

	throw std::invalid_argument("invalid key");
}

bool KeyValueDatabase::operator==(const Comparable* obj) const {
	const KeyValueDatabase* database = static_cast<const KeyValueDatabase*>(obj);
	if (database) {
		if (database->data.size() != this->data.size()) return false;

		for (size_t i = 0; i < this->data.size(); i++) {
			if (this->data[i] != database->data[i]) {
				return false;
			}
		}

		return true;
	}

	return false;
}

bool KeyValueDatabase::operator!=(const Comparable* obj) const {
	if (operator==(obj)) return false;
	return true;
}

std::string KeyValueDatabase::debug_print() const {
	std::string toPrint = "";
	for (size_t i = 0; i < data.size(); i++) {
		toPrint.append("{");
		toPrint.append(data[i].first);
		toPrint.append(":");
		toPrint.append(std::to_string(data[i].second));
		toPrint.append("}");
		toPrint.append("\n");
	}

	return toPrint;
}

std::string KeyValueDatabase::to_string() const {
	std::string str = "";
	str.append(name);
	str.append("\n");
	str.append(location);
	str.append("\n");
	str.append(extension);
	str.append("\n");
	for (size_t i = 0; i < data.size(); i++) {
		str.append(data[i].first);
		str.append(":");
		str.append(std::to_string(data[i].second));
		str.append("\n");
	}

	return str;
}

void KeyValueDatabase::from_string(const std::string& str1) {
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
	data.clear();
	while (str2.size() >= 1) {
		std::string tempKey;

		find = str2.find(':');
		tempKey = str2.substr(0, find);

		int find2 = str2.find('\n');
		int tempValue = std::stoi(str2.substr(find + 1, find2));

		std::pair<std::string, int> tempPair(tempKey, tempValue);
		data.push_back(tempPair);

		str = str2.substr(find2 + 1, str2.size());
		str2 = str;
	}
}

Object* KeyValueDatabase::clone() const {
	return new KeyValueDatabase(*this);
}