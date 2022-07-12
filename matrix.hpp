#pragma once
#include <stdexcept>
#include <initializer_list>

namespace skrbcr {

template <typename T, std::size_t m> class linvec {
private:
    T* lpData_;    // データ配列

public:
    linvec();
    linvec(std::initializer_list<T> list);
    linvec(const linvec<T, m>& vec);
    ~linvec();

    const T& operator[](std::size_t i) const;
    T& operator[](std::size_t i);
    linvec<T, m>& operator=(const linvec<T, m>& vec);
    linvec<T, m>& operator+=(const linvec<T, m>& vec);
    linvec<T, m>& operator-=(const linvec<T, m>& vec);
    linvec<T, m>& operator*=(const T k);
    linvec<T, m>& operator/=(const T k);

    // 配列を取得
    T* ptr() const noexcept;
};

template <typename T, std::size_t m> linvec<T, m>::linvec() {
    lpData_ = new T[m];
}
template <typename T, std::size_t m> linvec<T, m>::linvec(std::initializer_list<T> list) {
    lpData_ = new T[m];
    if (list.size() == static_cast<std::size_t>(0)) {
        for (std::size_t i = static_cast<std::size_t>(0); i < m; ++i) {
            lpData_[i] = *(list.begin());
        }
    }
    else if (list.size() == m) {
        int i = 0;
        for (auto it = list.begin(); it != list.end(); ++it) {
            lpData_[i] = *it;
            ++i;
        }
    }
    else {
        throw std::invalid_argument("Error: Length of list is wrong.");
    }
}
template <typename T, std::size_t m> linvec<T, m>::linvec(const linvec<T, m>& vec) {
    lpData_ = new T[m];
    for (std::size_t i = static_cast<std::size_t>(0); i < m; ++i) {
        lpData_[i] = vec[i];
    }
}
template <typename T, std::size_t m> linvec<T, m>::~linvec() {
    delete[] lpData_;
}

template <typename T, std::size_t m> const T& linvec<T, m>::operator[](std::size_t i) const {
    if (i < 0 || i >= m) {
        throw std::out_of_range("Error: Index out of range.");
    }
    return lpData_[i];
}
template <typename T, std::size_t m> T& linvec<T, m>::operator[](std::size_t i) {
    if (i < 0 || i >= m) {
        throw std::out_of_range("Error: Index out of range.");
    }
    return lpData_[i];
}
template <typename T, std::size_t m> linvec<T, m>& linvec<T, m>::operator=(const linvec<T, m>& vec) {
    for (std::size_t i = static_cast<std::size_t>(0); i < m; ++i) {
        lpData_[i] = vec[i];
    }
    return *this;
}
template <typename T, std::size_t m> linvec<T, m>& linvec<T, m>::operator+=(const linvec<T, m>& vec) {
    for (std::size_t i = static_cast<std::size_t>(0); i < m; ++i) {
        lpData_[i] += vec[i];
    }
    return *this;
}
template <typename T, std::size_t m> linvec<T, m>& linvec<T, m>::operator-=(const linvec<T, m>& vec) {
    for (std::size_t i = static_cast<std::size_t>(0); i < m; ++i) {
        lpData_[i] -= vec[i];
    }
    return *this;
}
template <typename T, std::size_t m> linvec<T, m>& linvec<T, m>::operator*=(const T k) {
    for (std::size_t i = static_cast<std::size_t>(0); i < m; ++i) {
        lpData_[i] *= k;
    }
    return *this;
}
template <typename T, std::size_t m> linvec<T, m>& linvec<T, m>::operator/=(const T k) {
    for (std::size_t i = static_cast<std::size_t>(0); i < m; ++i) {
        lpData_[i] /= k;
    }
    return *this;
}

template <typename T, std::size_t m> T* linvec<T, m>::ptr() const noexcept {
    return lpData_;
}


/* Arithmetic Operaters */
// ベクトル和・差
template <typename T, std::size_t m> linvec<T, m> operator+(const linvec<T, m>& v1, const linvec<T, m>& v2) {
    linvec<T, m> res = linvec<T, m>();
    for (std::size_t i = static_cast<std::size_t>(0); i < m; ++i) {
        res[i] = v1[i] + v2[i];
    }
    return res;
}
template <typename T, std::size_t m> linvec<T, m> operator-(const linvec<T, m>& v1, const linvec<T, m>& v2) {
    linvec<T, m> res = linvec<T, m>();
    for (std::size_t i = static_cast<std::size_t>(0); i < m; ++i) {
        res[i] = v1[i] - v2[i];
    }
    return res;
}
// スカラー積・商
template <typename T, std::size_t m> linvec<T, m> operator*(const linvec<T, m>& vec, const T k) {
    linvec<T, m> res = linvec<T, m>();
    for (std::size_t i = static_cast<std::size_t>(0); i < m; ++i) {
        res[i] = vec[i] * k;
    }
    return res;
}
template <typename T, std::size_t m> linvec<T, m> operator*(const T k, const linvec<T, m>& vec) {
    linvec<T, m> res = linvec<T, m>();
    for (std::size_t i = static_cast<std::size_t>(0); i < m; ++i) {
        res[i] = k * vec[i];
    }
    return res;
}
template <typename T, std::size_t m> linvec<T, m> operator/(const linvec<T, m>& vec, const T k) {
    linvec<T, m> res = linvec<T, m>();
    for (std::size_t i = static_cast<std::size_t>(0); i < m; ++i) {
        res[i] = vec[i] / k;
    }
    return res;
}

} // namespace skrbcr
