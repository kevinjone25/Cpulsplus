/* UVA11244 Counting Stars */

#include <bits/stdc++.h>

using namespace std;

const int DN = 8;
const int drow[] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dcol[] = {-1, 0, 1, -1, 1, -1, 0, 1};

const int N =101 - 1;
char grid[N + 2][N + 2];

int main()
{
    int r, c;
    while(~scanf("%d%d", &r, &c) && ( r || c)) {
        memset(grid, 0, sizeof(grid));

        for(int i = 1; i <= r; i++)
            scanf("%s", grid[i] + 1);

        int cnt = 0;
        for(int i = 1; i <= r; i++)
            for(int j = 1; j <= c; j++)
                if(grid[i][j] == '*') {
                    int flag = 1;
                    for(int k = 0; k < DN; k++)
                        if(grid[i + drow[k]][j + dcol[k]] == '*') {
                            flag = 0;
                            break;
                        }
                    cnt += flag;
                }
        printf("%d\n", cnt);
    }

    return 0;
}
