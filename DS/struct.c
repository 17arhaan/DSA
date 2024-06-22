#include<stdio.h>
#include<stdlib.h>

struct isSolar{
    char planet_name[50];
    double distance_frm_sun;
    int no_of_moons;
};
int main() {
    struct isSolar earth = {"Earth", 93000000, 1};
    struct isSolar venus = {"Venus", 67000000, 0};

    printf("%s: Distance from the sun - %.0f miles, Moons - %d\n", 
    earth.planet_name,earth.distance_frm_sun, earth.no_of_moons);
    printf("%s: Distance from the sun - %.0f miles, Moons - %d\n", 
    venus.planet_name, venus.distance_frm_sun, venus.no_of_moons);

    return 0;
}
