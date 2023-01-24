#include "../include/stdio.h"

#include "../include/string.h"
#include <stddef.h>
#include <limine.h>
#include <stdarg.h>

/* -----------------V Limine Bootloader Stuf V----------------- */
struct limine_terminal *_tty;

static volatile struct limine_terminal_request _tty_req = {
    .id = LIMINE_TERMINAL_REQUEST, .revision = 0};

/* -----------------V Kernel Stuf V----------------- */
int initIO() {
  if (_tty_req.response == NULL || _tty_req.response->terminal_count < 1) {
    return -1;
  }
  _tty = _tty_req.response->terminals[0];

  return 0;
}

char *__int_str(long long int num, char buff[]) {
  char digit[32] = {0};

  memset(digit, 0, 32);
  strcpy(digit, "0123456789");

  char *mbuff = buff;
  if (num < 0) {
    *mbuff++ = '-';
  }

  long long int tnum = num;

  do { // Move pointer to the most-left position needed
    ++mbuff;
    tnum = tnum / 10;
  } while (tnum);

  *mbuff = '\0'; // Null terminated C String!

  do {
    *--mbuff = digit[num % 10];
    num = num / 10;
  } while (num);

  return buff;
}

/* -----------------V Userspace Stuf V----------------- */
int printf(const char *format, ...) {
  va_list list;
  va_start(list, format);
  char numStrBuf[256] = {0};

  for (int i = 0; format[i]; i++) {
    if (format[i] == '%') {
      i++;

      switch (format[i]) {
      case 'd':
      case 'i': {
        memset(numStrBuf, 0, 256);

        long long int integer = va_arg(list, long long int);
        __int_str(integer, numStrBuf);

        _tty_req.response->write(_tty, numStrBuf, strlen(numStrBuf));
        break;
      }
      default:
        break;
      }
    }
  }
}