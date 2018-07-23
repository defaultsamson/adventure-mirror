#include "PotionType.h"

PotionType::PotionType(PotionTypeEnum characterType): type{characterType} {}
std::string PotionType::to_string() {
    switch(type) {
        case PotionTypeEnum::BoostAttack:
            return "Boost Attack Potion";
        case PotionTypeEnum::WoundAttack:
            return "Wound Attack Potion";
        case PotionTypeEnum::BoostDefense:
            return "Boost Defense Potion";
        case PotionTypeEnum::WoundDefense:
            return "Wound Defense Potion";
        case PotionTypeEnum::Health:
            return "Health Potion";
        case PotionTypeEnum::Poison:
            return "Poison Potion";
    }
    return "Invalid";
}
bool PotionType::operator==(PotionType other) {
    return type == other.type;
}
const PotionType PotionType::BoostAttack {PotionTypeEnum::BoostAttack};
const PotionType PotionType::WoundAttack {PotionTypeEnum::WoundAttack};
const PotionType PotionType::BoostDefense {PotionTypeEnum::BoostDefense};
const PotionType PotionType::WoundDefense {PotionTypeEnum::WoundDefense};
const PotionType PotionType::Health {PotionTypeEnum::Health};
const PotionType PotionType::Poison {PotionTypeEnum::Poison};

