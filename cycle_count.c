#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <asm/unistd.h>
#include <linux/perf_event.h>
#include "cycle_count.h"

int perf_fd = -1;

static long perf_event_open(struct perf_event_attr *hw_event, pid_t pid,
                            int cpu, int group_fd, unsigned long flags)
{
    int ret;
    ret = syscall(__NR_perf_event_open, hw_event, pid, cpu, group_fd, flags);
    return ret;
}

int cycle_count_init()
{
    int fd;
    struct perf_event_attr pe;

    memset(&pe, 0, sizeof(pe));
    pe.type = PERF_TYPE_HARDWARE;
    pe.size = sizeof(pe);
    pe.config = PERF_COUNT_HW_CPU_CYCLES;
    pe.exclude_kernel = 1;

    fd = perf_event_open(&pe, 0, -1, -1, 0);
    if (fd == -1) {
        fprintf(stderr, "error: perf_event_open: %s\n", strerror(errno));
        return 1;
    }

    perf_fd = fd;
    return 0;
}

int cycle_count_finalize()
{
    int err;

    if (perf_fd == -1)
        return 0;

    err = close(perf_fd);
    if (err) {
        fprintf(stderr, "error: close: %s\n", strerror(errno));
        return 1;
    }

    return 0;
}
