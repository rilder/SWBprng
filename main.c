/*
 * Copyright (c) 2014, Rilder Pires
 * All rights reserved.
 *
 * Subtract-With-Borrow Pseudo-Random Number Generator
 * This file is part of the SWBprng (Subtract-With-Borrow Pseudo-Random Number
 * Generator) algorithm described in this paper:
 *
 *   A random number generator for PC’s
 *   G. Marsaglia, B. Narasimhan and A. Zaman
 *   1990
 *
 * Any feedback is very welcome.
 * email: rilder@fisica.ufc.br
 * 
 * LICENSE:
 *
 * You may use this file under the terms of the BSD license as follows:
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 
 *  1. Redistributions of source code must retain the above copyright
 * 	  notice, this list of conditions and the following disclaimer.
 * 
 *  2. Redistributions in binary form must reproduce the above copyright
 * 	  notice, this list of conditions and the following disclaimer in the
 * 	  documentation and/or other materials provided with the distribution.
 * 
 *  3. The names of its contributors may not be used to endorse or promote 
 * 	  products derived from this software without specific prior written 
 * 	  permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <stdlib.h>

#define SWBprng_R 43
#define SWBprng_S 22
#define SWBprng_B 4294967296

unsigned int SWBprng_x[SWBprng_R];
unsigned int SWBprng_c=0;
int SWBprng_idx = SWBprng_R;

void SWBprng_Init(int seed){
  int i,j;
  unsigned int y[3];
  unsigned int z,yy,zz,x;
  int idx=3,bi,b;
  
  z=seed;
  y[0]=(8191*z+131071)%SWBprng_R;
  y[1]=(8191*y[0]+131071)%SWBprng_R;
  y[2]=(8191*y[1]+131071)%SWBprng_R;
  
  for(j=0;j<SWBprng_R;j++){
    x=0;
    b=2147483648;
    for(i=0;i<32;i++){
      yy = (y[(idx-3)%3]*y[(idx-2)%3]*y[(idx-1)%3])%179;
      zz = (53*z +1)%169;
      bi = (((yy*zz)%63)<32)?0:1;

      x+=b*bi;
      y[idx%3]=yy; z=zz; idx++;
      if(idx>6) idx-=3;
      b/=2;
    };
    SWBprng_x[j] = x;
  };
};

unsigned int SWBprng_Int32(){
  unsigned int rnd,rnd1,rnd2;
  rnd1 = SWBprng_x[(SWBprng_idx-SWBprng_S)%SWBprng_R];
  rnd2 = SWBprng_x[(SWBprng_idx-SWBprng_R)%SWBprng_R]+SWBprng_c;

  if (rnd2>rnd1) SWBprng_c = 1; else SWBprng_c = 0; 
  rnd = (rnd1 + (SWBprng_B - rnd2))%SWBprng_B;

  SWBprng_x[SWBprng_idx%SWBprng_R]=rnd;
  SWBprng_idx++;
  if(SWBprng_idx==(2*SWBprng_R)) SWBprng_idx-=SWBprng_R;
  return rnd;
}

int SWBprng_Int31(){
  return (SWBprng_Int32()%2147483648);
}

double SWBprng_Real(void){
  return (((double)SWBprng_Int32())/4294967296.0);
}

int main(){
  int i;
  unsigned int rnd;
  SWBprng_Init(1273173);

/*  For Dieharder test  */
/*  while(1){*/
/*    rnd=SWBprng_Int32();*/
/*    fwrite(&rnd,sizeof(unsigned int),1,stdout);*/
/*  };*/

  printf("Int32:\n");
  for (i=0;i<10;i++){
    printf("%u\n",SWBprng_Int32());
  }  

  printf("\nInt31:\n");
  for (i=0;i<10;i++){
    printf("%d\n",SWBprng_Int31());
  }  

  printf("\nReal:\n");
  for (i=0;i<10;i++){
    printf("%lf\n",SWBprng_Real());
  }  

  return 0;
};

