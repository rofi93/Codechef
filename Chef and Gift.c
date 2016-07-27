#include<stdio.h>
#include<math.h>
int main()
{
    int a[50],n,k,i,j,count,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&k);
        count=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]%2==0)
                count++;
        }
        if(count<k)
        {
            printf("NO\n");
            continue;
        }
        for(i=0;;i++)
        {
            if(j==n)
                break;
            count=0;
            for(j=i;j<i+k;j++)
            {
                if(a[j]%2==0)
                    count++;
                else
                    break;
            }
            if(count==k)
                break;
        }
        if(count==k)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
