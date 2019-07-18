/*5-24一般解空间搜索问题

问题描述：试设计一个用回溯法搜索一般解空间的函数。该函数的参数包括:生成解空间中下一扩展结点的函数、 结点可行性判定函数和
          上界函数等必要的函数，并将此函数用于解图的 m 着色问题。

          图的 m 着色问题描述如下:给定无向连通图 G 和 m 种不同的颜色。用这些颜色为图 G 的各顶点着色，每个顶点着一种颜色。
		  如果有一种着色法使 G 中每条边的 2 个顶点着不同颜色，则称这个图是 m 可着色的。图的 m 着色问题是对于给定图 G 和 m 种颜色，
		  找出所有不同的着色法。

算法设计：对于给定的无向连通图 G 和 m 种不同的颜色，编程计算图的所有不同的着色法。

数据输入：第 1 行有 3 个正整数 n，k 和 m，表示给定的图 G 有 n个顶点和 k 条边，m 种颜色。顶点编号为 1，2，…，n。接下来的 k 行中，
          每行有 2 个正整 数 u,v，表示图 G 的一条边(u,v)。*/
#include <iostream>
using namespace std;
 
class Color
{
    friend int mColoring(int,int,int**);
    private:
        bool ok(int k);
        void backtrack(int t);
        int n,          // 图的顶点数
            m,          // 可用颜色数
            **a,        // 图的邻接矩阵
            *x,         // 当前解
            sum;        // 当前已找到的可m着色方案数
};
 
bool Color::ok(int k)
{
    // 检查结点k颜色可用性
    for (int j=1; j<k; j++)
    {
        if ((a[k][j]==1)&&(x[j]==x[k]))//判断顶点k和j之间没有边并且顶点k和顶点j所着颜色是否相同
            return false;
    }
    return true;
}
 
/* 回溯法 子集树 */
void Color::backtrack(int t)//函数backtrack搜索第i层的子树
{
    if (t>n) // 当t>n时，算法搜索至叶结点，得到新的m着色方案，当前找到的可m着色方案数sum加1搜索到叶子结点
    {
        sum++;
        for (int i=1; i<=n; i++)
        {
            cout << x[i] << " ";//输出顶点i所着的颜色x[i]
        }
        cout << endl;
    }
    else    //当t<=N时，当前扩展结点是解空间中的内部顶点。该节点有x[i]=1,2,...,m,共m个儿子结点。
    {       //对当前扩展结点的每一个儿子结点，有函数ok检查其可行性，并以深度优先的方法递归的对可行树搜索，或剪去不可行子树
        for (int i=1; i<=m; i++)
        {
            x[t] = i;
            if (ok(t))//判断顶点是否可着颜色t
            {
                backtrack(t+1);//给顶点t+1查找可着的颜色
            }
            x[t] = 0;//当图中所有顶点都找到自己的可着颜色后，依次将x[n]、x[n-1]、...、x[1]置0
        }
    }
}
 
int mColoring(int n, int m, int** a)
{
    Color C;
    // 初始化C
    C.n = n;
    C.m = m;
    C.a = a;
    C.sum = 0;
    int *x = new int[n+1];
    for (int i=0; i<=n; i++)
    {
        x[i] = 0;
    }
    C.x = x;
    C.backtrack(1);
    delete []x;
    return C.sum;
}
 
void main()
{
    int e,m,n,u,v;
 
    int** a = new int*[100];
    for(int k=0; k<100; k++)
    {
        a[k] = new int[100];
    }
 
    while(1)
    {
        cout << "输入顶点数n、边数e和着色数m:" << endl;
        cin >> n >> e >> m;
        cout << "请输入无向图的边（如边(1,2)则输入1 2）:" << endl;
        for (int i=0; i<e; i++)
        {
            cin >> u >> v;
            a[u][v] = 1;
            a[v][u] = 1;
        }
        cout << "可行的着色法:" << endl;
        int sum = mColoring(n,m,a);
        cout << "总共有" << sum << "种着色法" << endl;
    }
}