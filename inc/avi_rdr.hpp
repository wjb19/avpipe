/**
 * @file avi_rdr.hpp
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
 * Reads AVI from stdin
 */



#ifndef __AVI_RDR__
#define __AVI_RDR__

#include <unistd.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include <memory>
#include "utilities.hpp"
#include "avi_hdr.hpp"
#include "shared_cb.hpp"
#include <boost/shared_array.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#define MAX_RDR_BUF 1024*1024*16

using namespace std;

namespace avpipe{
	/// reads AVI from stdin
	class avi_rdr : public avi_hdr
	{
		public:

			/**
			 * @param push_stdout Send out header info immediately to stdout
			 */
			avi_rdr(bool push_stdout, shared_cb * in,int workers);
			~avi_rdr(){};

			//friend ostream& operator<<(ostream &out, const avi_rdr& in);


		private:

	};
}
#endif
