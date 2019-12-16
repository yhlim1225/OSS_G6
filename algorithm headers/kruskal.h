#include <iostream>
#include <vector>
#include <algorithm>
#include<tuple>

template <typename T>
class Node {
private:
	T data;
	Node* next;
	Node* parent;
	size_t rank = 0;
public:
	Node() {
		T data = {};
		Node* next = nullptr;
		Node* parent = nullptr;
	}

	Node(T data) {
		this->data = data;
	}

	Node(T data, Node* next) {
		this->data = data;
		this->next = next;
	}

	Node(T data, Node* next, Node* parent) {
		this->data = data;
		this->next = next;
		this->parent = parent;
	}

	T GetData() {
		return data;
	}

	Node* GetNext() {
		return next;
	}

	Node* GetParent() {
		return parent;
	}

	size_t GetRank() {
		return rank;
	}

	void setData(T data) {
		this->data = data;
	}

	void SetNext(Node* next) {
		this->next = next;
	}

	void SetParent(Node* parent) {
		this->parent = parent;
	}

	void SetRank(size_t rank) {
		this->rank = rank;
	}

	void IncRank() {
		this->rank++;
	}
};
template <typename T>
class LinkedList {
private:
	Node<T>* head;
	Node<T>* tail;
public:
	LinkedList() {
		head = nullptr;
		tail = nullptr;
	}

	void InsertToBack(T data) {
		if (head == nullptr) {
			head = tail = new Node<T>(data);
			head->SetParent(head);

			return;
		}

		Node<T>* newNode = new Node<T>(data, nullptr, head);
		tail->SetNext(newNode);
		tail = newNode;
	}

	Node<T>* GetHead() {
		return head;
	}

	Node<T>* GetTail() {
		return tail;
	}
};
template <typename T>
class DisjointSet {
public:
	std::vector<LinkedList<T>*> sets;
	DisjointSet() {
		sets = {};
	}
	void MakeSet(T data) {
		LinkedList<T>* newSLL = new LinkedList<T>();
		newSLL->InsertToBack(data);
		sets.push_back(newSLL);
	}

	Node<T>* FindSet(Node<T>* d) {
		while (d != d->GetParent()) {
			d = d->GetParent();
		}
		return d;
	}

	void Union(Node<T>* x, Node<T>* y) {
		Link(FindSet(x), FindSet(y));
	}

	void Link(Node<T>* x, Node<T>* y) {
		if (x->GetRank() > y->GetRank()) {
			y->SetParent(x);
		}
		else {
			x->SetParent(y);
			if (x->GetRank() == y->GetRank())
				y->GetParent()->IncRank();
		}
	}

};
class Graph {
public:
	int N;
	std::vector<std::vector<std::tuple<int, int, int>>> adjList;
	Graph(int N) {
		adjList = {};
		this->N = N;
		for (int i = 0; i < N; i++) {
			std::vector<std::tuple<int, int, int>> a = {};
			adjList.push_back(a);
		}
	}

	void add_edge(int src, int dest, int weight) {
		adjList[src].push_back(std::make_tuple(src, dest, weight));
		adjList[dest].push_back(std::make_tuple(dest, src, weight));
	}


	void printList() { //print matrix
		int len = adjList.size();
		std::cout << "Listed as: --Index: Weight--" << std::endl;
		for (int i = 0; i < len; i++) {
			std::cout << "Adj List for: " << i << "|   ";
			int len2 = adjList[i].size();
			for (int j = 0; j < len2; j++) {
				std::cout << (std::get<1>)(adjList[i][j]) << ":" << (std::get<2>)(adjList[i][j]) << ", ";
			}
			std::cout << std::endl;
		}
	}

};



void KruskalMST(Graph* G) {
	Graph* MST = new Graph(G->N);
	DisjointSet<int>* djs = new DisjointSet<int>();
	DisjointSet<int>* aux_djs = new DisjointSet<int>();
	int size = G->N;
	for (int i = 0; i < size; i++) {
		djs->MakeSet(i);
	}
	std::vector<std::tuple<int, int, int>> aux = {};
	// O(E)
	for (int i = 0; i < size; i++) {
		int len2 = G->adjList[i].size();
		for (int j = 0; j < len2; j++) {
			aux.push_back((G->adjList[i][j]));
		}
	}
	//O(ElgE)
	std::sort(begin(aux), end(aux), [](auto const& t1, auto const& t2) {
		return std::get<2>(t1) < std::get<2>(t2);
		});
	// src,dest,weight
	// add src, dest, remove from need to add
	int aux_length = aux.size();
	for (int i = 0; i < aux_length; i++) {
		int src = std::get<0>(aux[i]);
		int dest = std::get<1>(aux[i]);
		int weight = std::get<2>(aux[i]);
		Node<int>* srcNode = (djs->sets[src])->GetHead();
		Node<int>* destNode = djs->sets[dest]->GetHead();

		if (djs->FindSet(srcNode) != djs->FindSet(destNode)) {
			MST->add_edge(src, dest, weight);
			djs->Union(srcNode, destNode);
		}
	}

	MST->printList();
}
