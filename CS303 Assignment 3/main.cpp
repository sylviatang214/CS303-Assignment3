#include "queue.h"
#include "linear_search.h"

using namespace std;

int main() {



// Q1

	queue<int> queue1;

	if (queue1.empty() == true) { 
		cout << "The queue is empty" << endl;
	}

	for (int i = 0; i < 10; i++) {
		queue1.push(i);
	}

	queue1.move_to_rear();


	while (queue1.empty() == false) {
		cout << "Item in front: " << queue1.front() << ". Item popped: ";
		queue1.pop(); 
		cout << ". Updated size: " << queue1.size() << endl;
	}


//Q2

	vector<int> vect;

	vect.push_back(2);
	vect.push_back(2);
	vect.push_back(1);
	vect.push_back(1);
	vect.push_back(3);
	vect.push_back(3);
	vect.push_back(4);
	vect.push_back(4);

	cout << "\nIndex of last occurence of item '3' : " << linear_search(vect, 3, vect.size() - 1) << endl << endl;

//Q3

	queue<int> queue2;

	queue2.push(100);
	queue2.push(70);
	queue2.push(60);
	queue2.push(90);
	queue2.push(10);
	queue2.push(40);
	queue2.push(50);
	queue2.push(30);
	queue2.push(80);
	queue2.push(20);

	for (int i = 0; i < 10; i++) {
		queue2.insertion_sort();
	}

	while (queue2.empty() == false) {
		cout << "Item in front: " << queue2.front() << ". Item popped: ";
		queue2.pop();
		cout << ". Updated size: " << queue2.size() << endl;
	}




	system("pause");
	return 0;
}