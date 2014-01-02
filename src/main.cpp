#include <boost/program_options/cmdline.hpp>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/shared_array.hpp>
#include <boost/shared_ptr.hpp>
#include <iostream>

#include "avi_wtr.hpp"
#include "avi_rdr.hpp"
#include "avi_wkr.hpp"
#include "gauss_blur.hpp"
#include "shared_cb.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <boost/thread/thread.hpp>


using namespace avpipe;
using namespace cv;
using namespace boost::program_options;


int main(int argc, char* argv[]){


	int workers=1, buffers=1;
	options_description desc("Allowed options");
	desc.add_options()
		("help", "produce help message")
		("n", value<int>(), "# of workers")
		("m", value<int>(), "# buffered avi chunks / worker")
		;

	variables_map vm;
	store(parse_command_line(argc, argv, desc), vm);
	notify(vm);    

	if (vm.count("help")) {
		cerr << desc << "\n";
		return 1;
	}

	if (vm.count("n")) {
		cerr << "number of workers was set to " 
			<< vm["n"].as<int>() << ".\n";
		workers = vm["n"].as<int>();
	} else {
		cerr << "number of workers was not set; assuming 2.\n";
		workers = 2;
	}

	if (vm.count("m")) {
		cerr << "number of avi chunks buffered / worker was set to " 
			<< vm["m"].as<int>() << ".\n";
		buffers = vm["m"].as<int>();
	} else {
		cerr << "number of avi chunks buffered / worker not set; assuming 100.\n";
		buffers=500;
	}

	//buffer to be shared by reader and workers
	shared_ptr<shared_cb> in_buffer(new shared_cb(buffers));
	
	//buffer to be shared by workers and writer
	shared_array<shared_cb> out_buffer(new shared_cb[workers]);

	for (int i=0; i<workers; i++)
		out_buffer[i].set(buffers); 

	//launch the writer
	boost::thread wtr(avi_wtr(out_buffer.get(),workers));
	

	//launch the workers
	boost::thread_group wkr_threads;

	//construct an op
	gauss_blur op;

	//make the workers perform the op on the buffered chunks
	for (int i=0; i<workers; i++){
		wkr_threads.add_thread(new boost::thread(avi_wkr<gauss_blur>,op, in_buffer.get(), out_buffer.get(), workers));
	}


	//get the header info &push chunks into buffer for processing
	avi_rdr reader(false,in_buffer.get(),workers);


	//done
	wtr.join();
	wkr_threads.join_all();
	
	//output header info
	cerr << reader << endl;
	
	return 0;
}
