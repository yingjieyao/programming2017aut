#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_N		105

int n;
int count;
double time;
double time_required[MAX_N];
int is_finished[MAX_N];
double time_finished[MAX_N];

void run(int i);
int compare_two_doubles(const void *a, const void *b);

int main()
{
	int t;
	scanf("%d", &t);
	for(int case_id = 1; case_id <= t; case_id++)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
		{
			scanf("%lf", &time_required[i]);
			is_finished[i] = 0;
			time_finished[i] = 0.0;
		}
		printf("Case %d:", case_id);
		count = 0;
		time = 0.0;
		while(count < n)
		{
			int flag = 1, i;
			while(flag)
			{
				for(i = 0; i < n; i++)
				{
					if(is_finished[i]) continue;
					if(time_required[i] <= 1.0)
					{
						flag = 0;
						break;
					}
					else
					{
						time_required[i] -= 1.0;
						time += 1.0;
					}
				}
				if(!flag) run(i);
			}
		}
		for(int i = 0; i < n - 1; i++) printf("%.2f ", time_finished[i]);
		printf("%.2f\n", time_finished[n - 1]);
	}
	return 0;
}

void run(int i)
{
	count++;
	time += time_required[i];
	is_finished[i] = 1;
	time_finished[i] = time;
	time += 1.0;
	
	int flag = 1, j;
	for(j = i + 1; j < n; j++)
	{
		if(is_finished[j]) continue;
		if(time_required[j] <= 1.0)
		{
			flag = 0;
			break;
		}
		else
		{
			time_required[j] -= 1.0;
			time += 1.0;
		}
	}
	if(!flag) run(j);
}

int compare_two_doubles(const void *a, const void *b)
{
	double value_a = *((double *)a), value_b = *((double *)b);
	if(value_a > value_b) return 1;
	else if (value_a == value_b) return 0;
	else return -1;
}
