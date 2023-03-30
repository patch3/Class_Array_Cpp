#ifndef ARRAY_IMPL_H
#define ARRAY_IMPL_H

#include "Array.h"

template<typename T>
Array<T>::Array(const int& len) {
    this->len = len;
    this->p_arr = new T[this->len];
}

template<typename T>
Array<T>::Array(const std::initializer_list<T>& list) {
    this->len = list.size();
    this->p_arr = new T[this->len];
    std::copy(list.begin(), list.end(), this->p_arr);
}

template<typename T>
Array<T>::Array(const T* obj, const int& len) {
    this->len = len;
    this->p_arr = new T[this->len];
    std::copy(obj, obj + this->len, this->p_arr);
}

template<typename T>
Array<T>::Array(const Array& obj) {
    this->len = obj.len;
    this->p_arr = new T[this->len];
    std::copy(obj.p_arr, obj.p_arr + this->len, this->p_arr);
}

template<typename T>
Array<T>::~Array() {
    delete[] this->p_arr;
}

template<typename T>
float Array<T>::sum() const {
    float sum = 0.0f;
    T* p_temp = this->p_arr;
    for (int i = 0; i < this->len; ++i) {
        sum += *p_temp;
        ++p_temp;
    }
    return sum;
}

template<typename T>
float Array<T>::arithmetic_mean() const {
    return this->sum() / this->len;
}

template<typename T>
T& Array<T>::operator[](const int& index) {
    if (index < 0 || index >= this->len) {
        throw std::out_of_range("index out of range");
    }
    return *(this->p_arr + index);
}

template<typename T>
std::string Array<T>::to_string() const {
    std::ostringstream oss;
    oss << "[";
    T* p_temp = this->p_arr;
    for (int i = 1; i <= len; ++i) {
        oss << "\n\t" << i << " => " << *p_temp;
        if (i != len) {
            oss << ", ";
        }
        ++p_temp;
    }
    oss << "\n]\n";
    return oss.str();
}

template<typename T>
T* Array<T>::get_point() {
    return this->p_arr;
}
template<typename T>
int Array<T>::get_len() {
    return this->len;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& obj) {
    os << obj.to_string();
    return os;
}

template<typename T>
std::istream& operator>>(std::istream& is, Array<T>& obj) {
    T* p_temp = obj.get_point();
    for (int i = 1; i <= obj.get_len(); ++i) {
        std::cout << i << ") ";
        is >> *p_temp;
        ++p_temp;
    }
    return is;
}

#endif