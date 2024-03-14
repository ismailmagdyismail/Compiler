CXX := clang++
CXXFLAGS := -std=gnu++20
BUILD_DIR := .

SRCS := $(shell find . -name '*.cpp')
OBJS := $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

# Main target
TARGET := interprter.out

.PHONY: all clean

all: $(TARGET) clean

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
