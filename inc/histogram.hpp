/**
 * @file histogram.hpp
 * @author  Bill Brouwer <whiskeyjulietb@gmail.com>
 * @version 1.0
 *
 * @section LICENSE
 * Copyright 2013 William J. Brouwer
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @section DESCRIPTION
 *
 * Basic histogram
 */



#ifndef __HISTOGRAM_HPP
#define __HISTOGRAM_HPP

#include <map>
#include <vector>
#include <iostream>
#include <assert.h>
#include <cmath>
#include "utilities.hpp"

#define _HIST_BINS_MAX 100

using namespace std;

namespace avpipe{

	/// a histogram class
	class histogram{

		private:
			map<int,float> datum;
			vector<float> bounds;
			vector<int> vals;

			int total;
			
		public :

		histogram(int firstValue, int stepSize, int totalValues);
	
		/// push in single value
		void set(float value);

		/// push in many values
		void set(vector<float> in);

		/// get fraction
		float get(float val);


		~histogram(){};
		
		friend ostream& operator<<(ostream &out, histogram& in);
	};

}
#endif
