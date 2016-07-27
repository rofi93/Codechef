#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    long int n,m,q,i,ans;
    while(scanf("%ld %ld",&n,&m)!=EOF)
    {
        for(i=0;i<m;i++)
        {
            scanf("%ld",&q);
            ans=0;
            if(q<=n+1)
            {
                ans=0;
                printf("%ld\n",ans);
            }
            else if(q>n+1 && q<=(2*n)+1)
            {
                ans=q-(n+1);
                printf("%ld\n",ans);
            }
            else
            {
                ans=(3*n)-(q-1);
                printf("%ld\n",ans);
            }
        }
    }
    return 0;
}
