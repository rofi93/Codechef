/* -------------------------------- */
/* Name: MD. Khairul Basar          */
/* Institute: HSTU                  */
/* Dept: CSE                        */
/* Email: khairul.basar93@gmail.com */
/* -------------------------------- */

#include<cmath>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>

#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<sstream>
#include<utility>
#include<iostream>
#include<algorithm>

#include<bits/stdc++.h>
/* all header files included */

#define LL long long

#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)

#define pii pair<int,int>

#define nl printf("\n")
/* defining macros */

using namespace std;

int main()
{
    int t,n,k,i,j,count,x,index[50];
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        j=0;
        memset(index,0,50);
        for(i=1; i<=n; i++)
        {
            cin>>x;
            if(x%2==0)
            {
                index[j++]=i;
            }
        }
        if(k>0)
        {
            if(j>=k)
                printf("YES\n");
            else
                printf("NO\n");
        }
        else
        {
            if(j==n)
                printf("No\n");
            else
                printf("YES\n");
        }
    }
    return 0;
}
