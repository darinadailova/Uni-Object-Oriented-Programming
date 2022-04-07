#pragma once
#include "Debug.hpp"
#include "Comparable.hpp"
#include "Serializable.hpp"

class Object : public Comparable, public Debug, public Serializable {
protected:
    std::string name;
    std::string location;
    std::string extension;
    std::string path;

public:
    Object(const std::string& name = "", const std::string& location = "", const std::string& extension = "");
    Object(const Object& rhs);
    virtual Object* clone() const = 0;
    void setPath();

    std::string get_name() const;
    std::string get_location() const;
    std::string get_extension() const;
    std::string get_fullpath() const;
};