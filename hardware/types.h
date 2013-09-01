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
* Description: Types definition
* Author: Caio Lima
* Date: 31 - 08 - 2013
*/ 

//TODO: Verify if it's platform independent
#include <stdint.h>

typedef uint8_t byte;
typedef uint16_t word;
typedef uint16_t addr_t;
typedef void (* instruction_t)() ;


