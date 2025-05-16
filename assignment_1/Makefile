CC := gcc
CFLAGS := -Wall -g
TARGET := p$(p).c

all:
ifneq ($(shell ls $(TARGET)),)
	@$(CC) $(CFLAGS) $(TARGET) -o run
endif

.PHONY: run
run: clean all
	@./run

.PHONY: clean
clean:
	@rm -f run
