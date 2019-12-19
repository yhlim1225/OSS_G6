#include <iostream>
#include <string>
using namespace std;


class NodeType {
public:
	int info;
	NodeType* link;
};

class LinkedList {

public:
	NodeType* head;

	LinkedList() {
		this->head = NULL;
	}

	~LinkedList() {
		NodeType* current = this->head;
		while (current != NULL) {
			current = current->link;
			delete head;
			head = current;
		}
	}

	void insertAtBeginning(int input) {
		NodeType* newNode = new NodeType;
		newNode->info = input;
		newNode->link = head;
		head = newNode;

	}

	void deleteItem(int value) {

		NodeType* prev = NULL, * toDelete = head;

		while (toDelete != NULL) {
			prev = toDelete;
			toDelete = toDelete->link;

			if (prev->info == value) {
				if (prev->info == head->info) {
					head = toDelete->link;
					delete toDelete;
					break;
				}
				else {
					prev->link = toDelete->link;
					delete toDelete;
					break;
				}
			}
		}
	}
};


class Queue {
	NodeType* queueFront; //queue’s first node (head) 
	NodeType* queueRear; //queue’s last node (tail) 

public:
	//constructor
	Queue() {
		this->queueFront = NULL;
		this->queueRear = NULL;
	}

	//destructor
	~Queue() {
		NodeType* current = queueFront;
		while (current != NULL) {
			current = current->link;
			delete queueFront;
			queueFront = current;
		}
	}

	//adds new node to the end of the queue
	void addQueue(int  elem) {
		NodeType* newNode = new NodeType;
		newNode->info = elem;

		if (queueFront == NULL) {
			newNode->link = queueRear;
			queueFront = newNode;
			queueRear = newNode;
		}
		else {
			newNode->link = queueRear->link;
			queueRear->link = newNode;
			queueRear = newNode;
		}
	}

	//deletes the first node and returns its info 
	int deleteQueue() {
		if (queueFront == NULL) {
			cout << "The queue is empty.";
			abort();
		}

		NodeType* tobedeleted = queueFront;
		queueFront = tobedeleted->link;
		int temp = tobedeleted->info;
		delete tobedeleted;

		return temp;
	}

	bool isEmpty() {
		if (queueFront == NULL) {
			return true;
		}
		else {
			return false;
		}
	}

	void printQ() {
		NodeType* current = queueFront;

		while (current != NULL) {
			if (current->link != NULL) {
				cout << current->info << " , ";
				current = current->link;
			}
			else {
				cout << current->info << endl;
				break;
			}
		}
	}
};

class AGraph {

public:
	int numOfVertices;
	LinkedList* Arr_ll;
	int* Arr_deg;

	AGraph(int numOfVertices) {
		if (numOfVertices <= 0) {
			cout << "Invalid value !";
			abort();
		}

		this->numOfVertices = numOfVertices;
		this->Arr_ll = new LinkedList[numOfVertices];
		this->Arr_deg = new int[numOfVertices];
	}

	~AGraph() {
		for (int i = 0; i < numOfVertices; i++) {
			Arr_ll[i].~LinkedList();
		}
		delete[]Arr_ll;
		delete[]Arr_deg;
	}

	void addDirectedEdge(int u, int v) {
		if (u <= 0 || u > numOfVertices || v <= 0 || v > numOfVertices) {
			cout << "Inserted value out of boundary !";
			abort();
		}

		this->Arr_ll[u - 1].insertAtBeginning(v);
	}

	void addUndirectedEdge(int u, int v) {
		if (u <= 0 || u > numOfVertices || v <= 0 || v > numOfVertices) {
			cout << "Inserted value out of boundary !";
			abort();
		}

		this->Arr_ll[u - 1].insertAtBeginning(v);
		this->Arr_ll[v - 1].insertAtBeginning(u);
	}

	void removeDirectedEdge(int u, int v) {
		this->Arr_ll[u - 1].deleteItem(v);
		cout << "Edge from " << u << " to " << v << " is removed." << endl;
	}

	void countDegree() {
		for (int i = 0; i < numOfVertices; i++) {
			Arr_deg[i] = 0;
		}

		NodeType* current;

		for (int i = 0; i < numOfVertices; i++) {
			current = this->Arr_ll[i].head;
			while (current != NULL) {
				Arr_deg[(current->info) - 1] = Arr_deg[(current->info) - 1] + 1;
				current = current->link;
			}
		}
	}

	void printTopologicalSort() {
		countDegree();

		Queue* Q_deg = new Queue();


		// reloop until all degree <0
		while (true) {

			// act as a flag to detect 0 degree vertices
			bool degree_0 = false;

			// to count the total processed vertices
			int count_done = 0;

			for (int i = 0; i < numOfVertices; i++) {
				if (Arr_deg[i] == 0) {

					// if the vertice has adjacent vertices, mark with -1
					if (Arr_ll[i].head != NULL) {
						Q_deg->addQueue(i + 1);
						Arr_deg[i] = Arr_deg[i] - 1;
						degree_0 = true;
					}
					// if the vertice has no adjacent vertices, mark with -2
					else {
						Q_deg->addQueue(i + 1);
						Arr_deg[i] = Arr_deg[i] - 2;
						degree_0 = true;
					}
				}
				// calculate total processed vertices
				else if (Arr_deg[i] < 0) {
					count_done = count_done + 1;
				}
			}

			// if there is NO vertice with 0 degree left 
			if ((degree_0 == false) && (count_done < numOfVertices)) {
				cout << "There is no topology sort in this graph because it is a cyclic graph. " << endl;

				Q_deg->~Queue();
				break;
			}
			else {

				// break when all the vertices are processed
				if (count_done == numOfVertices) {
					break;
				}
				else {
					for (int k = 0; k < numOfVertices; k++) {

						// search for row with -1 degree
						if (Arr_deg[k] == -1) {

							// traverse the row
							NodeType* current;
							current = Arr_ll[k].head;
							while (current != NULL) {

								// update degree array
								Arr_deg[(current->info) - 1] = Arr_deg[(current->info) - 1] - 1;
								current = current->link;
							}
							// clear the row
							Arr_ll[k].~LinkedList();
						}
					}
				}
			}

		}

		// print queue when it is not empty
		if (!Q_deg->isEmpty()) {
			cout << "The topological sort will be :" << endl;
			cout << endl;
			Q_deg->printQ();
			cout << endl;
		}

	}
};

