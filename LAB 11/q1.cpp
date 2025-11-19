
#include<iostream>
using namespace std;

class node{
	public:
		string key;
		string val;
		node *next;
//		node(){
//			key=null;
//			val=0;
//		}
		node(string k,string str){
			key=k;
			val=str;
			next=NULL;
		}
};

const int n=10;

class hashtable{
	public:
//		int n=10;
		node* table[n];
		
		hashtable(){
			for(int i=0;i<n;i++){
				table[i]==NULL;
			}
		}
		int sumASCII(string str) {
		    int sum = 0;
		    for (int i = 0; i < str.length(); i++) {
		        sum += (unsigned char)str[i];
		    }
		    return sum;
		}
		
		int hashfunc(int k){
			return k%n;
		}
		
		void insert(string key,string s){
			int x=sumASCII(key);
			int index=hashfunc(x);
			node* newn= new node(key,s);
			
			if(table[index]==NULL){
				table[index]=newn;
			}
			else{
				node* temp=table[index];
				while(temp->next != NULL){
					if(temp->key==key){
						temp->val=s;
						delete newn;
						return;
					}
					temp=temp->next;
				}
				if(temp->key==key){
					temp->val=s;
					delete newn;
					return;
				}
				temp->next=newn;
			}
		}
		
//		int sumASCII(string str) {
//		    int sum = 0;
//		    for (int i = 0; i < str.length(); i++) {
//		        sum += (unsigned char)str[i];
//		    }
//		    return sum;
//		}
//		
//		int hashfunc(int k){
//			return k%n;
//		}
		
		void display(){
			for(int i=0;i<n;i++){
				cout<<table[i]->val<<endl;
			}
		}
		
};

int main(){
	hashtable myhash;
	myhash.insert("A","aaaa");
	myhash.insert("B","bbb");
	myhash.insert("C","bbb");
	myhash.display();
	return 0;
}

