#pragma once
#include<list>
#include"TimeStamp.h"
#include"sNode.h"
#define NumWeekDay 7
using namespace std;

// Schedule
class Schedule {
public:
	// constructor
	Schedule() {
	
	}

	// destructor
	~Schedule() {}

	// check if there are works that conflict with a new work list
	bool checkConflict(list<timeStamp>& a) {
		list<timeStamp>::const_iterator newWork=a.begin();

		// check each new work
		while(newWork!=a.end()){
			list<timeStamp> *checkList=&(this->sche[static_cast<timeStamp>(*newWork).getDay()]);
			list<timeStamp>::const_iterator work= checkList->begin();
			
			// check each existing work
			while (work != checkList->end()) {
				if (static_cast<timeStamp>(*work).isConflict(static_cast<timeStamp>(*newWork))) {
					return true;
				}

				work++;
			}
			newWork++;
		}

		return false;
	}

	// check if there are works that conflict with a new work
	bool checkConflict(timeStamp& a) {
		list<timeStamp> *checkList = &(this->sche[a.getDay()]);
		list<timeStamp>::const_iterator work = checkList->begin();

		// check each existing work
		while (work != checkList->end()) {
			if (static_cast<timeStamp>(*work).isConflict(static_cast<timeStamp>(a))) {
				return true;
			}

			work++;
		}

		return false;
	}

	// add a new work
	void addWork(timeStamp& newWork) {
		if (!checkConflict(newWork)) {
			// add a new work
			static_cast<list<timeStamp>>(this->sche[newWork.getDay()]).insert(this->sche[newWork.getDay()].end(), newWork);

			// add a new work to the list of works
			list<timeStamp*> temp;
			temp.insert(temp.end(),&newWork);
			this->workList.insert(this->workList.end(), temp);
		}
	}

	// add a new work list
	void addWork(list<timeStamp>& newWork) {
		if (!checkConflict(newWork)) {
			list<timeStamp>::const_iterator iter = newWork.begin();
			
			// new list of works to add
			list<timeStamp*> temp;

			while (iter!=newWork.end()) {
				timeStamp work = static_cast<timeStamp>(*iter);
				// add a new work
				static_cast<list<timeStamp>>(this->sche[work.getDay()]).insert(this->sche[work.getDay()].end(), work);

				temp.insert(temp.end(),)
				temp.insert(temp.end(), &newWork);
				this->workList.insert(this->workList.end(), temp);
			}
		}
	}

	// delete a work or work list
	void deleteWork() {
		
	}

	// update a work or work list
	void update() {
		
	}

private:
	list<sNode<timeStamp>> sche[NumWeekDay];	// schedule
	list<list<sNode<timeStamp>>> workList;	// list of works
};