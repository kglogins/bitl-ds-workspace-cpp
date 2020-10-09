#include "CircleList.h"
#include <iostream>

int main()
{

    ds_course::CircleList *playList;
    // []
    playList->add(2);
    // [1*]
    playList->add(4);
    // [2, 1*]
    playList->add(6);
    // [3, 2, 1*]
    playList->add(4);
    // [4, 3, 2, 1*]

    // playList.advance();
    // // [2, 1, 3*]
    // playList.advance();
    // // [1, 3, 2*]
    // playList.remove();
    // // [3, 2*]
    // playList.add(4);
    // // [4, 3, 2*]

    std::cout << playList->to_str() << std::endl;

    return EXIT_SUCCESS;
}

void INS(ds_course::CircleList cL, int pos)
{
}
