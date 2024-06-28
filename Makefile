# Makefile for PipelineSolver Project
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
TARGET = $(BIN_DIR)/pipelinesolver
MKDIR_P = mkdir -p

SRCS = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/parser/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(patsubst $(SRC_DIR)/parser/%.c, $(OBJ_DIR)/parser/%.o, $(SRCS)))
DEPS = $(OBJS:.o=.d)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	@$(MKDIR_P) $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^ || { echo 'Build failed'; exit 1; }

-include $(DEPS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR_P) $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c -o $@ $< || { echo 'Compilation failed'; exit 1; }

$(OBJ_DIR)/parser/%.o: $(SRC_DIR)/parser/%.c
	@$(MKDIR_P) $(OBJ_DIR)/parser
	$(CC) $(CFLAGS) -MMD -MP -c -o $@ $< || { echo 'Compilation failed'; exit 1; }

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
