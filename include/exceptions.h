#pragma once

#include <exception>

// throw NotImplementedException();
// catch (NotImplementedException& e)
struct NotImplementedException : std::exception {
    [[nodiscard]] const char* what() const noexcept override {
        return "Not Implemented";
    }
};

struct NotUsedException : std::exception {
    [[nodiscard]] const char* what() const noexcept override {
        return "Not Used";
    }
};
