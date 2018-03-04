#ifndef CYCLE_COUNT_H_
#define CYCLE_COUNT_H_

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

    int cycle_count_init();
    int cycle_count_finalize();

    extern int perf_fd;

    static inline long long cycle_count()
    {
        long long v;
        ssize_t err;

        err = read(perf_fd, &v, sizeof(v));
#ifdef DEBUG
        if (err != sizeof(v)) {
            fprintf(stderr, "error: read: %s\n", strerror(errno));
            return -1LL;
        }
#else
        (void) err;
#endif

        return v;
    }

#endif /* CYCLE_COUNT_H_ */
