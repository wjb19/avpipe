#include "histogram.hpp"

namespace avpipe{

	histogram::histogram(int firstValue, int stepSize, int totalValues){

		assert((totalValues < _HIST_BINS_MAX) && (totalValues > 0));

		int val;
		for (int i=0; i<totalValues; i++){
	
			val = firstValue + i*stepSize;
			datum[i]=0;

			bounds.push_back((float)(val - stepSize/2));
			vals.push_back(val);
		}

		bounds.push_back(val+stepSize/2);

		total=0;
	};

	void histogram::set(vector<float> values){

		for (int i=0; i<values.size(); i++){
			int interval = binarySearch(bounds, abs(values[i]), 0, bounds.size()-1, bounds.size()-1);
				datum[interval] += 1.0;
				total += 1;
		}
	}


	void histogram::set(float value){

		assert((value > bounds[0]) && (value < bounds[bounds.size()-1]));

			int interval = binarySearch(bounds, abs(value), 0, bounds.size()-1, bounds.size()-1);
				datum[interval] += 1.0;
				total += 1;

	}

	float histogram::get(float value){


		assert((value > bounds[0]) && (value < bounds[bounds.size()-1]));

			int interval = binarySearch(bounds, abs(value), 0, bounds.size()-1, bounds.size()-1);

		return datum[interval] / (float) total;
	}
	
	ostream& operator<<(ostream &out, histogram& in){

		
		out << "value --- frequency" << endl;


		for (map<int,float>::iterator  it = in.datum.begin(); it != in.datum.end(); it++)
			out << it->first << " " << it->second << endl;


		return out;
	}

}
