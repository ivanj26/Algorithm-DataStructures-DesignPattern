#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

enum Oper {
	SET = '1',
	SET_IF_GREATER = '2',
	PRINT = '3'  
};

struct Vertex {
	int value;
	vector<int> neighbors;
	
	Vertex() {}
	
	void addNeighbor(int idxNeighbor) {
		neighbors.push_back(idxNeighbor);
	}
};

struct Operation {
	Oper operType;
	vector<int> v;  
};

void readInput(int &n, int &m, int &q) {
	string input;
	getline(cin, input);
	
	// parse input
	string delim = " ";
	string subs;

	int i = 0;
	int start = 0;
	int end = input.find(delim);
	
	while (end != std::string::npos) {
		subs = input.substr(start, end - start);
		
		if (i == 0) {
			n = stoi(subs);
		} else if (i == 1) {
			m = stoi(subs);
		}
		
		start = end + delim.length();
		end = input.find(delim, start);
		
		i++;
	}
	
	subs = input.substr(start, input.length() - start);
	if (i == 2) {
		q = stoi(subs);
	}
}

void createGraph(Vertex* vertices, int m) {
	while (m > 0) {
		string input;
		getline(cin, input);
		
		int end = input.find(" ");
		string subs = input.substr(0, end);
		
		int origin = stoi(subs);
		int dest = stoi(input.substr(end + 1));
		
		vertices[origin].addNeighbor(dest);
		
		m--;
	}
}

void setVerticesValue(Vertex* vertices, int u, int x) {
	queue<Vertex> q;
	
	// set value to x
	vertices[u].value = x;
	
	q.push(vertices[u]);
	
	while (!q.empty()) {
		Vertex v = q.front();
		
		q.pop();
		
		for (auto neighbor : v.neighbors) {
			vertices[neighbor].value = x;
			q.push(vertices[neighbor]);
		}
	}
}

void setVerticesValueIfGreater(Vertex* vertices, int u, int x) {
	queue<Vertex> q;
	
	// set value to x
	if (vertices[u].value > x) {
		vertices[u].value = x;
	}
	
	q.push(vertices[u]);
	
	while (!q.empty()) {
		Vertex v = q.front();
		
		q.pop();
		
		for (auto neighbor : v.neighbors) {
			if (vertices[neighbor].value > x) vertices[neighbor].value = x;
			q.push(vertices[neighbor]);
		}
	}
}

void readAndExecuteInstruction(Vertex* vertices, int q) {
	while (q > 0) {
		string input;
		string delim = " ";
		getline(cin, input);
		
		int start = 0;
		int end = input.find(delim);
		char oper = input.substr(start, end - start)[0];
		
		start = end + delim.length();
		
		switch (oper) {
			case Oper::SET: {// 1
				end = input.find(delim, start);
				int u = stoi(input.substr(start, end - start));
				
				start = end + delim.length();
				end = input.find(delim, start);
				int x = stoi(input.substr(start, input.size() - start));
				
				setVerticesValue(vertices, u, x);
				
				break;
			}
			case Oper::SET_IF_GREATER: {// 2
				end = input.find(delim, start);
				int u = stoi(input.substr(start, end - start));
				
				start = end + delim.length();
				end = input.find(delim, start);
				int x = stoi(input.substr(start, input.size() - start));
				
				setVerticesValueIfGreater(vertices, u, x);
				
				break;
			}
			case Oper::PRINT: { // 3
				int x = stoi(input.substr(start, input.size() - start));
				cout << vertices[x].value << endl;
				break;
			}
		}
		
		q--;
	}
}

/**
 * @brief You are given a Directed Acyclic Graph (DAG) with n vertices and m edges. Each vertex v has an integer, Av , associated with it and the initial value of Av is 0 for all vertices.
 * 
 * You must perform q queries on the DAG, where each query is one of the following types:
 * 1 u x: Set  to  for all  such that there is a path in the DAG from  to .
 * 2 u x: Set  to  for all  such that there is a path from  to  and .
 * 3 u: Print the value of  on a new line.
 * 
 */
int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */     // read the input
	int n, m, q;
	readInput(n, m, q);
	
	// create an array vertices
	Vertex *vertices = new Vertex[n + 1];
	
	// create a graph
	createGraph(vertices, m);
	
	// read instructions
	readAndExecuteInstruction(vertices, q);
	
	// delete memory
	delete[] vertices;
	
	return 0;
}
