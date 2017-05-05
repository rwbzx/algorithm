#include "BagBuilder.h"

class DLL_API BagBacktrackBuilder : public BagBuilder
{
public:
	BagBacktrackBuilder();
	virtual ~BagBacktrackBuilder();
	virtual void StartBag();
};
