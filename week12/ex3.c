#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "stdio.h"
#include "string.h"
#include "linux/input.h"
#include "linux/input-event-codes.h"

#define SIZE 10

int checkShortcut(struct input_event taped[], int shortcuts[], int n){
    int existance = 1;
    for (int i = 0; i < n; i++)
    {
        int existance2 = 0;
        for (int n = 0; n < SIZE; n++)
        {
            if (taped[n].code == shortcuts[i]) existance2 = 1;
        }

        if (!existance2) existance = 0; 
    }

    if (n == 0) return 0;
    return existance;
}

void main(){

    int event = open("/dev/input/by-path/pci-0000:00:14.0-usb-0:3:1.0-event-kbd",O_RDONLY);
    if(event==-1){
        printf("Can not open file");
        return 1;
    }
    struct input_event input_event;
    ssize_t n;
    struct input_event tap[SIZE];
    struct input_event checkShrt;
    checkShrt.type = 0;
    checkShrt.code = 0;
    checkShrt.value = 0;
    checkShrt.time.tv_sec = 0;
    checkShrt.time.tv_usec = 0;

    for (int i = 0; i < SIZE; i++)
    {
        tap[i] = checkShrt;
    }

    printf("\nA + M\n");

    while (1)
    {
        n = read(event, &input_event, sizeof(input_event));

        if (input_event.type == EV_KEY)
        {
            if (input_event.value == 0)
            {
                for (int i = 0; i < SIZE; i++)
                {
                    if (tap[i].code == input_event.code)
                    {
                        tap[i] = checkShrt;
                        break;
                    }
                }
            }

            if (input_event.value == 1)
            {
                for (int i = 0; i < SIZE; i++)
                {
                    if (tap[i].code == checkShrt.code && tap[i].type == checkShrt.type && tap[i].value == checkShrt.value)
                    {
                        tap[i] = input_event;
                        break;
                    }
                }
            }
        }
        int shortcut1[] = {KEY_P, KEY_E};
        int shortcut2[] = {KEY_C, KEY_A, KEY_P};
        int shortcut3[] = {KEY_A, KEY_M};
        if (checkShortcut(tap, shortcut1, 2)) printf("I passed the Exam!\n");
        if (checkShortcut(tap, shortcut2, 3)) printf("Get some cappuccino!\n");
        if (checkShortcut(tap, shortcut3, 2)) printf("I am Aisen\n");
    }
}

