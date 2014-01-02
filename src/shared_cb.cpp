#include "shared_cb.hpp"

using namespace std;
using namespace boost;

namespace avpipe{


	shared_cb::shared_cb(size_t capacity) {
		_circ_buf.set_capacity(capacity);
	}


	void shared_cb::set(size_t capacity){
		_circ_buf.set_capacity(capacity);
	}


	void shared_cb::push(shared_ptr<avi_chunks> chunk) {
		mutex::scoped_lock lock(_mutex);
		while (_circ_buf.full()) {
			_push_ready.wait(lock);
		}
		_circ_buf.push_back(chunk);
		lock.unlock();
		_pop_ready.notify_all();
	}

	shared_ptr<avi_chunks> shared_cb::pop() {
		mutex::scoped_lock lock(_mutex);
		while (_circ_buf.empty()) {
			_pop_ready.wait(lock);
		}
		shared_ptr<avi_chunks> chunk = _circ_buf.front();
		_circ_buf.pop_front(); 
		lock.unlock();
		_push_ready.notify_all();
		return chunk;
	}

};
