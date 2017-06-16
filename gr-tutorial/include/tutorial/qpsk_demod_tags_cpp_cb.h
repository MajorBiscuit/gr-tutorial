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


#ifndef INCLUDED_TUTORIAL_QPSK_DEMOD_TAGS_CPP_CB_H
#define INCLUDED_TUTORIAL_QPSK_DEMOD_TAGS_CPP_CB_H

#include <tutorial/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace tutorial {

    /*!
     * \brief <+description of block+>
     * \ingroup tutorial
     *
     */
    class TUTORIAL_API qpsk_demod_tags_cpp_cb : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<qpsk_demod_tags_cpp_cb> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of tutorial::qpsk_demod_tags_cpp_cb.
       *
       * To avoid accidental use of raw pointers, tutorial::qpsk_demod_tags_cpp_cb's
       * constructor is in a private implementation
       * class. tutorial::qpsk_demod_tags_cpp_cb::make is the public interface for
       * creating new instances.
       */
      static sptr make(gray_code);
    };

  } // namespace tutorial
} // namespace gr

#endif /* INCLUDED_TUTORIAL_QPSK_DEMOD_TAGS_CPP_CB_H */

