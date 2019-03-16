#include <vector>
#include <queue>

using namespace std;
const int INF = 10000000;



struct Node {
	int v;
	int dis;
	Node(int x, int y) :v(x), dis(y) {}
	bool operator < (const Node & a) const//��ΪSTL�⺯�����ȶ��е���Ҫ������������������涨���ȼ�˳��
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
	priority_queue<Node> q;//����һ�����ȶ���
	q.push(Node(s, d[s]));
	while (!q.empty())
	{
		Node x = q.top();//ȡ��ͷ�ڵ㣬Ҳ���Ǿ����������Ľ��
		q.pop();
		for (int i = 0; i < (int)Adj[x.v].size(); i++)//ѭ��ͷ�ڵ��ܹ���������нڵ�
		{
			Node y = Adj[x.v][i];
			if (d[y.v] > x.dis + y.dis)//��������㵽���ľ������ͷ�ڵ㵽���ľ������ͷ�ڵ㵽������ľ���
			{
				d[y.v] = x.dis + y.dis;//��������
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