#include "utilities.hpp"
using namespace std;

namespace avpipe{
	uint32_t _uint8_to_uint32(uint8_t * buf, int offset){

		return	(uint32_t) ((buf[offset+3] << 24) + (buf[offset+2] << 16)\
				+ (buf[offset+1] << 8) + buf[offset]);  
	}
	uint16_t _uint8_to_uint16(uint8_t * buf, int offset){
		return	(uint16_t) ((buf[offset+1] << 8) + buf[offset]);  

	}


	//sort two arrays eg., values & keys
	void mergeSort(double *input, double * values, int left, int right){

		int low = left;
		int high = right;

		if (low >=high){

			return;
		}

		int middle = (low+high) /2;
		mergeSort(input, values, low, middle);
		mergeSort(input, values, middle+1, high);
		int endLow = middle;
		int startHigh = middle +1;

		while ((low <= endLow) && (startHigh <= high)){
			if (input[low] < input[startHigh]){

				low++;
			}else{

				float temp 	= input[startHigh];
				float tempVal	= values[startHigh];

				for (int k=startHigh-1; k>= low; k--){
					input[k+1]=input[k];
					values[k+1]=values[k];
				}

				input[low] = temp;
				values[low] = tempVal;
				low++;
				endLow++;
				startHigh++;

			}

		}

	};


	//sort two arrays eg., values & keys
	void mergeSort(float *input, float * values, int left, int right){

		int low = left;
		int high = right;

		if (low >=high){

			return;
		}

		int middle = (low+high) /2;
		mergeSort(input, values, low, middle);
		mergeSort(input, values, middle+1, high);
		int endLow = middle;
		int startHigh = middle +1;

		while ((low <= endLow) && (startHigh <= high)){
			if (input[low] < input[startHigh]){

				low++;
			}else{

				float temp 	= input[startHigh];
				float tempVal	= values[startHigh];

				for (int k=startHigh-1; k>= low; k--){
					input[k+1]=input[k];
					values[k+1]=values[k];
				}

				input[low] = temp;
				values[low] = tempVal;
				low++;
				endLow++;
				startHigh++;

			}

		}

	};

	/// a heapsort on a float array
	void heapSort(float * input, int size){


		int halfLength = size /2;
		int remainingLength = size-1;
		int indexA, indexB;

		float temp;

		int k=-1,l=-1;

		while (k==-1){


			if (halfLength > 1){
				halfLength = halfLength-1;
				temp = input[halfLength];
			} else {
				temp = input[remainingLength-1];
				input[remainingLength-1] = input[0];
				remainingLength = remainingLength-1;
			}

			if (remainingLength == 1){
				input[0] = temp;
				return;
			}


			indexA = halfLength;
			indexB = 2* halfLength;

			l=-1;
			while (l==-1){


				if (indexB <= remainingLength){


					if (indexB < remainingLength)
						if (input[indexB] < input[indexB+1])
							indexB = indexB+1;

					if (temp < input[indexB]){
						input[indexA] = input[indexB];
						indexA = indexB;
						indexB = 2* indexB;		

					} else{
						indexB = remainingLength+1;
						l=-1;
					} 
				} else {
					l=0;
				}
			}

			input[indexA] = temp;

		}	


	};


	/// a heapsort on a vector<float>
	void heapSort(vector<float>& input){

		int size = input.size();


		int halfLength = size /2;
		int remainingLength = size-1;
		int indexA, indexB;

		float temp;

		int k=-1,l=-1;

		while (k==-1){


			if (halfLength > 1){
				halfLength = halfLength-1;
				temp = input.at(halfLength);
			} else {
				temp = input.at(remainingLength-1);
				input.at(remainingLength-1) = input.at(0);
				remainingLength = remainingLength-1;
			}

			if (remainingLength == 1){
				input.at(0) = temp;
				return;
			}


			indexA = halfLength;
			indexB = 2* halfLength;

			l=-1;
			while (l==-1){


				if (indexB <= remainingLength){


					if (indexB < remainingLength)
						if (input.at(indexB) < input.at(indexB+1))
							indexB = indexB+1;

					if (temp < input.at(indexB)){
						input.at(indexA) = input.at(indexB);
						indexA = indexB;
						indexB = 2* indexB;		

					} else{
						indexB = remainingLength+1;
						l=-1;
					} 
				} else {
					l=0;
				}
			}

			input.at(indexA) = temp;

		}	


	};


	int binarySearch(vector<float>& input, float value, int low, int high, int lastMid){

		int mid;

		if ((high < low) && (lastMid != (input.size() / 2)))
			return (lastMid % 2 == 0) ? lastMid : lastMid +1;
		else if ((high < low) && (lastMid == (input.size() / 2)))
			return -1;

		mid = low + (high-low) / 2;

		if (input.at(mid) && input.at(mid+1) > value)
			return binarySearch(input, value, low, mid-1, mid);
		else if (input.at(mid) && input.at(mid+1) < value)
			return binarySearch(input, value, mid+1, high, mid);
		else
			return mid;



	};


};
