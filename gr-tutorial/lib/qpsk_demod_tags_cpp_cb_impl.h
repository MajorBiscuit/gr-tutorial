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

#ifndef INCLUDED_TUTORIAL_QPSK_DEMOD_TAGS_CPP_CB_IMPL_H
#define INCLUDED_TUTORIAL_QPSK_DEMOD_TAGS_CPP_CB_IMPL_H

#include <tutorial/qpsk_demod_tags_cpp_cb.h>

namespace gr {
  namespace tutorial {

    class qpsk_demod_tags_cpp_cb_impl : public qpsk_demod_tags_cpp_cb
    {
     private:
      bool d_gray_code;

     public:
      qpsk_demod_tags_cpp_cb_impl(bool gray_code);
      ~qpsk_demod_tags_cpp_cb_impl();

      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);

      unsigned char get_minimum_distances(const gr_complex &sample);
    };

  } // namespace tutorial
} // namespace gr

#endif /* INCLUDED_TUTORIAL_QPSK_DEMOD_TAGS_CPP_CB_IMPL_H */

