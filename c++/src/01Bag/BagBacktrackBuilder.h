#pragma once

#include "ExportHeader.h"
class BagInput;

class DLL_API BagBacktrackBuilder : public BagBuilder
{
public:
	BagBacktrackBuilder();
	virtual ~BagBacktrackBuilder();
	virtual void StartBag();

private:
	int m_current_w;
	int m_current_v;
	int m_max_v;
	int m_final_w;
	int * m_item_selected;

	BagInput * input;
	void DoBag(int index, BagInput * input);
};
