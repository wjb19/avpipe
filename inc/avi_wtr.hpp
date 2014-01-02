/**
 * @file avi_wtr.hpp
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
 * Writes AVI to stdout
 */



#ifndef __AVI_WTR__
#define __AVI_WTR__

#include <unistd.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include <memory>
#include "utilities.hpp"
#include "shared_cb.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;

namespace avpipe{
	/// push stdout from a buffer of chunks
	class avi_wtr 
	{
		public:

			/**
			 * @param output data to stdout
			 */
			avi_wtr(shared_cb * output, int workers);
			~avi_wtr(){};
			void operator()();



		private:
			shared_cb * _buf;
			int _workers;

	};
}
#endif
