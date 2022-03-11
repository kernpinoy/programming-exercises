#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

int main()
{
    time_t now = time(NULL);

    char *stringnow = ctime(&now);
    printf("%s", stringnow);

    struct tm *gm_time = gmtime(&now);
    printf("tm_sec: %d\n", gm_time->tm_sec);
    printf("tm_min: %d\n", gm_time->tm_min);
    printf("tm_hour: %d\n", gm_time->tm_hour);
    printf("tm_mday: %d\n", gm_time->tm_mday);
    printf("tm_month: %d\n", gm_time->tm_mon);
    printf("tm_wday: %d\n", gm_time->tm_wday);
    printf("tm_yday: %d\n", gm_time->tm_yday);
    printf("tm_year: %d\n", gm_time->tm_year);
    printf("tm_dst: %d\n", gm_time->tm_isdst);

    printf("\n");
    struct tm *cur_time = localtime(&now);

    printf("tm_sec: %d\n", cur_time->tm_sec);
    printf("tm_min: %d\n", cur_time->tm_min);
    printf("tm_hour: %d\n", cur_time->tm_hour);
    printf("tm_mday: %d\n", cur_time->tm_mday);
    printf("tm_month: %d\n", cur_time->tm_mon);
    printf("tm_wday: %d\n", cur_time->tm_wday);
    printf("tm_yday: %d\n", cur_time->tm_yday);
    printf("tm_year: %d\n", cur_time->tm_year);
    printf("tm_dst: %d\n", cur_time->tm_isdst);

    char *other_string = asctime(cur_time);
    printf("%s", other_string);

    cur_time->tm_min = cur_time->tm_min + 1;
    time_t new_time = mktime(cur_time);

    printf("now: %ld\n", now);
    printf("new: %ld\n", new_time);

    char s[100];

    int strlen = strftime(s, 100, "%B %d, %Y", cur_time);
    printf("%s\n", s);
    printf("%d\n", strlen);

    clock_t start, end;
    start = clock();

    for (int i = 0; i < 100000000; i++)
    {
    }

    end = clock();

    double total = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time: %fs\n", total);
}