/*    
  This file was generated automatically with ../scripts/maple2c.pl.   
  Do not edit this file directly as it can be overwritten!!   
   
  This Source Code Form is subject to the terms of the Mozilla Public   
  License, v. 2.0. If a copy of the MPL was not distributed with this   
  file, You can obtain one at http://mozilla.org/MPL/2.0/.   
   
  Maple version     : Maple 2016 (X86 64 LINUX)   
  Maple source      : ../maple/lda_x_2d.mpl   
  Type of functional: work_lda   
*/   
   
#ifdef DEVICE   
__device__ static void   
xc_lda_x_2d_func0_kernel(const void *p, xc_lda_work_t *r)   
#else   
static void   
func0(const xc_func_type *p, xc_lda_work_t *r)   
#endif   
{   
  double t1, t5, t12;   
   
   
  t1 = M_SQRT2;   
  r->f = -0.42441318157838756203e0 * t1 / r->rs;   
   
  if(r->order < 1) return;   
   
  t5 = r->rs * r->rs;   
  r->dfdrs = 0.42441318157838756203e0 * t1 / t5;   
   
  if(r->order < 2) return;   
   
  r->d2fdrs2 = -0.84882636315677512406e0 * t1 / t5 / r->rs;   
   
  if(r->order < 3) return;   
   
  t12 = t5 * t5;   
  r->d3fdrs3 = 0.25464790894703253722e1 * t1 / t12;   
   
  if(r->order < 4) return;   
   
   
}   
   
#ifdef DEVICE   
__device__ static void   
xc_lda_x_2d_func1_kernel(const void *p, xc_lda_work_t *r)   
#else   
static void   
func1(const xc_func_type *p, xc_lda_work_t *r)   
#endif   
{   
  double t1, t3, t4, t5, t6, t7, t8, t9;   
  double t11, t12, t16, t17, t21, t26, t35, t39;   
   
   
  t1 = M_SQRT2;   
  t3 = t1 / 0.31415926535897932385e1;   
  t4 = 0.1e1 + r->z;   
  t5 = sqrt(t4);   
  t6 = t5 * t4;   
  t7 = 0.1e1 - r->z;   
  t8 = sqrt(t7);   
  t9 = t8 * t7;   
  t11 = t6 / 0.2e1 + t9 / 0.2e1;   
  t12 = 0.1e1 / r->rs;   
  r->f = -0.4e1 / 0.3e1 * t3 * t11 * t12;   
   
  if(r->order < 1) return;   
   
  t16 = r->rs * r->rs;   
  t17 = 0.1e1 / t16;   
  r->dfdrs = 0.4e1 / 0.3e1 * t3 * t11 * t17;   
  t21 = 0.3e1 / 0.4e1 * t5 - 0.3e1 / 0.4e1 * t8;   
  r->dfdz = -0.4e1 / 0.3e1 * t3 * t21 * t12;   
   
  if(r->order < 2) return;   
   
  t26 = 0.1e1 / t16 / r->rs;   
  r->d2fdrs2 = -0.8e1 / 0.3e1 * t3 * t11 * t26;   
  r->d2fdrsz = 0.4e1 / 0.3e1 * t3 * t21 * t17;   
  t35 = 0.3e1 / 0.8e1 / t5 + 0.3e1 / 0.8e1 / t8;   
  r->d2fdz2 = -0.4e1 / 0.3e1 * t3 * t35 * t12;   
   
  if(r->order < 3) return;   
   
  t39 = t16 * t16;   
  r->d3fdrs3 = 0.8e1 * t3 * t11 / t39;   
  r->d3fdrs2z = -0.8e1 / 0.3e1 * t3 * t21 * t26;   
  r->d3fdrsz2 = 0.4e1 / 0.3e1 * t3 * t35 * t17;   
  r->d3fdz3 = -0.4e1 / 0.3e1 * t3 * (-0.3e1 / 0.16e2 / t6 + 0.3e1 / 0.16e2 / t9) * t12;   
   
  if(r->order < 4) return;   
   
   
}   
   
#ifdef DEVICE   
__device__ void   
xc_lda_x_2d_func_kernel(const void *p, xc_lda_work_t *r)   
{   
  if(r->nspin == XC_UNPOLARIZED)   
xc_lda_x_2d_func0_kernel(p, r);   
  else   
xc_lda_x_2d_func1_kernel(p, r);   
}   
#else   
void    
xc_lda_x_2d_func(const xc_func_type *p, xc_lda_work_t *r)   
{   
  if(p->nspin == XC_UNPOLARIZED)   
    func0(p, r);   
  else   
    func1(p, r);   
}   
#endif   
   
#ifndef DEVICE   
#define maple2c_order 3   
#define maple2c_func  xc_lda_x_2d_func   
#define kernel_id 24 
#endif
