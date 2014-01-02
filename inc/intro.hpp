/*! \mainpage 
 *
 * \section Overview
 *
 * The last decade or so has seen a massive increase in video data generation, storage, processing and usage overall. This growth is naturally coupled with the social media explosion, improved codecs including the h264 standard http://www.itu.int/rec/T-REC-H.264, reduced storage and computation costs, and ever higher network bandwidths.
 *
 * There exists commercial packages for processing video data, but very little in the way of open source tools, particularly in a high throughput/batch computational environment. Until recently, there were also formidable ip issues with regards to working with avc/h.264.
 * 
 * The goal of avpipe is to provide video analysis tasks to users, for use with multi-core processors running a linux-like OS and using the newly available open source h.624 codec from cisco https://github.com/cisco/openh264. Ultimately said tasks will encompass feature extraction, stacking, splicing, tracking to name several. Avpipe takes advantage of UNIX pipes and is designed for streaming use, alleviating potential disk i/o bottlenecks. Built on boost, avpipe uses a simple map-reduce computational structure, with openCV for processing and feature extraction tasks.
 *
 * To build, simply edit paths in the makefile, pointing to openCV & boost, then make. The binary in the bin directory expects to read an AVI file from stdin and writes to stdout. 
 *
 * \section References 
 * 
 * Wikipedia & associated links
 * http://en.wikipedia.org/wiki/H.264/MPEG-4_AVC
 * 
 * Iain Richardson’s text
 * http://www.vcodex.com/h264.html
 * 
 * -Bill Brouwer 01/02/14
 * 
 */
