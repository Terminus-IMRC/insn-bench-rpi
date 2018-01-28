#include <stdio.h>
#include <stdlib.h>
#include "cycle_count.h"

/* 60Mi times */
#define NUM_LOOPS ((1<<20) * 60)

#define mb() asm volatile ("" : : :"memory")

#define INSN_REG_BEGIN(n) \
    do { \
        unsigned i __attribute__((aligned(4))) = NUM_LOOPS / n; \
        asm volatile ( \
                ".align 4\n\t" \
                "0:\n\t" \
                "subs %[cnt], #1\n\t"

#define INSN_REG_LIST \
                "bne 0b\n\t" \
                : [cnt] "+r" (i) \
                : \
                :

#define INSN_REG_END \
        ); \
    } while (0)


#define INSN_REG16_11_(reg, insn) \
    INSN_REG_BEGIN(16) \
        insn " " reg  "0, " reg  "0\n\t" \
        insn " " reg  "0, " reg  "0\n\t" \
        insn " " reg  "0, " reg  "0\n\t" \
        insn " " reg  "0, " reg  "0\n\t" \
        insn " " reg  "0, " reg  "0\n\t" \
        insn " " reg  "0, " reg  "0\n\t" \
        insn " " reg  "0, " reg  "0\n\t" \
        insn " " reg  "0, " reg  "0\n\t" \
        insn " " reg  "0, " reg  "0\n\t" \
        insn " " reg  "0, " reg  "0\n\t" \
        insn " " reg  "0, " reg  "0\n\t" \
        insn " " reg  "0, " reg  "0\n\t" \
        insn " " reg  "0, " reg  "0\n\t" \
        insn " " reg  "0, " reg  "0\n\t" \
        insn " " reg  "0, " reg  "0\n\t" \
        insn " " reg  "0, " reg  "0\n\t" \
    INSN_REG_LIST \
        reg "0" \
    INSN_REG_END

#define INSN_REG16_12_(reg, insn) \
    INSN_REG_BEGIN(8) \
        insn " " reg  "0, " reg  "1\n\t" \
        insn " " reg  "2, " reg  "3\n\t" \
        insn " " reg  "4, " reg  "5\n\t" \
        insn " " reg  "6, " reg  "7\n\t" \
        insn " " reg  "8, " reg  "9\n\t" \
        insn " " reg "10, " reg "11\n\t" \
        insn " " reg "12, " reg "13\n\t" \
        insn " " reg "14, " reg "15\n\t" \
    INSN_REG_LIST \
        reg  "0", reg  "1", reg  "2", reg  "3", \
        reg  "4", reg  "5", reg  "6", reg  "7", \
        reg  "8", reg  "9", reg "10", reg "11", \
        reg "12", reg "13", reg "14", reg "15"  \
    INSN_REG_END

#define INSN_REG16_111(reg, insn) \
    INSN_REG_BEGIN(16) \
        insn " " reg  "0, " reg  "0, " reg  "0\n\t" \
        insn " " reg  "0, " reg  "0, " reg  "0\n\t" \
        insn " " reg  "0, " reg  "0, " reg  "0\n\t" \
        insn " " reg  "0, " reg  "0, " reg  "0\n\t" \
        insn " " reg  "0, " reg  "0, " reg  "0\n\t" \
        insn " " reg  "0, " reg  "0, " reg  "0\n\t" \
        insn " " reg  "0, " reg  "0, " reg  "0\n\t" \
        insn " " reg  "0, " reg  "0, " reg  "0\n\t" \
        insn " " reg  "0, " reg  "0, " reg  "0\n\t" \
        insn " " reg  "0, " reg  "0, " reg  "0\n\t" \
        insn " " reg  "0, " reg  "0, " reg  "0\n\t" \
        insn " " reg  "0, " reg  "0, " reg  "0\n\t" \
        insn " " reg  "0, " reg  "0, " reg  "0\n\t" \
        insn " " reg  "0, " reg  "0, " reg  "0\n\t" \
        insn " " reg  "0, " reg  "0, " reg  "0\n\t" \
        insn " " reg  "0, " reg  "0, " reg  "0\n\t" \
    INSN_REG_LIST \
        reg "0" \
    INSN_REG_END

#define INSN_REG16_112(reg, insn) \
    INSN_REG_BEGIN(8) \
        insn " " reg  "0, " reg  "0, " reg  "1\n\t" \
        insn " " reg  "2, " reg  "2, " reg  "3\n\t" \
        insn " " reg  "4, " reg  "4, " reg  "5\n\t" \
        insn " " reg  "6, " reg  "6, " reg  "7\n\t" \
        insn " " reg  "8, " reg  "8, " reg  "9\n\t" \
        insn " " reg "10, " reg "10, " reg "11\n\t" \
        insn " " reg "12, " reg "12, " reg "13\n\t" \
        insn " " reg "14, " reg "14, " reg "15\n\t" \
    INSN_REG_LIST \
        reg  "0", reg  "1", reg  "2", reg  "3", \
        reg  "4", reg  "5", reg  "6", reg  "7", \
        reg  "8", reg  "9", reg "10", reg "11", \
        reg "12", reg "13", reg "14", reg "15"  \
    INSN_REG_END

#define INSN_REG16_123(reg, insn) \
    INSN_REG_BEGIN(5) \
        insn " " reg  "0, " reg  "1, " reg  "2\n\t" \
        insn " " reg  "3, " reg  "4, " reg  "5\n\t" \
        insn " " reg  "6, " reg  "7, " reg  "8\n\t" \
        insn " " reg  "9, " reg "10, " reg "11\n\t" \
        insn " " reg "12, " reg "13, " reg "14\n\t" \
    INSN_REG_LIST \
        reg  "0", reg  "1", reg  "2", reg  "3", \
        reg  "4", reg  "5", reg  "6", reg  "7", \
        reg  "8", reg  "9", reg "10", reg "11", \
        reg "12", reg "13", reg "14"            \
    INSN_REG_END


#define INSN_REG32_11_(reg, insn) INSN_REG16_11_(reg, insn)

#define INSN_REG32_12_(reg, insn) \
    INSN_REG_BEGIN(16) \
        insn " " reg  "0, " reg  "1\n\t" \
        insn " " reg  "2, " reg  "3\n\t" \
        insn " " reg  "4, " reg  "5\n\t" \
        insn " " reg  "6, " reg  "7\n\t" \
        insn " " reg  "8, " reg  "9\n\t" \
        insn " " reg "10, " reg "11\n\t" \
        insn " " reg "12, " reg "13\n\t" \
        insn " " reg "14, " reg "15\n\t" \
        insn " " reg "16, " reg "17\n\t" \
        insn " " reg "18, " reg "19\n\t" \
        insn " " reg "20, " reg "21\n\t" \
        insn " " reg "22, " reg "23\n\t" \
        insn " " reg "24, " reg "25\n\t" \
        insn " " reg "26, " reg "27\n\t" \
        insn " " reg "28, " reg "29\n\t" \
        insn " " reg "30, " reg "31\n\t" \
    INSN_REG_LIST \
        reg  "0", reg  "1", reg  "2", reg  "3", \
        reg  "4", reg  "5", reg  "6", reg  "7", \
        reg  "8", reg  "9", reg "10", reg "11", \
        reg "12", reg "13", reg "14", reg "15", \
        reg "16", reg "17", reg "18", reg "19", \
        reg "20", reg "21", reg "22", reg "23", \
        reg "24", reg "25", reg "26", reg "27", \
        reg "28", reg "29", reg "30", reg "31"  \
    INSN_REG_END

#define INSN_REG32_111(reg, insn) INSN_REG16_111(reg, insn)

#define INSN_REG32_112(reg, insn) \
    INSN_REG_BEGIN(16) \
        insn " " reg  "0, " reg  "0, " reg  "1\n\t" \
        insn " " reg  "2, " reg  "2, " reg  "3\n\t" \
        insn " " reg  "4, " reg  "4, " reg  "5\n\t" \
        insn " " reg  "6, " reg  "6, " reg  "7\n\t" \
        insn " " reg  "8, " reg  "8, " reg  "9\n\t" \
        insn " " reg "10, " reg "10, " reg "11\n\t" \
        insn " " reg "12, " reg "12, " reg "13\n\t" \
        insn " " reg "14, " reg "14, " reg "15\n\t" \
        insn " " reg "16, " reg "16, " reg "17\n\t" \
        insn " " reg "18, " reg "18, " reg "19\n\t" \
        insn " " reg "20, " reg "20, " reg "21\n\t" \
        insn " " reg "22, " reg "22, " reg "23\n\t" \
        insn " " reg "24, " reg "24, " reg "25\n\t" \
        insn " " reg "26, " reg "26, " reg "27\n\t" \
        insn " " reg "28, " reg "28, " reg "29\n\t" \
        insn " " reg "30, " reg "30, " reg "31\n\t" \
    INSN_REG_LIST \
        reg  "0", reg  "1", reg  "2", reg  "3", \
        reg  "4", reg  "5", reg  "6", reg  "7", \
        reg  "8", reg  "9", reg "10", reg "11", \
        reg "12", reg "13", reg "14", reg "15", \
        reg "16", reg "17", reg "18", reg "19", \
        reg "20", reg "21", reg "22", reg "23", \
        reg "24", reg "25", reg "26", reg "27", \
        reg "28", reg "29", reg "30", reg "31"  \
    INSN_REG_END

#define INSN_REG32_123(reg, insn) \
    INSN_REG_BEGIN(10) \
        insn " " reg  "0, " reg  "1, " reg  "2\n\t" \
        insn " " reg  "3, " reg  "4, " reg  "5\n\t" \
        insn " " reg  "6, " reg  "7, " reg  "8\n\t" \
        insn " " reg  "9, " reg "10, " reg "11\n\t" \
        insn " " reg "12, " reg "13, " reg "14\n\t" \
        insn " " reg "15, " reg "16, " reg "17\n\t" \
        insn " " reg "18, " reg "19, " reg "20\n\t" \
        insn " " reg "21, " reg "22, " reg "23\n\t" \
        insn " " reg "24, " reg "25, " reg "26\n\t" \
        insn " " reg "27, " reg "28, " reg "29\n\t" \
    INSN_REG_LIST \
        reg  "0", reg  "1", reg  "2", reg  "3", \
        reg  "4", reg  "5", reg  "6", reg  "7", \
        reg  "8", reg  "9", reg "10", reg "11", \
        reg "12", reg "13", reg "14", reg "15", \
        reg "16", reg "17", reg "18", reg "19", \
        reg "20", reg "21", reg "22", reg "23", \
        reg "24", reg "25", reg "26", reg "27", \
        reg "28", reg "29"                      \
    INSN_REG_END

#define INSN_REGS32_11_(insn) INSN_REG32_11_("s", insn)
#define INSN_REGS32_12_(insn) INSN_REG32_12_("s", insn)
#define INSN_REGS32_111(insn) INSN_REG32_111("s", insn)
#define INSN_REGS32_112(insn) INSN_REG32_112("s", insn)
#define INSN_REGS32_123(insn) INSN_REG32_123("s", insn)
#define INSN_REGD32_11_(insn) INSN_REG32_11_("d", insn)
#define INSN_REGD32_12_(insn) INSN_REG32_12_("d", insn)
#define INSN_REGD32_111(insn) INSN_REG32_111("d", insn)
#define INSN_REGD32_112(insn) INSN_REG32_112("d", insn)
#define INSN_REGD32_123(insn) INSN_REG32_123("d", insn)
#define INSN_REGQ16_11_(insn) INSN_REG16_11_("q", insn)
#define INSN_REGQ16_12_(insn) INSN_REG16_12_("q", insn)
#define INSN_REGQ16_111(insn) INSN_REG16_111("q", insn)
#define INSN_REGQ16_112(insn) INSN_REG16_112("q", insn)
#define INSN_REGQ16_123(insn) INSN_REG16_123("q", insn)

#define LATTH(insn_reg, insn) \
    do { \
        long long start, end; \
        start = cycle_count(); \
        mb(); \
        insn_reg(insn); \
        mb(); \
        end = cycle_count(); \
        mb(); \
        printf(" %5.2f", (double) (end - start) / NUM_LOOPS); \
    } while (0)

#define NAMEWIDTH -11

#define LATTH_2_S__(insn) \
    do { \
        printf("%*s s2:", NAMEWIDTH, insn); \
        LATTH(INSN_REGS32_11_, insn); \
        LATTH(INSN_REGS32_12_, insn); \
        printf("\n"); \
    } while (0)

#define LATTH_2__D_(insn) \
    do { \
        printf("%*s d2:", NAMEWIDTH, insn); \
        LATTH(INSN_REGD32_11_, insn); \
        LATTH(INSN_REGD32_12_, insn); \
        printf("\n"); \
    } while (0)

#define LATTH_2___Q(insn) \
    do { \
        printf("%*s q2:", NAMEWIDTH, insn); \
        LATTH(INSN_REGQ16_11_, insn); \
        LATTH(INSN_REGQ16_12_, insn); \
        printf("\n"); \
    } while (0)

#define LATTH_2__DQ(insn) \
    do { \
        LATTH_2__D_(insn); \
        LATTH_2___Q(insn); \
    } while (0)

#define LATTH_2_SD_(insn) \
    do { \
        LATTH_2_S__(insn); \
        LATTH_2__D_(insn); \
    } while (0)

#define LATTH_2_SDQ(insn) \
    do { \
        LATTH_2_S__(insn); \
        LATTH_2__D_(insn); \
        LATTH_2___Q(insn); \
    } while (0)

#define LATTH_3_S__(insn) \
    do { \
        printf("%*s s3:", NAMEWIDTH, insn); \
        LATTH(INSN_REGS32_111, insn); \
        LATTH(INSN_REGS32_112, insn); \
        LATTH(INSN_REGS32_123, insn); \
        printf("\n"); \
    } while (0)

#define LATTH_3__D_(insn) \
    do { \
        printf("%*s d3:", NAMEWIDTH, insn); \
        LATTH(INSN_REGD32_111, insn); \
        LATTH(INSN_REGD32_112, insn); \
        LATTH(INSN_REGD32_123, insn); \
        printf("\n"); \
    } while (0)

#define LATTH_3___Q(insn) \
    do { \
        printf("%*s q3:", NAMEWIDTH, insn); \
        LATTH(INSN_REGQ16_111, insn); \
        LATTH(INSN_REGQ16_112, insn); \
        LATTH(INSN_REGQ16_123, insn); \
        printf("\n"); \
    } while (0)

#define LATTH_3__DQ(insn) \
    do { \
        LATTH_3__D_(insn); \
        LATTH_3___Q(insn); \
    } while (0)

#define LATTH_3_SDQ(insn) \
    do { \
        LATTH_3_S__(insn); \
        LATTH_3__D_(insn); \
        LATTH_3___Q(insn); \
    } while (0)

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

    LATTH_3__DQ("vadd.f32");
    LATTH_3__DQ("vadd.i32");
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
