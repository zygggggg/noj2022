#include <iostream>
#include <queue>

using namespace std;

int maze[10][10]; // �Թ���ͼ
int vis[10][10][10][10]; // �������飬��¼״̬�Ƿ��ѷ��ʹ�
int step[10][10][10][10]; // �������飬��¼ÿ��״̬�Ĳ���
struct Node {
    int px, py; // ��ҵ�����
    int bx, by; // ���ӵ�����
};
int tx, ty; // Ŀ��λ�õ�����
int walk[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // ���������ĸ�������ƶ�
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
            if (maze[i][j] == 4) { // �ҵ���ҵĳ�ʼλ��
                now.px = i;
                now.py = j;
                maze[i][j] = 0;
            }
            if (maze[i][j] == 3) { // �ҵ�Ŀ��λ��
                tx = i;
                ty = j;
                maze[i][j] = 0;
            }
            if (maze[i][j] == 2) { // �ҵ����ӵĳ�ʼλ��
                now.bx = i;
                now.by = j;
                maze[i][j] = 0;
            }
        }
    }
    vis[now.px][now.py][now.bx][now.by] = 1; // ��ǳ�ʼ״̬Ϊ�ѷ���
    q.push(now);
    while (!q.empty()) {
        now = q.front();
        q.pop();
        for (i = 0; i < 4; i++) { // �������������ĸ�������ƶ�
            next.px = now.px + walk[i][0];
            next.py = now.py + walk[i][1];
            next.bx = now.bx;
            next.by = now.by;
            if (next.px < 0 || next.px >= 10 || next.py < 0 || next.py >= 10) { // Խ��
                continue;
            } else if (vis[next.px][next.py][next.bx][next.by] == 1) { // �ظ�״̬
                continue;
            } else if (maze[next.px][next.py] == 1) { // ײǽ
                continue;
            } else if (maze[next.px][next.py] == 0 && (next.px != next.bx || next.py != next.by)) { // �ո�
                vis[next.px][next.py][next.bx][next.by] = 1; // ���״̬Ϊ�ѷ���
                step[next.px][next.py][next.bx][next.by] = step[now.px][now.py][now.bx][now.by] + 1; // ���²���
                q.push(next);
                continue;
            } else { // ����
                next.bx += walk[i][0];
                next.by += walk[i][1];
                if (next.bx < 0 || next.bx >= 10 || next.by < 0 || next.by >= 10) { // ����Խ��
                    continue;
                }
                if (vis[next.px][next.py][next.bx][next.by] == 1) { // �ظ�״̬
                    continue;
                }
                if (maze[next.bx][next.by] == 1) { // ײǽ
                    continue;
                }
                if (maze[next.bx][next.by] == 0) {
                    if (next.bx == tx && next.by == ty) { // �Ƶ�Ŀ��λ��
                        return step[now.px][now.py][now.bx][now.by] + 1; // ���ز���
                    }
                    vis[next.px][next.py][next.bx][next.by] = 1; // ���״̬Ϊ�ѷ���
                step[next.px][next.py][next.bx][next.by] = step[now.px][now.py][now.bx][now.by] + 1; // ���²���
                    q.push(next);
                }
            }
        }
    }
    return -1; // �޷�����Ŀ��λ��
}
int main() {
    input();
    cout << bfs() << endl; // ������ٵĲ���
}