#pragma once

#ifdef DLL_EXPORT
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

class DLL_API BagBuilder
{
public:
	BagBuilder();
	virtual ~BagBuilder();

	virtual void StartBag() = 0;
};

class DLL_API BagDirector{
public:
	BagDirector();
	~BagDirector();
	void StartBagInstance(BagBuilder &);
};