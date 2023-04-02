
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <string.h>

#include "level.h"

/**
 * Initialize a level.
 * @param level the level
 */
void level_init(level_t *level) {
	int i, j;
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			level->cells[i][j] = btowc(' ');
			level->colors[i][j] = FG_WHITE;
			block_t block = { EMPTY_B, 0 };
			level->blocks[i][j] = block;
		}
	}
}

/**
 * Display a level in the terminal.
 * @param level the level
 */
void level_display(level_t *level) {
	int i, j;
	
	for (i = 0; i < WIDTH + 2; i++)
		printf("*");
	printf("\n");
	
	for (i = 0; i < HEIGHT; i++) {
		printf("*");
		for (j = 0; j < WIDTH; j++) {
			printf("\x1b[%dm%C\x1b[0m", level->colors[i][j], level->cells[i][j]);
		}
		printf("*\n");
	}
	
	for (i = 0; i < WIDTH + 2; i++)
		printf("*");
	printf("\n");
}

/**
 * Get the string representation of a level.
 * @param level the level
 * @return the string representation
 */
char* level_get_string(level_t *level) {
	int i, j;
	size_t size = 0;
	for (i = 0; i < HEIGHT; i++)
		for (j = 0; j < WIDTH; j++)
			if (level->blocks[i][j].type != EMPTY_B)
				size += 32;

	char *str = malloc(size);
	memset(str, '\0', size);

	strcat(str, "\nlevel\n");

	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			char line[32];
			memset(line, '\0', sizeof(line));
			
			switch (level->blocks[i][j].type) {
				case ROBOT_B: sprintf(line, "\tput(%d, %d, ROBOT)\n", j, i); break;
				case PROBE_B: sprintf(line, "\tput(%d, %d, PROBE)\n", j, i); break;
				case EMPTY_B: break;
				case BLOCK_B: sprintf(line, "\tput(%d, %d, BLOCK)\n", j, i); break;
				case TRAP_B: sprintf(line, "\tput(%d, %d, TRAP)\n", j, i); break;
				case LADDER_B: sprintf(line, "\tput(%d, %d, LADDER)\n", j, i); break;
				case BOMB_B: sprintf(line, "\tput(%d, %d, BOMB)\n", j, i); break;
				case LIFE_B: sprintf(line, "\tput(%d, %d, LIFE)\n", j, i); break;
				case KEY_B: sprintf(line, "\tput(%d, %d, KEY)\n", j, i); break;
				case GATE_B: sprintf(line, "\tput(%d, %d, GATE)\n", j, i); break;
				case DOOR_B: sprintf(line, "\tput(%d, %d, DOOR)\n", j, i); break;
				case START_B: sprintf(line, "\tput(%d, %d, START)\n", j, i); break;
				case EXIT_B: sprintf(line, "\tput(%d, %d, EXIT)\n", j, i); break;
			}

			strcat(str, line);
		}
	}

	strcat(str, "end\n");

	return str;
}

/**
 * Add a robot in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 */
void level_add_robot(level_t *level, int posX, int posY) {
	int i, j;
	
	for (i = posY; i < posY + 4; i++)
		for (j = posX; j < posX + 3; j++)
			level->colors[i][j] = FG_WHITE;
	
	level->cells[posY][posX] = 0x250C;             // ┌
	level->cells[posY][posX] = 0x250C;
	level->cells[posY][posX+1] = 0x2534;           // ┴
	level->cells[posY][posX+2] = 0x2510;           // ┐
	level->cells[posY+1][posX] = 0x2514;           // └
	level->cells[posY+1][posX+1] = 0x252C;         // ┬
	level->cells[posY+1][posX+2] = 0x2518;         // ┘
	level->cells[posY+2][posX] = 0x2500;           // ─
	level->cells[posY+2][posX+1] = 0x253C;         // ┼
	level->cells[posY+2][posX+2] = 0x2500;         // ─
	level->cells[posY+3][posX] = 0x250C;           // ┌
	level->cells[posY+3][posX+1] = 0x2534;         // ┴
	level->cells[posY+3][posX+2] = 0x2510;         // ┐

	// Add the robot block
	block_t block = { ROBOT_B, 0 };
	level->blocks[posY][posX] = block;
}

/**
 * Add a probe in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 */
void level_add_probe(level_t *level, int posX, int posY) {
	int i, j;
	
	for (i = posY; i < posY + 2; i++)
		for (j = posX; j < posX + 3; j++)
			level->colors[i][j] = FG_WHITE;
	
	level->cells[posY][posX] = 0x251C;             // ├
	level->cells[posY][posX+1] = 0x2500;           // ─
	level->cells[posY][posX+2] = 0x2524;           // ┤
	level->cells[posY+1][posX] = 0x2514;           // └
	level->cells[posY+1][posX+1] = 0x2500;         // ─
	level->cells[posY+1][posX+2] = 0x2518;         // ┘

	// Add the probe block
	block_t block = { PROBE_B, 0 };
	level->blocks[posY][posX] = block;
}

/**
 * Add a empty block in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 */
void level_add_empty(level_t *level, int posX, int posY) {
	level->cells[posY][posX] = btowc(' ');
	level->colors[posY][posX] = FG_WHITE;

	// Add the empty block
	block_t block = { EMPTY_B, 0 };
	level->blocks[posY][posX] = block;
}

/**
 * Add a block in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 */
void level_add_block(level_t *level, int posX, int posY) {
	level->cells[posY][posX] = btowc(' ');
	level->colors[posY][posX] = BK_BLUE;

	// Add the block block
	block_t block = { BLOCK_B, 0 };
	level->blocks[posY][posX] = block;
}

/**
 * Add a trap in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 */
void level_add_trap(level_t *level, int posX, int posY) {
	level->cells[posY][posX] = btowc('#');
	level->colors[posY][posX] = BK_BLUE;

	// Add the trap block
	block_t block = { TRAP_B, 0 };
	level->blocks[posY][posX] = block;
}

/**
 * Add a ladder in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 */
void level_add_ladder(level_t *level, int posX, int posY) {
	int i;
	
	for (i = posX; i < posX + 3; i++)
		level->colors[posY][i] = FG_YELLOW;
	
	level->cells[posY][posX] = 0x251C;             // ├
	level->cells[posY][posX+1] = 0x2500;           // ─
	level->cells[posY][posX+2] = 0x2524;           // ┤

	// Add the ladder block
	block_t block = { LADDER_B, 0 };
	level->blocks[posY][posX] = block;
}

/**
 * Add a bomb in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 */
void level_add_bomb(level_t *level, int posX, int posY) {
	level->cells[posY][posX] = btowc('O');
	level->colors[posY][posX] = FG_WHITE;

	// Add the bomb block
	block_t block = { BOMB_B, 0 };
	level->blocks[posY][posX] = block;
}

/**
 * Add a life in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 */
void level_add_life(level_t *level, int posX, int posY) {
	level->cells[posY][posX] = btowc('V');
	level->colors[posY][posX] = FG_RED;

	// Add the life block
	block_t block = { LIFE_B, 0 };
	level->blocks[posY][posX] = block;
}

/**
 * Add a key in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 * @param num the number of the key (1 to 4)
 */
void level_add_key(level_t *level, int posX, int posY, int num) {
	level->cells[posY][posX] = btowc('0' + num);
	level->cells[posY+1][posX] = 0x2518;         // ┘
	
	switch(num) {
		case 1:        
			level->colors[posY][posX] = BK_MAGENTA;
			level->colors[posY+1][posX] = FG_MAGENTA;
			break;
		case 2:        
			level->colors[posY][posX] = BK_GREEN;
			level->colors[posY+1][posX] = FG_GREEN;
			break;
		case 3:        
			level->colors[posY][posX] = BK_YELLOW;
			level->colors[posY+1][posX] = FG_YELLOW;
			break;
		case 4:        
			level->colors[posY][posX] = BK_BLUE;
			level->colors[posY+1][posX] = FG_BLUE;
			break;
	}

	// Add the key block
	block_t block = { KEY_B, num };
	level->blocks[posY][posX] = block;
}

/**
 * Add a gate in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 * @param num the number of the gate (1 to 4)
 */
void level_add_gate(level_t *level, int posX, int posY, int num) {
	level->cells[posY][posX] = 0x253C;           // ┼
	switch(num) {
		case 1:        
			level->colors[posY][posX] = FG_MAGENTA;
			break;
		case 2:        
			level->colors[posY][posX] = FG_GREEN;
			break;
		case 3:        
			level->colors[posY][posX] = FG_YELLOW;
			break;
		case 4:        
			level->colors[posY][posX] = FG_BLUE;
			break;
	}

	// Add the gate block
	block_t block = { GATE_B, num };
	level->blocks[posY][posX] = block;
}

/**
 * Add a door in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 * @param num the number of the door (1 to 99)
 */
void level_add_door(level_t *level, int posX, int posY, int num) {
	int i, j;
	
	level->cells[posY][posX] = btowc('0' + num / 10);
	level->colors[posY][posX] = FG_WHITE;
	level->cells[posY][posX + 1] = btowc('0' + num % 10);
	level->colors[posY][posX + 1] = FG_WHITE;
	level->cells[posY][posX + 2] = btowc(' ');
	level->colors[posY][posX + 2] = BK_GREEN;
	
	for (i = posY + 1; i < posY + 4; i++)
		for (j = posX; j < posX + 3; j++) {
			level->cells[i][j] = btowc(' ');
			level->colors[i][j] = BK_GREEN;
		}
	
	// Add the door block
	block_t block = { DOOR_B, num };
	level->blocks[posY][posX] = block;
}

/**
 * Add a start door in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 * @param num the number of the door (1 to 99)
 */
void level_add_start(level_t *level, int posX, int posY) {
	int i, j;
	
	for (i = posY; i < posY + 4; i++)
		for (j = posX; j < posX + 3; j++) {
			level->cells[i][j] = btowc(' ');
			level->colors[i][j] = BK_MAGENTA;
		}

	// Add the start block
	block_t block = { START_B, 0 };
	level->blocks[posY][posX] = block;
}

/**
 * Add an exit door in a level.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 */
void level_add_exit(level_t *level, int posX, int posY) {
	int i, j;
	
	for (i = posY; i < posY + 4; i++)
		for (j = posX; j < posX + 3; j++) {
			level->cells[i][j] = btowc(' ');
			level->colors[i][j] = BK_YELLOW;
		}

	// Add the exit block
	block_t block = { EXIT_B, 0 };
	level->blocks[posY][posX] = block;
}

/**
 * Get the block at a given position.
 * @param level the level
 * @param posX the X position
 * @param posY the Y position
 */
block_t level_get_block(level_t *level, int posX, int posY) {
	return level->blocks[posY][posX];
}

