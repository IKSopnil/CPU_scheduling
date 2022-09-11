// Banker's Algorithm
#include <stdio.h>
int main()
{
 
 
    int n, m, i, j, k, allocation[10][10],max[10][10];
    printf("Number of processes: n");
    scanf("%d",&n);//n means process here
    printf("Number of resource: n");
    scanf("%d",&m);//m means resource here
 
    printf("enter allocation element=n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
scanf("%d",&allocation[i][j]);
}
}
   printf("enter the max element=n");
for(i=0;i<n;i++)
{
for(j=0;j<m;j++)
{
scanf("%d",&max[i][j]);
}
}
 
    int avail[10];
    printf("enter available 3 digit available value:");
    for(i=0;i<3;i++)
    scanf("%d",&avail[i]);
 
    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];
    }
    int y = 0;
    for (k = 0; k < 5; k++) {
        for (i = 0; i < n; i++) {
 
            if (f[i] == 0) {
               int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]){
                        flag = 1;
                         break;
                    }
                }
 
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] =avail[y]+ allocation[i][y];
                    f[i] = 1;
                }
            }
        }
    }
 
      int flag = 1;
 
      for(int i=0;i<n;i++)
    {
      if(f[i]==0)
      {
        flag=0;
         printf("The following system is not safe");
        break;
      }
    }
 
      if(flag==1)
    {
      printf("Following is the SAFE Sequencen");
      for (i = 0; i < n - 1; i++)
        printf(" P%d ->", ans[i]);
      printf(" P%d", ans[n - 1]);
    }
 
 
    return (0);
 
    
}
/*
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
 
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
*/