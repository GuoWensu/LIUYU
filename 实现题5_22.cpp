#include <stdio.h>
#include <stdlib.h>
int findMax(float value[],int state[],int n)//����δ�ý����е���Ʒ���Լ۱���ߵ���Ʒ
{
    float max_value;
    int i,place;
    max_value=0;
    for(i=0; i<n; i++)
    {
        if(max_value<value[i]&&state[i]==0) //����״̬Ϊ1����ʾ����Ʒû���ý����У�����ѡ���ý�����
        {
            max_value=value[i];
            place=i;
        }
    }
    state[place]=1;//�ý����У�����״̬��Ϊ1
    return place;
}
int main()
{
    int n;
    int i;
    int left_weight,minWeight,Optimal_value=0;//��ʣ����������Ʒ��������С����Ʒ������
    float money[100],weight[100],value[100];//��Ʒ��ֵ���������Լ۱�
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
    while(left_weight>minWeight)//ʹ��̰��˼�룬����Ѱ���Լ۱���ߵ���Ʒ����װ���������Ʒ�е���С�������ڰ���ʣ������ʱ����ѭ����
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
