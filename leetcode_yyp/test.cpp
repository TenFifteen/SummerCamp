#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() { 
	//int a[] = {5,3,7,5,9,2,5};
	vector<int>array;
	/*array.push_back(19);
array.push_back(18);
array.push_back(17);
array.push_back(15);
array.push_back(13);
array.push_back(12);
array.push_back(5);*/
for (int i=1; i<10; i++) array.push_back(i);
random_shuffle(array.begin(), array.end());
	auto ptr = array.begin() +  5;
	nth_element(array.begin(), ptr, array.end());
	for(int i = 0; i < array.size(); i++)
		cout << array[i] << endl;
	return 0;
}
