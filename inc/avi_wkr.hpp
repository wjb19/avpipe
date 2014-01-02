/**
 * @file avi_wkr.hpp
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
 * Work on AVI chunk according to supplied function object
 */



#ifndef __AVI_WKR__
#define __AVI_WKR__

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

	///a function for working on chunks, template with desired operation
	template<typename T> void 
		avi_wkr(T &op, shared_cb * in, shared_cb * out, int workers){
			while (1){

				shared_ptr<avi_chunks> tmp = in->pop();

				int sequence_num = tmp.get()->getSeq();

				if (sequence_num==-1){
				
				for (int i=0; i<workers; i++)
				out[i].push(tmp);
					break;

				}

				op(tmp);
				out[sequence_num % workers].push(tmp);
			}



		};

}
#endif
