#pragma once

#include "BagBuilder.h"

class DLL_API BagDirector{
public:
	BagDirector();
	~BagDirector();
	void StartBagInstance(BagBuilder &);
};