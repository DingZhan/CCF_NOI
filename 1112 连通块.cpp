#include <iostream>
#include <queue>

#define MAX_N 103

using namespace std;

int main()
{
    int i, j, n, m, value, domain=0;
    bool graph[MAX_N][MAX_N]={{false}};
    bool takens[MAX_N][MAX_N]={{false}};
    queue<pair<int, int> > seeds;
    pair<int, int> seed;

    cin>>n>>m;
    for(i=1; i<=n; ++i)
    {
        for(j=1; j<=m; ++j)
        {
            cin>>value;
            graph[i][j] = (value?true:false);
        }
    }
    //BFS: breadth first search
    for(i=1; i<=n; ++i)
    {
        for(j=1; j<=m; ++j)
        {
            if(takens[i][j] || !graph[i][j])
                continue;
            takens[i][j] = true;
            seeds.push(std::make_pair(i, j));
            while(!seeds.empty())
            {
                seed = seeds.front();
                seeds.pop();
                //up
                if(graph[seed.first-1][seed.second] && !takens[seed.first-1][seed.second])
                {
                    takens[seed.first-1][seed.second] = true;
                    seeds.push(std::make_pair(seed.first-1, seed.second));
                }
                //down
                if(graph[seed.first+1][seed.second] && !takens[seed.first+1][seed.second])
                {
                    takens[seed.first+1][seed.second] = true;
                    seeds.push(std::make_pair(seed.first+1, seed.second));
                }
                //left
                if(graph[seed.first][seed.second-1] && !takens[seed.first][seed.second-1])
                {
                    takens[seed.first][seed.second-1] = true;
                    seeds.push(std::make_pair(seed.first, seed.second-1));
                }
                //right
                if(graph[seed.first][seed.second+1] && !takens[seed.first][seed.second+1])
                {
                    takens[seed.first][seed.second+1] = true;
                    seeds.push(std::make_pair(seed.first, seed.second+1));
                }
            }
            ++domain;
        }
    }

    cout<<domain<<endl;
    return 0;
}
