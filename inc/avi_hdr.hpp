/**
 * @file avi_hdr.hpp
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
 * A description of the main avi header
 */

#ifndef __AVI_HDR__
#define __AVI_HDR__

#define _MAX_AVIH_SIZE 1000000

#include <unistd.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include <memory>
#include "utilities.hpp"
#include <boost/shared_ptr.hpp>
#include "strl.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace boost;

namespace avpipe{
	/// reads AVI hdr from stdin
	class avi_hdr
	{
		public:
			avi_hdr(bool push_stdout);
			avi_hdr(){};
			~avi_hdr(){};

			friend ostream& operator<<(ostream &out, const avi_hdr& in);
		

		protected:

			uint32_t _frames;
			uint32_t _flags;
			uint32_t _streams;
			uint32_t _file_size;
			uint32_t _avih_size;
			uint32_t _micro_sec_per_frame;
			uint32_t _max_bytes_per_sec;
			uint32_t _padding_granularity;
			uint32_t _width;
			uint32_t _height;

			int _main_ptr;

			vector<strl> _stream_hdr_list;
	};

}

#endif


