#include"PutUPnIN.h"
#include<cmath>
#include<iostream>
#include"Random.h"
#include<algorithm>
#include<vector>

//definition of constructor
PutUPnIN::PutUPnIN(
	int nInt_,
	double strike_,
	double spot_,
	double vol_,
	double r_,
	double expiry_,
	double b_ ){
		nInt = nInt_;
		strike = strike_;
		spot = spot_;
		vol = vol_;
		r = r_;
		expiry = expiry_;
		b = b_;
		generatePath();
}

//method definition
void PutUPnIN::generatePath(){
	double thisDrift = (r * expiry - 0.5 * vol * vol * expiry) / double(nInt);
	double cumShocks = 0;
	thisPath.clear();

	for(int i = 0; i < nInt; i++){
		cumShocks += (thisDrift + vol * sqrt(expiry / double(nInt)) * GetOneGaussianByBoxMuller());
		thisPath.push_back(spot * exp(cumShocks));
	}
}

//method definition
void PutUPnIN::printPath(){
    std::cout << "Here are all prices inside the current path: \n";
    std::cout << "=============================================\n";

	for(int i = 0;  i < nInt; i++){

		std::cout << "price # " << (i+1) << ": " << thisPath[i] << "\n";
	}
}

//method definition
double PutUPnIN::PricePutUPnIn(int nReps){

	double rollingSum = 0.0;
    double Maxprice;

	for(int i = 0; i < nReps; i++){
		generatePath();
		int mid = (thisPath.size()% 2 == 0) ? (thisPath.size()/2) : ((thisPath.size()-1)/2);
		Maxprice = *std::max_element(thisPath.begin(), thisPath.begin() + mid);
        if (Maxprice >= b) rollingSum += (thisPath.back() < strike) ? (strike - thisPath.back()) : 0;

	}
	return exp(-r*expiry)*rollingSum/double(nReps);

}



