#include <cassert>
#include "BagInput.h"

BagInput::BagInput() :m_bag_volumn(0), m_item_num(0), m_item_w(0), m_item_p(0)
{
}

BagInput::~BagInput()
{
	if (m_item_w)
	{
		delete[] m_item_w;
		m_item_w = NULL;
	}
	if (m_item_p)
	{
		delete[] m_item_p;
		m_item_p = NULL;
	}
}

std::istream & operator>>(std::istream & in, BagInput & data)
{
	in >> data.m_bag_volumn >> data.m_item_num;
	assert(data.m_bag_volumn > 0 && data.m_item_num > 0);

	data.m_item_w = new int[data.m_item_num];
	data.m_item_p = new int[data.m_item_num];
	for (int i = 0; i < data.m_item_num; i++)
	{
		in >> data.m_item_w[i];
	}
	for (int i = 0; i < data.m_item_num; i++)
	{
		in >> data.m_item_p[i];
	}

	return in;
}