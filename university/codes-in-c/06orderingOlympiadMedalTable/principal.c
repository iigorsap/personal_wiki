// Created by Igor Santiago - 19.1.4033 on 28/07/2021.

#include "ordenacao.h"
#include <stdio.h>


int main(){ 

    MedalsBoard *medals_board;  

    // read size of board
    size_of_board(&number_countries);
    
    medals_board = new_board(medals_board, number_countries);
    
    fill_medals_board(medals_board, number_countries);

    order_golds(medals_board, number_countries);
    order_silvers(medals_board, number_countries);
    order_bronzes(medals_board, number_countries);
    order_country_name(medals_board, number_countries);

    print_medals_board(medals_board, number_countries);

    free_board(medals_board);
    
    return 0;
}
