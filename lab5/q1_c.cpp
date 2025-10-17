#include<iostream>
#include<string>
using namespace std;
void findPath(int mat[][4],int r,int c,string ans,int n){
	if(r< 0 || c< 0 || r>= n || c>= n || mat[r][c]== 0 || mat[r][c]== -1){
		return;
	}
	if(r==2 && c==0){
		cout<<ans<<endl;
		return;
	}
	mat[r][c]= -1;
	findPath(mat,r+1,c,ans+"D",n);
	findPath(mat,r-1,c,ans+"U",n);
	findPath(mat,r,c+1,ans+"R",n);
	findPath(mat,r,c-1,ans+"L",n);
	
	mat[r][c]=1;
}
int main(){
	int mat[4][4]={{1,1,1,1},{0,0,0,1},{1,1,0,1},{1,1,1,1}};
	string ans="";
	findPath(mat,0,0,ans,4);
}
