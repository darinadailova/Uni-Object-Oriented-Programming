#pragma once
#include <string>

class Error {
    std::string error_message;
public:
    Error(const std::string& message = "");
    Error(const Error& rhs);
    Error& operator=(const Error& rhs);

    std::string get_message() const;
    void set_message(const std::string& new_message);
};