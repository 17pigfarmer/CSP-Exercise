#include <vector>
#include <queue>

using namespace std;
const int INF = 10000000;



struct Node {
	int v;
	int dis;
	Node(int x, int y) :v(x), dis(y) {}
	bool operator < (const Node & a) const//因为STL库函数优先队列的需要，必须重载运算符，规定优先级顺序
	{
		if (dis == a.dis) return v < a.v;
		else return dis > a.dis;
	}

};

void Dijkstra(int n, int s, vector<vector<Node>> Adj, vector<bool>& vis, vector<int> &d) {
	fill(d.begin(), d.end(), INF);
	fill(vis.begin(), vis.end(), false);
	d[s] = 0;
	for (int i = 0; i < n; i++) {
		int u = -1;
		int MIN = INF;
		for (int j = 0; j < n; j++) {
			if (d[j] < MIN&&vis[j] == false) {
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1) {
			return;
		}
		vis[u] = true;
		for (int j = 0; j < (int)Adj[u].size(); j++) {
			int v = Adj[u][j].v;
			if (vis[v] == false && d[v] > d[u] + Adj[u][j].dis) {
				d[v] = d[u] + Adj[u][j].dis;
			}
		}
	}
}

void Dijkstra2( int s, vector<vector<Node>> Adj, vector<int> &d)
{
	fill(d.begin(), d.end(), INF);
	d[s] = 0;
	priority_queue<Node> q;//定义一个优先队列
	q.push(Node(s, d[s]));
	while (!q.empty())
	{
		Node x = q.top();//取出头节点，也就是距离起点最近的结点
		q.pop();
		for (int i = 0; i < (int)Adj[x.v].size(); i++)//循环头节点能够到达的所有节点
		{
			Node y = Adj[x.v][i];
			if (d[y.v] > x.dis + y.dis)//如果这个结点到起点的距离大于头节点到起点的距离加上头节点到这个结点的距离
			{
				d[y.v] = x.dis + y.dis;//更新数据
				q.push(Node(y.v, d[y.v]));
			}
		}
	}
}

void DFS( int s, vector<vector<Node>> Adj, vector<bool>& vis) {
	vis[s] = true;
	

	if (false) {
		return;
	}

	for (int i = 0; i < Adj[s].size(); i++) {
		if (vis[Adj[s][i].v] != true) {
			
			DFS( Adj[s][i].v, Adj, vis);
		}

	}
	return;
	
}



int main() {
	vector<vector<Node>> Adj;
	vector<Node> temp;

	temp.push_back(Node(1, 2));
	temp.push_back(Node(2, 4));
	temp.push_back(Node(3, 7));
	Adj.push_back(temp);
	temp.clear();
	temp.push_back(Node(0, 2));
	temp.push_back(Node(4, 2));
	temp.push_back(Node(2, 1));
	Adj.push_back(temp);
	temp.clear();
	temp.push_back(Node(0, 4));
	temp.push_back(Node(1, 1));
	temp.push_back(Node(4, 6));
	temp.push_back(Node(3, 1));
	Adj.push_back(temp);
	temp.clear();
	temp.push_back(Node(2, 1));
	temp.push_back(Node(0,7));
	Adj.push_back(temp);
	temp.clear();
	temp.push_back(Node(1, 2));
	temp.push_back(Node(2, 6));
	Adj.push_back(temp);
	vector<int> d;
	d.resize(5);
	fill(d.begin(), d.end(), 0);
	vector<bool> vis;
	vis.resize(5);
	//Dijkstra(5,0, Adj,vis, d);
	//Dijkstra2( 0, Adj, d);
	DFS( 0, Adj, vis);
	return 0;
}