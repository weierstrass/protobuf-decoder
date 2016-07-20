TEST_SRC_DIR = ./src
TEST_OBJ_DIR = ./build

VPATH = $(TEST_SRC_DIR)
CCSRCS = $(addsuffix /*.cpp, $(TEST_SRC_DIR))
CSRCS = $(wildcard $(CCSRCS))

TEST_SRCS = $(ASRCS) $(CSRCS)  
TEST_OBJS = $(addprefix $(TEST_OBJ_DIR)/, $(notdir $(CSRCS:.cpp=.o)))

CXX = clang++

TEST_CPPFLAGS += -isystem /usr/include

CXXFLAGS = -g -std=c++11 `pkg-config gtkmm-3.0 --cflags` -I/usr/local/Cellar/boost/1.60.0_2/include -pthread
LDFLAGS = `pkg-config gtkmm-3.0 --libs`
TEST_LDD_FLAGS = /usr/local/lib/libgtest.a


# Build rules
all: $(OBJDIR) a.out

$(TEST_OBJ_DIR):
	mkdir $(TEST_OBJ_DIR)

$(TEST_OBJ_DIR)/%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

a.out: $(TEST_OBJS)
	$(CXX) $(TEST_OBJS) $(LDFLAGS)  $(TEST_LDD_FLAGS)

clean:
	rm -f a.out $(OBJDIR)/*.o *.o $(TEST_OBJ_DIR)/*.o

print:
	echo $(SRCS)
	echo $(OBJS)
