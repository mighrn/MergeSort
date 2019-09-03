#pragma once

void merge(std::vector<int> &, int, int, int);
void mergeSort(std::vector<int> &, int, int);

/*
@param f : the INDEX of the 'leftmost' element
@param e : the INDEX of the 'rightmost' element
*/
void mergeSort(std::vector<int>& v, int f, int e)
{
	if (e - f > 1) //we can split the array in half
	{
		int m = (f + e) / 2; //calculate the midpoint of the array
		mergeSort(v, f, m); //recursive call with the left half of this array
		mergeSort(v, m, e); //recursive call with the right half of this array
		merge(v, f, m, e); //
	}
}

void merge(std::vector<int>& v, int f, int m, int e)
{
	std::vector<int> l;//temporary arrays to copy elements
	std::vector<int> r;
	//NOTE this can be done with only one temporary array
	//for the sake of explanation, will be done with two

	for (int i = f; i < m; i++)
	{
		l.push_back(v[i]);
	}
	for (int i = m; i < e; i++)
	{
		r.push_back(v[i]);
	}

	//indeces of left and right side respectively
	int i = 0; //if done with single array: i = f
	int j = 0; //if done with single array: j = m

	for (int k = f; k < e; k++)
	{
		/*
		i + f < m  ``indicates left side still has elements to be sorted
		j + m >= e ``indicates right side does NOT have elements to be sorted
		l[i] < r[j] ``CHANGE/OVERRIDE THIS COMPARISON FOR DIFFERENT ORDERING
		*/
		if (i + f < m && (j + m >= e || l[i] < r[j])) //if done with single array: (i < m && (j >= e || t[i] < t[j]))
		{
			v[k] = l[i];
			i++;
		}
		else
		{
			v[k] = r[j];
			j++;
		}
	}
}
