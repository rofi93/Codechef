#include<cstdio>
#include<set>
using namespace std;
int main()
{
    int i,t,n,x;
    set<int> a;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            a.insert(x);
        }
        printf("%d\n",a.size());
        a.clear();
    }
    return 0;
}
