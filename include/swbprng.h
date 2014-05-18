/*
Copyright (c) 2014, Rilder Pires
All rights reserved.

Subtract-With-Borrow Pseudo-Random Number Generator
This file is part of the SWBprng (Subtract-With-Borrow Pseudo-Random Number
Generator) algorithm described in this paper:

  A random number generator for PC’s
  G. Marsaglia, B. Narasimhan and A. Zaman
  1990

LICENSE:

You may use this file under the terms of the BSD license as follows:

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * The names of its contributors may not be used to endorse or promote
      products derived from this software without specific prior written
      permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef __SWBPRNG_H__
#define __SWBPRNG_H__

#include <stdio.h>
#include <stdlib.h>

#define SWBprng_R 43
#define SWBprng_S 22
#define SWBprng_B 4294967296

/* Functions: */

void SWBprng_Init(int seed);

unsigned int SWBprng_Int32();

int SWBprng_Int31();

double SWBprng_Real();

#endif /* __SWBPRNG_H__ */
