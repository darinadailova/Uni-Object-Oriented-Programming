#pragma once
#include "Error.hpp"
#include "Optional.hpp"

template<typename T>

class Result {
    T result;
    Error error;
public:
    Result();
    Result(const T& result);
    Result(const std::string& error_message);

    Optional<T> get_result() const;
    Optional<Error> get_error() const;
    
    bool operator==(const T& rhs) const;
    bool operator==(const Error& rhs) const;
};

template<typename T>
Result<T>::Result() {
    result = T();
    error = Error();
}

template<typename T>
Result<T>::Result(const T& result) {
    this->result = result;
}

template<typename T>
Result<T>::Result(const std::string& error_message) {
    error.set_message(error_message);
}

template<typename T>
Optional<T> Result<T>::get_result() const {
    return result;
}

template<typename T>
Optional<Error> Result<T>::get_error() const {
    return error;
}

template<typename T>
bool Result<T>::operator==(const T& rhs) const {
    if (error.get_message() == "") return true;
    return false;
}

template<typename T>
bool Result<T>::operator==(const Error& rhs) const {
    if (error.get_message() == "") return false;
    return true;
}