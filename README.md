# Tic tac toe game
This tic tac toe game is written in C, developed just to learn the C syntax.

We have seven functions other than main, and there are:
1. `player_turn()` = here we have all the logic about the player when it has to place the sign
2. `bot_turn()` = is the same as the player_turn, but here the bot choose a place where to put his sign randomly
3. `display_table()` = we call this function every time we have to display the board, updated with the moves made by the players
4. `check_win()` = here we check if any of the player has win (tris) by checking the rows, columns and diagonals
5. `game()` = in this function all the game run, assign all the turns, display the table and check for a winner
6. `choose_sign()` = this function is called once at the beginning, the player can choose either of the two sign, the bot will be assigned with the sign left
7. `show_game_winner()` = this last function is called when we have a winner, will print to the user if it has lost or not
