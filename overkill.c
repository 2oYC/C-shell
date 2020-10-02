#include "shell.h"

void overkill(){
    for(int i=0; i<bg_order_len; i++)
        kill(bg_order[i],9);
    return;
}