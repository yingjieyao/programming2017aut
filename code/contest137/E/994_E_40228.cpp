#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
struct point
{
    int x,y,step;
}arr[10001];
int main()
{
    int x,t,hd,tl,ss,i,n,m,j,p,q;
    int flag[101][101];
    char s[101][101];
    scanf("%d",&t);
    for(x=0;x<t;++x)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<n;++i)
        {
            scanf("%s",s[i]);
        }
        memset(flag,0,sizeof(flag));
        int count=0;
        for(i=0;i<n;++i)
        {
            for(j=0;j<m;++j)
            {
                if(s[i][j]=='@' && !flag[i][j])
                {   count++;
                    flag[i][j]=1;
                    hd=tl=ss=0;
                    arr[0].x=i;
                    arr[0].y=j;
                    arr[0].step=0;
                    while(hd<=tl)
                    {
                        while(arr[hd].step==ss)
                        {
                            p=arr[hd].x+1,q=arr[hd].y;
                            if(p>=0 && p<n && q>=0 && q<m && s[p][q]=='@' && !flag[p][q]) //flag?
                            {
                                tl++;
                                arr[tl].x=p;
                                arr[tl].y=q;
                                arr[tl].step=ss+1;
                                flag[p][q]=1;
                            }
                            p=arr[hd].x-1,q=arr[hd].y;
                            if(p>=0 && p<n && q>=0 && q<m && s[p][q]=='@' && !flag[p][q]) //flag?
                            {
                                tl++;
                                arr[tl].x=p;
                                arr[tl].y=q;
                                arr[tl].step=ss+1;
                                flag[p][q]=1;
                            }
                            p=arr[hd].x,q=arr[hd].y+1;
                            if(p>=0 && p<n && q>=0 && q<m && s[p][q]=='@' && !flag[p][q]) //flag?
                            {
                                tl++;
                                arr[tl].x=p;
                                arr[tl].y=q;
                                arr[tl].step=ss+1;
                                flag[p][q]=1;
                            }
                            p=arr[hd].x,q=arr[hd].y-1;
                            if(p>=0 && p<n && q>=0 && q<m && s[p][q]=='@' && !flag[p][q]) //flag?
                            {
                                tl++;
                                arr[tl].x=p;
                                arr[tl].y=q;
                                arr[tl].step=ss+1;
                                flag[p][q]=1;
                            }
                            hd++;
                            if(hd>tl) break;
                        }
                        ss++;
                    }
                }
            }
        }
        memset(flag,0,sizeof(flag));
        int count2=0;
        for(i=0;i<n;++i)
        {
            for(j=0;j<m;++j)
            {
                if(s[i][j]=='@' && !flag[i][j])
                {   count2++;
                    flag[i][j]=1;
                    hd=tl=ss=0;
                    arr[0].x=i;
                    arr[0].y=j;
                    arr[0].step=0;
                    while(hd<=tl)
                    {
                        while(arr[hd].step==ss)
                        {
                            p=arr[hd].x+1,q=arr[hd].y;
                            if(p>=0 && p<n && q>=0 && q<m && s[p][q]=='@' && !flag[p][q]) //flag?
                            {
                                tl++;
                                arr[tl].x=p;
                                arr[tl].y=q;
                                arr[tl].step=ss+1;
                                flag[p][q]=1;
                            }
                            p=arr[hd].x-1,q=arr[hd].y;
                            if(p>=0 && p<n && q>=0 && q<m && s[p][q]=='@' && !flag[p][q]) //flag?
                            {
                                tl++;
                                arr[tl].x=p;
                                arr[tl].y=q;
                                arr[tl].step=ss+1;
                                flag[p][q]=1;
                            }
                            p=arr[hd].x,q=arr[hd].y+1;
                            if(p>=0 && p<n && q>=0 && q<m && s[p][q]=='@' && !flag[p][q]) //flag?
                            {
                                tl++;
                                arr[tl].x=p;
                                arr[tl].y=q;
                                arr[tl].step=ss+1;
                                flag[p][q]=1;
                            }
                            p=arr[hd].x,q=arr[hd].y-1;
                            if(p>=0 && p<n && q>=0 && q<m && s[p][q]=='@' && !flag[p][q]) //flag?
                            {
                                tl++;
                                arr[tl].x=p;
                                arr[tl].y=q;
                                arr[tl].step=ss+1;
                                flag[p][q]=1;
                            }
                            p=arr[hd].x+1,q=arr[hd].y+1;
                            if(p>=0 && p<n && q>=0 && q<m && s[p][q]=='@' && !flag[p][q]) //flag?
                            {
                                tl++;
                                arr[tl].x=p;
                                arr[tl].y=q;
                                arr[tl].step=ss+1;
                                flag[p][q]=1;
                            }
                            p=arr[hd].x+1,q=arr[hd].y-1;
                            if(p>=0 && p<n && q>=0 && q<m && s[p][q]=='@' && !flag[p][q]) //flag?
                            {
                                tl++;
                                arr[tl].x=p;
                                arr[tl].y=q;
                                arr[tl].step=ss+1;
                                flag[p][q]=1;
                            }
                            p=arr[hd].x-1,q=arr[hd].y+1;
                            if(p>=0 && p<n && q>=0 && q<m && s[p][q]=='@' && !flag[p][q]) //flag?
                            {
                                tl++;
                                arr[tl].x=p;
                                arr[tl].y=q;
                                arr[tl].step=ss+1;
                                flag[p][q]=1;
                            }
                            p=arr[hd].x-1,q=arr[hd].y-1;
                            if(p>=0 && p<n && q>=0 && q<m && s[p][q]=='@' && !flag[p][q]) //flag?
                            {
                                tl++;
                                arr[tl].x=p;
                                arr[tl].y=q;
                                arr[tl].step=ss+1;
                                flag[p][q]=1;
                            }
                            hd++;
                            if(hd>tl) break;
                        }
                        ss++;
                    }
                }
            }
        }
        printf("%d %d\n",count,count2);
    }
    return 0;
}
