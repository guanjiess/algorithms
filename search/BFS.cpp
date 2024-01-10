#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct node{
    int x, y;
    int step;
} Node;

const int maxn = 100;
bool in_que[maxn][maxn] = {false};
int x_side[4] = {0, 0, -1, 1};
int y_side[4] = {1, -1, 0, 0};

bool judge(char** maze, int m, int n, node way)
{
    int x = way.x, y = way.y;
    bool is_valid = true;
    if(x >= n || x < 0 || y >= n || y < 0) return false;
    if(in_que[x][y]) return false;
    if(maze[x][y] == '*') return false;
    return true;
}

int BFS(char** maze, node start, node dest)
{
    queue<node> q;
    int ans = 0;
    q.push(start);
    in_que[start.x][start.y] = true;

    while (!q.empty()) {
        node top = q.front();
        q.pop();
        if(maze[top.x][top.y] == 'T'){
            return top.step;
        }
        for (int i = 0; i < 4; i++) {
            struct node surrouding_way;
            int new_x = top.x + x_side[i];
            int new_y = top.y + y_side[i];
            surrouding_way.x = new_x; 
            surrouding_way.y = new_y;

            bool is_valid = judge(maze, 5, 5, surrouding_way);
            if (is_valid) {
                surrouding_way.step = top.step + 1;
                q.push(surrouding_way);
                ans++;
                in_que[surrouding_way.x][surrouding_way.y] = true;
            }            
        }
    }    

    return ans;
}

void print2Darray(char** arr, int rows, int columns)
{
    for (int row_i = 0; row_i < rows; row_i++) {
        for (int col = 0; col < columns; col ++) {
            printf("%c ", arr[row_i][col]);
        }
        printf("\n");
    }
}

const char MAZE[5][5] = {
    {'.', '.', '.', '.', '.'},
    {'.', '*', '.', '*', '.'},
    {'.', '*', 'S', '*', '.'},
    {'.', '*', '*', '*', '.'},
    {'.', '.', '.', 'T', '.'}
    };

int main()
{
    int m, n;
    while (scanf("%d%d", &m, &n), m != 0){
        char** maze = new char*[m];
        for (int i = 0; i < m; i ++) {
            maze[i] = new char[n];
        }
        for (int i = 0; i < m; i++) {
            // filter the \n at the end of each line.
            for (int j = 0; j < n; j++) {
                //scanf("%c", maze[i]+j);
                maze[i][j] = MAZE[i][j];
            }
            maze[i][n] = '\0';
        }

        struct node start, dest;
        start.x = 2, start.y = 2, start.step = 0;
        dest.x = 4, dest.y = 3;
        int steps = BFS(maze, start, dest);

        print2Darray(maze, m, n); 
        printf("%d\n", steps);

        for (int i = 0; i < m; i++) {
            delete [] maze[i];
        }
        delete [] maze;
        // for test
        break;
    }

    //BFS();
    return 0;
}