#ifndef CHARACTERTYPE_H
#define CHARACTERTYPE_H

#include <string>

struct CharacterType {
	enum class CharacterTypeEnum {
		Invalid,
		Shade,
		Drow,
		Vampire,
		Troll,
		Goblin,
		Human,
		Dwarf,
		Elf,
		Orc,
		Merchant,
		Dragon,
		Halfling
	};
	CharacterTypeEnum type;
    CharacterType(CharacterTypeEnum characterType);
    std::string to_string();
    bool operator==(CharacterType other);
	const static CharacterType Shade;
	const static CharacterType Drow;
	const static CharacterType Vampire;
	const static CharacterType Troll;
	const static CharacterType Goblin;
	const static CharacterType Human;
	const static CharacterType Dwarf;
	const static CharacterType Elf;
	const static CharacterType Orc;
	const static CharacterType Merchant;
	const static CharacterType Dragon;
	const static CharacterType Halfling;
	const static CharacterType Invalid;
};
#endif
