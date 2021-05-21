#pragma once

template <typename T>

class Optional {
    T obj;
    bool is_empty = false; // if is_empty is true then the object is empty(it was created with the default constructor)
public:
    Optional();
    Optional(const T& value);

    bool is_none() const;
    T get_value() const;
};

template <typename T>
Optional<T>::Optional() {
    obj = T();
    is_empty = true;
}

template<typename T>
Optional<T>::Optional(const T& value) {
    obj = value;
}

template<typename T>
bool Optional<T>::is_none() const {
    if (is_empty) return true;
    return false;
}

template<typename T>
T Optional<T>::get_value() const { return obj; }