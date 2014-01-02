#include "avi_rdr.hpp"


#define msg "no video or audio data found"

namespace avpipe{
	avi_rdr::avi_rdr(bool push_stdout, shared_cb * in_buf, int workers) : avi_hdr::avi_hdr(push_stdout){




		uint8_t * avi_chnks 	= new uint8_t[MAX_RDR_BUF];
		uint8_t * meta		= new uint8_t[16];
		uint8_t * words		= new uint8_t[8];
		uint8_t * word		= new uint8_t[4];

		uint32_t size;
		//fast forward to the chunks
		while (1){

			if (!cin.read((char*) meta,16))
				throw std::invalid_argument( msg );

			string labels((char*) (meta+8),8);

			size = _uint8_to_uint32(meta, 4);

			//we've reached the actual data
			if (!labels.find("movi"))
				break;

			if (!cin.read((char*)avi_chnks,size-8))
				throw std::invalid_argument( msg );

			if (push_stdout){
				cout << meta;
				cout << avi_chnks;
			}
		}

		string labels((char*) (meta+8),8);
		if (!cin.read((char*) word,4))
			throw std::invalid_argument( msg );

		size = _uint8_to_uint32(word, 0);

		//parse the  chunks
		if (!cin.read((char*)avi_chnks,size))
			throw std::invalid_argument( msg );

		int seq=0;
		while (!cin.eof()){

			if (!cin.read((char*) words,8)){

				//signal to all the workers we're done
				//FIXME: not all data will get to stdout
				for (int i=0; i<workers; i++)
					in_buf->push(make_shared<avi_chunks>(-1,size,avi_chnks,meta));
				break;
			}

			string labels((char*) words,4);
			size = _uint8_to_uint32(words, 4);

			//done with chunks, on to idx1 or something
			if (size > MAX_RDR_BUF){
				for (int i=0; i<workers; i++)
					in_buf->push(make_shared<avi_chunks>(-1,size,avi_chnks,meta));
				break;
			}

			//assert(size>0);


			if (!cin.read((char*)avi_chnks,size)){

				for (int i=0; i<workers; i++)
					in_buf->push(make_shared<avi_chunks>(-1,size,avi_chnks,meta));
				break;

			}

			in_buf->push(make_shared<avi_chunks>(seq,size,avi_chnks,meta));

			seq++;


		}

		while (!cin.eof()){

			if (!cin.read((char*) words,8))
				break;

			string labels((char*) words,4);
			size = _uint8_to_uint32(words, 4);


			//done with everything, hopefully
			if (size > MAX_RDR_BUF)
				break;



			if (!cin.read((char*)avi_chnks,size))
				break;

		}

		delete[] avi_chnks;
		delete[] word;
		delete[] words;
		delete[] meta;
	};
};
