/**
 * Jon Durrant.
 * Blink LED on Raspberry PICO using Timer strategy
 */

#include "pico/stdlib.h"
#include "pico/types.h"

#define DELAY 500 // in microseconds

uint32_t nextAction = 0;
bool on=true;
const uint LED_PIN = PICO_DEFAULT_LED_PIN;

void setupBlink(){
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
}

bool blinkLED(repeating_timer_t *rt){
	gpio_put(LED_PIN, on);
	on = !on;
	return true;
}

int main() {
	setupBlink();

	struct repeating_timer timer;
	add_repeating_timer_ms(
	    DELAY,
		blinkLED,
		NULL,
		&timer
	);


    while (true) { // Loop forever
        sleep_ms(DELAY*10);
    }

}
