#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pos;
    double time;
} Car;

int cmp(const void* a, const void* b) {
    Car* ca = (Car*)a;
    Car* cb = (Car*)b;
    return cb->pos - ca->pos; // Sort by position descending
}

int carFleet(int target, int* position, int n, int* speed) {
    if (n == 0) return 0;
    
    Car* cars = (Car*)malloc(n * sizeof(Car));
    
    for (int i = 0; i < n; i++) {
        cars[i].pos = position[i];
        cars[i].time = (double)(target - position[i]) / speed[i];
    }
    
    qsort(cars, n, sizeof(Car), cmp);
    
    int fleets = 1;
    double currentTime = cars[0].time;
    
    for (int i = 1; i < n; i++) {
        if (cars[i].time > currentTime) {
            fleets++;
            currentTime = cars[i].time;
        }
    }
    
    free(cars);
    return fleets;
}

int main() {
    int target, n;
    
    printf("Enter target distance: ");
    scanf("%d", &target);
    
    printf("Enter number of cars: ");
    scanf("%d", &n);
    
    int* position = (int*)malloc(n * sizeof(int));
    int* speed = (int*)malloc(n * sizeof(int));
    
    printf("Enter positions: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &position[i]);
    }
    
    printf("Enter speeds: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &speed[i]);
    }
    
    int result = carFleet(target, position, n, speed);
    printf("Number of car fleets: %d\n", result);
    
    free(position);
    free(speed);
    return 0;
}