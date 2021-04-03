#include "TestCase.hpp"
#include <cstring>

TestCase::TestCase(const std::string& name, const Error& error)
{
	this->name = name;
	this->error = error;
}

std::string TestCase::getName() const
{
	return this->name;;
}

bool TestCase::isPassing() const
{
	return ErrorType::None == error.getType() || ErrorType::Warning == error.getType();
}

bool TestCase::hasError() const
{
	return error.getType() != ErrorType::None;
}

ErrorType TestCase::getErrorType() const
{
	if (hasError())
	{
		return error.getType();
	}

	return  ErrorType::None;
}

std::string TestCase::getErrorMessage() const
{
	return this->error.getMessage();
}

TestCase& TestCase::operator=(const TestCase& rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.name;
		this->error = rhs.error;
	}

	return *this;
}

TestCase::TestCase(const TestCase& copyFrom)
{
	this->name = copyFrom.name;
	this->error = copyFrom.error;
}
