#include "BagBacktrackBuilder.h"
#include "BagInput.h"
#include <cassert>

BagBacktrackBuilder::BagBacktrackBuilder() :m_current_w(0), m_current_v(0), m_final_w(0), m_max_v(0), m_item_selected(NULL)
{
}

BagBacktrackBuilder::~BagBacktrackBuilder()
{
	if (m_item_selected)
	{
		delete[] m_item_selected;
		m_item_selected = NULL;
	}
}

void BagBacktrackBuilder::StartBag()
{
	BagInput input;
	std::cin >> input;

	assert(input.m_item_num);
	m_item_selected = new int[input.m_item_num];
	memset(m_item_selected, 0, sizeof(int)*input.m_item_num);

	DoBag(0, &input);

	std::cout << "final weight: " << m_final_w << std::endl;
	std::cout << "max value: " << m_max_v << std::endl;
}

void BagBacktrackBuilder::DoBag(int index, BagInput * input)
{
	if (index < input->m_item_num)
	{
		if (m_current_w + input->m_item_w[index] <= input->m_bag_volumn)
		{
			m_current_w += input->m_item_w[index];
			m_current_v += input->m_item_p[index];
			if (m_max_v < m_current_v)
			{
				m_max_v = m_current_v;
				m_final_w = m_current_w;
			}
			m_item_selected[index] = 1;

			DoBag(index + 1, input);

			m_current_w -= input->m_item_w[index];
			m_current_v -= input->m_item_p[index];
			m_item_selected[index] = 0;
		}
		DoBag(index + 1, input);
	}
}
