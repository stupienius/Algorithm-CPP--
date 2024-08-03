#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// 定義邊的結構
struct Edge {
    int u, v;     // 邊的兩個端點
    int weight;   // 邊的權重
    int index;    // 邊在輸入中的原始索引

    // 重載小於運算符，用於排序
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// 並查集數據結構，用於檢測圖中的環
struct DisjointSet {
    vector<int> parent, rank;

    // 初始化並查集
    DisjointSet(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);  // 初始時每個元素的父節點是自己
    }

    // 查找元素所屬的集合（找到根節點）
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);  // 路徑壓縮
        }
        return parent[u];
    }

    // 合併兩個集合
    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            // 按秩合併
            if (rank[rootU] < rank[rootV]) {
                swap(rootU, rootV);
            }
            parent[rootV] = rootU;
            if (rank[rootU] == rank[rootV]) {
                rank[rootU]++;
            }
        }
    }
};

// Kruskal算法的變體，計算包含指定邊的最小生成樹權重和
int kruskal(int n, vector<Edge>& edges, const Edge& selectedEdge) {
    DisjointSet ds(n);
    int totalWeight = selectedEdge.weight;  // 初始權重為選定邊的權重
    ds.unite(selectedEdge.u, selectedEdge.v);  // 首先連接選定的邊

    for (const auto& edge : edges) {
        if (edge.index == selectedEdge.index) continue;  // 跳過選定的邊
        if (ds.find(edge.u) != ds.find(edge.v)) {  // 如果不會形成環
            ds.unite(edge.u, edge.v);  // 連接這條邊
            totalWeight += edge.weight;  // 加上這條邊的權重
        }
    }

    return totalWeight;
}

int main() {
    int n, m;
    cin >> n >> m;  // 讀取節點數和邊數

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        edges[i].u--; edges[i].v--;  // 轉換為0-based索引
        edges[i].index = i;  // 保存原始索引
    }

    // 按權重排序邊
    sort(edges.begin(), edges.end());

    vector<int> results(m);
    for (int i = 0; i < m; ++i) {
        const Edge& selectedEdge = edges[i];
        // 計算包含當前邊的最小生成樹權重和
        int totalWeight = kruskal(n, edges, selectedEdge);
        results[selectedEdge.index] = totalWeight;  // 保存結果
    }

    // 按原始順序輸出結果
    for (int result : results) {
        cout << result << '\n';
    }

    return 0;
}