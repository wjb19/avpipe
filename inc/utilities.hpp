/**
 * @file utilities.hpp
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
 * Helper functions
 */



#ifndef _UTILITIES
#define _UTILITIES

#include <unistd.h>
#include <iostream>
#include <string>
#include <memory>
#include <stdint.h>
#include <vector>

using namespace std;

namespace avpipe{

	/// Make uint32 from 4x uint8
	uint32_t _uint8_to_uint32(uint8_t * buf, int offset);
	/// Make uint16 from 2x uint8
	uint16_t _uint8_to_uint16(uint8_t * buf, int offset);
	/// sort two arrays eg., values & keys
	void mergeSort(float *input, float * values, int left, int right);
	/// sort two arrays eg., values & keys
	void mergeSort(double *input, double * values, int left, int right);
	/// a heapsort on a float array
	void heapSort(float * input, int size);
	/// a heapsort on a vector<float>
	void heapSort(vector<float>& input);
	/// a binary search
	int binarySearch(vector<float>& input, float value, int low, int high, int lastMid);
}

#endif
