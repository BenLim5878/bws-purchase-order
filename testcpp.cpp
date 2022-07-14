#include <iostream>
#include <string>
#include <fstream>
#include <string>

using namespace std;
int test() {
	string line;
	ifstream myFile;
	myFile.open("C:\\Users\\sheay\\source\\repos\\System\\PurchaseOrder.txt", true);
	if (myFile.is_open()) {
		while(getline(myFile, line))
		{
			cout << line << '\n';
		}
		myFile.close();
	}
	else cout << "Unable to open file";

	return 0;
}