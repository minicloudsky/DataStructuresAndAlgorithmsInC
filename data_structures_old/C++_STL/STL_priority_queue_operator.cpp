#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<queue>
using namespace std;
struct Info
{
    string name;
    float score;
    bool operator < (const Info &a) const
    {
        //按照score右小到大排序，如果要有大到小，用>
        return a.score<score;
    }
};
int main()
{
    priority_queue<Info> pq;
    Info info;
    info.name = "Jack";
    info.score = 68.3;
    pq.push(info);
    info.name = "Bomi";
    info.score = 12.4;
    pq.push(info);
    info.name = "java";
    info.score = 90.7;
    pq.push(info);
    while(pq.empty()!=true)
    {
        cout<<pq.top().name<<" "<<pq.top().score<<endl;
        pq.pop();
    }
    cout<<endl;
    return 0;
}
