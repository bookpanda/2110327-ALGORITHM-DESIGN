#include "map_bst.h"
#include "student.h"
#include <iostream>

using std::cin;
using std::cout;

int main(){
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	CP::map_bst<int , int > bst;
	for(int i=0;i<n;i++){
		int numberToInsert;
		cin >> numberToInsert;
		bst.insert(std::make_pair(numberToInsert, 0));
	}

	cout << bst.furthest_distance() << '\n';
}