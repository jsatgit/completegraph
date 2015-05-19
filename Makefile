BIN=completeGraph
CXX=g++

BIN_DIR=bin
BUILD_DIR=build

SOURCES=$(wildcard *.cc)
OBJECTS=$(SOURCES:%.cc=$(BUILD_DIR)/%.o)
DEPENDS=$(SOURCES:%.cc=$(BUILD_DIR)/%.d)

CXXFLAGS=-std=c++11 -Wall -MMD
INCLUDES=-I/usr/local/include
LDFLAGS=-L/usr/local/lib 
LDLIBS=	-lglfw3 			\
		-framework OpenGL 	\
		-framework Cocoa 	\
		-framework IOKit

all: $(BIN_DIR)/$(BIN)

$(BIN_DIR)/$(BIN) : $(OBJECTS) 
	@mkdir -p $(BIN_DIR)
	$(CXX) $(OBJECTS) $(LDFLAGS) $(LDLIBS) -o $@ 

$(BUILD_DIR)/%.o : %.cc
	@mkdir -p $(BUILD_DIR) 
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@ 

-include $(DEPENDS)

.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR) $(BIN_DIR)
