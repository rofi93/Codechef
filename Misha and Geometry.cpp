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

#define pr1(x)        cout<<x<<"\n"
#define pr2(x,y)      cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z)    cout<<x<<" "<<y<<" "<<z<<"\n"
#define pr4(w,x,y,z)  cout<<w<<" "<<x<<" "<<y<<" "<<z<<"\n"
/* defining macros */

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int>pii;
typedef pair<LL, LL>pll;
typedef vector<int>vi;
typedef vector<LL>vll;
typedef vector<pii>vpii;
typedef vector<pll>vpll;
/* type definition */

int tc=1;
const double eps=1e-9;
const double pi=acos(-1.0);
const long long int mx=1e5;
const long long int mod=1e9+7;
/* global declaration */
using namespace std;


struct Point
{
    LL x;
    LL y;
};
vector<Point>points;
Point p0;

Point nextToTop(stack<Point> &st)
{
    Point p,res;

    p=st.top();
    st.pop();
    res=st.top();
    st.push(p);

    return res;
}

LL swap(Point &p1, Point &p2)
{
    Point p = p1;
    p1 = p2;
    p2 = p;
}

LL dist(Point p1, Point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

LL orientation(Point p1, Point p2, Point p3)
{
    LL val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);

    if (val==0) return 0;
    return (val > 0) ? 1 : 2;
}

int compare(const void *vp1, const void *vp2)
{
    Point *p1 = (Point *) vp1;
    Point *p2 = (Point *) vp2;

    int o = orientation(p0, *p1, *p2);
    if (o == 0) return (dist(p0, *p2) >= dist(p0, *p1)) ? -1 : 1;
    return (o == 2) ? -1 : 1;

}

double convexHull(void)
{
    vector<Point>vp;

    if(points.size()<3) return 0.0;

    LL ymin = INT_MAX, min=-1, n=points.size(),i,y;

    for (i = 0; i < n; i++)
    {
        y = points[i].y;
        if ((y < ymin) || (ymin == y && points[i].x < points[min].x)) ymin = points[i].y, min = i;
    }

    swap(points[0], points[min]);
    p0 = points[0];

    qsort(&points[1], n - 1, sizeof(Point), compare);
    stack<Point>S;

    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    for (i = 3; i < n; i++)
    {
        while(S.size()>1 && orientation(nextToTop(S), S.top(), points[i]) != 2) S.pop();
        S.push(points[i]);
    }

    double area=0.0;
    Point first,prev,next;
    first=S.top();
    while(S.size()>1)
    {
        prev=S.top();
        S.pop();
        next=S.top();
        area+=prev.x*next.y-prev.y*next.x;
    }
    area+=next.x*first.y-next.y*first.x;

    return area;
}

int main()
{
    double area;
    LL n,q,t,i,k;
    char ch[5];
    Point pp;
    cin>>t;
    while(t--)
    {
        if(points.size()) points.clear();
        scanf("%lld",&q);
        while(q--)
        {
            scanf("%s %lld %lld",ch,&pp.x,&pp.y);
            vector<Point>vvvv;
            if(ch[0]=='+')
            {
                points.pb(pp);
            }
            else
            {
                for(i=0; i<points.size(); i++)
                {
                    if(points[i].x==pp.x && points[i].y==pp.y)
                    {
                        points.erase(points.begin()+i);
                        break;
                    }
                }
            }
            area=convexHull();
            area=fabs(area);
            printf("%.1lf\n",area/2.0);
        }
    }
    return 0;
}
