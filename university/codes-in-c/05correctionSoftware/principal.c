// Created by Igor Santiago - 19.1.4033 on 17/06/2021.

#include "corretor.h"
#include "stdio.h"

int main(){

    TADsub *S;
    TADhm *H;
    
    read_length_submissions(&length);
    
    S = new_submissions(S, length);
    read_submissions(S, length);
    
    hits = get_hits(S, length);

    H = new_hm(H, S, length, hits);
    
    get_correct_questions(H, S, length);
    check_incomplete_judgments(H, S, length);

    total_time = correction(S, H, length);
    
    print_correction(hits, total_time);

    S = free_submissions(S);
    H = free_hm(H);

    return 0;
}