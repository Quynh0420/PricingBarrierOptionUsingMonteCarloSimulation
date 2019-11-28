#include<vector>


class PutUPnIN{
public:

	//constructor
	PutUPnIN(
		int nInt_, // number of intervals (steps)
		double strike_,
		double spot_,
		double vol_,
		double r_,
		double expiry_,
		double b_ // barrier of the option
		);

	//destructor
	~PutUPnIN(){};

	//methods
	void generatePath();
	void printPath();
	double PricePutUPnIn(int nReps);

	//members
	std::vector<double> thisPath;
	int nInt; // number of Intervals
	double strike;
	double spot;
	double vol;
	double r;
	double expiry;
	double b; // barrier of the option

};
