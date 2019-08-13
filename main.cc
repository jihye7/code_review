#include <iostream>
#include <cstdlib>

#include "priority_queue.h"

using namespace std;

template <typename T>
void PushQueue(TemplatePriorityQueue<T>* Que, int data){
	cout << "[+] Integer "<< data <<" pushed in the Priority Queue." << endl;
	Que->Push(data);
}

template<typename T>
void PopQueue(TemplatePriorityQueue<T>* Que){
	cout << "[+] Integer "<< Que->Top() << " will be poped from the Priority Queue." << endl;
	Que->Pop();
}

int main(int argc, char* argv[]){
	TemplatePriorityQueue<int> PriQueue;
	int custom_number = 0;

	//empty check
	if(PriQueue.Empty()){
		cout << "[!] Priority Queue is empty - initalized" << endl;
	}

	// push
	PushQueue(&PriQueue,23);
	PushQueue(&PriQueue,598);
	PushQueue(&PriQueue,302);

	if( argc > 1 ){
		custom_number = atoi(argv[1]);
		if( custom_number > -500 && custom_number < 2000 ){
			PushQueue(&PriQueue,custom_number);
		}
		else{
			PushQueue(&PriQueue,-1);
		}
	}
	else{
		PushQueue(&PriQueue,-1);
	}

	//empty & size
	if(PriQueue.Empty()){
		cout << "[-] Priority Queue is empty. - Push method did not work!" << endl;
		return -1;
	}
	else{
		cout << "[+] Priority Queue has data. - Queue Size : " << PriQueue.Size() <<endl;
	}

	// pop twice
	PopQueue(&PriQueue);
	PopQueue(&PriQueue);

	cout << "[+] Now, Top element of Priority Queue is " << PriQueue.Top() << endl;
	
	return 0;
}
