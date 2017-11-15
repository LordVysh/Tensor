#pragma once
#include "group_includes.h"
#include "GraphicsNLP.h"

class Objects
{

};

class DataSet
{
private:
	std::map<std::string, std::vector<Objects>> kv;
public:
	void addKey(std::string key)
	{

	}

	void attach(std::string key, std::vector<Objects> objects)
	{
		for (auto& o : objects)
		{
			kv[key].push_back(o);
		}
	}
};

class Event
{

};

class EventQueue
{
private:
	std::vector<Event> events;
public:
	EventQueue()
	{

	}
};

class Function : Objects 
{
public:
	Function()
	{

	}

	Function(std::string input)
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
		delete nlpE;
	}

	~Function()
	{

	}
};

class UpperIndex : Objects
{
public:
	UpperIndex()
	{

	}

	~UpperIndex()
	{

	}
};

class LowerIndex : Objects
{
public:
	LowerIndex()
	{

	}

	~LowerIndex()
	{

	}
};

class Tensor : Objects
{
private:
	std::vector<Objects> tensorObjects;
	std::vector<UpperIndex> upperIndices;
	std::vector<LowerIndex> lowerIndices;
	std::string identifier;
	int parseStatus = -1;

public:
	Tensor()
	{
		std::string input = "";
		NLP_Engine *nlpE = new NLP_Engine();
		nlpE->Begin();
		nlpE->Parse(input);
		if (nlpE->getParseStatus() != -1)
		{
			parseStatus = nlpE->getParseStatus();
			identifier = nlpE->getIdentifier();
			nlpE->End();
		}
		else
		{
			nlpE->throwError();
			nlpE->End();
		}
		delete nlpE;
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
		delete nlpE;
	}

	~Tensor()
	{
		for (auto& u : upperIndices)
		{
			u.~UpperIndex();
		}
		for (auto& l : lowerIndices)
		{
			l.~LowerIndex();
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

	bool isMalformed()
	{
		if (parseStatus != -1)
		{
			return false;
		}
		return true;
	}

	std::string getIdentifier()
	{
		return identifier;
	}

	std::vector<Objects> getObjects()
	{
		return tensorObjects;
	}
};

class SessionManager
{
private:
	EventQueue *eq = new EventQueue();
	DataSet *data = new DataSet();
public:
	SessionManager()
	{

	}

	void addTensor(std::string input)
	{
		Tensor *candidate = new Tensor(input);
		if (!candidate->isMalformed())
		{
			data->addKey(candidate->getIdentifier());
			data->attach(candidate->getIdentifier(), candidate->getObjects());
		}

	}

};