#include<stdio.h> 
#include<conio.h> 
#include<stdlib.h> 
 
int  find(int v, int p[100]) 
{ 
while(p[v]!=v)  v=p[v];  
return  v; 
} 
 
void kruskal( int cost[100][100], int n) 
{ 
 	int  i,j,k,u,v,sum,t[100][2],p[100],mincost,count; 
 	count=0; k=0; 
sum=0; 
 	 
 	for(i=0;i<n;i++) 
 	{ 	 
 	 	p[i]=i; 
 	} 
 	 
while(count<n-1) 
{ 
mincost=999; 
for(i=0;i<n;i++) 
{ 
for(j=0;j<n;j++) 
{ if((cost[i][j]!=0) && (cost[i][j]<mincost)) 
{ 
mincost=cost[i][j]; u=i; 
v=j; 
}  
} 
} 
 
if(mincost==999) 
	 	break; 
i=find(u,p); j=find(v,p);  if(i!=j) 
{ 
 	t[k][0]=u;  	t[k][1] =v; 
	 	k++; 
 	count=count+1;  	sum=sum+mincost;  	if(i<j) 
 	 	p[j]=i;  	else 
	 	 	p[i]=i; 
} 
cost[u][v]=cost[v][u]=999; 
} 
if(count==n-1) 
 	{ 
printf("\nThe  edges  of  Minimum  Cost  Spanning  Tree  are\n\n"); 
 	 	for(i=0;i<n-1;i++) 
 	 	{ printf("\n%d  ->%d  ",t[k][0],t[k][1]); 
 	 	} 
	 	printf("\n\tMinimum  cost  =  %d\n",sum); 
 	} 
 	else 
	 	printf("\nSpanning tree does not exists"); 
} 
 
void  main() 
{ int i,j,cost[100][100],n; 
clrscr(); 
 
printf("\n\n\tImplementation  of  Kruskal's  algorithm\n\n"); printf("\nEnter  the  no.  of  vertices\n"); 
scanf("%d",&n); 
printf("\nEnter  the  cost  adjacency  matrix\n"); for(i=0;i<n;i++) 
{ 
for(j=0;j<n;j++) 
{ scanf("%d",&cost[i][j]);  
} 
} 
 
Kruskal(cost,n); 
getch(); 
} 
