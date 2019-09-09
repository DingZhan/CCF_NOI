#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX_N 202

//�����㷨ֻʹ����̰�ģ����г�ʱ���⣬��Ϊһ���޽⣬���ܾ��п�����ѭ��
bool A2B(int A, int B, int N, int steps[], int &count)
{
    bool bSucc=false;
    count = 0;
    while(A!=B)
    {
        if(A<B)
        {
            if(A+steps[A]<=N)
                A+=steps[A];
            else
            {
                A-=steps[A];
                if(A<0)
                    break;
            }
        }
        else if(A>B)
        {
            if(A-steps[A]>=1)
                A-=steps[A];
            else
            {
                if(A+steps[A]>N)
                    break;
                A+=steps[A];
            }
        }
        ++count;
    }
    if(A==B)
        bSucc = true;
    return bSucc;
}

//̰��+����
bool A2B2(int A, int B, int N, int steps[], int &count)
{
    if(A==B)
        return true;
    else if(A<=0||A>N)
        return false;

    ++count;
    if(A2B2(A+steps[A], B, N, steps, count))
        return true;
    --count;

    ++count;
    if(A2B2(A-steps[A], B, N, steps, count))
        return true;
    --count;
    return false;
}

//Ӧ����ͼ�Ŀ��������������BFS,ԭ����A��Ŀ�����B,Ӧ�����ȹ���ͼgraph[MAX_N][MAX_N]
//��ĿҪ����̾���ʵ���Ͼ��Ǵ�A��B�����·��
//��Floyd�㷨��,��ֻ����60��,���������Ҫ������ͼ������ͼ��������ͼ
int dis[MAX_N][MAX_N];
#define INFINITE 10000000
int Floyd(int A, int B, int N, int steps[])
{
    if(A==B)
        return 0;
    int i,j, k;
    //��������(���ּ䣩����ͨͼ
    for(i=1; i<=N; ++i)
    {
        for(j=1; j<=N; ++j)
            dis[i][j] = INFINITE;
    }
    for(i=1; i<=N; ++i)
    {
        if(i+steps[i]>=1 && i+steps[i]<=N)
        {
            dis[i][i+steps[i]] = 1;
            //��仰�������������⣬��Ϊ���ͼ��������ͼ
            //dis[i+steps[i]][i] = 1;
        }
        if(i-steps[i]>=1 && i-steps[i]<=N)
        {
            dis[i][i-steps[i]] = 1;
            //��仰�������������⣬��Ϊ���ͼ��������ͼ
//            dis[i-steps[i]][i] = 1;
        }
    }
    for(k=1; k<=N; ++k)
    {
        for(i=1; i<=N; ++i)
        {
            if(i==k)
                continue;
            if(dis[i][k]==INFINITE)
                continue;
            for(j=1; j<=N; ++j)
            {
                if(j==k || j==i)
                    continue;
                if(dis[k][j]==INFINITE)
                    continue;
                if(dis[i][k]+dis[k][j]<dis[i][j])
                {
                    dis[i][j] = dis[i][k]+dis[k][j];
                    //dis[j][i] = dis[i][j];
                }
            }
        }
    }
    return dis[A][B];
}

//������ͼ�Ŀ����������BFS���ԣ�һ��ͨ��
int BFS(int A, int B, int N, int steps[])
{
    if(A==B)
        return 0;
    //�ڵ�[1,N]�ķ��ʱ��λ�����һ���ڵ��Ѿ������ʹ��ˣ���Ҫ����ӵ�����������ȥ
    bool bTakens[MAX_N] = {false};
    //�������У�������pair��ʾ������Ԫ�ص�������¥��ID+�������
    queue<pair<int, int> > seeds;
    //���ӽڵ���¥��id+�������
    pair<int, int> seed; //value--depth
    int next, id, depth;
    //�Ƿ��ҵ��˵���B��·��
    bool bSucc=false;

    //���������һ��ʼA��B����ȣ�����Ҫ�����ݣ����Է���0
    if(A==B)
        return 0;

    //���������ʱ��
    bTakens[A] = true;
    //�����������
    seed.first = A;
    seed.second = 0; //��ʼ�������Ϊ0
    //�����A�ӵ���������
    seeds.push(seed);

    //�����Ӷ��зǿ�
    while(!seeds.empty())
    {
        //�Ӷ���ǰ�ε���һ������
        seed = seeds.front();
        seeds.pop();
        //��ǰ���ӵ�¥��id�ͷ������
        id = seed.first;
        depth = seed.second;

        //���ϰ����ݺ��¥��
        next = id+steps[id];
        //����ܵ���B�����ҵ��˷���
        if(next==B)
        {
            bSucc=true;
            //�ۼ�һ�ε�������
            ++depth;
            break;
        }
        //�������¥����Ч����δ�����ʹ������ȱ�����
        if(next>=1 && next<=N && bTakens[next]==false)
        {
            //���÷��ʱ��
            bTakens[next]=true;
            //��������¥���
            seed.first = next;
            //���÷������
            seed.second = depth+1;
            //��ӵ����Ӷ���
            seeds.push(seed);
        }

        //���°����ݺ��¥��
        next = id-steps[id];
        //����ܵ���B�����ҵ��˷���
        if(next==B)
        {
            bSucc=true;
            //�ۼ�һ�ε�������
            ++depth;
            break;
        }
        //�������¥����Ч����δ�����ʹ������ȱ�����
        if(next>=1 && next<=N && bTakens[next]==false)
        {
            //���÷��ʱ��
            bTakens[next]=true;
            //��������¥���
            seed.first = next;
            //���÷������
            seed.second = depth+1;
            //��ӵ����Ӷ���
            seeds.push(seed);
        }
    }
    //����ɹ�����B��������������
    if(bSucc)
        return depth;
    else//���򷵻�һ�������ֵ
        return INFINITE;
}


int main ()
{
    int N, A, B, i;
    int steps[MAX_N], count=0;

    cin>>N>>A>>B;
    for(i=1; i<=N; ++i)
        cin>>steps[i];

        /*
    if(A2B2(A, B, N, steps, count))
        cout<<count<<endl;
    else
        cout<<"-1"<<endl;
        */
    count = Floyd(A, B, N, steps);
//    count = BFS(A, B, N, steps);
    if(count!=INFINITE)
        cout<<count<<endl;
    else
        cout<<"-1"<<endl;
}


