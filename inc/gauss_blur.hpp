/**
 * @file gauss_blur.hpp
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
 * function object for avi chunk, provides gauss blur
 */



#ifndef __GAUSS_BLUR__
#define __GAUSS_BLUR__

#include <unistd.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include <memory>
#include "utilities.hpp"
#include "avi_hdr.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;

namespace avpipe{

	/// A function object providing gaussian blur
	class gauss_blur 
	{
		public:

			/**
			 * A function object providing gaussian blur
			 * @param in the data to operate on
			 */
			void operator()(shared_ptr<avi_chunks> in) const{
	
				uint8_t * tmp = new uint8_t[8+in.get()->getSize()];

				memcpy(tmp,in.get()->getMeta(),8);
				memcpy(tmp+8,in.get()->getData(),in.get()->getSize());

					
				delete[] tmp;

			}


		private:

	};
}
#endif
