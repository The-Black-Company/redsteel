OUT	= microprocess.so
CC	 = g++

HEADER	= -I ./include/
SOURCE	= $(wildcard src/*.cpp)
OBJS	= $(SOURCE:.cpp=.o)
TRASH   = $(wildcard src/*~) $(wildcard include/*~) $(wildcard *~) $(wildcard src/*.o)

FLAGS	 = -g3 -c -Wall -std=c++20 -fPIC -rdynamic
LFLAGS	 = 

all: bin

bin: $(OBJS)
	@$(CC) -shared -o $(OUT) $(OBJS) $(LFLAGS)
	@cp microprocess.so ../ressources_pc
	@echo "[OUT]" $(OUT)

.cpp.o:
	@$(CC) $(FLAGS) $< -o $@ $(HEADER)
	@echo "[G++]" $<

clean:
	@rm -f $(OBJS)
	@rm -f $(TRASH)

fclean: clean
	@rm -f $(OUT)


re: fclean all







.PHONY: all clean

SUFFIXES: .c .cpp .o
