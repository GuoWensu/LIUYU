#include <stdio.h>
#include <stdlib.h>
int findMax(float value[],int state[],int n)//查找未拿进包中的物品中性价比最高的物品
{
    float max_value;
    int i,place;
    max_value=0;
    for(i=0; i<n; i++)
    {
        if(max_value<value[i]&&state[i]==0) //若其状态为1，表示该物品没被拿进包中，可以选择拿进包中
        {
            max_value=value[i];
            place=i;
        }
    }
    state[place]=1;//拿进包中，将其状态置为1
    return place;
}
int main()
{
    int n;
    int i;
    int left_weight,minWeight,Optimal_value=0;//包剩于容量，物品中质量最小的物品的重量
    float money[100],weight[100],value[100];//物品价值，质量，性价比
    int state[100]= {0};
    scanf("%d %d",&n,&left_weight);
    for(i=0; i<n; i++)
        scanf("%f",&money[i]);
    for(i=0; i<n; i++)
        scanf("%f",&weight[i]);
    for(i=0; i<n; i++)
        value[i]=money[i]/weight[i];
    minWeight=weight[0];
    for(i=1; i<n; i++)
    {
        if(minWeight>weight[i])
            minWeight=weight[i];
    }
    while(left_weight>minWeight)//使用贪心思想，不断寻找性价比最高的物品将其装进包里，当物品中的最小质量大于包的剩余质量时结束循环。
    {
        i=findMax(value,state,n);
        left_weight-=weight[i];
    }
    for(i=0;i<n;i++)
    {
        if(state[i]==1)
           Optimal_value+=money[i];
    }
    printf("Optimal value is\n%d\n",Optimal_value);
    for(i=0; i<n; i++)
        printf("%d ",state[i]);
    return 0;
}
