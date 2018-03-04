CC = $(CROSS_COMPILE)gcc
CFLAGS += -pipe -W -Wall -Wextra -g -O3

.PHONY: all
all:

neon32: TARGET_ARCH += -march=armv7-a -mfpu=neon-vfpv4
neon64: TARGET_ARCH += -march=armv8-a

neon32: neon32.c cycle_count.c
	$(LINK.c) neon32.c cycle_count.c $(LDLIBS) $(OUTPUT_OPTION)

neon64: neon64.c cycle_count.c
	$(LINK.c) neon64.c cycle_count.c $(LDLIBS) $(OUTPUT_OPTION)

neon32 neon64: cycle_count.h $(MAKEFILE_LIST)

.PHONY: clean
clean:
	$(RM) neon32 neon64
