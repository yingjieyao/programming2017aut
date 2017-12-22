#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char q[110][110],a[110][110];
int n,m;

int ifsame(char a[],char b[])
{
    if (a[0]!=b[0]) return 0;
    for (int i=1;i<=a[0];i++)
        if (a[i]!=b[i]) return 0;
    return 1;
}

int main()
{
    while (scanf("%d%d",&n,&m)>-1)
    {
        char www;
        scanf("%c",&www);
        for (int i=1;i<=n;i++)
        {
            int j=1;
            while (scanf("%c",&q[i][j])>-1&&q[i][j]!='\n'){if (q[i][j]>='A'&&q[i][j]<='Z')q[i][j]=q[i][j]-'A'+'a';  j++;}
            q[i][0]=j;
            j=1;
            while (scanf("%c",&a[i][j])>-1&&a[i][j]!='\n')j++;
            a[i][0]=j;
        }
        while (m--)
        {
            int j=1;
            char ak[110];
            while (scanf("%c",&ak[j])>-1&&ak[j]!='\n') {if (ak[j]>='A'&&ak[j]<='Z')ak[j]=ak[j]-'A'+'a';  j++;}
            ak[0]=j;
            int flg=0;
            for (int i=1;i<=n;i++)
            {
                if (ifsame(q[i],ak))
                {
                    for (int k=1;k<=a[i][0];k++)
                        printf("%c",a[i][k]);
                    flg=1;
                }
            }
            if (flg==0) puts("What are you saying?");
        }
    }
    return 0;
}
