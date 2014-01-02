/**
 * @file shared_cb.hpp
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
 * circular buffer intended for AVI chunks w/ some synchronization
 */



#ifndef _SHARED_CB
#define _SHARED_CB

#include <string>
#include <unistd.h>
#include <iostream>
#include <stdexcept>
#include <memory>
#include <boost/unordered_map.hpp> 
#include <boost/circular_buffer.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>
#include <boost/thread/thread.hpp>
#include "avi_chunks.hpp"

using namespace std;
using namespace boost;

namespace avpipe{

	///A thread safe circular buffer
	class shared_cb {
		public:


			/**
			 * Construct a thread safe circular buffer
			 * @param capacity set the capacity of the circular buffer
			 */

			shared_cb(size_t capacity);
			~shared_cb(){};

			shared_cb(){};
			//shared_cb(const shared_cb& in):

			//_circ_buf(in._circ_buf)
			//{
				

			//};

			void push(shared_ptr<avi_chunks> chunk);
			shared_ptr<avi_chunks> pop();
			void set(size_t capacity);

		private:     
			mutex _mutex;
			condition _pop_ready;
			condition _push_ready;
			circular_buffer<shared_ptr<avi_chunks> > _circ_buf;
	};


};
#endif
