#include "Object.hpp"

Object::Object(const std::string& name, const std::string& location, const std::string& extension)
    : Comparable(), Debug(), Serializable(), name(name), location(location), extension(extension), path("") {
    setPath();
}

Object::Object(const Object& rhs) {
    this->name = rhs.name;
    this->location = rhs.location;
    this->extension = rhs.extension;
    this->setPath();
}

void Object::setPath() {
        path = "";
        path.append(location);
        path.append("/");
        path.append(name);
        path.append(".");
        path.append(extension);
}

std::string Object::get_name() const {
    return name;
}

std::string Object::get_location() const {
    return location;
}

std::string Object::get_extension() const {
    return extension;
}

std::string Object::get_fullpath() const {
    return path;
}