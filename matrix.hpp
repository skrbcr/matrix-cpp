#pragma once
#include <stdexcept>
#include <initializer_list>

namespace skrbcr {

template <typename T, std::size_t m> class linvector {
private:
    T* vec_;    // 配列

public:
    linvector();
    linvector(std::initializer_list<T> list);
    linvector(const linvector<T, m>& v);
    ~linvector();

    const T& operator[](std::size_t i) const;
    T& operator[](std::size_t i);
    linvector<T, m>& operator=(const linvector<T, m> v);

    // 配列を取得
    T* ptr() const noexcept;
};

template <typename T, std::size_t m> linvector<T, m>::linvector() {
    vec_ = new int[m];
}
template <typename T, std::size_t m> linvector<T, m>::linvector(std::initializer_list<T> list) {
    vec_ = new int[m];
    if (list.size() == static_cast<std::size_t>(0)) {
        for (std::size_t i = static_cast<std::size_t>(0); i < m; ++i) {
            vec_[i] = *(list.begin());
        }
    }
    else if (list.size() == m) {
        int i = 0;
        for (auto it = list.begin(); it != list.end(); ++it) {
            vec_[i] = *it;
            ++i;
        }
    }
    else {
        throw std::invalid_argument("Error: Length of list is wrong.");
    }
}
template <typename T, std::size_t m> linvector<T, m>::linvector(const linvector<T, m>& v) {
    vec_ = new int[m];
    for (std::size_t i = static_cast<std::size_t>(0); i < m; ++i) {
        vec_[i] = v[i];
    }
}
template <typename T, std::size_t m> linvector<T, m>::~linvector() {
    delete[] vec_;
}

template <typename T, std::size_t m> const T& linvector<T, m>::operator[](std::size_t i) const {
    if (i < 0 || i >= m) {
        throw std::out_of_range("Error: Index out of range.");
    }
    return vec_[i];
}
template <typename T, std::size_t m> T& linvector<T, m>::operator[](std::size_t i) {
    if (i < 0 || i >= m) {
        throw std::out_of_range("Error: Index out of range.");
    }
    return vec_[i];
}
template <typename T, std::size_t m> linvector<T, m>& linvector<T, m>::operator=(const linvector<T, m> v) {
    for (std::size_t i = static_cast<std::size_t>(0); i < m; ++i) {
        vec_[i] = v[i];
    }
    return *this;
}

template <typename T, std::size_t m> T* linvector<T, m>::ptr() const noexcept {
    return vec_;
}


/* Arithmetic Operaters */

template <typename T, std::size_t m> linvector<T, m> operator+(const linvector<T, m>& v1, const linvector<T, m>& v2) {
    linvector<T, m> res = linvector<T, m>();
    for (std::size_t i = static_cast<std::size_t>(0); i < m; ++i) {
        res[i] = v1[i] + v2[i];
    }
    return res;
}
template <typename T, std::size_t m> linvector<T, m> operator-(const linvector<T, m>& v1, const linvector<T, m>& v2) {
    linvector<T, m> res = linvector<T, m>();
    for (std::size_t i = static_cast<std::size_t>(0); i < m; ++i) {
        res[i] = v1[i] - v2[i];
    }
}

} // namespace skrbcr
