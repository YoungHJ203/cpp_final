#pragma once
#include"sNode.h"

template<class T>
class List {
public:
	// constructor
	List() {
		this->header.setNext(this->trailer);
		this->trailer.setPre(this->header);
		this->size = 0;
	}

	// destructor
	~List() {}

	// initialize the list
	void init() {
		// remove all nodes in the list
		for (int i = 0; i < this->size; i++) {
			this->removeFirst();
		}

		// set the number of elements to zero
		this->size = 0;
	}

	// get the number of elements
	int getSize() const{
		return this->size;
	}

	// add a new node
	void addFirst(T ele) {
		sNode<T>* newNode = new sNode<T>(ele,this->header,this->header.getNext());

		this->header->getNext()->setPre(newNode);
		this->header->setNext(newNode);
	}

	void addFirst(sNode<T>& node) {
		sNode<T>* newNode = new sNode<T>(node.getEle(),this->header,this->header.getNext(),node.getSame());

		this->header->getNext()->setPre(newNode);
		this->header->setNext(newNode);
	}

	void addLast(T ele) {
		sNode<T>* newNode = new sNode<T>(ele,this->trailer.getPre(),this->trailer);

		this->trailer->getNext 
	}

	void addLast(sNode<T>& node) {
		sNode<T>* newNode = new sNode<T>(node.getEle(), this->trailer.getPre(),this->trailer, node.getSame());


	}

	// delete a existing node
	void removeFirst() {
		
	}

	void removeLast() {
	
	}

private:
	sNode<T> header;		// header node
	sNode<T> trailer;		// trailer node
	int size;				// number of elements
};