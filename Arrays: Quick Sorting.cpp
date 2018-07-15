void quickSort(std::vector<int> &input_array, int left, int right) 
{
	/* setting up indexes at the beginning and end, a pivot 	point in a 	middle*/
	int i{ left }, j{ right }, pivot{ input_array[(left + right) 	/ 2] };

	/* stepping through an array in between i and j */
	while (i <= j)
	{
		/* if left indexes elements smaller and right one 	bigger than a pivot than step over them, hey are already in 	order*/
		while (input_array[i] < pivot)
			i++;
		while (input_array[j] > pivot)
			j--;

		/* after meet element not in order - swap it and step 	further */
		if (i <= j)
		{
			int temp{ input_array[i] };
			input_array[i] = input_array[j];
			input_array[j] = temp;
			i++;
			j--;
		}
	}

	/* recursive way */
	/* if i didnt reach a end (right) or j didnt reach a 	beginning (left), 	then repeat function */
	if (left < j)
		quickSort(input_array, left, j);
	if (i < right)
		quickSort(input_array, i, right);
}
