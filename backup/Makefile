# example4/Makefile

ASSIGNMENT=a5
QUESTION=cc3k
CXX=g++
CXXFLAGS=-std=c++14 -Wextra -Wpedantic -Wall -Werror -MMD -g -Werror=vla -I "./races/" -I "./map/"
OBJECTS=main.o Entity.o Item.o Potion.o Character.o BaseCharacter.o CharacterDecorator.o Wall.o Pathway.o Ground.o \
		DungeonMap.o Floor.o Gold.o DragonGold.o Enemy.o Direction.o DrowRace.o ShadeRace.o GoblinRace.o VampireRace.o \
		TrollRace.o StaticEntity.o HumanEnemy.o DwarfEnemy.o ElfEnemy.o OrcEnemy.o HalflingEnemy.o DragonEnemy.o Merchant.o \
		Stair.o BoostAtkEffect.o WoundAtkEffect.o BoostDefEffect.o WoundDefEffect.o HealthPotion.o EffectPotion.o
DEPENDS=${OBJECTS:.o=.d}
EXEC=cc3k

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
.PHONY: clean
