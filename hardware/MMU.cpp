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
* Description: MMU implementation
* Author: Caio Lima
* Date: 31 - 08 - 2013
* 
* This class represents the GameBoy's  MMU. It's based on Imran Nazar's jsGB implementation
*/ 

#include "types.h"
#include "MMU.h"

byte MMU::readByte(addr_t addr){
  return 0;
};

word MMU::readWord(addr_t addr){
  return 0;
};

void MMU::writeByte(addr_t addr, byte value){
  
};

void MMU::writeWord(addr_t addr, word value){};