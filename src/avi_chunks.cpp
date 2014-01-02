#include "avi_chunks.hpp"	

namespace avpipe{
	avi_chunks::avi_chunks(int seq, int size, uint8_t * in, uint8_t * meta){

		_sequence_num=seq;
		if (seq!=-1){

			_size=size;

			if (size>0){ 
				
				shared_array<uint8_t> tmp_data(new uint8_t[size]);	
				_data = tmp_data;

				memcpy(_data.get(),in,size);
			}

				shared_array<uint8_t> tmp_meta(new uint8_t[8]);	
				_meta = tmp_meta;

				memcpy(_meta.get(),meta,8);
			//_meta(8);
			//memcpy(_meta.get(),meta,8);

		}

	};

};


