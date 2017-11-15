#pragma once
#include "group_includes.h"

class NLP_Engine
{
private:
	int parseStatus = -1;
	std::string identifier;
public:
	NLP_Engine()
	{

	}

	~NLP_Engine()
	{

	}

	void Begin()
	{

	}

	void Parse(std::string input)
	{
		if (input == "")
		{
			parseStatus = 0;
		}
	}

	int getParseStatus()
	{
		return parseStatus;
	}

	std::string getIdentifier()
	{
		return identifier;
	}

	void throwError()
	{

	}

	void End()
	{
		
	}
};
