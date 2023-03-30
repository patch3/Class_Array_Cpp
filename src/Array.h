#pragma once

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <sstream>
#include <string>

template<typename T>
class Array {
private:
    int len;
    T* p_arr;

public:
    Array() : len(0), p_arr(nullptr) {};
    explicit Array(const int& len);
    Array(const std::initializer_list<T>& list);
    Array(const T* ptr, const int& len);
    Array(const Array& obj);
    ~Array();

    float sum() const;
    float arithmetic_mean() const;

    T& operator[](const int& index);

    std::string  to_string() const;
    T* get_point();
    int get_len();
};
#include "Array_impl.hpp"

#endif // ARRAY_H