#include <iostream>
#include <functional>
#include <cmath>
#include <ctime>
#include <cstring>
#include "UniqueVector.h"
#include "Room.h"
#include "RoomType.h"
#include "Customer.h"
#include "Time.h"
#include "Reservation.h"
#include "Hotel.h"


int main()
{
    Hotel* hotel = new Hotel(3, 3);
    char name[] = "Test name";
    char tel[] = "0864559235";
    char add[] = "test Address";

    Time* s = new Time(2023, 5, 4, 12, 56, 20);
    Time* e = new Time(2023, 5, 7, 12, 56, 20);
    Room* room1 = new Room(103, RoomType::Single, add);   
    Room* room2 = new Room(104, RoomType::Double, add);   
    Customer* customer1 = new Customer(name, tel, add);   
    Reservation* reservation1 = new Reservation(1, *customer1, *room1,*s,*e);   
    Reservation* reservation2 = new Reservation(2, *customer1, *room2,*s,*e);   
    Reservation* reservation3 = new Reservation(4, *customer1, *room2,*s,*e);   
    hotel->addReservation(*reservation1);
    std::cout << *hotel;

    hotel->removeReservationWithNumber(1);
    hotel->addReservation(*reservation1);
    hotel->addReservation(*reservation2);
    hotel->addReservation(*reservation3);
    std::cout << *hotel;
    std::cout<<"Profit from date " << *e << ": " << hotel->profitFromReservationsEndingOn(*e) << std::endl;
    std::cout << "Reservations made by " << name << std::endl;
    hotel->ReservatinsMadeByClient(name);
    hotel->removeReservationWithNumber(1);
    std::cout << *hotel;
    
    hotel->addRoom(*room2);

    std::cout << std::boolalpha << hotel->isRoomFreeBetween(*s,*e,104) << std::endl;
    hotel->freeRoomsBetween(*s, *e);


    delete hotel;
    delete s,e;
    delete room1, room2;
    delete customer1;
    delete reservation1, reservation2, reservation3;


}

