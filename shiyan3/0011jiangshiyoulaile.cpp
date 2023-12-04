#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
 
struct rec {
	int x, y;
	int useful;
	int time;
};
queue <rec> q;
rec st, ed, chomper;
int m, n, t, p, more;
int visited[201][201];
char maze[200][200];
 
int dx[4] = {0, 0, -1, 1};
 
int dy[4] = {-1, 1, 0, 0};
 
void init() {
	cin >> m >> n >> t >> p;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> maze[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (maze[i][j] == '!') {
				st.x = i, st.y = j;
			}
			if (maze[i][j] == '@') {
				chomper.x = i, chomper.y = j;
			}
			if (maze[i][j] == '+') {
				ed.x = i, ed.y = j;
			}
		}
	}
	st.time = 0;
}
 /*
 struct rec {
	int x, y;
	int useful;
	int time;
};
 */
rec moveto(rec now, int i) {
	rec next;
	next.x = now.x + dx[i];
	next.y = now.y + dy[i];
	if (next.x >= m || next.x < 0 || next.y >= n || next.y < 0 || maze[next.x][next.y] == '#') { //位置不合法
		next.useful = false;
		return next;
	}
	next.useful = true;
	return next;
}
 
int bfs1() {
	q.push(st);
	while (q.size()) {
		rec now = q.front();
		if (now.x == chomper.x && now.y == chomper.y && now.time >= t) {
			return -1;
		}
		if (now.time > p) {
			return -1;
		}
		if (now.x == ed.x && now.y == ed.y) {
			return now.time;
		}
		if (now.x == chomper.x && now.y == chomper.y) {
			more = now.time;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			rec next = moveto(now, i);
			if (next.useful == true && !visited[next.x][next.y]) {
				visited[next.x][next.y] = 1;
				next.time = now.time + 1;
				q.push(next);
			}
		}
	}
	return -1;
}
 
int bfs2() {
	q.push(st);
	while (q.size()) {
		rec now = q.front();
		if (now.x == ed.x && now.y == ed.y) {
			return now.time;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			rec next = moveto(now, i);
			if (next.useful == true && !visited[next.x][next.y] && maze[next.x][next.y] != '@') {
				visited[next.x][next.y] = 1;
				next.time = now.time + 1;
				q.push(next);
			}
		}
	}
	return -1;
}
 
 
 
int main() {
	init();
	int ans1 = bfs1();
	memset(visited, 0, sizeof(visited));
	while (q.size()) {
		q.pop();
	}
	int ans2 = bfs2();
	if (ans2 != -1 && ans1 != -1) {
		cout << min(ans2, ans1 + more) << endl;
	} else if (ans2 == -1 && ans1 != -1) {
		cout << ans1 + more << endl;
	} else if (ans1 == -1 && ans2 != -1) {
		cout << ans2 << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}