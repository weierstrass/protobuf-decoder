SRCDIR = src src/view/window src/view/signal_handler src/conversion
OBJDIR = build

VPATH = $(SRCDIR)
CCSRCS = $(addsuffix /*.cpp, $(SRCDIR))
CSRCS = $(wildcard $(CCSRCS))

SRCS = $(ASRCS) $(CSRCS)  
OBJS = $(addprefix $(OBJDIR)/, $(notdir $(CSRCS:.cpp=.o)))

CXX = clang++

CXXFLAGS = -g -std=c++11
LDFLAGS = `pkg-config gtkmm-3.0 --cflags --libs` -I/usr/local/Cellar/boost/1.60.0_2/include

LIBS =

# Build rules
.PHONY: print all clean test

all: $(OBJDIR) a.out

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o: %.cpp
	$(CXX) $(LDFLAGS) $(CXXFLAGS) -c $< -o $@

a.out: $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) $(LIBS) 

clean:
	rm -f a.out $(OBJDIR)/*.o *.o

print:
	echo $(SRCS)
	echo $(OBJS)

#test:
#	gcc -fverbose-asm -O2 -S -c test.c