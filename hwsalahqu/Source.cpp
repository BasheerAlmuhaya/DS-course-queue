// linkQueue.cpp
// demonstrates queue implemented as double-ended list
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Node
{
public:
	double Data; // data item
	Node *Next;	 // ptr to next Node in list
	//------------------------------------------------------------
	Node(double d) : Data(d), Next(NULL) {} // constructor
	//------------------------------------------------------------
	void displayNode() // display this Node
	{
		cout << Data << "  ";
	}
	//------------------------------------------------------------
}; // end class Node
////////////////////////////////////////////////////////////////
class Queue
{
private:
	Node *front; // ptr to Head Node
	Node *rear;	 // ptr to last Node
public:
	//------------------------------------------------------------
	Queue() : front(NULL), rear(NULL) {} // constructor
	//------------------------------------------------------------
	~Queue()				// destructor
	{						//  (deletes all Nodes)
		Node *ptr = front;	// start at beginning
		while (ptr != NULL) // until end of list,
		{
			Node *temp = ptr; // remember current
			ptr = ptr->Next;  // move to next Node
			delete temp;	  // delete old current
		}
	}
	//------------------------------------------------------------
	bool isEmpty() // true if no Nodes
	{
		return front == NULL;
	}
	//------------------------------------------------------------
	void enqueue(double dd) // insert at end of list
	{
		Node *NewNode = new Node(dd); // make new Node
		if (isEmpty())				  // if empty list,
			front = NewNode;		  // first --> newNode
		else
			rear->Next = NewNode; // old last --> newNode
		rear = NewNode;			  // newNode <-- last
	}
	//------------------------------------------------------------
	double dequeue() // delete first Node
	{				 //(assumes non-empty list)
		if (isEmpty())
			return 0;
		Node *temp = front; // remember first Node
		double tmp = front->Data;
		if (front->Next == NULL) // if only one item
			rear = NULL;		 // null <-- last
		front = front->Next;	 // first --> old next
		delete temp;			 // delete the Node
		return tmp;
	}
	//----------------------------------------------------------
	void displayList()
	{
		if (isEmpty())
		{
			cout << "empty";
			return;
		}
		Node *ptr = front;	// start at beginning
		while (ptr != NULL) // until end of list,
		{
			ptr->displayNode(); // print data
			ptr = ptr->Next;	// move to next Node
		}
		cout << endl;
	}
	//------------------------------------------------------------
	void displayQueue()
	{
		cout << "Queue (front-->rear): ";
		displayList();
	}
	//------------------------------------------------------------
}; // end class Queue
   ////////////////////////////////////////////////////////////////
int main()
{
	Queue queue;	   // make a queue
	queue.enqueue(20); // enqueue items
	queue.enqueue(40);
	queue.displayQueue(); // display queue (20, 40)
	queue.enqueue(60);	  // enqueue items
	queue.enqueue(80);
	queue.displayQueue(); // display queue (20, 40, 60, 80)
	cout << "Removing two items" << endl;
	queue.dequeue(); // dequeue items (20, 40)
	queue.dequeue();
	queue.displayQueue(); // display queue (60, 80)
	system("pause");
	return 0;
} // end main()
