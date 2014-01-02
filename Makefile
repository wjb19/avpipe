# Makefile layout originally developed by Bill Lynch
SOURCES     := $(sort $(wildcard src/*.cpp src/*.cu src/*.cc src/*.c))
OBJECTS     := $(sort $(patsubst src/%, obj/%.o, $(SOURCES)))
DEPENDS     := $(sort $(patsubst src/%, obj/%.d, $(SOURCES)))

# 
CPPFLAGS    += -I./inc -I/home/bill/Downloads/opencv-2.4.6.1/build/include
LDFLAGS     += -lboost_thread -lboost_program_options
LDFLAGS	    += -L/home/bill/Downloads/opencv-2.4.6.1/build/lib -lopencv_core -lopencv_imgproc -lopencv_highgui -lm

CXX         := g++ -Wall -g

bin/avpipe.x: $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf bin obj html latex

obj/%.cpp.o: src/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

obj/%.cc.o: src/%.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@


obj/%.c.o: src/%.c
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

obj/%.cpp.d: src/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -MM -MT "$(strip $(patsubst %.d, %.o, $@) $@)" $< -o $@

obj/%.cc.d: src/%.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -MM -MT "$(strip $(patsubst %.d, %.o, $@) $@)" $< -o $@

obj/%.c.d: src/%.c
	$(CXX) $(CPPFLAGS)  $(CFLAGS) -MM -MT "$(strip $(patsubst %.d, %.o, $@) $@)" $< -o $@

# Create system layout for Objects and binaries
ifneq ($(MAKECMDGOALS),clean)
$(shell mkdir -p bin obj)
-include $(DEPENDS)
endif
