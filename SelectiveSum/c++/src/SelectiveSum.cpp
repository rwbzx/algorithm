#include "SelectiveSum.h"
#include <algorithm>

bool SelectiveSum(int * input, int num, int sum)
{
	if (!num || !input)
	{
		return false;
	}

	std::sort(input, input + num);
	int low = 0;
	int high = num - 1;

	int result = 0;
	while (low != high)
	{
		result = input[low] + input[high];
		if (result == sum)
		{
			return true;
		}
		else if (result < sum)
		{
			low++;
		}
		else
		{
			high--;
		}
	}
	return false;
}