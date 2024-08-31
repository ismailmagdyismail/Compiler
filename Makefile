CXX := clang++
CXXFLAGS := -std=c++20
BUILD_DIR := ./build

SRCS := $(shell find . -name '*.cpp')
OBJS := $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

# Main target
TARGET := ${BUILD_DIR}/interprter.out

.PHONY: all clean

all: $(TARGET) clean

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
