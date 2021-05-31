#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node* next;
	bool IsEqual(const Node& other) const {
		return value == other.value;
	}
};

struct Iterator {
	Node* ptr;
};

Iterator ToNext(const Iterator& it) {
	if (it.ptr != nullptr) {
		return Iterator{ it.ptr->next };
	}
	else {
		return Iterator{ nullptr };
	}
}

bool operator==(const Iterator& first, const Iterator& second) {
	return first.ptr == second.ptr;
}

bool operator!=(const Iterator& first, const Iterator& second) {
	return !(first == second);
}

Iterator operator++(Iterator& it) {
	it.ptr = it.ptr->next;
	return it;
}


class List
{
private:

	Node* start = nullptr;
	Node* finish = nullptr;
	int number = 0;



public:
	void push_back(int val)
	{
		Node* newNode = new Node;
		newNode->value = val;
		newNode->next = nullptr;

		if (number == 0)
		{
			start = newNode;
			finish = newNode;
		}
		else
		{
			finish->next = newNode;
			finish = newNode;
		}
		++number;
	}



	void push_front(int val)
	{
		Node* newNode = new Node;
		newNode->value = val;
		newNode->next = nullptr;

		if (number == 0)
		{
			start = newNode;
			finish = newNode;
		}
		else
		{
			newNode->next = start;
			start = newNode;
		}
		++number;
	}

	void pop_front()
	{
		Node* tmp = start;
		start = tmp->next;
		delete tmp;
		if (number == 1)
		{
			finish = nullptr;
		}

		--number;
	}

	Iterator begin() {
		return Iterator{ start };
	}

	Iterator end() {
		return Iterator{ finish->next };
	}

	Iterator Find(const int& value) {
		for (Iterator it = begin(); it != end(); ++it) {
			if (it.ptr->value == value) {
				return it;
			}
		}
		return Iterator{ nullptr };
	}

	void Print() {
		for (Iterator it = begin(); it != end(); ++it) {
			cout << it.ptr->value << endl;
		}
	}

};


int main() {
	List list;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		list.push_back(i);
	}

	list.Print();

	for (Iterator it = list.begin(); it != list.end(); ++it) {
		if (it == list.Find(3)) {
			cout << "Find 3" << endl;
		}
	}


	return 0;
}