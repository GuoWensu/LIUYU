#include<stdio.h>
int n,m,d; 
int value[100][100],weight[100][100];
int best[100]={0};//���ѡ�񷽰�
int min=1000000;//��С���� 
int b[100]={0};//��ǰ��ѡ�񷽰� 
int cur_weight=0;//��ǰ������ 
int cur_value=0;//��ǰ�ܼ�ֵ 
void traceback(int num)
{
    int i;
    if(num==n) { 
        if(cur_weight<min) {
            min=cur_weight; //������С���� 
            for(i=0;i<n;i++)
                best[i]=b[i]+1;//�������ѡ�񷽰��������0��ʼ�����Ҫ��1  
        }
        return ;
    }
    for(i=0;i<m;i++) { //��m����Ӧ�̿ɹ�ѡ��
        b[num]=i;
        cur_weight+=weight[num][i];
        cur_value+=value[num][i];
        if(cur_weight<min && cur_value<=d) //�Ⱥű���� 
            traceback(num+1);
        cur_weight-=weight[num][i];
        cur_value-=value[num][i];
        b[num]=0;
    }
}

int main()
{
    int i,j;
    scanf("%d%d%d",&n,&m,&d);
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            scanf("%d",&value[i][j]);
        }
    }
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            scanf("%d",&weight[i][j]);
        }
    }
    traceback(0);
    printf("the min weight is %d\n",min);
    for(i=0;i<n;i++) {
        printf("%d ",best[i]);
    }
    printf("\n");
    return 0;
} 
