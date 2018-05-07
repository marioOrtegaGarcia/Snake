//
//  GameBoard.cpp
//  glutapp
//
//  Created by Mario Ortega on 4/26/18.
//  Copyright © 2018 Angelo Kyrilov. All rights reserved.
//

#include "GameBoard.hpp"
Board::Board(){
  for (int i = 0; i < 10; i++)
      for (int j = 0; j < 10; j++)
          gameBoard[i][j] = nullptr;
}
Board::~Board(){
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            delete gameBoard[i][j];
}
