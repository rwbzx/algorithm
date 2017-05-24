#include "BagDPBuilder.h"
#include "BagInput.h"
#include <cassert>

BagDPBuilder::BagDPBuilder() :m_transform_state(NULL), m_current_state(NULL), m_last_state(NULL)
{
}

BagDPBuilder::~BagDPBuilder()
{
	if (m_transform_state)
	{
		delete[] m_transform_state;
		m_transform_state = NULL;
	}
}

void BagDPBuilder::StartBag()
{
	BagInput input;
	std::cin >> input;

	assert(input.m_bag_volumn);
	m_transform_state = new int[(input.m_bag_volumn+1) * 2];
	memset(m_transform_state, 0, sizeof(int)*(input.m_bag_volumn+1) * 2);

	m_current_state = m_transform_state;
	m_last_state = m_transform_state + input.m_bag_volumn + 1;

	DoBag(&input);
}

void BagDPBuilder::DoBag(BagInput * input)
{
	//for each item in item list, calculate its transform state
	for (int i = 0; i < input->m_item_num; i++)
	{
		std::cout << "transform state: ";
		for (int j = 1; j <= input->m_bag_volumn; j++)
		{
			if (j >= input->m_item_w[i])
			{
				m_current_state[j] = (m_last_state[j] >(m_last_state[j - input->m_item_w[i]] + input->m_item_p[i]))
					? m_last_state[j] : m_last_state[j - input->m_item_w[i]] + input->m_item_p[i];
			}
			else
			{
				m_current_state[j] = m_last_state[j];
			}
			std::cout << m_current_state[j] << " ";
		}
		std::cout << std::endl;
		std::swap(m_current_state, m_last_state);
		memset(m_current_state, 0, sizeof(int)*input->m_bag_volumn);
	}

	std::cout << m_last_state[input->m_bag_volumn] << std::endl;
}
