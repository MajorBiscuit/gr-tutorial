/* -*- c++ -*- */
/* 
 * Copyright 2017 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "qpsk_demod_tags_cpp_cb_impl.h"

namespace gr {
  namespace tutorial {

    qpsk_demod_tags_cpp_cb::sptr
    qpsk_demod_tags_cpp_cb::make(gray_code)
    {
      return gnuradio::get_initial_sptr
        (new qpsk_demod_tags_cpp_cb_impl(gray_code));
    }

    /*
     * The private constructor
     */
    qpsk_demod_tags_cpp_cb_impl::qpsk_demod_tags_cpp_cb_impl(gray_code)
      : gr::sync_block("qpsk_demod_tags_cpp_cb",
              gr::io_signature::make(1, 1, sizeof(gr_complex)),
	      gr::io_signature::make(1, 1, sizeof(char))),
	// initialise d_gray_code to gray_code
	d_gray_code(gray_code)
    {}

    /*
     * Our virtual destructor.
     */
    qpsk_demod_tags_cpp_cb_impl::~qpsk_demod_tags_cpp_cb_impl()
    {
    }

    int
    qpsk_demod_tags_cpp_cb_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const gr_complex *in = (const gr_complex *) input_items[0];
      unsigned char *out = (unsigned char *) output_items[0];
      gr_complex origin = gr_complex(0,0);

      // Do <+signal processing+>
      // Perform ML decoding over the input data to generate alphabets
      for(int i = 0; i < noutput_items; i++)
	{
	  out[i] = get_minimum_distances(in[i]);
	}
      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

    unsigned char
    qpsk_demod_cpp_cb_impl::get_minimum_distances(const gr_complex &sample)
    {
      /*
	Mapping with gray code:

	(-1+1j) 10 | 00 (1+1j)
	-----------+-----------
	(-1-1j) 11 | 01 (1-1j)

	Mapping without gray code:

	(-1+1j) 11 | 00 (1+1j)
	-----------+-----------
	(-1-1j) 10 | 01 (1-1j)
      */
      
      if (d_gray_code) {
	unsigned char bit0 = 0;
	unsigned char bit1 = 0;
	// The two lower quadrants have the 1st bit set to 1
	if (sample.imag() < 0) {
	  bit0 = 0x01;
	}
	// The two left quadrants have the 2nd bit set to 1
	if (sample.real() < 0) {
	  bit1 = 0x01 << 1;
	}
	return bit0 bitor bit1;
      }
      else {
	// Non-gray code
	if (sample.real() >= 0 and sample.imag() >= 0) { // 1+1j
	  return 0x00;
	}
	else if (sample.real() < 0 and sample.imag() >= 0) { // -1+1j
	  return 0x03;
	}
	else if (sample.real() < 0 and sample.imag() < 0) { // -1-1j
	  return 0x02;
	}
	else if (sample.real() >= 0 and sample.imag() < 0) { // 1-1j
	  return 0x01;
	} 
      }
    }

  } /* namespace tutorial */
} /* namespace gr */

