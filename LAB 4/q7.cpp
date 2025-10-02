#include <iostream>
#include <string>
using namespace std;

int linearSearch(string arr[], int size, string target, int &count) {
    count = 0;
    for (int i = 0; i < size; i++) {
        count++;
        if (arr[i] == target){
		
            cout<<"Linear search: "<<target<<" fount at index position "<<i<<" in "<<count<<" steps"<<endl;
            return i;
        }
    }
    return -1;
}

int binarySearch(string arr[], int size, string target, int &count) {
    int low = 0, high = size - 1;
    count = 0;
    while (low <= high) {
        count++;
        int mid = (low + high) / 2;
        if (arr[mid] == target){
		
            cout<<"Binary search: "<<target<<" fount at index position "<<mid<<" in "<<count<<" steps"<<endl;
            return mid;
        }
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    const int SIZE = 10;
    string names[SIZE] = {"Ahmed", "Ali", "Basit", "Karim", "Rizwan", "Sarwar", "Tariq", "Taufeeq", "Yaseen", "Zulfiqar"};
    string targets[3] = {"Aftab", "Rizwan", "Tariq"};
    for(int i=0;i<3;i++){
	    string name=targets[i];
	    int lsteps=0;
	    int bsteps=0;
        int ls = linearSearch(names, SIZE, name,lsteps);
        int bs = binarySearch(names, SIZE, name,bsteps);
        if(bs==-1 && ls==-1){
        	cout<<"target: "<<targets[i]<<" not found"<<endl;
		}
   }


    return 0;
}

