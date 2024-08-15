#include <stdlib.h>
#include <stdio.h>

int main() {
    int consec_evens, consec_odds, this_rand, consecs, i;
    const char *even = "even";
    const char *odd = "odd";
    const char *message;
    for (i = 0; i < 100; i++) {
        this_rand = rand() % 2;
        if (this_rand == 0) {
            consec_evens++;
            consec_odds = 0;
            consecs = consec_evens;
            message = even;
        } else {
            consec_odds++;
            consec_evens = 0;
            consecs = consec_odds;
            message = odd;
        }
        printf("result: %d\nthere have been %d consecutive %s results\n", this_rand, consecs, message);
    }
    return 0;
}
