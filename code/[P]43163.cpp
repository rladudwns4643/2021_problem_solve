#include <string>
#include <vector>
#include <map>
#include <list>
#include <queue>

using namespace std;

map<string, int> visit;

int bfs(map<string, list<string>> graph, string begin, string target) {
	int answer = 0;
	queue<string> q;
	q.push(begin);
	visit[begin] = 0;

	while (!q.empty()) {
		string t = q.front();
		q.pop();
		int d = visit[t];
		for (const string& i : graph[t]) {
			if (i == target) {
				answer = d + 1;
				return answer;
			}
			if (visit[i] == -1) {
				visit[i] = d + 1;
				q.push(i);
			}
		}
	}
	return 0;
}

bool check(const string& l, const string& r) {
	int n = l.size();
	int cnt{ 0 };
	for (int i = 0; i < l.size(); ++i) {
		if (l[i] != r[i]) ++cnt;
	}
	return cnt == 1 ? true : false;
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	visit[begin] = -1;
	visit[target] = -1;
	for (const auto& i : words) visit[i] = -1;

	map<string, list<string>> graph;
	graph[begin] = list<string>();
	for (const auto& i : words) graph[i] = list<string>();
	for (const auto& i : graph) {
		for (const auto& j : graph) {
			if (check(i.first, j.first)) {
				graph[i.first].push_back(j.first);
			}
		}
	}

	return bfs(graph, begin, target);
}