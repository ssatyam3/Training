#include<bits/stdc++.h>
using namespace std;

template <typename T>

class Stack{
	T *data;
	int nextIndex;
	int capacity;

public:

	Stack(){
		capacity = 4;
		data = new T [capacity];
		nextIndex = 0;
	}


int size(){
	return nextIndex;
}

bool isEmpty(){
	return nextIndex == 0;
}

void push(T val){
	if(nextIndex == capacity){
		T *newData = new T [2*capacity];
		for(int i=0 ; i<capacity ; i++){
			newData[i] = data[i];
		}
		capacity *= 2;
		delete [] data;
		data = newData;
	}
	data[nextIndex] = val;
	nextIndex++;
}

T pop(){
	if(isEmpty()){
		cout << "Stack is Empty" << endl;
		return 0;
	}
	nextIndex--;
	return data[nextIndex];
}

T top(){
	if(isEmpty()){
		cout << "Stack is empty" << endl;
		return 0;
	}
	return data[nextIndex-1];
}

};

int main(){

	Stack<char> s;
	s.push(100);
	s.push(101);
	s.push(102);
	s.push(103);
	s.push(104);

	cout << s.top() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;

	cout << s.getSize() << endl;

	cout << s.isEmpty() << endl;



	return 0;
}
