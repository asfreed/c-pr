#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;

struct Aeroflot {
    string flightDestinationName;
    int flightNumber;
    string aircraftType;
};

struct Marsh {
    string nameOfTheStartingPointOfTheRoute;
    string nameOfTheDestinationOfTheRoute;
    string routeNumber;
};

void printMarsh(Marsh m) {
    cout << m.nameOfTheStartingPointOfTheRoute << "\t-\t" 
         << m.nameOfTheDestinationOfTheRoute << endl;
}

void sortByRouteNumbers(Marsh * a, int size) {
    for (int i = 0; i < size; i++) {
        int smallestnum = i;
        for (int j = 0; j < size; j++) {
            char first = a[j].routeNumber[0];
            char second = a[smallestnum].routeNumber[0];
            if (first > second) {
                smallestnum = j;
            }
            else if (first == second) {
                char first1 = a[j].routeNumber[1];
                char second1 = a[smallestnum].routeNumber[1];
                if (first1 > second1) {
                    swap(a[j], a[smallestnum]);
                }
            }
            swap(a[i], a[smallestnum]);
        }
    }
}

void printInfoAboutNeededRouteNum(Marsh * a, int size, string routeNumber) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (routeNumber == a[i].routeNumber) {
            printMarsh(a[i]);
            count -= 1;
        }
        else if (count == 6) {
            printf("\n%s\n", "There are no such route numbers");
        }
        else {
            count++;
        }
    }
}

void sortByDestinations(Aeroflot * a, int size) {
    for (int i = 0; i < size; i++) {
        int smallestnum = i;
        for (int j = 0; j < size; j++) {
            char first = a[j].flightDestinationName[0];
            char second = a[smallestnum].flightDestinationName[0];
            if (first > second) {
                smallestnum = j;
            }
            else if (first == second) {
                char first1 = a[j].flightDestinationName[1];
                char second1 = a[smallestnum].flightDestinationName[1];
                if (first1 > second1) {
                    swap(a[j], a[smallestnum]);
                }
            }
            swap(a[i], a[smallestnum]);
        }
    }
}

void printFlight(Aeroflot flight) {
    cout << flight.flightDestinationName << "\t\t" << flight.flightNumber << endl;
}

void printPlacesServedByPlane(Aeroflot * a, int size, string flight) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (flight == a[i].aircraftType) {
            printFlight(a[i]);
            count -= 1;
        }
        else if (count == 6) {
            printf("\n%s\n", "There are no such aircrafts");
        }
        else {
            count++;
        }
    }
}

void aeroflotArrayFilling(Aeroflot * a, int size) {
    for (int i = 0; i < size; i++) {
        printf("\n%s\n", "Enter infotmation of aircraft");
        cout << "Enter flight destination: ";
        cin >> a[i].flightDestinationName;
        cout << "Enter flight number: ";
        cin >> a[i].flightNumber;
        cout << "Enter aircraft type: ";
        cin >> a[i].aircraftType;
        printf("\n");
    }
    sortByDestinations(a, size);
    for (int i = 0; i < size; i++) {
        printFlight(a[i]);
    }
}

void marshArrayFilling(Marsh * a, int size) {
    for (int i = 0; i < size; i++) {
        printf("\n%s\n", "Enter infotmation of marsh");
        cout << "Enter starting point of the route: ";
        cin >> a[i].nameOfTheStartingPointOfTheRoute;
        cout << "Enter the destination of the route: ";
        cin >> a[i].nameOfTheDestinationOfTheRoute;
        cout << "Enter route number: ";
        cin >> a[i].routeNumber;
        printf("\n");
    }
    sortByRouteNumbers(a, size);
    for (int i = 0; i < size; i++) {
        cout << a[i].nameOfTheStartingPointOfTheRoute << "\t" << a[i].nameOfTheDestinationOfTheRoute << "\t" << a[i].routeNumber << endl;
    }
}

int main()
{
    string neededAircraft, neededRoute;
    int const sizeFlights = 7;
    int const sizeMarsh = 8;
    
    Aeroflot * flights = new Aeroflot [sizeFlights];
    aeroflotArrayFilling(flights, sizeFlights);
    printf("\n%s\n", "Enter needed aircraft type: ");
    cin >> neededAircraft;
    printPlacesServedByPlane(flights, sizeFlights, neededAircraft);
    
    Marsh * marshes = new Marsh [sizeMarsh];
    marshArrayFilling(marshes, sizeMarsh);
    printf("\n%s\n", "Enter needed route number: ");
    cin >> neededRoute;
    printInfoAboutNeededRouteNum(marshes, sizeMarsh, neededRoute);
    
    delete [] flights;
    delete [] marshes;
    return 0;
}
