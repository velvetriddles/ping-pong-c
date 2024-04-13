#include <stdio.h>

int main() {
    int max_x = 80, max_y = 25;
    int ball_x = max_x / 2, ball_y = max_y / 2;
    int P1_x = 1, P1_y = max_y / 2;
    int P2_x = max_x - 2, P2_y = max_y / 2;
    int b_vx = 1, b_vy = 1;
    int exit_flag = 0, win_flag = 0;
    int score_1 = 18, score_2 = 0;

    while (win_flag == 0) {
        //----------
        switch (getchar()) {
            case 'k':
                P2_y = P2_y > 0 ? P2_y - 1 : P2_y;
                break;
            case 'm':
                P2_y = P2_y < max_y - 4 ? P2_y + 1 : P2_y;
                break;
            case 'a':
                P1_y = P1_y > 0 ? P1_y - 1 : P1_y;
                break;
            case 'z':
                P1_y = P1_y < max_y - 4 ? P1_y + 1 : P1_y;
                break;
            case 'y':
                exit_flag = 1;
                break;
        }
        if (exit_flag == 1) {
            break;
        }
        //----------
        if (ball_y + b_vy == 0 || ball_y + b_vy == max_y - 1)
            b_vy = -b_vy;
        else
            ball_y += b_vy;  // Отбив от верхней и нижней границы

        if (ball_x + b_vx == max_x - 1) {
            if (ball_y + b_vy != P2_y && ball_y + b_vy != P2_y + 1 && ball_y + b_vy != P2_y + 2) {
                score_1++;
                ball_x += b_vx;
            } else {
                b_vx = -b_vx;
            }
        } else
            ball_x += b_vx;

        if (ball_x + b_vx == 0) {
            if (ball_y + b_vy != P1_y && ball_y + b_vy != P1_y + 1 && ball_y + b_vy != P1_y + 2) {
                score_2++;
                ball_x += b_vx;
            } else {
                b_vx = -b_vx;
            }
        } else
            ball_x += b_vx;

        if (ball_x >= max_x || ball_x <= 0) {
            ball_x = max_x / 2;
            ball_y = max_y / 2;
        }
        //----------

        if (score_1 == 21 || score_2 == 21) {
            exit_flag = 0;
            win_flag = 0;
        }

        for (int y = 0; y < max_y; y++) {
            for (int x = 0; x < max_x; x++) {
                if (y == 0 || y == max_y - 1)
                    printf("*");
                else if (ball_x == x && ball_y == y)
                    printf("@");
                else if ((y == P1_y || y == P1_y + 1 || y == P1_y + 2) && x == P1_x)
                    printf("I");
                else if ((y == P2_y || y == P2_y + 1 || y == P2_y + 2) && x == P2_x)
                    printf("I");
                else
                    printf(" ");
            }
            printf("\n");
        }
        printf("P1 score: %d      P2 score: %d", score_1, score_2);
        if (getchar() == ' ') break;
        printf("\e[%dA", max_y);
        //----------
    }
    if (score_1 == 21) {
        printf("win_1");

    } else if (score_2 == 21) {
        printf("win_2yyy");
    }

    return 0;
}
