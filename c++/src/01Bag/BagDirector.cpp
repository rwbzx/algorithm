#include "BagDirector.h"
#include "BagInput.h"

BagDirector::BagDirector()
{
}


BagDirector::~BagDirector()
{
}

void BagDirector::StartBagInstance(BagBuilder &builder)
{
	BagInput input;
	std::cin >> input;
	builder.StartBag();
}
