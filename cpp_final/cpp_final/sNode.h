#pragma once
#include<iostream>

template<class T>
class sNode {
public:
	// constructor
	sNode(T ele, sNode<T>* pre = nullptr, sNode<T>* next = nullptr, sNode<T>* same = nullptr) {
		this->ele = ele;
		this->same = same;
		this->pre = pre;
		this->next = next;
	}

	sNode(const sNode& node) {
		this->T = node.getEle();
		this->same = node.getSame();
		this->pre = node.getPre();
		this->next = node.getNext();
	}

	// destructor
	~sNode() {}

	// getter & setter
	T getEle() const{
		return this->ele;
	}

	sNode<T>* getSame() const {
		return this->same;
	}

	sNode<T>* getPre() const {
		return this->pre;
	}

	sNode<T>* getNext() const {
		return this->next;
	}

	void setEle(T ele) {
		this->ele = ele;
	}

	void setSame(sNode<T>* same) {
		this->same = same;
	}

	void setPre(sNode<T>* pre) {
		this->pre = pre;
	}

	void setNext(sNode<T>* next) {
		this->next = next;
	}

private:
	sNode<T>* same;	// pointer pointing to the node that has same element
	sNode<T>* pre;	// previous node
	sNode<T>* next;	// next node
	T ele;			// element
};