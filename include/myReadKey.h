#ifndef MYREADKEY_H
#define MYREADKEY_H

#include "Lprint.h"
#include "mySimpleComputer.h"
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#define MIN_BUF_SIZE 6
extern char buffer[MIN_BUF_SIZE];
extern struct termios save;

enum keys
{
  ESC_KEY = 16,
  L_KEY,
  S_KEY,
  R_KEY,
  T_KEY,
  I_KEY,
  F5_KEY,
  F6_KEY,
  UP_KEY,
  DOWN_KEY,
  LEFT_KEY,
  RIGHT_KEY,
  ENTER_KEY,
  NOTHING_KEY,
  INVALID_KEY,

  ZERO_KEY = 0,
  ONE_KEY,
  TWO_KEY,
  THREE_KEY,
  FOUR_KEY,
  FIVE_KEY,
  SIX_KEY,
  SEVEN_KEY,
  EIGHT_KEY,
  NINE_KEY,
  A_KEY = 10,
  B_KEY,
  C_KEY,
  D_KEY,
  E_KEY,
  F_KEY,

  PLUS_KEY = 45,
  MINUS_KEY = 43

};

int rk_readkey (enum keys *key);
int rk_mytermsave ();
int rk_mytermrestore ();
int rk_mytermregime (int regime, int vtime, int vmin, int echo, int sigint);
int rk_readvalue (int *value, int timeout);

#endif