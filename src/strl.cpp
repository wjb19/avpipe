#include "strl.hpp"
namespace avpipe{

	ostream& operator<<(ostream &out, const strl& in){

		out << "++stream type: 		"	<< in._type << endl;
		out << "  codec:		"	<< in._codec << endl;
		out << "  flags:		"	<< in._flags << endl;
		out << "  priority:		"	<< in._priority << endl;
		out << "  language:		"	<< in._lang << endl;
		out << "  initial frames:	"	<< in._init_frames << endl;
		out << "  scale:		"	<< in._scale << endl;
		out << "  rate:			"	<< in._rate << endl;
		out << "  start:		"	<< in._start << endl;
		out << "  length:		"	<< in._length << endl;
		out << "  suggested buffer sz:	"	<< in._sug_buf_size << endl;
		out << "  quality:		"	<< in._quality << endl;
		out << "  sample size:		"	<< in._samp_size << endl;

		if (!in._type.compare("vids")){
		//if (1){

			out << "  bi size		" 	<< in._size << endl;
			out << "  bi width		" 	<< in._width << endl;
			out << "  bi height		" 	<< in._height << endl;
			out << "  bi planes		" 	<< in._planes << endl;
			out << "  bi bit count		" 	<< in._bit_count << endl;
			out << "  bi compression	" 	<< in._compression << endl;
			out << "  bi size		" 	<< in._size_image << endl;
			out << "  bi xpix param		" 	<< in._xpix_param << endl;
			out << "  bi ypix param		" 	<< in._ypix_param << endl;
			out << "  bi clr used		" 	<< in._clr_used << endl;
			out << "  bi clr import		" 	<< in._clr_import << endl;

		} else {

			out << "  format tag		" 	<< in._format_tag << endl;
			out << "  n channels		"	<< in._n_channels << endl;
			out << "  n samples		"	<< in._n_samples_sec << endl;
			out << "  n avg bytes		"	<< in._n_avg_bytes_sec << endl;
			out << "  block align		"	<< in._block_align << endl;
			out << "  bits sample		"       << in._bits_sample << endl;
			out << "  cb size		"	<< in._cb_size << endl;

		}

		return out;
	};






	strl::strl(uint8_t * buf,int off){


	//	char * tmp = (char*) buf.get();

		string str_type((char*) (buf+16+off),4);
		string str_hand((char*) (buf+20+off),4);
		bool success = str_type.find("vids");
		success |= str_type.find("auds");

		if(!success)
			throw std::invalid_argument( "missing stream header(s) strh" );


		//cout << _type << endl;

		_type 		= str_type;
		_codec 		= str_hand;

		_flags		= _uint8_to_uint32(buf, 	24+off);
		_priority 	= _uint8_to_uint16(buf, 	28+off);
		_lang		= _uint8_to_uint16(buf,		30+off);
		_init_frames	= _uint8_to_uint32(buf,		32+off);
		_scale		= _uint8_to_uint32(buf, 	36+off);
		_rate		= _uint8_to_uint32(buf, 	40+off);
		_start		= _uint8_to_uint32(buf, 	44+off);
		_length		= _uint8_to_uint32(buf, 	48+off);
		_sug_buf_size 	= _uint8_to_uint32(buf, 	52+off);
		_quality	= _uint8_to_uint32(buf, 	56+off);
		_samp_size	= _uint8_to_uint32(buf, 	60+off);

		if (!_type.compare("vids")){
	//	if (1){

			//vids
			_size  	= _uint8_to_uint32(buf,		76+off);
			_width 	=_uint8_to_uint32(buf,		80+off);
			_height 	= _uint8_to_uint32(buf,		84+off);
			_planes 	= _uint8_to_uint32(buf,		88+off);
			_bit_count	= _uint8_to_uint32(buf,		92+off);
			_compression	= string((char*) (buf + 96+off),4);
			_size_image  = _uint8_to_uint32(buf,		100+off);
			_xpix_param  = _uint8_to_uint32(buf,		104+off);
			_ypix_param  = _uint8_to_uint32(buf,		108+off);
			_clr_used    = _uint8_to_uint32(buf,		112+off);
			_clr_import  = _uint8_to_uint32(buf,		116+off);

		} else if (!_type.compare("auds")){
	//	} else if (0){

			_codec		= "N/A";
			_format_tag 	= _uint8_to_uint16(buf,	76+off);
			_n_channels 	= _uint8_to_uint32(buf,	78+off);
			_n_samples_sec 	= _uint8_to_uint32(buf,	82+off);
			_n_avg_bytes_sec= _uint8_to_uint32(buf,	86+off);
			_block_align 	= _uint8_to_uint32(buf,	90+off);
			_bits_sample 	= _uint8_to_uint32(buf,	94+off);
			_cb_size 	= _uint8_to_uint32(buf,	98+off);

		} 
		else {
			throw std::invalid_argument( "no aud/vid stream found" );
		}

	};

};
