#include <iostream>
#include <queue>

using namespace std;

int maze[10][10]; // 迷宫地图
int vis[10][10][10][10]; // 访问数组，记录状态是否已访问过
int step[10][10][10][10]; // 步数数组，记录每个状态的步数
struct Node {
    int px, py; // 玩家的坐标
    int bx, by; // 箱子的坐标
};
int tx, ty; // 目标位置的坐标
int walk[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 上下左右四个方向的移动
void input() {
    int i, j;
    char c;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            cin >> c;
            maze[i][j] = c - '0';
        }
    }
}
int bfs() {
    int i, j;
    queue<Node> q;
    Node now, next;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (maze[i][j] == 4) { // 找到玩家的初始位置
                now.px = i;
                now.py = j;
                maze[i][j] = 0;
            }
            if (maze[i][j] == 3) { // 找到目标位置
                tx = i;
                ty = j;
                maze[i][j] = 0;
            }
            if (maze[i][j] == 2) { // 找到箱子的初始位置
                now.bx = i;
                now.by = j;
                maze[i][j] = 0;
            }
        }
    }
    vis[now.px][now.py][now.bx][now.by] = 1; // 标记初始状态为已访问
    q.push(now);
    while (!q.empty()) {
        now = q.front();
        q.pop();
        for (i = 0; i < 4; i++) { // 尝试上下左右四个方向的移动
            next.px = now.px + walk[i][0];
            next.py = now.py + walk[i][1];
            next.bx = now.bx;
            next.by = now.by;
            if (next.px < 0 || next.px >= 10 || next.py < 0 || next.py >= 10) { // 越界
                continue;
            } else if (vis[next.px][next.py][next.bx][next.by] == 1) { // 重复状态
                continue;
            } else if (maze[next.px][next.py] == 1) { // 撞墙
                continue;
            } else if (maze[next.px][next.py] == 0 && (next.px != next.bx || next.py != next.by)) { // 空格
                vis[next.px][next.py][next.bx][next.by] = 1; // 标记状态为已访问
                step[next.px][next.py][next.bx][next.by] = step[now.px][now.py][now.bx][now.by] + 1; // 更新步数
                q.push(next);
                continue;
            } else { // 箱子
                next.bx += walk[i][0];
                next.by += walk[i][1];
                if (next.bx < 0 || next.bx >= 10 || next.by < 0 || next.by >= 10) { // 箱子越界
                    continue;
                }
                if (vis[next.px][next.py][next.bx][next.by] == 1) { // 重复状态
                    continue;
                }
                if (maze[next.bx][next.by] == 1) { // 撞墙
                    continue;
                }
                if (maze[next.bx][next.by] == 0) {
                    if (next.bx == tx && next.by == ty) { // 推到目标位置
                        return step[now.px][now.py][now.bx][now.by] + 1; // 返回步数
                    }
                    vis[next.px][next.py][next.bx][next.by] = 1; // 标记状态为已访问
                step[next.px][next.py][next.bx][next.by] = step[now.px][now.py][now.bx][now.by] + 1; // 更新步数
                    q.push(next);
                }
            }
        }
    }
    return -1; // 无法到达目标位置
}
int main() {
    input();
    cout << bfs() << endl; // 输出最少的步数
}