#include <stdio.h>
#include <stdlib.h>

#define MAX_N		100005

struct Computer
{
	int distance;
	int is_connected;
} computers[MAX_N];

int connected_computers_count;
struct Connect_Computer
{
	int distance;
	int left, right;
} connected_computers[MAX_N];

int compare_two_computers_by_distance(const void *a, const void *b);
long long min(int a, int b);

int main()
{
	int t;
	scanf("%d", &t);
	for(int case_id = 1; case_id <= t; case_id++)
	{
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", &computers[i].distance);
		for(int i = 0; i < n; i++) scanf("%d", &computers[i].is_connected);
		qsort(computers, n, sizeof *computers, &compare_two_computers_by_distance);
		
		connected_computers_count = 0;
		for(int i = 0; i < n; i++)
		{
			if(computers[i].is_connected)
			{
				if(connected_computers_count == 0)
				{
					connected_computers[connected_computers_count].distance = computers[i].distance;
					connected_computers[connected_computers_count].left = i;
					connected_computers[connected_computers_count].right = i;
					connected_computers_count++;
				}
				else if(connected_computers[connected_computers_count - 1].distance == computers[i].distance)
				{
					connected_computers[connected_computers_count - 1].right = i;
				}
				else
				{
					connected_computers[connected_computers_count].distance = computers[i].distance;
					connected_computers[connected_computers_count].left = i;
					connected_computers[connected_computers_count].right = i;
					connected_computers_count++;
				}
			}
		}
		
		if(connected_computers_count == 0)
		{
			printf("Case #%d: -1\n", case_id);
			continue;
		}
		long long ans = (long long)(connected_computers[0].distance - computers[0].distance);
		for(int i = 0; i < connected_computers_count - 1; i++)
		{
			if(connected_computers[i].right + 1 == connected_computers[i + 1].left) continue;
			int distance_left = connected_computers[i].distance, distance_right = connected_computers[i + 1].distance;
			int distance_max = 0;
			for(int j = connected_computers[i].right; j < connected_computers[i + 1].left; j++)
			{
				int distance_tmp = computers[j + 1].distance - computers[j].distance;
				if(distance_tmp > distance_max) distance_max = distance_tmp;
			}
			ans += (long long)(distance_right - distance_left - distance_max);
		}
		ans += (long long)(computers[n - 1].distance - connected_computers[connected_computers_count - 1].distance);
		
		printf("Case #%d: %lld\n", case_id, ans);
	}
	return 0;
}

int compare_two_computers_by_distance(const void *a, const void *b)
{
	struct Computer *computer_a = (struct Computer *)a, *computer_b = (struct Computer *)b;
	if(computer_a->distance == computer_b->distance) return computer_a->is_connected - computer_b->is_connected;
	else return computer_a->distance - computer_b->distance;
}

long long min(int a, int b)
{
	return (long long)(a < b ? a : b);
}
