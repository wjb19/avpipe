#include "avi_hdr.hpp"

#define err_msg_a "received currupt bytes/non-avi on stdin"
#define err_msg_b "received bad avi header info on stdin"
#define err_msg_c "found no streams on stdin"
#define err_msg_d "no support for streams >= 2"


namespace avpipe{
	avi_hdr::avi_hdr(bool push_stdout){

		
		uint8_t buf[16];
		if (!cin.read((char*) buf,16)) 
			throw std::invalid_argument( err_msg_a );

		if (push_stdout)
			cout << buf;

		string file_type((char*) buf);
		bool success = file_type.find("RIFF");
		success |= file_type.find("AVI");
		success |= file_type.find("LIST");

		if (!success)
			throw std::invalid_argument( err_msg_a );

		//add length of first two words
		_file_size = _uint8_to_uint32(buf, 4);
		_file_size += 8;

		if (!cin.read((char*) buf,16))
			throw std::invalid_argument( err_msg_a );
		if (push_stdout)
			cout << buf;

		string avih_head((char*) buf);
		success = avih_head.find("hdrl");
		success |= avih_head.find("avih");

		if (!success)
			throw std::invalid_argument( err_msg_b );


		_avih_size = _uint8_to_uint32(buf, 0);
		//ignore text
		_avih_size -= 12;

		if ((_avih_size < 0) || (_avih_size > _MAX_AVIH_SIZE))						
			throw std::invalid_argument( err_msg_b );

		
		uint8_t * avih_buf = new uint8_t[_avih_size];
		
		if (!cin.read((char*) avih_buf,_avih_size))
			throw std::invalid_argument( err_msg_a );

		if (push_stdout)
			cout << avih_buf;

		_micro_sec_per_frame 	= _uint8_to_uint32(avih_buf, 0);
		_max_bytes_per_sec 	= _uint8_to_uint32(avih_buf, 4);
		_padding_granularity 	= _uint8_to_uint32(avih_buf, 8);
		_flags		 	= _uint8_to_uint32(avih_buf, 12);
		_frames		 	= _uint8_to_uint32(avih_buf, 16);
		_streams		= _uint8_to_uint32(avih_buf, 24);
		_width			= _uint8_to_uint32(avih_buf, 28);
		_height			= _uint8_to_uint32(avih_buf, 32);


		//position at end LIST word
		int offset=68,length;
		length= _uint8_to_uint32(avih_buf, 60);
		offset+=length;
		

		strl tmp(avih_buf,60);
		_stream_hdr_list.push_back(tmp);


		if (_streams==2){
			strl tmpb(avih_buf,offset);
			_stream_hdr_list.push_back(tmpb);

		} else if (_streams>=2)
			throw std::invalid_argument( err_msg_d );


	delete[] avih_buf;

	};


	ostream& operator<<(ostream &out, const avi_hdr& in){

		out << "file size: 		" 	<< in._file_size << endl;
		out << "avi hdr size: 		" 	<< in._avih_size << endl;
		out << "+micro.s / frame:	" 	<< in._micro_sec_per_frame << endl;
		out << " max bytes / sec:	" 	<< in._max_bytes_per_sec << endl;
		out << " pad granularity:	" 	<< in._padding_granularity << endl;
		out << " flags: 		" 	<< in._flags << endl;
		out << " frames: 		" 	<< in._frames << endl;
		out << " streams: 		" 	<< in._streams << endl;
		out << " v.width: 		" 	<< in._width << endl;
		out << " v.height: 		" 	<< in._height << endl;


		for(vector<strl>::const_iterator it = in._stream_hdr_list.begin(); it != in._stream_hdr_list.end(); it++){
			out << *it << endl;

		}

		return out;
	};

};
