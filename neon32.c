#if !defined(__arm__) || defined(__aarch64__)
#error "This code is for AArch32 only. Use a suitable compiler."
#endif

#include <stdio.h>
#include <stdlib.h>
#include "arm32_common.h"

int main()
{
    cycle_count_init();

    LATTH_3__DQ("vaba.u32");
    puts("");

    LATTH_3__DQ("vabd.u32");
    LATTH_3__DQ("vabd.f32");
    puts("");

    LATTH_2__DQ("vabs.s32");
    LATTH_2__DQ("vabs.f32");
    puts("");

    LATTH_2__DQ("vacge.f32");
    puts("");

    LATTH_3__DQ("vadd.i32");
    LATTH_3__DQ("vadd.f32");
    puts("");

    LATTH_3__DQ("vand");
    puts("");

    LATTH_3__DQ("vbic");
    puts("");

    LATTH_3__DQ("vbif");
    puts("");

    LATTH_3__DQ("vbsl");
    puts("");

    LATTH_3__DQ("vcge.u32");
    LATTH_3__DQ("vcge.f32");
    puts("");

    LATTH_2__DQ("vclz.i32");
    puts("");

    LATTH_2_S__("vcmp.f32");
    puts("");

    LATTH_3_S__("vdiv.f32");
    puts("");

    LATTH_3_SDQ("vfma.f32");
    puts("");

    LATTH_3__DQ("vmax.u32");
    LATTH_3__DQ("vmax.f32");
    puts("");

    LATTH_3__DQ("vmla.i32");
    LATTH_3_SDQ("vmla.f32");
    puts("");

    LATTH_2_SDQ("vmov.f32");
    puts("");

    LATTH_3__DQ("vmul.i32");
    LATTH_3_SDQ("vmul.f32");
    puts("");

    LATTH_2__DQ("vneg.s32");
    LATTH_2_SDQ("vneg.f32");
    puts("");

    LATTH_2__DQ("vpadal.u32");
    puts("");

    LATTH_3__D_("vpadd.i32");
    LATTH_3__D_("vpadd.f32");
    puts("");

    LATTH_2__DQ("vrecpe.u32");
    LATTH_2__DQ("vrecpe.f32");
    puts("");

    LATTH_3__DQ("vrecps.f32");
    puts("");

    LATTH_2__DQ("vrev64.8");
    puts("");

    LATTH_3__DQ("vrhadd.u32");
    puts("");

    LATTH_2__DQ("vrsqrte.u32");
    LATTH_2__DQ("vrsqrte.f32");
    puts("");

    LATTH_3__DQ("vrsqrts.f32");
    puts("");

    LATTH_2_S__("vsqrt.f32");
    puts("");

    LATTH_2__DQ("vswp");
    puts("");

    LATTH_2__DQ("vtrn.8");

    cycle_count_finalize();
    return 0;
}
