TARGET := main
OBJS := main.o cycle_count.o
HDRS :=        cycle_count.h

CFLAGS += -pipe -W -Wall -Wextra -g -O3
TARGET_ARCH := -mfloat-abi=hard -mfpu=neon-vfpv4

all: main

main $(OBJS): $(HDRS) $(MAKEFILE_LIST)

main: $(OBJS)
	$(LINK.o) $(OBJS) $(LOADLIBES) $(LDLIBS) $(OUTPUT_OPTION)

.PHONY: clean
clean:
	$(RM) $(TARGET)
	$(RM) $(OBJS)
