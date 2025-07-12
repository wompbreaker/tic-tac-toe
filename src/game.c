#include "game.h"


void clear_console() {
#ifdef _WIN32
    system("cls");
#elif defined(__APPLE__)
    system("clear");
#elif defined(__linux__)
    system("clear");
#else
    printf("\033[2J\033[H");
#endif
}

void wait_for_key_press() {
    printf("Press <ENTER> to continue...\n");
    int c;
    // Read until newline or EOF to clear the buffer
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void print_grid(char game_board[3][3])
{
    printf("    0   1   2  \n");
    printf("  +---+---+---+\n");
    printf("0 | %c | %c | %c |\n", game_board[0][0], game_board[0][1], game_board[0][2]);
    printf("  +---+---+---+\n");
    printf("1 | %c | %c | %c |\n", game_board[1][0], game_board[1][1], game_board[1][2]);
    printf("  +---+---+---+\n");
    printf("2 | %c | %c | %c |\n", game_board[2][0], game_board[2][1], game_board[2][2]);
    printf("  +---+---+---+\n");
}

void sleep_ms(int milliseconds) {
#ifdef _WIN32
    Sleep(milliseconds);
#else
    // usleep takes microseconds, so multiply milliseconds by 1000
    usleep(milliseconds * 1000);
#endif
}

void init_game(char game_board[3][3], Player_s *player1, Player_s *player2)
{
    clear_console();
    // Initialize board
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            game_board[i][j] = ' ';
    // Initialize players
    (*player1).id = 1;
    (*player1).name = 'X';
    (*player2).id = 2;
    (*player2).name = 'O';
}

char check_winner_diag(char game_board[3][3])
{
    char ret_val = ' ';
    if (
        (game_board[0][0] & game_board[1][1] & game_board[2][2]) == game_board[0][0] ||
        (game_board[0][2] & game_board[1][1] & game_board[2][0]) == game_board[0][2]
    )
        ret_val = game_board[1][1];
    return ret_val;
}

char check_winner_hor(char game_board[3][3])
{
    char ret_val = ' ';
    if((game_board[0][0] & game_board[0][1] & game_board[0][2]) == game_board[0][0])
        ret_val = game_board[0][0];
    if((game_board[1][0] & game_board[1][1] & game_board[1][2]) == game_board[1][0])
        ret_val = game_board[1][0];
    if((game_board[2][0] & game_board[2][1] & game_board[2][2]) == game_board[2][0])
        ret_val = game_board[2][0];
    return ret_val; 
}

char check_winner_ver(char game_board[3][3])
{
    char ret_val = ' ';
    if ((game_board[0][0] & game_board[1][0] & game_board[2][0]) == game_board[0][0])
        ret_val = game_board[0][0];
    if ((game_board[0][1] & game_board[1][1] & game_board[2][1]) == game_board[0][1])
        ret_val = game_board[0][1];
    if ((game_board[0][2] & game_board[1][2] & game_board[2][2]) == game_board[0][2])
        ret_val = game_board[0][2]; 
    return ret_val; 
}

char check_winner(char game_board[3][3])
{
    char winner_char = ' ';
    char ret_val = check_winner_diag(game_board);
    if (ret_val != ' ')
        winner_char = ret_val;
    ret_val = check_winner_hor(game_board);
    if (ret_val != ' ')
        winner_char = ret_val;
    ret_val = check_winner_ver(game_board);
    if (ret_val != ' ')
        winner_char = ret_val;
    return winner_char; 
}

uint8_t check_tied(char game_board[3][3])
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game_board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

uint8_t validate_player_move(char game_board[3][3], Player_s player, uint8_t x, uint8_t y)
{
    if (game_board[y][x] != ' ') {
        printf("Invalid move! Cell already occupied.\n");
        return 0;
    }
    game_board[y][x] = player.name;
    return 1;
}

void player_move(char game_board[3][3], Player_s player)
{
    char x_coor[100];
    char y_coor[100];
    do {
        clear_console();
        print_grid(game_board);
        printf("Player %u move...\n", player.id);
        printf("Enter the x coordinate [0-2]: ");
        fgets(x_coor, sizeof(x_coor), stdin);
    } while(strlen(x_coor) > 2 || x_coor[0] < '0' || x_coor[0] > '2');
    uint8_t x = (uint8_t) x_coor[0] - '0';
    do {
        clear_console();
        print_grid(game_board);
        printf("Player %u move...\n", player.id);
        printf("Enter the x coordinate [0-2]: %u\n", x);
        printf("Enter the y coordinate [0-2]: ");
        fgets(y_coor, sizeof(y_coor), stdin);
    } while(strlen(y_coor) > 2 && y_coor[0] < '0' || y_coor[0] > '2');
    uint8_t y = (uint8_t) y_coor[0] - '0';
    if (!validate_player_move(game_board, player, x, y)) {
        sleep_ms(1000);
        player_move(game_board, player);
    }
}

void print_instructions()
{
    clear_console();
    printf("Welcome to a simple terminal-based tic-tac-toe game!\n");
    printf("The rules are pretty simple: \n");
    printf("1. Two players take turns placing their marks (X or O) on the board.\n");
    printf("2. Player 1 starts the game, placing 'X' by choosing an X and Y coordinate.\n");
    printf("3. Player 2 chooses the x and y coordinates where they will put the 'O'.\n");
    printf("4. The player who places three of their marks consecutively in any row, column, or diagonal wins.\n");
    printf("5. If neither player wins the game, it's a draw.\n");
    wait_for_key_press();
}