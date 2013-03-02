/* -*- c++ -*- */
/* 
 * Copyright 2013  Sylvain Munaut <tnt@246tNt.com>
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


#ifndef INCLUDED_IQBALANCE_OPTIMIZE_C_H
#define INCLUDED_IQBALANCE_OPTIMIZE_C_H

#include <iqbalance_api.h>
#include <gr_sync_block.h>

class iqbalance_optimize_c;

typedef boost::shared_ptr<iqbalance_optimize_c> iqbalance_optimize_c_sptr;

IQBALANCE_API iqbalance_optimize_c_sptr iqbalance_make_optimize_c (int period);

/*!
 * \brief <+description+>
 * \ingroup block
 *
 */
class IQBALANCE_API iqbalance_optimize_c : public gr_sync_block
{
 private:
  friend IQBALANCE_API iqbalance_optimize_c_sptr iqbalance_make_optimize_c (int period);

  iqbalance_optimize_c(int period);

  int d_period, d_count;
  bool d_first;
  float d_mag, d_phase;

 public:
  ~iqbalance_optimize_c();

  void set_period(int period) { this->d_period = period; }
  const int period() const { return this->d_period; }

  const float mag() const { return this->d_mag; }
  const float phase() const { return this->d_phase; }

  void reset(void) { this->d_first = true; this->d_mag = this->d_phase = 0.0f; }

  void forecast (int noutput_items, gr_vector_int &ninput_items_required);

  int work (int noutput_items,
            gr_vector_const_void_star &input_items,
            gr_vector_void_star &output_items);
};

#endif /* INCLUDED_IQBALANCE_OPTIMIZE_C_H */
