# insn-bench-rpi

Yet another instruction benchmark program mainly for Raspberry Pi 2 and 3.


## Building

```
$ make
```


## Running

```
$ ./main
```

<table>
<tr> <th>Cortex-A7 (32bit)</th> <th>Cortex-A53 (32bit)</th> </tr> <tr> <td><pre>

vaba.u32    d3:  5.00  2.13  2.20
vaba.u32    q3:  5.06  4.25  4.40

vabd.u32    d3:  4.00  1.13  1.20
vabd.u32    q3:  4.00  2.25  2.40
vabd.f32    d3:  4.00  2.13  2.20
vabd.f32    q3:  4.13  4.25  4.40

vabs.s32    d2:  4.00  1.13
vabs.s32    q2:  4.00  2.25
vabs.f32    d2:  4.00  2.13
vabs.f32    q2:  4.13  4.25

vacge.f32   d2:  4.00  2.13
vacge.f32   q2:  4.13  4.25

vadd.i32    d3:  4.00  1.13  1.20
vadd.i32    q3:  4.00  2.25  2.40
vadd.f32    d3:  4.00  2.13  2.20
vadd.f32    q3:  4.13  4.25  4.40

vand        d3:  4.00  1.13  1.20
vand        q3:  4.00  2.25  2.40

vbic        d3:  4.00  1.13  1.20
vbic        q3:  4.00  2.25  2.40

vbif        d3:  4.00  1.13  1.20
vbif        q3:  4.00  2.25  2.40

vbsl        d3:  4.00  1.13  1.20
vbsl        q3:  4.00  2.25  2.40

vcge.u32    d3:  4.00  1.13  1.20
vcge.u32    q3:  4.00  2.25  2.40
vcge.f32    d3:  4.00  2.13  2.20
vcge.f32    q3:  4.13  4.25  4.40

vclz.i32    d2:  4.00  1.13
vclz.i32    q2:  4.00  2.25

vcmp.f32    s2:  1.06  1.06

vdiv.f32    s3: 18.00 15.00 15.00

vfma.f32    s3:  8.00  1.06  1.10
vfma.f32    d3:  8.00  2.13  2.20
vfma.f32    q3:  8.00  4.25  4.40

vmax.u32    d3:  4.00  1.13  1.20
vmax.u32    q3:  4.00  2.25  2.40
vmax.f32    d3:  4.00  2.13  2.20
vmax.f32    q3:  4.13  4.25  4.40

vmla.i32    d3:  4.00  2.13  2.20
vmla.i32    q3:  4.13  4.25  4.40
vmla.f32    s3:  8.00  1.06  1.10
vmla.f32    d3:  8.00  2.13  2.20
vmla.f32    q3:  8.00  4.25  4.40

vmov.f32    s2:  4.00  1.06
vmov.f32    d2:  4.00  1.13
vmov.f32    q2:  4.00  2.25

vmul.i32    d3:  4.00  2.13  2.20
vmul.i32    q3:  4.13  4.25  4.40
vmul.f32    s3:  4.00  1.06  1.10
vmul.f32    d3:  4.00  2.13  2.20
vmul.f32    q3:  4.13  4.25  4.40

vneg.s32    d2:  4.00  1.13
vneg.s32    q2:  4.00  2.25
vneg.f32    s2:  4.00  1.06
vneg.f32    d2:  4.00  2.13
vneg.f32    q2:  4.13  4.25

vpadal.u32  d2:  5.00  2.13
vpadal.u32  q2:  5.06  4.25

vpadd.i32   d3:  4.00  1.13  1.20
vpadd.f32   d3:  5.00  2.13  2.20

vrecpe.u32  d2:  4.00  2.13
vrecpe.u32  q2:  4.13  4.25
vrecpe.f32  d2:  4.00  2.13
vrecpe.f32  q2:  4.13  4.25

vrecps.f32  d3:  8.00  2.13  2.20
vrecps.f32  q3:  8.00  4.25  4.40

vrev64.8    d2:  4.00  1.13
vrev64.8    q2:  4.00  2.25

vrhadd.u32  d3:  4.00  1.13  1.20
vrhadd.u32  q3:  4.00  2.25  2.40

vrsqrte.u32 d2:  4.00  2.13
vrsqrte.u32 q2:  4.13  4.25
vrsqrte.f32 d2:  4.00  2.13
vrsqrte.f32 q2:  4.13  4.25

vrsqrts.f32 d3:  8.00  2.13  2.20
vrsqrts.f32 q3:  8.00  4.25  4.40

vsqrt.f32   s2: 17.00 14.00

vswp        d2:  5.00  2.13
vswp        q2:  5.06  4.25

vtrn.8      d2:  5.00  2.13
vtrn.8      q2:  5.06  4.25</pre></td> <td><pre>vaba.u32    d3:  4.00  2.06  2.10
vaba.u32    q3:  4.00  2.13  2.20

vabd.u32    d3:  3.00  0.56  0.60
vabd.u32    q3:  3.00  1.13  1.20
vabd.f32    d3:  4.00  0.56  0.60
vabd.f32    q3:  4.00  1.13  1.20

vabs.s32    d2:  3.00  0.56
vabs.s32    q2:  3.00  1.13
vabs.f32    d2:  4.00  0.56
vabs.f32    q2:  4.00  1.13

vacge.f32   d2:  2.00  0.56
vacge.f32   q2:  2.00  1.13

vadd.i32    d3:  2.00  0.56  0.60
vadd.i32    q3:  2.00  1.13  1.20
vadd.f32    d3:  4.00  0.56  0.60
vadd.f32    q3:  4.00  1.13  1.20

vand        d3:  1.00  0.56  0.60
vand        q3:  1.06  1.13  1.20

vbic        d3:  1.00  0.56  0.60
vbic        q3:  1.06  1.13  1.20

vbif        d3:  2.00  0.56  0.60
vbif        q3:  2.00  1.13  1.20

vbsl        d3:  2.00  0.56  0.60
vbsl        q3:  2.00  1.13  1.20

vcge.u32    d3:  2.00  0.56  0.60
vcge.u32    q3:  2.00  1.13  1.20
vcge.f32    d3:  2.00  0.56  0.60
vcge.f32    q3:  2.00  1.13  1.20

vclz.i32    d2:  2.00  0.56
vclz.i32    q2:  2.00  1.13

vcmp.f32    s2:  0.56  0.56

vdiv.f32    s3: 13.00 10.00 10.00

vfma.f32    s3:  8.00  0.56  0.70
vfma.f32    d3:  8.00  0.56  0.70
vfma.f32    q3:  8.00  1.13  1.20

vmax.u32    d3:  2.00  0.56  0.60
vmax.u32    q3:  2.00  1.13  1.20
vmax.f32    d3:  4.00  0.56  0.60
vmax.f32    q3:  4.00  1.13  1.20

vmla.i32    d3:  4.00  0.56  0.60
vmla.i32    q3:  4.00  1.13  1.20
vmla.f32    s3:  8.00  0.56  0.70
vmla.f32    d3:  8.00  0.56  0.70
vmla.f32    q3:  8.00  1.13  1.20

vmov.f32    s2:  1.00  0.56
vmov.f32    d2:  1.00  0.56
vmov.f32    q2:  1.06  1.13

vmul.i32    d3:  4.00  0.56  0.60
vmul.i32    q3:  4.00  1.13  1.20
vmul.f32    s3:  4.00  0.56  0.60
vmul.f32    d3:  4.00  0.56  0.60
vmul.f32    q3:  4.00  1.13  1.20

vneg.s32    d2:  2.00  0.56
vneg.s32    q2:  2.00  1.13
vneg.f32    s2:  4.00  0.56
vneg.f32    d2:  4.00  0.56
vneg.f32    q2:  4.00  1.13

vpadal.u32  d2:  4.00  2.06
vpadal.u32  q2:  4.00  2.13

vpadd.i32   d3:  3.00  0.56  0.60
vpadd.f32   d3:  4.00  0.56  0.60

vrecpe.u32  d2:  4.00  0.56
vrecpe.u32  q2:  4.00  1.13
vrecpe.f32  d2:  4.00  0.56
vrecpe.f32  q2:  4.00  1.13

vrecps.f32  d3:  8.00  0.56  0.70
vrecps.f32  q3:  8.00  1.13  1.20

vrev64.8    d2:  2.00  0.56
vrev64.8    q2:  2.00  1.13

vrhadd.u32  d3:  2.00  0.56  0.60
vrhadd.u32  q3:  2.00  1.13  1.20

vrsqrte.u32 d2:  4.00  0.56
vrsqrte.u32 q2:  4.00  1.13
vrsqrte.f32 d2:  4.00  0.56
vrsqrte.f32 q2:  4.00  1.13

vrsqrts.f32 d3:  8.00  0.56  0.70
vrsqrts.f32 q3:  8.00  1.13  1.20

vsqrt.f32   s2: 12.00  9.00

vswp        d2:  1.06  1.06
vswp        q2:  1.06  2.13

vtrn.8      d2:  4.00  3.06
vtrn.8      q2:  4.00  3.13</pre></td> </tr></table>
