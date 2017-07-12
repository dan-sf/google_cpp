#include <iostream>
#include <math.h>
using namespace std;

void StartUp() {
    cout << "Welcome to Artillery." << endl;
    cout << "You are in the middle of a war and being charged by thousands of enemies." << endl;
    cout << "You have one cannon, which you can shoot at any angle." << endl;
    cout << "You only have 10 cannonballs for this target.." << endl;
    cout << "Let's begin..." << endl;
    cout << endl;
}

float ToRad(float angle) {
    float output = (angle / 360.0) * 2*M_PI;
    return output;
}

int Fire() {
    int over;
    float in_angle = 0;

    srand(time(NULL));
    int enemy_dist = rand() % 1000 + 100;
    cout << "The enemy is " << enemy_dist << " feet away!!!" << endl;

    float velocity = 200.0; // initial velocity of 200 ft/sec
    float gravity = 32.2; // gravity for distance calculation

    int i;
    for (i = 0; i < 10; i++) {
        cout << "What angle? "; cin >> in_angle;

        float time_in_air = (2.0 * velocity * sin(ToRad(in_angle))) / gravity;
        float distance = round((velocity * cos(ToRad(in_angle))) * time_in_air);

        over = (int)round(distance) - enemy_dist;
        if (over >= -5 && over <= 5) {
            cout << "You hit him!" << endl;
            printf("It took you %d shots.\n", i + 1);
            break;
        } else {
            if (over > 0)
                printf("You over shot by %d\n", over);
            else
                printf("You under shot by %d\n", abs(over));
        }
    }

    if (i >= 10)
        return 0;
    else
        return 1;
}

int main() {
    StartUp();
    int killed = 0;
    string done;

    do {
        killed += Fire();
        cout << "I see another one, care to shoot again? (Y/N) " << endl;
        cin >> done;
    } while (done != "N" && done != "n");
    cout << "You killed " << killed << " enemies." << endl;
}

