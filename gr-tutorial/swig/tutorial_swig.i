/* -*- c++ -*- */

#define TUTORIAL_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "tutorial_swig_doc.i"

%{
#include "tutorial/qpsk_demod_cpp_cb.h"
%}


%include "tutorial/qpsk_demod_cpp_cb.h"
GR_SWIG_BLOCK_MAGIC2(tutorial, qpsk_demod_cpp_cb);
