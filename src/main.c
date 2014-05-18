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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "swbprng.h"

int main(int argc, char *argv[]){
  int i;
  unsigned int rnd;
  SWBprng_Init(1273173);

  if(argc==1){
    printf("Subtract-With-Borrow Pseudo-Random Number Generator\n\n");

    printf("Int32 output:\n");
    for (i=0;i<10;i++){
      printf("%u\n",SWBprng_Int32());
    }; 

    printf("\nInt31 output:\n");
    for (i=0;i<10;i++){
      printf("%d\n",SWBprng_Int31());
    }; 

    printf("\nReal output:\n");
    for (i=0;i<10;i++){
      printf("%lf\n",SWBprng_Real());
    };

    printf("\nFor more information try: %s -h\n",argv[0]);

  }else{
    if(strcmp(argv[1],"-h")==0){
      printf("usage: %s <option>\n\n",argv[0]);
      printf("options:\n");
      printf("\t-b\tSet output to binary mode for dieharder test.\n");
      printf("\t-h\tShow this help.\n");
    };
    if(strcmp(argv[1],"-b")==0){
      while(1){
        rnd=SWBprng_Int32();
        fwrite(&rnd,sizeof(unsigned int),1,stdout);
      };
    };
  };
  return 0;
};

