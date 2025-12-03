#include<stdio.h>
#include<stdbool.h>

bool calculateFuel(int fuel, int consumption, int recharge, int solarBonus, int totalPlanets, int planet){
    if(fuel <= 0) return false;
    if(planet > totalPlanets) return true;

    
    fuel = fuel - consumption;
    fuel = fuel + recharge;
    if(planet % 4 == 0) fuel += solarBonus;
    if(fuel < 0) fuel = 0;
    printf("Planet %d: Fuel Remaining = %d\n", planet, fuel);
    return calculateFuel(fuel, consumption, recharge, solarBonus, totalPlanets, planet + 1);

}
int main(){
    int fuel = 1000, consumption = 300, recharge = 100, solarBonus = 150, totalPlanets = 5;

    bool result = calculateFuel(fuel, consumption, recharge, solarBonus,totalPlanets, 1);
    if(result){
        printf("Spacecraft reached sucessfully!");
    }
    else{
        printf("High fuel consumption spacecraft didn't reached to the planet: %d!", totalPlanets);
    }
    return 0;
}