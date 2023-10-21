// Created by Igor Santiago - 19.1.4033 on 28/07/2021.

# ifndef ordenacao_h
# define ordenacao_h
    
    typedef struct{
        char country[50];
        int gold_medals;
        int silver_medals;
        int bronze_medals;
    }MedalsBoard;
    
    int number_countries;

    MedalsBoard *new_board(MedalsBoard *medals_board, int number_countries);

    MedalsBoard *free_board(MedalsBoard *medals_board);
    
    void size_of_board(int *number_countries);

    void fill_medals_board(MedalsBoard *medals_board, int number_countries);

    void print_medals_board(MedalsBoard *medals_board, int number_countries);

    void order_golds(MedalsBoard *medals_board, int number_countries);

    void order_silvers(MedalsBoard *medals_board, int number_countries);

    void order_bronzes(MedalsBoard *medals_board, int number_countries);

    // functions in tests
    void order_country_name(MedalsBoard *medals_board, int number_countries);

# endif