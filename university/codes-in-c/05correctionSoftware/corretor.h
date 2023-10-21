// Created by Igor Santiago - 19.1.4033 on 17/06/2021.

# ifndef corretor_h
# define corretor_h
   
    #define TAXA_ERROR 20

    int length;
    int hits;
    int total_time;
    
    typedef struct submissions TADsub;
    typedef struct hits_and_misses TADhm;

    void read_length_submissions(int *length);
    void read_submissions(TADsub *S, int length);
    
    TADsub *new_submissions(TADsub *S, int length);
    TADsub *free_submissions(TADsub * S);

    TADhm *new_hm(TADhm *H, TADsub *S, int length, int hits);
    TADhm *free_hm(TADhm *H);

    void get_correct_questions(TADhm *H, TADsub *S, int length);

    int get_hits(TADsub *S, int length);
    void check_incomplete_judgments(TADhm *H, TADsub *S, int length);

    int correction(TADsub *S, TADhm *H, int length);
    void print_correction(int qtd_correct, int total_time);
    
# endif