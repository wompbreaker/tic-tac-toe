#include "game.h"

int main()
{
    Player_s player1, player2;
    Player_s *current_player = &player1;
    char game_board[3][3];
    char winner;
    uint8_t tied = 0;
    print_instructions();
    init_game(game_board, &player1, &player2);
    while (1) {
        player_move(game_board, *current_player);
        winner = check_winner(game_board);
        tied = check_tied(game_board);
        if (winner != ' ') {
            clear_console();
            print_grid(game_board);
            printf("Player %u wins!\n", current_player->id);
            break;
        }
        if (tied) {
            clear_console();
            print_grid(game_board);
            printf("The game is tied!\n");
            break;
        }
        
        // Switch players
        if (current_player->id == player1.id) {
            current_player = &player2;
        } else {
            current_player = &player1;
        }
    }
    
    return 0;
}