#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

int a[10005][1005];
int n;

void del(int i)
{
    int j;
    for(j=1; j<=n; j++)
    {
        if(a[i][j]==1)
        {
            a[i][j]=0;
            a[j][i]=0;
            del(j);
        }
    }
}

int allempty()
{
    int i,j;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            if(a[i][j]==1) return 0;
    return 1;
}

int main()
{
    int i,j,k,l,m;
    int ans;
    int q,w;
    int p;

    int N;
    cin>>N;
    while(N--)
    {
        cin>>n>>m;
        ans=1;

        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
                a[i][j]=0;
            a[i][i]=1;
        }

        /*for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
                printf("%d ",a[i][j]);
            printf("\n");
        }*/
        for(i=1; i<=m; i++)
        {
            cin>>q>>w;
            a[q][w]=1;
            a[w][q]=1;

        }

            for(i=1; i<=n; i++)
            {
                for(j=1; j<=n; j++)
                {
                    if(a[i][j]==1)
                    {
                        del(i);
                        ans++;
                        /*for(p=1; p<=n; p++)
                        {
                            for(q=1; q<=n; q++)
                                printf("%d ",a[p][q]);
                            printf("\n");
                        }*/
                    }
                }
            }
        cout<<ans-1<<"\n";
    }


}
