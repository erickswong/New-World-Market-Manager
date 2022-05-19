#pragma once

#include <exception>
#include <string>
#include <utility>

// throw NotImplementedException();
// catch (NotImplementedException& e)
struct NotImplementedException final : std::exception {
    [[nodiscard]] const char* what() const noexcept override {
        return "Not Implemented";
    }
};

struct NotUsedException final : std::exception {
    [[nodiscard]] const char* what() const noexcept override {
        return "Not Used";
    }
};

struct BadJsonException final : std::exception {
	BadJsonException() = default;
	explicit BadJsonException(std::string message) {
		this->message = std::move(message);
	}

	[[nodiscard]] const char* what() const noexcept override {
		return message.c_str();
	}

	private:
		std::string message = "Bad JSON";
};
