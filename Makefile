SRCDIR = src src/view/window src/view/signal_handler src/conversion
OBJDIR = build

VPATH = $(SRCDIR)
CCSRCS = $(addsuffix /*.cpp, $(SRCDIR))
CSRCS = $(wildcard $(CCSRCS))

SRCS = $(ASRCS) $(CSRCS)  
OBJS = $(addprefix $(OBJDIR)/, $(notdir $(CSRCS:.cpp=.o)))

CXX = clang++

CXXFLAGS = -g -std=c++11 `pkg-config gtkmm-3.0 --cflags` -I/usr/local/Cellar/boost/1.60.0_2/include
LDFLAGS = `pkg-config gtkmm-3.0 --libs`

# Build rules
.PHONY: print all clean test

all: $(OBJDIR) a.out

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJDIR)/%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

a.out: $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) 

clean:
	rm -f a.out $(OBJDIR)/*.o *.o $(TEST_OBJ_DIR)/*.o
