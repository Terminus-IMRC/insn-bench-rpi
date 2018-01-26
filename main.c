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

#define INSN_REGS32_111(insn) INSN_REG32_111("s", insn)
#define INSN_REGS32_112(insn) INSN_REG32_112("s", insn)
#define INSN_REGS32_123(insn) INSN_REG32_123("s", insn)
#define INSN_REGD32_111(insn) INSN_REG32_111("d", insn)
#define INSN_REGD32_112(insn) INSN_REG32_112("d", insn)
#define INSN_REGD32_123(insn) INSN_REG32_123("d", insn)
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


#define LATTH_S(insn) \
    do { \
        printf("%s s:", insn); \
        LATTH(INSN_REGS32_111, insn); \
        LATTH(INSN_REGS32_112, insn); \
        LATTH(INSN_REGS32_123, insn); \
        printf("\n"); \
    } while (0)

#define LATTH_D(insn) \
    do { \
        printf("%s d:", insn); \
        LATTH(INSN_REGD32_111, insn); \
        LATTH(INSN_REGD32_112, insn); \
        LATTH(INSN_REGD32_123, insn); \
        printf("\n"); \
    } while (0)

#define LATTH_Q(insn) \
    do { \
        printf("%s q:", insn); \
        LATTH(INSN_REGQ16_111, insn); \
        LATTH(INSN_REGQ16_112, insn); \
        LATTH(INSN_REGQ16_123, insn); \
        printf("\n"); \
    } while (0)

#define LATTH_SQD(insn) \
    do { \
        LATTH_S(insn); \
        LATTH_D(insn); \
        LATTH_Q(insn); \
    } while (0)

int main()
{
    cycle_count_init();

    LATTH_SQD("vadd.f32");
    LATTH_SQD("vmul.f32");
    LATTH_SQD("vmla.f32");
    LATTH_S  ("vdiv.f32");

    cycle_count_finalize();
    return 0;
}
