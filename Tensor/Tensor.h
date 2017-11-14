#pragma once
#include "group_includes.h"
#include "GraphicsNLP.h"

class Function
{

};

class Tensor
{

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
public:
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
