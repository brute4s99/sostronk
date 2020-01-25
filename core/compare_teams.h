#ifndef COMPARE_TEAMS_H
#define COMPARE_TEAMS_H

#include<iostream>
#include<algorithm>
#include "matchmake.h"

bool operator<(PLAYER const &player1, PLAYER const &player2);

bool compare(PLAYER const &player1, PLAYER const &player2);

bool areDisjoint(TEAM &team1, TEAM &team2);

#endif