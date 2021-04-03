#include "Error.hpp"
#include <cstring>

bool Error::hasMessage() const
{
	if (message == nullptr)
	{
		return false;
	}

	return true;
}

const char* Error::getMessage() const
{
	return this->message;
}

ErrorType Error::getType() const
{
	return this->errorType;
}

Error Error::newNone()
{
	Error noneError;
	noneError.errorType = ErrorType::None;

	return noneError;
}

Error Error::newBuildFailed(const char* message)
{
	Error buildFailedError;
	buildFailedError.errorType = ErrorType::BuildFailed;
	int messageLength = strlen(message);
	delete[] buildFailedError.message;
	buildFailedError.message = new char[messageLength + 1];
	strcpy_s(buildFailedError.message, messageLength + 1, message);

	return Error(buildFailedError);
}

Error Error::newWarning(const char* message)
{
	Error warningError;
	warningError.errorType = ErrorType::Warning;
	int messageLength = strlen(message);
	delete[] warningError.message;
	warningError.message = new char[messageLength + 1];
	strcpy_s(warningError.message, messageLength + 1, message);

	return Error(warningError);
}

Error Error::newFailedAssertion(const char* message)
{
	Error failedAssertionError;
	failedAssertionError.errorType = ErrorType::FailedAssertion;
	int messageLength = strlen(message);
	delete[] failedAssertionError.message;
	failedAssertionError.message = new char[messageLength + 1];
	strcpy_s(failedAssertionError.message, messageLength + 1, message);

	return Error(failedAssertionError);
}

Error::Error(const char* message, ErrorType errorType)
{
	this->message = NULL;

	int messageLength = strlen(message);
	this->message = new char[messageLength + 1];
	strcpy_s(this->message, messageLength + 1, message);
	this->errorType = errorType;

}

Error::Error()
{
	this->message = NULL;
	this->errorType = ErrorType::None;
}

Error& Error::operator=(const Error& rhs)
{
	if (this != &rhs)
	{
		if (rhs.message != NULL)
		{
			delete[] message;
			int nameLength = strlen(rhs.message);
			message = new char[nameLength + 1];
			strcpy_s(message, nameLength + 1, rhs.message);
		}
		this->errorType = rhs.errorType;
	}
	return *this;
}

Error::Error(const Error& copyFrom)
{
	if (copyFrom.message != NULL)
	{
		int messageLength = strlen(copyFrom.message);
		message = new char[messageLength + 1];
		strcpy_s(message, messageLength + 1, copyFrom.message);
	}
	this->errorType = copyFrom.errorType;
}

Error::~Error()
{
	delete[] message;
}
