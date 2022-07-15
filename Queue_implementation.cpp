#include <iostream>
using namespace std;

template <typename T>

class Queue{

	T *data;
	int nextIndex;
	int firstIndex;
	int size;
	int capacity;

public:

	Queue(int s){
		data = new T[s];
		nextIndex = 0;
		firstIndex = -1;
		size = 0;
		capacity = s;
	}

int getSize(){
	return size;
}

bool isEmpty(){
	return size == 0;
}

void enqueue(T val){
	if(size == capacity){
		T *newData = new T[2*capacity];
		int j=0;
		for(int i=firstIndex; i<capacity; i++){
			newData[j++] = data[i];
		}
		for(int i=0; i<firstIndex ; i++){
			newData[j++] = data[i];
		}
		delete [] data;
		data = newData;
		firstIndex = 0;
		nextIndex = capacity;
		capacity *= 2;
	}
	data[nextIndex] = val;
	nextIndex = (nextIndex + 1) % capacity;
	if(firstIndex == -1){
		firstIndex = 0;
	}
	size++;
}

T front(){
	if(isEmpty()){
		cout << "Queue is empty!" << endl;
		return 0;
	}
	return data[firstIndex];
}

T dequeue(){
	if(isEmpty()){
		cout << "Queue is empty!" << endl;
		return 0;
	}
	T ans = data[firstIndex];
	firstIndex = (firstIndex + 1) % capacity;
	size--;
	if(size == 0){
		firstIndex = -1;
		nextIndex = 0;
	}
	return ans;	
}


};

int main(){

	Queue<int> q;

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);

	cout << q.front() << endl;
	q.dequeue();
	q.dequeue();
	q.dequeue();


	cout << q.front() << endl;
	cout << q.getSize() << endl;
	cout << q.isEmpty() << endl;
	

	return 0;

}
