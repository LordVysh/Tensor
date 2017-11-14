#pragma once
#include "group_includes.h"
#include "GraphicsNLP.h"

class Function
{

};

class UpperIndex
{

};

class LowerIndex
{

};

class Tensor
{
private:
	std::vector<UpperIndex> upperIndices;
	std::vector<LowerIndex> lowerIndices;

public:
	Tensor()
	{
		std::string input = "";
		NLP_Engine *nlpE = new NLP_Engine();
		nlpE->Begin();
		nlpE->Parse(input);
		if (nlpE->getParseStatus() != -1)
		{
			nlpE->End();
		}
		else
		{
			nlpE->throwError();
			nlpE->End();
		}
	}
	Tensor(std::string input)
	{
		NLP_Engine *nlpE = new NLP_Engine();
		nlpE->Begin();
		nlpE->Parse(input);
		if (nlpE->getParseStatus() != -1)
		{
			nlpE->End();
		}
		else
		{
			nlpE->throwError();
			nlpE->End();
		}
	}

	void addUpperIndex(UpperIndex index)
	{
		upperIndices.push_back(index);
	}

	void removeUpperIndex(int N)
	{
		upperIndices.erase(upperIndices.begin() + N);
	}

	void addLowerIndex(LowerIndex index)
	{
		lowerIndices.push_back(index);
	}

	void removeLowerIndex(int N)
	{
		lowerIndices.erase(lowerIndices.begin() + N);
	}

	Function getFirstDerivative()
	{
		
	}

	Function getSecondDerivative()
	{

	}

	Function getNthDerivative(int N)
	{

	}
};
