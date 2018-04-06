/*
 * MutablePriorityQueue.h
 * A simple implementation of mutable priority queues, required by Dijkstra algorithm.
 *
 * Created on: 17/03/2018
 *      Author: Jo�o Pascoal Faria
 */

#ifndef SRC_MUTABLEPRIORITYQUEUENODE_H_
#define SRC_MUTABLEPRIORITYQUEUENODE_H_

#include <vector>
#include "Node.h"

using namespace std;

/**
 * class T must have: (i) accessible field int queueIndex; (ii) operator< defined.
 */

class MutablePriorityQueue {
	vector<Node *> H;
	void heapifyUp(unsigned i);
	void heapifyDown(unsigned i);
	inline void set(unsigned i, Node * x);
public:
	MutablePriorityQueue();
	void insert(Node * x);
	Node * extractMin();
	void decreaseKey(Node * x);
	bool empty();
};

// Index calculations
#define parent(i) ((i) >> 1)  /* i / 2 */
#define leftChild(i) ((i) << 1)  /* i * 2 */

MutablePriorityQueue::MutablePriorityQueue() {
	H.push_back(NULL);
	// indices will be used starting in 1
	// to facilitate parent/child calculations
}

bool MutablePriorityQueue::empty() {
	return H.size() == 1;
}

Node* MutablePriorityQueue::extractMin() {
	auto x = H[1];
	x->queueIndex = 0;
	H[1] = H.back();
	H.pop_back();
	if ( ! empty())
		heapifyDown(1);
	return x;
}

void MutablePriorityQueue::insert(Node *x) {
	H.push_back(x);
	heapifyUp(H.size()-1);
}

void MutablePriorityQueue::heapifyUp(unsigned i) {
	auto x = H[i];
	while (i > 1 && *x < *H[parent(i)]) {
		set(i, H[parent(i)]);
		i = parent(i);
	}
	set(i, x);
}

void MutablePriorityQueue::decreaseKey(Node *x) {
	heapifyUp(x->queueIndex);
}

void MutablePriorityQueue::heapifyDown(unsigned i) {
	auto x = H[i];
	while (true) {
		unsigned k = leftChild(i);
		if (k >= H.size())
			break;
		if (k+1 < H.size()  && *H[k+1] < *H[k])
			k++; // right child of i
		if ( ! (*H[k] < *x) )
			break;
		set(i, H[k]);
		i = k;
	}
	set(i, x);
}

void MutablePriorityQueue::set(unsigned i, Node * x) {
	H[i] = x;
	x->queueIndex = i;
}

#endif /* SRC_MUTABLEPRIORITYQUEUE_H_ */
