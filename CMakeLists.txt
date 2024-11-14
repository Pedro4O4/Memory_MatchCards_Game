cmake_minimum_required(VERSION 3.28)
project(Memory_MatchCard_Game)

set(CMAKE_CXX_STANDARD 17)

add_executable(Memory_MatchCard_Game main.cpp
        Card.h
        Deck.h
        Player.h
        Game.h
        StandardCard.h
        BonusCard.h
        PenaltyCard.h)
