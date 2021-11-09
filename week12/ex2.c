#include <stdio.h>
#include <linux/input.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    int event = open("/dev/input/by-path/pci-0000:00:14.0-usb-0:3:1.0-event-kbd",O_RDONLY);
    if(event==-1){
        printf("Can not open file");
        return 1;
    }
    struct input_event input_event;
    while(1){
        ssize_t n = read(event, &input_event, sizeof(input_event));
        if(input_event.type!=EV_KEY) continue;
        if (input_event.value	== 0) {
			printf("RELEASED %#x (%d)\n", input_event.code, input_event.code);
		} else if (input_event.value == 1) {
			printf("PRESSED %#x (%d)\n", input_event.code, input_event.code);
		}
    }
}