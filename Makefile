# example4/Makefile

ASSIGNMENT=a5
QUESTION=cc3k
CXX=g++
CXXFLAGS=-std=c++14 -Wextra -Wpedantic -Wall -Werror -MMD -g -Werror=vla -I "./characters/" -I "./map/"
OBJECTS=main.o Entity.o DungeonMap.o Chamber.o\
		\
		characters/BaseCharacter.o characters/Character.o characters/CharacterDecorator.o characters/DragonEnemy.o \
		characters/DrowRace.o characters/DwarfEnemy.o characters/ElfEnemy.o characters/Enemy.o characters/GoblinRace.o \
		characters/HalflingEnemy.o characters/HumanEnemy.o characters/Merchant.o characters/OrcEnemy.o characters/ShadeRace.o \
		characters/TrollRace.o characters/VampireRace.o characters/CharacterType.o characters/NullDecorator.o characters/BelungaRace.o \
		\
		map/BoostAtkEffect.o map/BoostDefEffect.o map/Direction.o map/DragonGold.o map/EffectPotion.o map/Floor.o map/Gold.o \
		map/Ground.o map/HealthPotion.o map/Item.o map/Pathway.o map/Potion.o map/Stair.o map/StaticEntity.o map/Wall.o \
		map/WoundAtkEffect.o map/WoundDefEffect.o map/PotionType.o

DEPENDS=${OBJECTS:.o=.d}
EXEC=cc3k

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
.PHONY: clean
