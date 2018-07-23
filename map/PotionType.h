#ifndef POTIONTYPE_H
#define POTIONTYPE_H

#include <string>

struct PotionType {
	enum class PotionTypeEnum {
		BoostAttack,
		WoundAttack,
		BoostDefense,
		WoundDefense,
		Health,
		Poison
	};
	PotionTypeEnum type;
    PotionType(PotionTypeEnum type);
    std::string to_string();
    bool operator==(PotionType other);
	const static PotionType BoostAttack;
	const static PotionType WoundAttack;
	const static PotionType BoostDefense;
	const static PotionType WoundDefense;
	const static PotionType Health;
	const static PotionType Poison;
};
#endif
