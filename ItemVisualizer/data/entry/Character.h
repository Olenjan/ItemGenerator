#ifndef CHARACTER_H
#define CHARACTER_H

#include "DataTableBase.h"
#include "Modifier.h"


struct CharacterStats
{
    Name name;
    Level level;

    //Resource
    RollValue life  = 0;
    RollValue mana  = 0;
    RollValue stamina = 0;

    //Attr
    RollValue strength = 0;
    RollValue dexterity = 0;
    RollValue intelligence = 0;

    //Offence
    RollValue minimumPhysicalDamage = 0;
    RollValue maximumPhysicalDamage = 0;
    RollValue increasedPhysicalDamage = 0;

    //Defence
    RollValue armor = 0;
};


class CharacterAnimationState
{
private:
public:
    enum class eCharacterUpperState
    {
        NONE = 0,
        IDLE,
        CASTING,
        ATTACKING,
        BLOCKING,
        CROUCHING,
        DYING
    };

    enum class eCharacterLowerState
    {
        NONE = 0,
        IDLE,
        WALKING,
        RUNNING,
        TURNING_LEFT,
        TURNING_RIGHT,
        JUMPING,
        FALLING,
        CROUCHING,
        DYING
    };

private:
    // Member variables
    eCharacterUpperState upperState = eCharacterUpperState::NONE;
    eCharacterLowerState lowerState = eCharacterLowerState::NONE;
public:
    CharacterAnimationState() = default;


    // Accessor methods
    eCharacterUpperState GetUpperState() const{}
    eCharacterLowerState GetLowerState() const{}

    // Mutator methods
    void SetUpperState(eCharacterUpperState state){}
    void SetLowerState(eCharacterLowerState state){}

};


class Character
{
private:
    CharacterStats           m_Stats;
    CharacterAnimationState  m_AnimationState;
public:
    Character(){}

    //virtual void setVelocity(const glm::vec3& velocity) = 0;
};

#endif // CHARACTER_H
