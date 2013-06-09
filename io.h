#ifndef __IO_H__
#define __IO_H__

#define X_MAX	80
#define Y_MAX 25

enum {
	GENERAL,
	BALANS,
	PROFIT,
	EXPANSE,
	ACTIVE,
	PASSIVE,
	SETTINGS,
	EXIT
};

struct CellStruct {
				char* name;
				unsigned long number;
};

void clearScreen(void);
void gotoxy(int x, int y);

#endif
