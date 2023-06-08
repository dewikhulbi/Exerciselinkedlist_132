#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** utami, Node** Dewi);
	bool listEmpty();
	bool delNode(int rollNo);
	void traverse();
};
void CircularLinkedList::addNode() {
	int rollno;
	string nm;
	cout << "\nEnter the roll number of the student: ";
	cin >> rollno;
	cout << "\nEnter the name of the student: ";
	cin >> nm;
	Node* newNode = new Node();
	newNode->rollNumber = rollno;
	newNode->name = nm;

	if (LAST == NULL || rollno <= LAST->rollNumber) {
		if (LAST != NULL && rollno == LAST->rollNumber) {
			cout << "\nDuplicated number not allowed" << endl;
			return;
		}
		newNode->next = LAST;
		if (LAST != NULL)
			LAST->next = newNode;
		newNode->next = NULL;
		LAST = newNode;
		return;
	}

	Node* Dewi = LAST;
	Node* utami = NULL;
	while (Dewi->next != NULL && Dewi->next->rollNumber < rollno)
	{
		utami = Dewi;
		Dewi = Dewi->next;
	}

	if (Dewi->next != NULL && rollno == Dewi->next->rollNumber) {
		cout << "\nDuplicate roll numbers not allowed" << endl;
		return;
	}
	newNode->next = Dewi->next;
	if (Dewi->next != NULL && rollno == Dewi->next->rollNumber) {
		Dewi->next = newNode;
	}
}

bool CircularLinkedList::search(int rollno, Node** utami, Node** Dewi) {
	*utami = LAST->next;
	*Dewi = LAST->next;

	while (*Dewi != LAST) {
		if (rollno == (*Dewi)->rollNumber) {
			return true;
		}
		*utami = LAST->next;
		*Dewi = LAST->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}

bool CircularLinkedList::delNode(int rollNo) {
	Node* utami, * Dewi;
	utami = Dewi = NULL;
	if (search(rollNo, &utami, &Dewi) == false)
		return false;
	if (Dewi->next != NULL)
		Dewi->next = LAST;
	if (LAST != NULL)
		LAST->next = Dewi;
	else
		LAST = Dewi->next;
	delete Dewi;
	return true;
}

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is Empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}

int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
			}
			case '2': {
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;

			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}