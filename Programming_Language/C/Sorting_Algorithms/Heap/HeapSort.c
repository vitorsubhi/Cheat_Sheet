#include <stdio.h>

void rebuild(int v[], int limit, int pos)
{
		
	int c1, c2;
	
	c1 = 2 * pos;
	c2 = c1 + 1;
	
	if(c1 > limit || (v[pos - 1] >= v[c1 - 1] && v[pos - 1] >= v[c2 - 1]))
		return;
	
	int greater_index = -1;
	
	if(c2 > limit)
		greater_index = c1;
	else
	{
		if(v[c1 - 1] > v[c2 - 1])
			greater_index = c1;
		else
			greater_index = c2;
	}
	
	if(greater_index != -1)
	{
		int aux = v[greater_index - 1];
		v[greater_index - 1] = v[pos - 1];
		v[pos - 1] = aux;
		rebuild(v, limit, greater_index);
	}
}


void build(int v[], int size_v)
{
	int left;
	
	if(size_v % 2 == 0)
		left = size_v / 2 + 1;
	else
		left = (size_v - 1) / 2 + 1;
	
	while(left > 1)
	{
		left--;
		rebuild(v, size_v, left);
	}
}

void heap_sort(int v[], int size_v)
{
	build(v, size_v);

	int limit = size_v;
	
	while(1)
	{
		int aux = v[0];
		v[0] = v[limit - 1];
		v[limit - 1] = aux;
		
		rebuild(v, limit - 1, 1);
			
		limit--;
		
		if(limit <= 2 && v[0] <= v[1])
			break;
	}
}
