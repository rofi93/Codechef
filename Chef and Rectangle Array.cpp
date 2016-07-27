/* -------------------------------- */
/* Name: MD. Khairul Basar          */
/* Institute: HSTU                  */
/* Dept: CSE                        */
/* Email: khairul.basar93@gmail.com */
/* -------------------------------- */

#include <bits/stdc++.h>
/* all header files included */

#define fs            first
#define sc            second
#define sp            printf(" ")
#define nl            printf("\n")
#define pb(a)         push_back(a)
#define mp(a,b)       make_pair(a,b)

#define setzero(a)    memset(a,0,sizeof(a))
#define setneg(a)     memset(a,-1,sizeof(a))
#define setinf(a)     memset(a,126,sizeof(a))

#define tc1(x)        printf("Case %d: ",x)
#define tc2(x)        printf("Case #%d: ",x)
#define tc3(x)        printf("Case %d:\n",x)
#define tc4(x)        printf("Case #%d:\n",x)

#define pr1(x)        cout<<x<<"\n"
#define pr2(x,y)      cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z)    cout<<x<<" "<<y<<" "<<z<<"\n"
#define pr4(w,x,y,z)  cout<<w<<" "<<x<<" "<<y<<" "<<z<<"\n"
#define fast          ios::sync_with_stdio(0)
#define read          freopen("input.txt","r",stdin)
#define write         freopen("output.txt","w",stdout)
#define prflag1(flag) printf("%s\n",(flag)?"YES":"NO")
#define prflag2(flag) printf("%s\n",(flag)?"Yes":"No")
#define prflag3(flag) printf("%s\n",(flag)?"yes":"no")
#define _max(a,b)     ((a>b)?a:b)
#define _min(a,b)     ((a<b)?a:b)
/* defining macros */

using namespace std;

template <class T> inline T bigmod(T b, T p, T m)
{
    T ret;
    if(p==0) return 1;
    if(p&1)
    {
        ret=(bigmod(b,p/2,m)%m);
        return ((b%m)*ret*ret)%m;
    }
    else
    {
        ret=(bigmod(b,p/2,m)%m);
        return (ret*ret)%m;
    }
}
/* template functions */

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int>pii;
typedef pair<LL, LL>pll;
typedef vector<int>vi;
typedef vector<LL>vll;
typedef vector<pii>vpii;
typedef vector<pll>vpll;
/* type definition */

int dx4[]= {1,-1,0,0};
int dy4[]= {0,0,1,-1};
int dx6[]= {0,0,1,-1,0,0};
int dy6[]= {1,-1,0,0,0,0};
int dz6[]= {0,0,0,0,1,-1};
int dx8[]= {1,-1,0,0,-1,1,-1,1};
int dy8[]= {0,0,1,-1,1,1,-1,-1};
int dkx8[]= {-1,1,-1,1,-2,-2,2,2};
int dky8[]= {2,2,-2,-2,1,-1,1,-1};
/* direction array */

int tc=1;
const double eps=1e-9;
const double pi=acos(-1.0);
const long long int mx=1e3;
const long long int mod=1e9+7;
/* global declaration */

int x[mx+5][mx+5],L[mx+5],R[mx+5],row[mx+5][mx+5],col[mx+5][mx+5],cum[mx+5][mx+5];

int main()
{
    int n,m,i,j,k,q,a,b,lmx,rmx,sum,total,ans,cntl,cntr;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        setzero(cum);
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                scanf("%d",&x[i][j]);
                cum[i][j]=cum[i][j-1]+cum[i-1][j]+x[i][j]-cum[i-1][j-1];
            }
        }
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d %d",&a,&b);
            for(i=1; i<=n; i++)
            {
                cntl=0;
                cntr=m%b;
                lmx=rmx=INT_MIN;
                for(j=1,k=m; j<=m; j++,k--)
                {
                    if(cntr==0) rmx=INT_MIN,cntr=b;
                    cntr--;

                    rmx=max(rmx,x[i][k]);
                    lmx=max(lmx,x[i][j]);

                    L[j]=lmx;
                    R[k]=rmx;

                    cntl++;
                    if(cntl==b) lmx=INT_MIN,cntl=0;
                }
                for(j=1; j<=m-b+1; j++)
                {
                    row[i][j]=max(R[j],L[j+b-1]);
                }
            }
            for(i=1; i<=m-b+1; i++)
            {
                cntl=0;
                cntr=n%a;
                lmx=rmx=INT_MIN;
                for(j=1,k=n; j<=n; j++,k--)
                {
                    if(cntr==0) rmx=INT_MIN,cntr=a;
                    cntr--;

                    rmx=max(rmx,row[k][i]);
                    lmx=max(lmx,row[j][i]);

                    L[j]=lmx;
                    R[k]=rmx;

                    cntl++;
                    if(cntl==a) lmx=INT_MIN,cntl=0;
                }
                for(j=1; j<=n-a+1; j++)
                {
                    col[j][i]=max(R[j],L[j+a-1]);
                }
            }
            ans=INT_MAX;
            for(i=1; i<=n-a+1; i++)
            {
                for(j=1; j<=m-b+1; j++)
                {
                    sum=cum[i+a-1][j+b-1]-cum[i+a-1][j-1]-cum[i-1][j+b-1]+cum[i-1][j-1];
                    total=col[i][j]*a*b;
                    ans=min(ans,total-sum);
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
