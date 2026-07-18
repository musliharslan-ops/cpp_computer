CXX      ?= g++
CXXFLAGS ?= -std=c++20 -Wall -Wextra -Wpedantic -O2 -g -Isrc/modules -Isrc/types -MMD -MP

BUILD := build

CORE_SRCS := src/sim/main.cpp
APP      := $(BUILD)/software_sim

.PHONY: all test app clean
all: $(BUILD) 
	./$(APP)

$(BUILD): $(CORE_SRCS) src/modules/* src/types/*
	@mkdir -p $(BUILD)
	$(CXX) $(CORE_SRCS) $(CXXFLAGS) -o $(APP)

app: $(APP)

clean:
	rm -rf $(BUILD)

