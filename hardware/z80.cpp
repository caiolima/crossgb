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
#include "z80.h"

#define IMPL_LDrr(METHOD_NAME,X,Y) \
void z80::METHOD_NAME(){ \
  X = Y; \
  m = 1; \
}

IMPL_LDrr(LDrr_bb,r_b,r_b);
IMPL_LDrr(LDrr_bc,r_b,r_c);
IMPL_LDrr(LDrr_bd,r_b,r_d);
IMPL_LDrr(LDrr_be,r_b,r_e);
IMPL_LDrr(LDrr_bh,r_b,r_h);
IMPL_LDrr(LDrr_bl,r_b,r_l);
IMPL_LDrr(LDrr_ba,r_b,r_a);

IMPL_LDrr(LDrr_cb,r_c,r_b);
IMPL_LDrr(LDrr_cc,r_c,r_c);
IMPL_LDrr(LDrr_cd,r_c,r_d);
IMPL_LDrr(LDrr_ce,r_c,r_e);
IMPL_LDrr(LDrr_ch,r_c,r_h);
IMPL_LDrr(LDrr_cl,r_c,r_l);
IMPL_LDrr(LDrr_ca,r_c,r_a);

IMPL_LDrr(LDrr_db,r_d,r_b);
IMPL_LDrr(LDrr_dc,r_d,r_c);
IMPL_LDrr(LDrr_dd,r_d,r_d);
IMPL_LDrr(LDrr_de,r_d,r_e);
IMPL_LDrr(LDrr_dh,r_d,r_h);
IMPL_LDrr(LDrr_dl,r_d,r_l);
IMPL_LDrr(LDrr_da,r_d,r_a);

IMPL_LDrr(LDrr_eb,r_e,r_b);
IMPL_LDrr(LDrr_ec,r_e,r_c);
IMPL_LDrr(LDrr_ed,r_e,r_d);
IMPL_LDrr(LDrr_ee,r_e,r_e);
IMPL_LDrr(LDrr_eh,r_e,r_h);
IMPL_LDrr(LDrr_el,r_e,r_l);
IMPL_LDrr(LDrr_ea,r_e,r_a);

IMPL_LDrr(LDrr_hb,r_h,r_b);
IMPL_LDrr(LDrr_hc,r_h,r_c);
IMPL_LDrr(LDrr_hd,r_h,r_d);
IMPL_LDrr(LDrr_he,r_h,r_e);
IMPL_LDrr(LDrr_hh,r_h,r_h);
IMPL_LDrr(LDrr_hl,r_h,r_l);
IMPL_LDrr(LDrr_ha,r_h,r_a);

IMPL_LDrr(LDrr_lb,r_l,r_b);
IMPL_LDrr(LDrr_lc,r_l,r_c);
IMPL_LDrr(LDrr_ld,r_l,r_d);
IMPL_LDrr(LDrr_le,r_l,r_e);
IMPL_LDrr(LDrr_lh,r_l,r_h);
IMPL_LDrr(LDrr_ll,r_l,r_l);
IMPL_LDrr(LDrr_la,r_l,r_a);

IMPL_LDrr(LDrr_ab,r_a,r_b);
IMPL_LDrr(LDrr_ac,r_a,r_c);
IMPL_LDrr(LDrr_ad,r_a,r_d);
IMPL_LDrr(LDrr_ae,r_a,r_e);
IMPL_LDrr(LDrr_ah,r_a,r_h);
IMPL_LDrr(LDrr_al,r_a,r_l);
IMPL_LDrr(LDrr_aa,r_a,r_a);

#define IMPL_LDrHLm(METHOD_NAME, X) \
void z80::METHOD_NAME(){ \
  addr_t aAddr = r_h; \
  X = aMMU.readByte((aAddr << 8) + r_l); \
  m = 2; \
} 

IMPL_LDrHLm(LDrHLm_b,r_b);
IMPL_LDrHLm(LDrHLm_c,r_c);
IMPL_LDrHLm(LDrHLm_d,r_d);
IMPL_LDrHLm(LDrHLm_e,r_e);
IMPL_LDrHLm(LDrHLm_h,r_h);
IMPL_LDrHLm(LDrHLm_l,r_l);
IMPL_LDrHLm(LDrHLm_a,r_a);

#define IMPL_LDHLmr(METHOD_NAME, X) \
void z80::METHOD_NAME(){ \
  addr_t aAddr = r_h; \
  aMMU.writeByte((aAddr << 8) + r_l, X); \
  m = 2; \
}

IMPL_LDHLmr(LDHLmr_b, r_b);
IMPL_LDHLmr(LDHLmr_c, r_c);
IMPL_LDHLmr(LDHLmr_d, r_d);
IMPL_LDHLmr(LDHLmr_e, r_e);
IMPL_LDHLmr(LDHLmr_h, r_h);
IMPL_LDHLmr(LDHLmr_l, r_l);
IMPL_LDHLmr(LDHLmr_a, r_a);

#define IMPL_LDrn(METHOD_NAME, X) \
void z80::METHOD_NAME(){ \
  X = aMMU.readByte(pc); \
  pc++; \
  m = 2; \
}

IMPL_LDrn(LDrn_b, r_b);
IMPL_LDrn(LDrn_c, r_c);
IMPL_LDrn(LDrn_d, r_d);
IMPL_LDrn(LDrn_e, r_e);
IMPL_LDrn(LDrn_h, r_h);
IMPL_LDrn(LDrn_l, r_l);
IMPL_LDrn(LDrn_a, r_a);

void z80::LDHLmn(){
  addr_t aAddr = r_h;
  aMMU.writeByte((aAddr << 8) + r_l, aMMU.readByte(pc));
  pc++;
  m = 3;
};

void z80::LDBCmA(){
  addr_t aAddr = r_b;
  aMMU.writeByte((aAddr << 8)+r_c, r_a);
  m = 2;
};

void z80::LDDEmA(){
  addr_t aAddr = r_d;
  aMMU.writeByte((aAddr << 8)+r_e, r_a);
  m = 2;
};

void z80::LDmmA(){
  aMMU.writeByte(aMMU.readWord(pc), r_a);
  pc += 2;
  m = 4;
};

void z80::LDABCm(){
  addr_t aAddr = r_b;
  r_a = aMMU.readByte((aAddr << 8) + r_c);
  m = 2;
}

void z80::LDADEm(){
  addr_t aAddr = r_d;
  r_a = aMMU.readByte((aAddr << 8) + r_e);
  m = 2;
}

void z80::LDAmm(){
  r_a = aMMU.readByte(aMMU.readWord(pc));
  pc += 2;
  m = 4;
}

#define IMPL_LD_nn(METHOD_NAME, X, Y) \
void z80::METHOD_NAME(){ \
  X = aMMU.readByte(pc); \
  Y = aMMU.readByte(pc + 1); \
  pc += 2; \
  m = 3; \
}

IMPL_LD_nn(LDBCnn, r_c, r_b);
IMPL_LD_nn(LDDEnn, r_e, r_d);
IMPL_LD_nn(LDHLnn, r_l, r_h);

void z80::LDSPnn(){
  sp = aMMU.readWord(pc);
  pc += 2;
  m = 3;
};

void z80::LDHLmm(){
  addr_t aAddr = aMMU.readWord(pc);
  pc += 2;
  r_l = aMMU.readByte(aAddr);
  r_h = aMMU.readByte(aAddr + 1);
  m = 5;
};

void z80::LDmmHL(){
  addr_t aAddr = aMMU.readWord(pc);
  pc += 2;
  word aWord = r_h;
  aMMU.writeWord(aAddr,(aWord << 8) + r_l);
  m = 5;
};

void z80::LDHLIA(){
  addr_t aAddr = r_h;
  aMMU.writeByte((aAddr << 8) + r_l, r_a);
  r_l = (r_l+1) & 255;
  if(!r_l)
    r_h = (r_h + 1) & 255;
  m = 2;
};

void z80::LDAHLI(){
  addr_t aAddr = r_h;
  r_a = aMMU.readByte((aAddr << 8) + r_l);
  r_l = (r_l+1) & 255;
  if(!r_l)
    r_h = (r_h + 1) & 255;
  m = 2;
};

void z80::LDHLDA(){
  addr_t aAddr = r_h;
  aMMU.writeByte((aAddr << 8) + r_l, r_a);
  r_l = (r_l-1) & 255;
  if(r_l == 255)
    r_h = (r_h - 1) & 255;
  m = 2;
};

void z80::LDAHLD(){
  addr_t aAddr = r_h;
  r_a = aMMU.readByte((aAddr << 8) + r_l);
  r_l = (r_l - 1) & 255;
  if(r_l == 255)
    r_h = (r_h - 1) & 255;
  m = 2;
};

void z80::LDAIOn(){
  r_a = aMMU.readByte(0xFF00 + aMMU.readByte(pc));
  pc++;
  m = 3;
};

void z80::LDIOnA(){
  aMMU.writeByte(0xFF00 + aMMU.readByte(pc), r_a);
  pc++;
  m = 3;
};

void z80::LDAIOC(){
  r_a = aMMU.readByte(0xFF00 + r_c);
  m = 2;
};

void z80::LDIOCA(){
  aMMU.writeByte(0xFF00 + r_c, r_a);
  m = 2;
};

//TODO: Verify about this instruction. It may be bugged
void z80::LDHLSPn(){
  word aWord = aMMU.readByte(pc);
  if(aWord > 127)
  	aWord = -((~aWord + 1) & 255);
  pc++;
  aWord += sp;
  r_h = (aWord >> 8) & 255;
  r_l = aWord & 255;
  m = 3;
};

#define IMPL_SWAPR(METHOD_NAME, X) \
void z80::METHOD_NAME(){ \
  byte aByte = X; \
  X = ((aByte & 0xF) << 4) | ((aByte & 0xF0) >> 4); \
  flags = X ? 0 : 0x80; \
  m = 1; \
}

IMPL_SWAPR(SWAPr_b, r_b);
IMPL_SWAPR(SWAPr_c, r_c);
IMPL_SWAPR(SWAPr_d, r_d);
IMPL_SWAPR(SWAPr_e, r_e);
IMPL_SWAPR(SWAPr_h, r_h);
IMPL_SWAPR(SWAPr_l, r_l);
IMPL_SWAPR(SWAPr_a, r_a);

/* -- Data processing Instructions --*/
#define IMPL_ADD_R(METHOD_NAME, X) \
void z80::METHOD_NAME(){ \
  byte aByte = r_a; \
  r_a += X; \
  flags = (r_a > 255)?0x10:0; \
  r_a &= 255; \
  if(!r_a) \
    flags |= 0x80; \
  if((r_a ^ X ^ aByte) & 0x10) \
    flags |= 0x20; \
  m=1; \
}

IMPL_ADD_R(ADDr_b, r_b);
IMPL_ADD_R(ADDr_c, r_c);
IMPL_ADD_R(ADDr_d, r_d);
IMPL_ADD_R(ADDr_e, r_e);
IMPL_ADD_R(ADDr_h, r_h);
IMPL_ADD_R(ADDr_l, r_l);
IMPL_ADD_R(ADDr_a, r_a);

void z80::ADDHL(){
  byte aByte=r_a;
  addr_t aAddr = r_h;
  byte aData = aMMU.readByte((aAddr << 8) + r_l);
  r_a += aData;
  flags=(r_a > 255) ? 0x10 : 0;
  r_a &= 255;
  
  if(!r_a)
    flags |= 0x80;
  
  if((r_a ^ aByte ^ aData)&0x10)
    flags |= 0x20;

  m = 2;
};

void z80::ADDn(){
  byte aByte = r_a;
  byte aData = aMMU.readByte(pc); 
  r_a += m; 
  pc++;
  flags=(r_a > 255) ? 0x10 : 0;
  r_a &= 255;
  
  if(!r_a)
    flags |= 0x80;
  
  if((r_a ^ aByte ^ aData)&0x10)
    flags |= 0x20;

  m = 2;
};

#define IMPL_ADDHL(METHOD_NAME,X,Y) \
void z80::METHOD_NAME(){ \
  word hl = r_h; \
  hl = (hl << 8) + r_l; \
  word tempWord = X; \
  hl += (tempWord << 8) + Y; \
  if(hl>65535) \
    flags |= 0x10; \
  else \
    flags &= 0xEF; \ 
  r_h = (hl >> 8) & 255; \ 
  r_l =hl & 255; \
  m = 3; \
}

IMPL_ADDHL(ADDHLBC, r_b, r_c);
IMPL_ADDHL(ADDHLDE, r_d, r_e);
IMPL_ADDHL(ADDHLHL, r_h, r_l);

void z80::ADDHLSP(){
  word hl = r_h;
  hl = (hl << 8) + r_l; 
  hl += sp; 
  if(hl > 65535) 
    flags |= 0x10; 
  else 
    flags &= 0xEF; 
  r_h = (hl >> 8) & 255; 
  r_l = hl & 255; 
  m = 3;
}; 

void z80::ADDSPn(){
  byte i = aMMU.readByte(pc); 
  if(i > 127) 
    i=-((~i + 1) & 255); 
  pc++; 
  sp+=i; 
  m=4;
};

#define IMPL_ADCR(METHOD_NAME, X) \
void z80::METHOD_NAME(){ \
  byte a = r_a; \
  r_a += X; \
  r_a += (flags & 0x10) ? 1 : 0; \
  flags = (r_a > 255) ? 0x10 : 0; \
  r_a &= 255; \
  if(!r_a) \
    flags |= 0x80; \ 
  if((r_a ^ X ^ a) & 0x10) \ 
    flags |= 0x20; \
  m=1; \
}

IMPL_ADCR(ADCr_b, r_b);
IMPL_ADCR(ADCr_c, r_c);
IMPL_ADCR(ADCr_d, r_d);
IMPL_ADCR(ADCr_e, r_e);
IMPL_ADCR(ADCr_h, r_h);
IMPL_ADCR(ADCr_l, r_l);
IMPL_ADCR(ADCr_a, r_a);

