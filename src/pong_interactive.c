#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    int max_x = 80, max_y = 25;
    int ball_x = max_x / 2, ball_y = max_y / 2;
    int P1_x = 1, P1_y = max_y / 2;
    int P2_x = max_x - 2, P2_y = max_y / 2;
    int b_vx = 1, b_vy = 1;
    int exit_flag = 0, win_flag = 0;
    int score_1 = 0, score_2 = 0;

    initscr();              // Инициализация ncurses
    noecho();               // Не отображать вводимые символы
    curs_set(FALSE);        // Скрыть курсор
    keypad(stdscr, TRUE);   // Включить поддержку клавиш
    nodelay(stdscr, TRUE);  // Неблокирующий ввод

    while (win_flag == 0) {
        clear();

        //----------
        mvprintw(ball_y, ball_x, "@");
        //----------
        for (int i = 0; i < 3; ++i) {
            mvprintw(P1_y + i, P1_x, "I");
            mvprintw(P2_y + i, P2_x, "I");
        }
        for (int i = 0; i < max_x; i++) {
            mvprintw(0, i, "-");
            mvprintw(max_y - 1, i, "-");
        }
        mvprintw(max_y + 2, 0,
                 "Player 1 score: %d                                          Player 2 score: %d\n", score_1,
                 score_2);
        //----------
        switch (getch()) {
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
            clear();
            printw("ENDDDD");
            refresh();
            sleep(1);
            break;
        }
        //---------

        //----------
        if (ball_y + b_vy == 0 || ball_y + b_vy == max_y - 1)
            b_vy = -b_vy;
        else
            ball_y += b_vy;  // Отбив от верхней и нижней границы

        if (ball_x + b_vx >= max_x - 1) {
            if (ball_y + b_vy != P2_y && ball_y + b_vy != P2_y + 1 && ball_y + b_vy != P2_y + 2) {
                score_1++;
                ball_x += b_vx;
            } else {
                b_vx = -b_vx;
            }
        } else
            ball_x += b_vx;

        if (ball_x + b_vx <= 0) {
            if (ball_y + b_vy != P1_y && ball_y + b_vy != P1_y + 1 && ball_y + b_vy != P1_y + 2) {
                score_2++;
                ball_x += b_vx;
            } else {
                b_vx = -b_vx;
            }
        } else
            ball_x += b_vx;

        //------
        if (score_1 == 21 || score_2 == 21) {
            exit_flag = 1;
            win_flag = 1;
        }
        //-----

        if (ball_x >= max_x || ball_x <= 0) {
            ball_x = max_x / 2;
            ball_y = max_y / 2;
            b_vx = (rand() % 2) * 2 - 1;
            b_vy = (rand() % 2) * 2 - 1;
            refresh();
            usleep(600000);
        }

        //----------
        refresh();
        usleep(70000);
    }
    if (score_1 == 21) {
        clear();
        printw("win 1");
        refresh();
        sleep(1);
    } else if (score_2 == 21) {
        clear();
        printw("win 2");
        refresh();
        sleep(1);
    }

    endwin();

    return 0;
}
