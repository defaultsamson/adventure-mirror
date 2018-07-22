#include "CharacterType.h"

CharacterType::CharacterType(CharacterTypeEnum characterType): type{characterType} {}
std::string CharacterType::to_string() {
    switch(type) {
        case CharacterTypeEnum::Shade:
            return "Shade";
            break;
        case CharacterTypeEnum::Drow:
            return "Drow";
            break;
        case CharacterTypeEnum::Vampire:
            return "Vampire";
            break;
        case CharacterTypeEnum::Troll:
            return "Troll";
            break;
        case CharacterTypeEnum::Goblin:
            return "Goblin";
            break;
        case CharacterTypeEnum::Human:
            return "Human";
            break;
        case CharacterTypeEnum::Dwarf:
            return "Dwarf";
            break;
        case CharacterTypeEnum::Elf:
            return "Elf";
            break;
        case CharacterTypeEnum::Orc:
            return "Orc";
            break;
        case CharacterTypeEnum::Merchant:
            return "Merchant";
            break;
        case CharacterTypeEnum::Dragon:
            return "Dragon";
            break;
        case CharacterTypeEnum::Halfling:
            return "Halfling";
            break;
        default:
            return "Invalid";
            break;
    }
}
bool CharacterType::operator==(CharacterType other) {
    return type == other.type;
}
const CharacterType CharacterType::Shade {CharacterTypeEnum::Shade};
const CharacterType CharacterType::Drow {CharacterTypeEnum::Drow};
const CharacterType CharacterType::Vampire {CharacterTypeEnum::Vampire};
const CharacterType CharacterType::Troll {CharacterTypeEnum::Troll};
const CharacterType CharacterType::Goblin {CharacterTypeEnum::Goblin};
const CharacterType CharacterType::Human {CharacterTypeEnum::Human};
const CharacterType CharacterType::Dwarf {CharacterTypeEnum::Dwarf};
const CharacterType CharacterType::Elf {CharacterTypeEnum::Elf};
const CharacterType CharacterType::Orc {CharacterTypeEnum::Orc};
const CharacterType CharacterType::Merchant {CharacterTypeEnum::Merchant};
const CharacterType CharacterType::Dragon {CharacterTypeEnum::Dragon};
const CharacterType CharacterType::Halfling {CharacterTypeEnum::Halfling};
const CharacterType CharacterType::Invalid {CharacterTypeEnum::Invalid};