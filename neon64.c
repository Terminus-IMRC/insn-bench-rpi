#if defined(__arm__) || !defined(__aarch64__)
#error "This code is for AArch64 only. Use suitable compiler."
#endif

#include <stdio.h>
#include "cycle_count.h"


/* 60Mi times */
#define NUM_LOOPS ((1<<20) * 60)


#define mb() asm volatile ("" : : :"memory")


#define LOOP_BEGIN(n) \
    do { \
        unsigned i __attribute__((aligned(4))) = NUM_LOOPS / n; \
        asm volatile ( \
                ".align 4\n\t" \
                "0:\n\t" \
                "subs %[cnt], %[cnt], #1\n\t"

#define LOOP_REG_LIST \
                "bne 0b\n\t" \
                : [cnt] "+r" (i) \
                : \
                :

#define LOOP_END \
        , "cc"); \
    } while (0)


#define LOOP_11(insn, arr) \
    LOOP_BEGIN(32) \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr "\n\t" \
    LOOP_REG_LIST \
        "v0" \
    LOOP_END

#define LOOP_12(insn, arr) \
    LOOP_BEGIN(16) \
        insn "  v0." arr ",  v1." arr "\n\t" \
        insn "  v2." arr ",  v3." arr "\n\t" \
        insn "  v4." arr ",  v5." arr "\n\t" \
        insn "  v6." arr ",  v7." arr "\n\t" \
        insn "  v8." arr ",  v9." arr "\n\t" \
        insn " v10." arr ", v11." arr "\n\t" \
        insn " v12." arr ", v13." arr "\n\t" \
        insn " v14." arr ", v15." arr "\n\t" \
        insn " v16." arr ", v17." arr "\n\t" \
        insn " v18." arr ", v19." arr "\n\t" \
        insn " v20." arr ", v21." arr "\n\t" \
        insn " v22." arr ", v23." arr "\n\t" \
        insn " v24." arr ", v25." arr "\n\t" \
        insn " v26." arr ", v27." arr "\n\t" \
        insn " v28." arr ", v29." arr "\n\t" \
        insn " v30." arr ", v31." arr "\n\t" \
    LOOP_REG_LIST \
         "v0",  "v1",  "v2",  "v3",  "v4",  "v5",  "v6",  "v7", \
         "v8",  "v9", "v10", "v11", "v12", "v13", "v14", "v15", \
        "v16", "v17", "v18", "v19", "v20", "v21", "v22", "v23", \
        "v24", "v25", "v26", "v27", "v28", "v29", "v30", "v31"  \
    LOOP_END

#define LOOP_111(insn, arr) \
    LOOP_BEGIN(32) \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
        insn "  v0." arr ",  v0." arr ",  v0." arr "\n\t" \
    LOOP_REG_LIST \
        "v0" \
    LOOP_END

#define LOOP_122(insn, arr) \
    LOOP_BEGIN(16) \
        insn "  v0." arr ",  v1." arr ",  v1." arr "\n\t" \
        insn "  v2." arr ",  v3." arr ",  v3." arr "\n\t" \
        insn "  v4." arr ",  v5." arr ",  v5." arr "\n\t" \
        insn "  v6." arr ",  v7." arr ",  v7." arr "\n\t" \
        insn "  v8." arr ",  v9." arr ",  v9." arr "\n\t" \
        insn " v10." arr ", v11." arr ", v11." arr "\n\t" \
        insn " v12." arr ", v13." arr ", v13." arr "\n\t" \
        insn " v14." arr ", v15." arr ", v15." arr "\n\t" \
        insn " v16." arr ", v17." arr ", v17." arr "\n\t" \
        insn " v18." arr ", v19." arr ", v19." arr "\n\t" \
        insn " v20." arr ", v21." arr ", v21." arr "\n\t" \
        insn " v22." arr ", v23." arr ", v23." arr "\n\t" \
        insn " v24." arr ", v25." arr ", v25." arr "\n\t" \
        insn " v26." arr ", v27." arr ", v27." arr "\n\t" \
        insn " v28." arr ", v29." arr ", v29." arr "\n\t" \
        insn " v30." arr ", v31." arr ", v31." arr "\n\t" \
    LOOP_REG_LIST \
         "v0",  "v1",  "v2",  "v3",  "v4",  "v5",  "v6",  "v7", \
         "v8",  "v9", "v10", "v11", "v12", "v13", "v14", "v15", \
        "v16", "v17", "v18", "v19", "v20", "v21", "v22", "v23", \
        "v24", "v25", "v26", "v27", "v28", "v29", "v30", "v31"  \
    LOOP_END

#define LOOP_123(insn, arr) \
    LOOP_BEGIN(10) \
        insn "  v0." arr ",  v1." arr ",  v2." arr "\n\t" \
        insn "  v3." arr ",  v4." arr ",  v5." arr "\n\t" \
        insn "  v6." arr ",  v7." arr ",  v8." arr "\n\t" \
        insn "  v9." arr ", v10." arr ", v11." arr "\n\t" \
        insn " v12." arr ", v13." arr ", v14." arr "\n\t" \
        insn " v15." arr ", v16." arr ", v17." arr "\n\t" \
        insn " v18." arr ", v19." arr ", v20." arr "\n\t" \
        insn " v21." arr ", v22." arr ", v23." arr "\n\t" \
        insn " v24." arr ", v25." arr ", v26." arr "\n\t" \
        insn " v27." arr ", v28." arr ", v29." arr "\n\t" \
    LOOP_REG_LIST \
         "v0",  "v1",  "v2",  "v3",  "v4",  "v5",  "v6",  "v7", \
         "v8",  "v9", "v10", "v11", "v12", "v13", "v14", "v15", \
        "v16", "v17", "v18", "v19", "v20", "v21", "v22", "v23", \
        "v24", "v25", "v26", "v27", "v28", "v29"                \
    LOOP_END

#define DO_LOOP(loop, insn, arr) \
    do { \
        long long start, end; \
        start = cycle_count(); \
        mb(); \
        loop(insn, arr); \
        mb(); \
        end = cycle_count(); \
        mb(); \
        printf(" %5.2f", (double) (end - start) / NUM_LOOPS); \
    } while (0)


#define NAMEWIDTH -11

#define LATTH_2(insn) \
    do { \
        printf(  "%*s 2S:", NAMEWIDTH, insn); \
        DO_LOOP(LOOP_11,  insn, "2s"); \
        DO_LOOP(LOOP_12,  insn, "2s"); \
        printf("\n%*s 4S:", NAMEWIDTH, insn); \
        DO_LOOP(LOOP_11,  insn, "4s"); \
        DO_LOOP(LOOP_12,  insn, "4s"); \
        printf("\n%*s 2D:", NAMEWIDTH, insn); \
        DO_LOOP(LOOP_11,  insn, "2d"); \
        DO_LOOP(LOOP_12,  insn, "2d"); \
        printf("\n"); \
    } while (0)

#define LATTH_3(insn) \
    do { \
        printf(  "%*s 2S:", NAMEWIDTH, insn); \
        DO_LOOP(LOOP_111, insn, "2s"); \
        DO_LOOP(LOOP_122, insn, "2s"); \
        DO_LOOP(LOOP_123, insn, "2s"); \
        printf("\n%*s 4S:", NAMEWIDTH, insn); \
        DO_LOOP(LOOP_111, insn, "4s"); \
        DO_LOOP(LOOP_122, insn, "4s"); \
        DO_LOOP(LOOP_123, insn, "4s"); \
        printf("\n%*s 2D:", NAMEWIDTH, insn); \
        DO_LOOP(LOOP_111, insn, "2d"); \
        DO_LOOP(LOOP_122, insn, "2d"); \
        DO_LOOP(LOOP_123, insn, "2d"); \
        printf("\n"); \
    } while (0)


int main(void)
{
    cycle_count_init();

    LATTH_2("fabs");

    LATTH_3("fadd");
    LATTH_3("fsub");
    LATTH_3("fmul");
    LATTH_3("fmla");
    LATTH_3("fdiv");
    LATTH_3("fmax");
    LATTH_3("fmin");

    cycle_count_finalize();
    return 0;
}
