#include<iostream>
#include<cstdio>
int d[100005],n;
int lowbit(int x){
	return x&(-x);
}
int sum(int x){//��ѯ 
	int res=0;
	while(x){
		res+=d[x];
		x-=lowbit(x);
	}
	return res;
}

void update(int x,int v){//��a[x]�ϼ�v������ 
	while(x<=n){
		d[x]+=v;
		x+=lowbit(x);  
	}
}
int main()
{
	return 0;
}
