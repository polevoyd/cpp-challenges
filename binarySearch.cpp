int binarySearch(std::vector<int> v, int e)
{
	/* binary search in a vector */
	int v_size{ (int)v.size() };
	int left{ 0 }, right{ v_size - 1 };
	int pivot{ v_size / 2 };

	while (pivot != e)
	{
		if (v[pivot] == e)
			return pivot;
		else if (v[pivot] > e)
		{
			right = pivot;
			pivot /= 2;
		}
		else
		{
			left = pivot;
			pivot += pivot / 2;
		}
	}
	return pivot;
}
