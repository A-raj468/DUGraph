#pragma once

template <typename T> struct Result {
    bool success;
    T value;

    Result() : success(false) {}
    Result(bool s, const T &v) : success(s), value(v) {}
};

template <> struct Result<void> {
    bool success;

    Result() : success(false) {}
    Result(bool s) : success(s) {}
};
