#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
struct mmp{
    int x,y;
};

queue <mmp> dqs;
char mapp[105][105];
int vis[105][105];
int way1_x[4]={1,-1,0,0};
int way1_y[4]={0,0,1,-1};
int way2_x[8]={1,-1,0,0,1,1,-1,-1};
int way2_y[8]={0,0,1,-1,1,-1,1,-1};

int n,m;
int ans1,ans2;

void bfs1(int x,int y)
{
    if(mapp[x][y]=='#'||vis[x][y]) return;
    while(!dqs.empty()) dqs.pop();
    vis[x][y]=1;
    mmp start;
    start.x=x;start.y=y;
    dqs.push(start);
    while(!dqs.empty()){
        mmp cur=dqs.front();
        dqs.pop();
        for(int i=0;i<4;i++)
        {
            int xx=cur.x+way1_x[i],yy=cur.y+way1_y[i];
            if(xx>=0&&xx<n&&yy>=0&&yy<m&&mapp[xx][yy]!='#'&&vis[xx][yy]==0)
            {
                mmp next;
                next.x=xx;next.y=yy;
                vis[xx][yy]=1;
                dqs.push(next);
            }
        }
    }
    ans1++;
}

void bfs2(int x,int y)
{
    if(mapp[x][y]=='#'||vis[x][y]) return;
    while(!dqs.empty()) dqs.pop();
    vis[x][y]=1;
    mmp start;
    start.x=x;start.y=y;
    dqs.push(start);
    while(!dqs.empty()){
        mmp cur=dqs.front();
        dqs.pop();
        for(int i=0;i<8;i++)
        {
            int xx=cur.x+way2_x[i],yy=cur.y+way2_y[i];
            if(xx>=0&&xx<n&&yy>=0&&yy<m&&mapp[xx][yy]=='@'&&vis[xx][yy]==0)
            {
                mmp next;
                next.x=xx;next.y=yy;
                vis[xx][yy]=1;
                dqs.push(next);
            }
        }
    }
    ans2++;
}

int main(){
    //freopen("text.txt","r",stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) scanf("%s",mapp[i]);
        ans1=0;
        ans2=0;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bfs1(i,j);
            }
        }
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bfs2(i,j);
            }
        }
        printf("%d %d\n",ans1,ans2);
    }
}
