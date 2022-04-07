#pragma once
#include "Object.hpp"
#include <vector>
#include <utility>
#include <stdexcept>

class KeyValueDatabase : public Object {
    std::vector<std::pair<std::string, int>> data;
public:
    KeyValueDatabase(const std::string& name = "", const std::string& location = "", const std::string& extension = "");
    KeyValueDatabase(const KeyValueDatabase& rhs);
    KeyValueDatabase& operator=(const KeyValueDatabase& rhs);

    void add_entry(const std::pair<std::string, int>& entry);
    int get_value(const std::string& key) const;

    virtual bool operator==(const Comparable* obj) const override;
    virtual bool operator!=(const Comparable* obj) const override;

    virtual std::string debug_print() const override;
  
    virtual std::string to_string() const override;
    virtual void from_string(const std::string& str1) override;

    virtual Object* clone() const override;
};