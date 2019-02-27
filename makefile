CXX = g++
CXXFLAGS = -std=c++11 -Wall -pedantic-errors -g

SRCS = Main.cpp Character.cpp Vampire.cpp Barbarian.cpp BlueMen.cpp Medusa.cpp HarryPotter.cpp Menu.cpp
OBJS = ${SRCS: .cpp = .o}
HEADERS = Character.hpp Vampire.hpp Barabarian.hpp BlueMen.hpp Medusa.hpp HarryPotter.hpp Menu.hpp

MAIN = battle

all: ${MAIN}
	@echo sucessfully compiled!

${MAIN}: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${MAIN}

.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	${RM} ${PROGS} ${OBJS} *.0 *~.
