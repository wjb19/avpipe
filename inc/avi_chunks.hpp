/**
 * @file avi_chunks.hpp
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
 * A holder for AVI elements
 */



#ifndef __AVI_CHUNKS__
#define __AVI_CHUNKS__

#include <unistd.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include <memory>
#include <boost/shared_array.hpp>
#include <boost/make_shared.hpp>
#include "utilities.hpp"
#include "strl.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <assert.h>

using namespace std;
using namespace cv;
using namespace boost;

namespace avpipe{

	/// container for AVI chunks
	class avi_chunks
	{
		public:

			avi_chunks():
				_sequence_num(-1),
				_size(0)
		{
		};
			avi_chunks(int seq, int size, uint8_t * in, uint8_t * meta);
			~avi_chunks(){

				//cout << "my seq num was : " << _sequence_num << endl;

			};

			friend ostream& operator<<(ostream &out, const avi_chunks& in);

			/// return the sequence number; if -1, we're done
			int getSeq(){ return _sequence_num;};	

			/// set the sequence number; if -1, we're done
			void setSeq(int seq){ _sequence_num=seq;};	
			/// return the data pointer
			uint8_t * getData(){ return _data.get();};

			/// return the meta pointer
			uint8_t * getMeta(){ return _meta.get();};

			/// return the chunk type
			string getType(){ return _type;};

			/// return the data size
			int getSize(){ return _size;};

		private:

			/**
			 * Global position of this chuck
			 */
			int _sequence_num;
			/**
			 * Size of chunk
			 */
			int _size;
			/**
			 * Raw bytes, encoded
			 */
			shared_array<uint8_t>  _data;
			/**
			 * Type of data, two supported : 'dc' for video, 'wb' for audio
			 */
			string _type; 

			/**
			 * Raw meta, for output to stream
			 */
			shared_array<uint8_t>  _meta;
	};

}

#endif


