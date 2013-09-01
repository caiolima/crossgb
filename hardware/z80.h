/*This file is part of CrossGB project.
*
*CrossGB is free software: you can redistribute it and/or modify
*it under the terms of the GNU General Public License as published by
*the Free Software Foundation, either version 3 of the License, or
*(at your option) any later version.
*
*CrossGB is distributed in the hope that it will be useful,
*but WITHOUT ANY WARRANTY; without even the implied warranty of
*MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
*GNU General Public License for more details.
*
*You should have received a copy of the GNU General Public License
*along with CrossGB. If not, see <http://www.gnu.org/licenses/>.
*
* Description: Z80 core implementation
* Author: Caio Lima
* Date: 31 - 08 - 2013
* 
* This class represents the GameBoy's CPU z80. It's based on Imran Nazar's jsGB implementation
*/ 

#include "types.h"
#include "MMU.h"

#ifndef z80_H
#define z80_H

class z80{

private:
  //List of registers. These registers are 8 byte
  byte r_a, r_b, r_c, r_d, r_e, r_h, r_l, flags;
  word pc, sp;

  //clock counter m is inctruction clock counter and clock_m is total clock counter
  long m, clock_m;
  long ime; //???

  MMU aMMU;
  
public:
  //Instruction operations definition

  //Load/Store functions
  void LDrr_bb();
  void LDrr_bc();
  void LDrr_bd();
  void LDrr_be();
  void LDrr_bh();
  void LDrr_bl();
  void LDrr_ba();
  void LDrr_cb();
  void LDrr_cc();
  void LDrr_cd();
  void LDrr_ce();
  void LDrr_ch();
  void LDrr_cl();
  void LDrr_ca();
  void LDrr_db();
  void LDrr_dc();
  void LDrr_dd();
  void LDrr_de();
  void LDrr_dh();
  void LDrr_dl();
  void LDrr_da();
  void LDrr_eb();
  void LDrr_ec();
  void LDrr_ed();
  void LDrr_ee();
  void LDrr_eh();
  void LDrr_el();
  void LDrr_ea();
  void LDrr_hb();
  void LDrr_hc();
  void LDrr_hd();
  void LDrr_he();
  void LDrr_hh();
  void LDrr_hl();
  void LDrr_ha();
  void LDrr_lb();
  void LDrr_lc();
  void LDrr_ld();
  void LDrr_le();
  void LDrr_lh();
  void LDrr_ll();
  void LDrr_la();
  void LDrr_ab();
  void LDrr_ac();
  void LDrr_ad();
  void LDrr_ae();
  void LDrr_ah();
  void LDrr_al();
  void LDrr_aa();

  void LDrHLm_b();
  void LDrHLm_c();
  void LDrHLm_d();
  void LDrHLm_e();
  void LDrHLm_h();
  void LDrHLm_l();
  void LDrHLm_a();

  void LDHLmr_b();
  void LDHLmr_c();
  void LDHLmr_d();
  void LDHLmr_e();
  void LDHLmr_h();
  void LDHLmr_l();
  void LDHLmr_a();

  void LDrn_b();
  void LDrn_c();
  void LDrn_d();
  void LDrn_e();
  void LDrn_h();
  void LDrn_l();
  void LDrn_a();

  void LDHLmn();

  void LDBCmA();
  void LDDEmA();

  void LDmmA();

  void LDABCm();
  void LDADEm();

  void LDAmm();

  void LDBCnn();
  void LDDEnn();
  void LDHLnn();
  void LDSPnn();

  void LDHLmm();
  void LDmmHL();

  void LDHLIA();
  void LDAHLI();

  void LDHLDA();
  void LDAHLD();

  void LDAIOn();
  void LDIOnA();
  void LDAIOC();
  void LDIOCA();

  void LDHLSPn();

  void SWAPr_b();
  void SWAPr_c();
  void SWAPr_d();
  void SWAPr_e();
  void SWAPr_h();
  void SWAPr_l();
  void SWAPr_a();

};

#endif