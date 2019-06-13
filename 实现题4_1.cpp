/*4-1会场安排问题

问题描述:假设在足够多的会场里安排一批活动，并希望使用尽可能少的会场。设计一个有效的贪心算法进行安排。（这个问题实际上是著名的图着色问题。
         若将每一个活动作为图的一个顶点，不相容活动间用边相连。使相邻顶点有不同颜色的最小着色数，相当于要找的最小会场数）。

算法设计:对于给定的k个待安排的活动，计算使用最少会场的时间表。

数据输入:由文件input.txt给出输入数据。第1行有一个正整数k,表示有k个待安排的活动。
         接下来的k行中，每行有两个正整数，分别表示k个待安排的活动的开始时间和结束时间。时间以0点开始的分钟计。

结果输出:将计算的最少会场数输出到文件output.txt

输出文件示例  输入文件示例
Input.txt     output.txt
5                3
1  23
12 28
25 35
27 80
36 50


具体的思路是：看一活动的开始时间是否大于某一会场的结束时间，
如果是就加入该会场中，并更新该会场的结束时间，（如果有多个会场选择的话，就选最优的那一个，即结束时间最小的),
如果所有的会场都不满足，则再新增一个会场，把该活动的结束时间赋予这个新增的会场。*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point
{
    int t;//t是时间
    bool f;//true表示活动开始,false标志活动结束时间
};

bool cmp(point x,point y)//比较时间点的大小，x<y为真
{
    return x.t<y.t;
}

int greedy(vector<point> x)
{
    int max=0,cur=0,n=x.size();
    sort(x.begin(),x.end(),cmp);//从小到大排序一下各个活动时间点,排序规则是cmp
    for(int i=0;i<n;i++)
    {
        if(x[i].f) 
            cur++;//开始时间
        else
            cur--;//结束时间
        if((i==n-1 || x[i].t<x[i+1].t) && cur>max)//处理x[i]==x[i+1]的情况
            max=cur;                              //当cur>max且x[i]==x[i+1]时，i时间肯定是开始时间，i+1时间可能是开始时间，也可能是结束时间
    }                                              //如果是结束时间，说明某活动开始时间和结束时间相同，不需要会场，故不对max更新;如果是开始时间，那在i+1次更新max效果一样
    return max;                                   //因此i次不进行更新
}

int main()
{
    vector<point> x;//x作为容器
    int n,i;//n表示会场，i表示第i个会场
    point temp;
    while(cin>>n,n)//输入n，且n不等于0
    {
        for(i=0;i<n;i++)//排序，开始时间越早排在越前面
        {
            temp.f=true;
            cin>>temp.t;
            x.push_back(temp);//活动开始时间，标志temp.f为true,进入容器
            temp.f=false;
            cin>>temp.t;
            x.push_back(temp);//活动结束时间，标志temp.f为false,进入容器
        }
        cout<<greedy(x)<<endl;
        x.clear();
    }
    return 0;
}
//算法的时间复杂度： 设有 n 个活动，使用了k（k<=n）个会场，则时间复杂度为 O（n（k+nlogn））