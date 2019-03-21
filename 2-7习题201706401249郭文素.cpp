#include<stdio.h> //编译预处理命令,用来提供程序要求的信息
int f(int n,int m)//n代表元素个数，m代表子集个数
{
     if(m==1||n==m)
        return 1;
    else
        return f(n-1,m-1)+f(n-1,m)*m;
	//函数递归调用
	//若不符合以上情况，则有以下情况：
	//情况一：在n-1个元素划分成的m-1个集合里添加一个由一个元素形成的独立的集合
	//情况二：在n-1个元素划分成的m个集合里面添加一个新的元素。
}
 
int main() 
{
    int n;
    while(scanf("%d",&n)==1&&n>=1)
    {
        int i;
        int sum=0;
        for(i=1;i<=n;i++)//此程序的时间复杂度为O(n)
        {
            sum+=f(n,i); //表示sum=sum+f(n,i),此处是调用f（）函数
        }
        printf("%d\n",sum);
    }
    return 0;
}