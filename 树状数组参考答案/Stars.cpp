#include<stdio.h>
#include<string.h>
const int N=1003;
int c[N+5][N+5], flag[N+5][N+5], n, m;
int lowbit(int x)
{
	return x&(-x);
}
void update(int x,int y,int v)
{
	int i, j;
	for(i=x; i<=N; i+=lowbit(i))
	{
		for(j=y; j<=N; j+=lowbit(j))
		{
			c[i][j] += v;
		}
	}
}

int sum(int x, int y)
{
    int res=0,i,j;
    for(i=x; i; i-=lowbit(i))
	{
		for(j=y; j; j-=lowbit(j))
		{
			res += c[i][j];
		}
	}
	return res;
}

int main()
{
	int x1,x2,y1,y2;
	while(scanf("%d",&m)!=EOF)
	{
	    memset(c,0,sizeof(c));
	    memset(flag,0,sizeof(flag));//标记有没有开灯 
	    while(m--)
        {
            char s[2];
            scanf("%s",s);
            if(s[0]=='Q')
            {
                scanf("%d %d %d %d",&x1,&x2,&y1,&y2);
                x1++;y1++;x2++;y2++;
                if(x1>x2) {int temp=x1;x1=x2;x2=temp;}//确保x1<x2 
                if(y1>y2) {int temp=y1;y1=y2;y2=temp;}
                int ans=sum(x2,y2)-sum(x2,y1-1)-sum(x1-1,y2)+sum(x1-1,y1-1);
                printf("%d\n",ans);
            }
            else if(s[0]=='B')
            {
                scanf("%d %d",&x1,&y1);
                x1++;y1++;
                if(flag[x1][y1]==1) continue;
                flag[x1][y1]=1;
                update(x1,y1,1);
            }
            else
                {
                   scanf("%d %d",&x1,&y1);
                   x1++;y1++;
                   if(flag[x1][y1]==0) continue;
                   flag[x1][y1]=0;
                   update(x1,y1,-1);
                }
        }
	}
	return 0;
}
