#include "avi_wtr.hpp"

namespace avpipe{
	avi_wtr::avi_wtr(shared_cb * out_buf, int workers):
		_buf(out_buf),
		_workers(workers)
	{
	};


	void avi_wtr::operator()(){


		int it=0;

		while (1){
			shared_ptr<avi_chunks> tmp = _buf[it % _workers].pop();

			if (tmp.get()->getSeq()==-1)
				break;
			else
				//cout << tmp.get()->getData() << endl;
			
			it++;
		}


	};

	//ostream& operator<<(ostream &out, const avi_rdr& in){

		//out << in._avi_hdr << endl;
	//	return out;
	//};

};
