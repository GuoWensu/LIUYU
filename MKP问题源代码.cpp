#include<iostream>
#include<algorithm>
using namespace std;

#define N 1000

struct goods{//������Ʒ
int m;						//��Ʒ���� 
int n;                     //��Ʒ���Ը���					
float p[N];			//��Ʒ��ֵ
int a[N][N];			//��Ʒ����ֵ
int con[N];				//ÿ�����Ե�Լ��ֵ
}goods;


     int i;                  //��������        
     int x[N];			     //ѡȡ״̬
     float cp;           //��ǰ����������ֵ
     float bestp;            //����ֵ
     float now_add[N];		//��ǰ��ѡ��Ʒ������ֵ�ܺ�



	int Constraint(int r){//����Լ������
	int i;
	for(i=0;i<goods.n;i++)
	{
       if(goods.con[i]-(now_add[i]+goods.a[i][r])>0)
		  i++;
	   else
		   return 0;
	   }
	   return 1;//����Լ����������1
}


//���ݺ���
int Backtrack(int r)
{
	//�����������ڵ�
	if (r >= goods.m) //���������Ҷ�ӽڵ�
	{   

		if (cp >= bestp)				//�����ǰ��Ʒ��ֵ������һ�ε����ż�ֵ
		{   
			bestp = cp;    			//��ǰ�����ܼ�ֵΪ���ż�ֵ

		}
		return 0;
	}
	//����������
      
		if ( Constraint(r)) 			//����Ʒ����Լ������������װ�뵱ǰ�ı���
		{  
	
		for (i = 0; i < goods.n; i++)
		{
			now_add[i] = now_add[i] + goods.a[i][r];       //��ʾ�Ѹ���Ʒ��������ӵ�ԭ�������������У���ǰ����ֵ�ܺͼ�����һ������ֵ
		} 
		cp = cp+goods.p[r];   				//���µ�ǰ����������ֵ 
		x[r]=1; //1��ʾװ�뱳��
	

		Backtrack(r + 1);          // ̽����һ���


		for (i = 0; i < goods.n; i++) 				//���ݣ����������������м�֦��
		{
		now_add[i] =now_add[i] - goods.a[i][r];        //���µ����Ժ�
		}
		cp = cp - goods.p[r];					//���µļ�ֵ��
		x[r]=0;
		
		}	
		Backtrack(r + 1);
		return 0;

}



void main()
{
	int i,j;
	cout<<"��������Ʒ������:";
     cin>>goods.m;

    cout<<"��������Ʒ���Եĸ���:";
         cin>>goods.n;
	
    cout<<"������ÿ����Ʒ�ļ�ֵ:";
	for (i = 0; i < goods.m; i++)
	{
		   cin>>goods.p[i];
			
	}
	
	
	cout<<"��������Ʒ����ֵ:"<<endl;
			for (i= 0; i < goods.n; i++)
			for (j = 0; j < goods.m; j++)
			{ cin>>goods.a[i][j];}	
	
	 cout<<"��Ʒ���Ե�Լ��ֵ�ֱ�Ϊ:";
	for (i = 0; i < goods.n; i++)
		cin>>goods.con[i];		
	    Backtrack(0);

		printf("���ż�ֵΪ��%f\n", bestp);
	

}
