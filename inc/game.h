#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include <string.h>

/**
 * @struct Player
 * @brief Structure representing a player in the game.
 *
 * @var Player::id
 * Player's unique identifier (1 or 2).
 * @var Player::name
 * Player's symbol/mark (e.g., 'X' or 'O').
 */
typedef struct Player {
    uint8_t id;   /**< Player's unique identifier. */
    char name;    /**< Player's symbol/mark. */
} Player_s;

/**
 * @brief Waits for the user to press the Enter key.
 *        Clears any extra input from the buffer.
 */
void wait_for_key_press();

/**
 * @brief Clears the console screen.
 */
void clear_console();

/**
 * @brief Prints the current state of the game board.
 * @param game_board The 3x3 game board array.
 */
void print_grid(char game_board[3][3]);

/**
 * @brief Pauses execution for a specified number of milliseconds.
 * @param milliseconds Number of milliseconds to sleep.
 */
void sleep_ms(int milliseconds);

/**
 * @brief Initializes the game board and player structures.
 * @param game_board The 3x3 game board array.
 * @param player1 Pointer to the first player structure.
 * @param player2 Pointer to the second player structure.
 */
void init_game(char game_board[3][3], Player_s *player1, Player_s *player2);

/**
 * @brief Checks for a winner in the diagonals of the game board.
 * @param game_board The 3x3 game board array.
 * @return The symbol of the winning player, or ' ' if no winner.
 */
char check_winner_diag(char game_board[3][3]);

/**
 * @brief Checks for a winner in the rows of the game board.
 * @param game_board The 3x3 game board array.
 * @return The symbol of the winning player, or ' ' if no winner.
 */
char check_winner_hor(char game_board[3][3]);

/**
 * @brief Checks for a winner in the columns of the game board.
 * @param game_board The 3x3 game board array.
 * @return The symbol of the winning player, or ' ' if no winner.
 */
char check_winner_ver(char game_board[3][3]);

/**
 * @brief Checks for a winner in the game board (rows, columns, diagonals).
 * @param game_board The 3x3 game board array.
 * @return The symbol of the winning player, or ' ' if no winner.
 */
char check_winner(char game_board[3][3]);

/**
 * @brief Checks if the game is tied (no empty spaces and no winner).
 * @param game_board The 3x3 game board array.
 * @return 1 if tied, 0 otherwise.
 */
uint8_t check_tied(char game_board[3][3]);

/**
 * @brief Validates a player's move.
 * @param game_board The 3x3 game board array.
 * @param player The player making the move.
 * @param x The x coordinate (column).
 * @param y The y coordinate (row).
 * @return 1 if the move is valid, 0 otherwise.
 */
uint8_t validate_player_move(char game_board[3][3], Player_s player, uint8_t x, uint8_t y);

/**
 * @brief Handles a player's move (input and update board).
 * @param game_board The 3x3 game board array.
 * @param player The player making the move.
 */
void player_move(char game_board[3][3], Player_s player);

/**
 * @brief Prints the game instructions and rules.
 */
void print_instructions();