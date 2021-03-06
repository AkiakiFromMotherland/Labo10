/*
 -----------------------------------------------------------------------------------
 Laboratoire : Snake
 Fichier     : display.cpp
 Auteur(s)   : Yann Lederrey
 Date        : 20.01.2019
 
 Compilateur : g++ (GCC) 9.2.0

 Brief       : Implémentation des fonctions du fichier display.h
 -----------------------------------------------------------------------------------
 */

#include "display.h"

void displayMenu(int score){
    std::cout << MENU_WELCOME << std::endl;
    std::cout << MENU_START << std::endl;
    std::cout << MENU_QUIT << std::endl;
    std::cout << MENU_INSTRUCTION << std::endl;
    std::cout << MENU_SCORE << std::to_string(score) << std::endl;
}

void displayInstructions(){
    std::cout << INSTR_UP << std::endl;
    std::cout << INSTR_LEFT << std::endl;
    std::cout << INSTR_DOWN << std::endl;
    std::cout << INSTR_RIGHT << std::endl;
    std::cout << INSTR_EXIT << std::endl;
    std::cout << INSTR_MENU << std::endl;   
}

void draw(int width, int height, int snakePosX, int snakePosY, int fruitPosX, int fruitPosY, int snakeSize, int tailX[], int tailY[], const GamePanel &gp)
 {
    for (int i = 0; i < width + 2; i++) {
        std::cout << BORDER;
    }

    std::cout << std::endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                std::cout << BORDER;

            if (i == snakePosY && j == snakePosX)
                std::cout << SNAKE_HEAD;

            else if (i == fruitPosY && j == fruitPosX)
                std::cout << FRUIT;

            else if(gp.at(i).at(j) == OBSTACLE)
                std::cout << OBSTACLE_STR;

            else {

                bool print = false;

                for (int k = 0; k < snakeSize; k++) {

                    if (tailX[k] == j && tailY[k] == i) {

                        std::cout << SNAKE_TAIL;
                        print = true;
                    }
                }

                if (!print)
                    std::cout << " ";
            }

            if (j == width - 1)

                std::cout << BORDER;


        }
        std::cout << std::endl;
    }

    for (int i = 0; i < width + 2; i++) {
        std::cout << BORDER;
    }

    std::cout << std::endl;

    std::cout << ACTUAL_SCORE << snakeSize << std::endl;

}

void displayUserScore(){
    std::cout << USER_SCORE_WELCOME;
}