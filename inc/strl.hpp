/**
 * @file strl.hpp
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
 * A description of relevant strl/strh AVI lists
 */



#ifndef _STRL
#define _STRL

#include <string>
#include <unistd.h>
#include <iostream>
#include <stdexcept>
#include <memory>
#include <boost/scoped_ptr.hpp>

#include "utilities.hpp"
using namespace std;
using namespace boost;
namespace avpipe{


	/// container for AVI stream header lists
	class strl{

		private:
			string  _type;
			string  _codec;
			uint32_t _flags;	
			uint16_t _priority;
			uint16_t _lang;
			uint32_t _init_frames;
			uint32_t _scale;
			uint32_t _rate;
			uint32_t _start;
			uint32_t _length;
			uint32_t _sug_buf_size;
			uint32_t _quality;
			uint32_t _samp_size;

			//vids
			uint32_t _size;
			uint32_t _width;
			uint32_t _height;
			uint32_t _planes;
			uint32_t _bit_count;
			string  _compression;
			uint32_t _size_image;
			uint32_t _xpix_param;
			uint32_t _ypix_param;
			uint32_t _clr_used;
			uint32_t _clr_import;
			//aud
			uint16_t _format_tag;
			uint32_t _n_channels;
			uint32_t _n_samples_sec;
			uint32_t _n_avg_bytes_sec;
			uint32_t _block_align;
			uint32_t _bits_sample;
			uint32_t _cb_size;

		public:
			friend ostream& operator<<(ostream &out, const strl& in);

			
			strl(uint8_t * buf,int off);
			~strl(){};

	}; 
};
#endif
