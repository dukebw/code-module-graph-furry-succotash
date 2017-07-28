#
# Cross Platform Makefile
# Compatible with MSYS2/MINGW, Ubuntu 14.04.1 and Mac OS X
#
#
# if you using Mac OS X:
# You'll need glfw
#    http://www.glfw.org
#

#CXX = g++

EXE = code_graph
OBJS = code_graph.o imgui_impl_glfw.o
OBJS += imgui/imgui.o imgui/imgui_draw.o

UNAME_S := $(shell uname -s)


ifeq ($(UNAME_S), Linux) #LINUX
	ECHO_MESSAGE = "Linux"
	LIBS = -lGL `pkg-config --static --libs glfw3`

	CXXFLAGS = -I../../ `pkg-config --cflags glfw3`
	CXXFLAGS += -Wall -Wformat
	CFLAGS = $(CXXFLAGS)
endif

.cpp.o:
	$(CXX) $(CXXFLAGS) -c -o $@ $<

all: $(EXE)
	@echo Build complete for $(ECHO_MESSAGE)

$(EXE): $(OBJS)
	$(CXX) -o $(EXE) $(OBJS) $(CXXFLAGS) $(LIBS)

clean:
	rm $(EXE) $(OBJS)

