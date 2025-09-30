CFLAGS=-Wall -pedantic -std=c11 -I. -g -Iinclude

BUILD_DIR=build
SRC_DIR=src
TEST_DIR=tests

SRCS=$(wildcard $(SRC_DIR)/*.c)
TEST_SRCS=$(wildcard $(TEST_DIR)/*.c)

LIB_OBJS=$(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

TEST_OBJS=$(TEST_SRCS:$(TEST_DIR)/%.c=$(BUILD_DIR)/$(TEST_DIR)/%.o)
TEST_BINS=$(TEST_SRCS:$(TEST_DIR)/%.c=$(BUILD_DIR)/$(TEST_DIR)/%)

tests: $(TEST_BINS)

$(BUILD_DIR)/$(TEST_DIR)/%: $(BUILD_DIR)/$(TEST_DIR)/%.o

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/$(TEST_DIR)/%: $(BUILD_DIR)/tests/%.o $(LIB_OBJS)
	@mkdir -p $(dir $@)
	gcc $^ -o $@

clean:
	rm -rf $(BUILD_DIR)
