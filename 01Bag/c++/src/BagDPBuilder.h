#pragma once

#include "ExportHeader.h"
class BagInput;

class DLL_API BagDPBuilder : public BagBuilder
{
public:
	BagDPBuilder();
	virtual ~BagDPBuilder();
	virtual void StartBag();
private:
	int * m_transform_state;
	int * m_current_state;
	int * m_last_state;
	void DoBag(BagInput *);
};

