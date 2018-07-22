#ifndef NULLDECORATOR_H
#define NULLDECORATOR_H

class NullDecorator: public CharacterDecorator {
public:
	NullDecorator(CharacterDecorator *component);
}

#endif

