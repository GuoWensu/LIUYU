#include<iostream>
#include<algorithm>
using namespace std;

#define N 1000

struct goods{//定义物品
int m;						//物品数量 
int n;                     //物品属性个数					
float p[N];			//物品价值
int a[N][N];			//物品属性值
int con[N];				//每种属性的约束值
}goods;


     int i;                  //辅助变量        
     int x[N];			     //选取状态
     float cp;           //当前背包的最大价值
     float bestp;            //最大价值
     float now_add[N];		//当前所选物品的属性值总和



	int Constraint(int r){//声明约束函数
	int i;
	for(i=0;i<goods.n;i++)
	{
       if(goods.con[i]-(now_add[i]+goods.a[i][r])>0)
		  i++;
	   else
		   return 0;
	   }
	   return 1;//符合约束条件返回1
}


//回溯函数
int Backtrack(int r)
{
	//已搜索到根节点
	if (r >= goods.m) //如果搜索到叶子节点
	{   

		if (cp >= bestp)				//如果当前物品价值大于上一次的最优价值
		{   
			bestp = cp;    			//则当前背包总价值为最优价值

		}
		return 0;
	}
	//遍历左子树
      
		if ( Constraint(r)) 			//该物品满足约束条件，可以装入当前的背包
		{  
	
		for (i = 0; i < goods.n; i++)
		{
			now_add[i] = now_add[i] + goods.a[i][r];       //表示把该物品的属性项加到原本背包的属性中，当前属性值总和加上下一个属性值
		} 
		cp = cp+goods.p[r];   				//更新当前背包的最大价值 
		x[r]=1; //1表示装入背包
	

		Backtrack(r + 1);          // 探索下一结点


		for (i = 0; i < goods.n; i++) 				//回溯，进入右子树（进行剪枝）
		{
		now_add[i] =now_add[i] - goods.a[i][r];        //更新的属性和
		}
		cp = cp - goods.p[r];					//更新的价值和
		x[r]=0;
		
		}	
		Backtrack(r + 1);
		return 0;

}



void main()
{
	int i,j;
	cout<<"请输入物品的数量:";
     cin>>goods.m;

    cout<<"请输入物品属性的个数:";
         cin>>goods.n;
	
    cout<<"请输入每个物品的价值:";
	for (i = 0; i < goods.m; i++)
	{
		   cin>>goods.p[i];
			
	}
	
	
	cout<<"请输入物品属性值:"<<endl;
			for (i= 0; i < goods.n; i++)
			for (j = 0; j < goods.m; j++)
			{ cin>>goods.a[i][j];}	
	
	 cout<<"物品属性的约束值分别为:";
	for (i = 0; i < goods.n; i++)
		cin>>goods.con[i];		
	    Backtrack(0);

		printf("最优价值为：%f\n", bestp);
	

}
