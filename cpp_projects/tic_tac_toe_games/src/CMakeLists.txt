cmake_minimum_required(VERSION 3.27)
project(discussion)

set(CMAKE_CXX_STANDARD 17)

add_executable(discussion A2_S5_20231211_SheetPb6.cpp)

add_executable(discussion2 A2_T1,1_S5_20231211_SheetPb3.cpp)

add_executable(discussion3
        3x3X_O.h
        BoardGame_Classes.h
        Four_by_four_tic_tac_toe.h
        Four_in_a_row.h
        Numerical_tic_tac_toe.h
        TIC_TAC.h
        word_X_O.h
        X_O_5x5.h
        X_O_9x9.h
        Misere_X_O.h
        main.cpp)

