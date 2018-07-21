# example4/Makefile

ASSIGNMENT=a5
QUESTION=cc3k
CXX=g++
CXXFLAGS=-std=c++14 -Wextra -Wpedantic -Wall -Werror -MMD -g -Werror=vla
OBJECTS=main.o Observer.o Entity.o Item.o Potion.o Character.o BaseCharacter.o CharacterDecorator.o Wall.o Pathway.o Ground.o TestEntity.o DungeonMap.o Floor.o Gold.o DragonGold.o Enemy.o Direction.o DrowRace.o ShadeRace.o GoblinRace.o VampireRace.o TrollRace.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=cc3k

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
.PHONY: clean
