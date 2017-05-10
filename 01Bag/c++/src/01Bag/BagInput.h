#include <iostream>

class BagInput
{
public:
	BagInput();
	~BagInput();

public:
	int m_bag_volumn;
	int m_item_num;
	int * m_item_w;
	int * m_item_p;

	friend std::istream & operator>>(std::istream & in , BagInput & data);
};