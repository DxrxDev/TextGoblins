#pragma once

/* Secondary effects of weapon when used */
enum WeaponEffect{
    WE_NONE = 0b0000,
    WE_HEAL = 0b0001,
    WE_POISON = 0b0010,
    WE_FREEZE = 0b0100,
    WE_DEFEND = 0b1000
};

/* Basic weapon struct */
struct Weapon{
    const char *name; /* Name of weapon in-game */
    const char cost;
    const int power1; /* Power of primary attack */
    const int numSwing; /* How many swings per attack */
    const int numChain; /* How many enemies hit per attack */
    const int power2; /* Power of secondary effect */
    const char WE; /* What secondary effects the weapon has */
};

/* Weapon def structure

Weapon _NAME_ {
    _name_, _cost_,
    _primDamage_, _numAttack_, _numEnemies_,
    _effectStr_, _Effect(s)_
};
*/

/* 1st teir weapon definitions */
Weapon w_stick  {
    "stick", 1,
    3, 1, 1,
    1, WE_DEFEND
};
Weapon w_rocks  {
    "rocks", 1,
    1, 2, 2,
    0, WE_NONE
};
Weapon w_book   {
    "book", 1,
    2, 2, 1,
    0, WE_NONE
};