#include<iostream>
#include<vector>
#include"PutUPnIN.h"
#include<ctime>
#include<cstdlib>
#include"Functions.h"
#include"Random.h"
#include<cmath>
#include<algorithm>

using std::vector;
using std::cout;
using std::cin;

int main(){

	// set the seed
	srand( time(NULL) );

	//create a new instance of class
	PutUPnIN myPut(126, 100, 95, 0.2, 0.06, 0.5, 98);

	// Iterate over all the elements.
	myPut.printPath();

    // Check where is the middle price
    int mid = (myPut.thisPath.size()% 2 == 0) ? (myPut.thisPath.size()/2) : ((myPut.thisPath.size()-1)/2);
    cout << "The middle price is price no. " << mid
         << " and equal to " << myPut.thisPath[mid - 1]
         << "\n";

    // first and last price
 	cout << "1st price of underlying = " << myPut.thisPath.front() << "\n";
	cout << "last price of underlying = " << myPut.thisPath.back() << "\n";

	// Price of the option
	cout << "Price of Put Up and In = " << myPut.PricePutUPnIn(100000) << "\n";

	//check whether data generating process runs correctly
	//(is the expected price and volatility of underlying close to option parameters?)
	vector<double> myVec2;
	for(int i = 0; i < 1000; i++){
		myPut.generatePath();
		myVec2.push_back(myPut.thisPath.back());
	}

	cout << "mean of last underlying prices is " << mean(myVec2) << "\n";
	cout << "stddev of last underlying prices is " << stdDev(myVec2) << "\n";

	//cout << "\nPress Enter to continue...";
	//cin.get();
	return 0;
}

