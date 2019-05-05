#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int map[50][50] = {0,};
int tmap[50][50] = {0,};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int tcase;
int n;
int m;
int k;


void dfs(int x, int y, int index)
{
    //범위를 넘어섰다면 나간다.
    if(x < 0 || x > n-1 || y < 0 || y > m-1)
        return;    

    //범위 내라면 확인해볼 가치가 있다.
    //만약 배추이면서 탐색한 구역이 아닐때
    if(map[y][x] == 1 && tmap[y][x] == 0)
    {
        tmap[y][x] = index;
        for(int i = 0; i < 4; ++i)
        {
            //상하좌우 4방향을 탐색한다.
            dfs(x+dx[i], y+dy[i], index);
        }
    }

}

void refreshMap()
{
    for(int i = 0; i < 50; ++i)
    {
        for(int j = 0; j < 50; ++j)
        {
            map[i][j] = tmap[i][j] = 0;
        }
    }
}

int main(int argc, char * argv[])
{
    freopen("input.txt", "r", stdin);
    cin>>tcase;

    for(int t = 0; t < tcase; ++t)
    {
        //맵 사이즈를 받고
        cin>>n;
        cin>>m;
        cin>>k;

        refreshMap();
        int index = 1;

        for(int i = 0; i < k; ++i)
        {
            int x, y;
            cin>>x;
            cin>>y;

            map[y][x] = 1;
        }

        //하나를 만나면 옆으로 퍼져나간다. check 배열이 필요할듯하다.
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                //배추면서 탐색안했을때
                if(map[i][j] == 1 && tmap[i][j] == 0)
                {
                    dfs(j, i, index);
                    ++index;
                }
            }
        }

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                cout<<tmap[i][j];
            }
            cout<<endl;
        }

        cout << index-1 <<endl;
    }

    return 0;
}