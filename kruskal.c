#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


void kruskal(int cost[25][25],int n);
int find(int v,int p[]);

void main()
{
    int cost[25][25],n,i,j,u,v,t[25][25],mincost;
    printf("Enter no. of vertices\n");
    scanf("%d",&n);
    printf("enterb");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }
    kruskal(cost,n);
    getch();
}


int find(int v,int p[])
{
    while (p[v]!=v)
    {
        v=p[v];
    }
    return v;
}

void kruskal(int cost[25][25],int n)
{
    int i,j,p[25],k,sum=0,count=0;
    for(i=0;i<n;i++)
    {
        p[i]=i;
    }
    while(count<=n-1)
    {
        mincost=999;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(cost[i][j]=0 && cost[i][j]<mincost)
                {
                    mincost=cost[i][j];
                    u=i;v=j;
                }
            }
        }
        if(mincost==999)
            break;
        i=find(u,p);
        j=find(v,p);
        if(i!=j)
        {
            t[k][0]=u;
            t[k][1]=v;
            k++;count++;
            sum=sum+mincost;
            if(i<j)
                p[j]=i;
            else
                p[i]=j;
            cost[u][v]=cost[v][u]=999;
        }
    } 
    if(count==n-1)
    {
        printf("Minimal spannning tree exists is\n");
        for(i=0;i<n-1;i++)
        {
            printf("%d--->%d",t[i][0],t[i][1]);
        }
        printf("The cost is %d\n",sum);
    }     
    else
    {
        printf("Minimal spanning tree doesn't exists");
    } 
}