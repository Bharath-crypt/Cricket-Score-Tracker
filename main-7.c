#include <stdio.h>
#include <stdlib.h>

struct batsman {
    char name[25];
    int runs, score, balls, toruns, tobal, ones, twos, threes, fours, sixes;
    int max_six, max_run, max_four;
    float str;
} pl1[100], pl3;

struct bowler {
    char name[25];
    int runsgv, wkttkn, overs;
    int max_w;
    float econ;
} pl2[100], pl4;

int main() {
    int plno, choice;
    int i, n, m;

    printf("Enter the number of batsmen:\n");
    scanf("%d", &m);
    
    for (i = 0; i < m; i++) {
        printf("Enter name of batsman %d:\n", i + 1);
        scanf("%s", pl1[i].name);
        printf("Enter the number of ones, twos, threes, fours, sixes scored by player %d:\n", i + 1);
        scanf("%d %d %d %d %d", &pl1[i].ones, &pl1[i].twos, &pl1[i].threes, &pl1[i].fours, &pl1[i].sixes);
        printf("Enter the balls played by player %d:\n", i + 1);
        scanf("%d", &pl1[i].balls);
    }

    printf("Enter the number of bowlers:\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter name of bowler %d:\n", i + 1);
        scanf("%s", pl2[i].name);
        printf("Enter the runs given, overs bowled, and wickets taken by bowler %d:\n", i + 1);
        scanf("%d %d %d", &pl2[i].runsgv, &pl2[i].overs, &pl2[i].wkttkn);
    }

    printf("Thank you! All details are recorded.\n");

    do {
        printf("Enter the choice:\n 1) Batsman detail\n 2) Bowler detail\n 3) Match summary\n 4) Records\n 5) Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the batsman number to see his details\n");
                scanf("%d", &plno);
                plno--;
                pl1[plno].runs = (1 * pl1[plno].ones) + (2 * pl1[plno].twos) + 
                                 (3 * pl1[plno].threes) + (4 * pl1[plno].fours) + 
                                 (6 * pl1[plno].sixes);
                pl1[plno].str = (pl1[plno].runs * 100.0) / pl1[plno].balls;

                printf("\nBatsman Details:\n");
                printf("---------------------------------------------------------\n");
                printf("Name          Runs    Balls   Fours   Sixes   SR\n");
                printf("---------------------------------------------------------\n");
                printf("%-12s %-7d %-7d %-7d %-7d %.2f\n\n",
                       pl1[plno].name, pl1[plno].runs, pl1[plno].balls, 
                       pl1[plno].fours, pl1[plno].sixes, pl1[plno].str);
                break;

            case 2:
                printf("Enter the bowler number to see his details\n");
                scanf("%d", &plno);
                plno--;
                pl2[plno].econ = (float) pl2[plno].runsgv / pl2[plno].overs;

                printf("\nBowler Details:\n");
                printf("---------------------------------------------------------\n");
                printf("Name          Overs    Runs    Wickets   Economy\n");
                printf("---------------------------------------------------------\n");
                printf("%-12s %-8d %-7d %-9d %.2f\n\n",
                       pl2[plno].name, pl2[plno].overs, pl2[plno].runsgv, 
                       pl2[plno].wkttkn, pl2[plno].econ);
                break;

            case 3:
                printf("\nMatch Summary:\n");
                printf("---------------------------------------------------------\n");
                printf("Batsman       Runs    Balls   Fours   Sixes   SR\n");
                printf("---------------------------------------------------------\n");
                
                pl3.toruns = 0;
                for (i = 0; i < m; i++) {
                    pl1[i].runs = (1 * pl1[i].ones) + (2 * pl1[i].twos) + 
                                  (3 * pl1[i].threes) + (4 * pl1[i].fours) + 
                                  (6 * pl1[i].sixes);
                    pl3.toruns += pl1[i].runs;
                    pl1[i].str = (pl1[i].runs * 100.0) / pl1[i].balls;

                    printf("%-12s %-7d %-7d %-7d %-7d %.2f\n",
                           pl1[i].name, pl1[i].runs, pl1[i].balls, 
                           pl1[i].fours, pl1[i].sixes, pl1[i].str);
                }
                printf("TOTAL RUNS: %d\n\n", pl3.toruns);

                printf("---------------------------------------------------------\n");
                printf("Bowler        Overs    Runs    Wickets   Economy\n");
                printf("---------------------------------------------------------\n");

                for (i = 0; i < n; i++) {
                    pl2[i].econ = (float) pl2[i].runsgv / pl2[i].overs;
                    printf("%-12s %-8d %-7d %-9d %.2f\n",
                           pl2[i].name, pl2[i].overs, pl2[i].runsgv, 
                           pl2[i].wkttkn, pl2[i].econ);
                }
                break;

            case 4:
                pl3.max_run = 0;
                pl4.max_w = 0;
                pl3.max_four = 0;
                pl3.max_six = 0;

                for (i = 0; i < m; i++) {
                    pl1[i].runs = (1 * pl1[i].ones) + (2 * pl1[i].twos) + 
                                  (3 * pl1[i].threes) + (4 * pl1[i].fours) + 
                                  (6 * pl1[i].sixes);
                    if (pl3.max_run < pl1[i].runs) pl3.max_run = pl1[i].runs;
                    if (pl3.max_six < pl1[i].sixes) pl3.max_six = pl1[i].sixes;
                    if (pl3.max_four < pl1[i].fours) pl3.max_four = pl1[i].fours;
                }

                for (i = 0; i < n; i++) {
                    if (pl4.max_w < pl2[i].wkttkn) pl4.max_w = pl2[i].wkttkn;
                }

                printf("\nRecord Statistics:\n");
                printf("Highest runs scored by a batsman: %d\n", pl3.max_run);
                printf("Maximum fours scored: %d\n", pl3.max_four);
                printf("Maximum sixes scored: %d\n", pl3.max_six);
                printf("Maximum wickets taken by a bowler: %d\n", pl4.max_w);
                break;

            case 5:
                exit(0);

            default:
                printf("Enter a valid choice\n");
        }
    } while (choice != 5);

    return 0;
}
