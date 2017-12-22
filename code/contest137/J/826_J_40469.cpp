#include <stdio.h>
#include <string.h>

#define MAX_M		100
#define MAX_LENGTH	101

char questions[MAX_M][MAX_LENGTH], answers[MAX_M][MAX_LENGTH];
char chat[MAX_LENGTH];

int main()
{
	int m, n;
	while(scanf("%d%d", &m, &n) == 2)
	{
		gets(chat);
		for(int i = 0; i < m; i++)
		{
			gets(questions[i]);
			gets(answers[i]);
		}
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < strlen(questions[i]); j++)
			{
				if(questions[i][j] >= 'A' && questions[i][j] <= 'Z') questions[i][j] = questions[i][j] - (int)('A' - 'a');
			}
		}
		for(int i = 0; i < n; i++)
		{
			gets(chat);
			for(int j = 0; j < strlen(chat); j++)
			{
				if(chat[j] >= 'A' && chat[j] <= 'Z') chat[j] = chat[j] - (int)('A' - 'a');
			}
			int flag = 0;
			for(int j = 0; j < m; j++)
			{
				if(strcmp(chat, questions[j]) == 0)
				{
					printf("%s\n", answers[j]);
					flag = 1;
					break;
				}
			}
			if(!flag) printf("What are you saying?\n");
		}
	}
	return 0;
}
