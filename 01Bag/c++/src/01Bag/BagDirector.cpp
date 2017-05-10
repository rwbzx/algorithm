#include "ExportHeader.h"


BagDirector::BagDirector()
{
}


BagDirector::~BagDirector()
{
}

void BagDirector::StartBagInstance(BagBuilder &builder)
{
	builder.StartBag();
}
