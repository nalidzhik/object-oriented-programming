#include "TestSuite.hpp"
#include <vector>

TestSuite::TestSuite(std::string name)
{
	this->name = name;
}

void TestSuite::add(const TestCase& to_add)
{
	testCase.push_back(to_add);
}

std::vector<TestCase> TestSuite::filterPassing() const
{
	std::vector<TestCase> passingCase;
	for (int i = 0;i < testCase.size();i++)
	{
		if (testCase[i].isPassing())
		{
			passingCase.push_back(testCase[i]);
		}
	}
	return passingCase;
}

std::vector<TestCase> TestSuite::filterFailing() const
{
	std::vector<TestCase> failingCase;
	for (int i = 0;i < testCase.size();i++)
	{
		if (!(testCase[i].isPassing()))
		{
			failingCase.push_back(testCase[i]);
		}
	}
	return failingCase;
}

std::vector<TestCase> TestSuite::filterByErrorType(ErrorType errorType) const
{
	std::vector<TestCase> filteredByErrorCase;

	for (int i = 0;i < testCase.size();i++)
	{
		if (testCase[i].getErrorType() == errorType)
		{
			filteredByErrorCase.push_back(testCase[i]);
		}
	}
	return filteredByErrorCase;
}

void TestSuite::removeByErrorType(ErrorType errorType)
{
	for (int i = 0;i < testCase.size();i++)
	{
		if (testCase[i].getErrorType() == errorType)
		{
			testCase.erase(testCase.begin() + i);
		}
	}
}

std::string TestSuite::getName() const
{
	return name;
}

void TestSuite::setName(const std::string& name)
{
	this->name = name;
}
