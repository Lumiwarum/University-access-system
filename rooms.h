#ifndef BOJESPASI_ROOMS_H
#define BOJESPASI_ROOMS_H
#include "enums.h"
#include "users.h"
using namespace std;

class room {
public:
    int getRoomNumber(){
        return roomNumber;
    }
    int getNumberOfSeats(){
        return seatCapacity;
    }
    rooms getTypeOfRoom(){
        return typeOfRoom;
    }
    room(int Number,int seats){
        roomNumber=Number;
        seatCapacity=seats;
    }
protected:
    int seatCapacity;
    int roomNumber;
    rooms typeOfRoom;
};

class ClassRoom: public room{
public:
    void tryToOpen(person opener){
        if ((opener.getAccessLevel()>=green)||(opener.getPersonType()==admin)){
            cout<<opener.getName()<<" "<<opener.getLastName();
            cout<<" successfully open "<<roomNumber<<" class room"<<endl;
        } else {
            cout<<opener.getName()<<" "<<opener.getLastName();
            cout<<" unsuccessfully cannot open "<<roomNumber<<" class room"<<endl;
        }
    }
    ClassRoom(int Number, int seats): room(Number,seats){
        roomNumber=Number;
        seatCapacity=seats;
        typeOfRoom = classRoom;
    }
};
class LectureRoom: public room{
public:
    void tryToOpen(person opener){
        if ((opener.getAccessLevel()>=green)||(opener.getPersonType()==admin)){
            cout<<opener.getName()<<" "<<opener.getLastName();
            cout <<" successfully open "<<roomNumber<<" lecture room"<<endl;
        } else {
            cout<<opener.getName()<<" "<<opener.getLastName();
            cout <<" unsuccessfully cannot open "<<roomNumber<<" lecture room"<<endl;
        }
    }
    LectureRoom(int Number, int seats): room(Number,seats){
        roomNumber=Number;
        seatCapacity=seats;
        typeOfRoom = lectureRoom;
    }
};

class ConferenceRoom: public room {
public:
    void tryToOpen(person opener){
        if ((opener.getAccessLevel()>=yellow)||(opener.getPersonType()==admin)){
            cout<<opener.getName()<<" "<<opener.getLastName()<<" successfully open "<<roomNumber<<" conference room"<<endl;
        } else {
            cout<<opener.getName()<<" "<<opener.getLastName()<<" unsuccessfully cannot open "<<roomNumber<<" conference room"<<endl;
        }
    }
    ConferenceRoom(int Number, int seats): room(Number,seats){
        roomNumber=Number;
        seatCapacity=seats;
        typeOfRoom = conferenceRoom;
    }
};
class Cabinet: public room{
public:
    void changeOwner(person isAdmin,person newOwner){
        if (isAdmin.getPersonType()==admin){
            cout <<isAdmin.getName()<<" "<<isAdmin.getLastName();
            cout <<" set"<<newOwner.getName()<<" "<<newOwner.getLastName()<<"as owner of"<<roomNumber<<" cabinet"<<endl;
            ownerId=newOwner.getId();
        }
    }
    void tryToOpen(person opener){
        if (ownerId==opener.getId()||(opener.getPersonType()==admin)){
            cout<<opener.getName()<<" "<<opener.getLastName()<<" successfully open "<<roomNumber<<" cabinet"<<endl;
        } else {
            cout<<opener.getName()<<" "<<opener.getLastName()<<" unsuccessfully cannot open "<<roomNumber<<" cabinet"<<endl;
        }
    }
    Cabinet(int Number,person owner): room(Number,5){
        roomNumber=Number;
        typeOfRoom = cabinet;
        ownerId=owner.getId();
    }


protected:
    int ownerId;
};
class DirectorCabinet: public room{
public:
    void tryToOpen(person opener){
        if (((opener.getPersonType()==director)&&(opener.getAccessLevel()>=red))||(opener.getPersonType()==admin)){
            cout<<opener.getName()<<" "<<opener.getLastName();
            cout <<" successfully open "<<roomNumber<<" director's cabinet"<<endl;
        } else {
            cout<<opener.getName()<<" "<<opener.getLastName();
            cout<<" unsuccessfully cannot open "<<roomNumber<<" director's cabinet"<<endl;
        }
    }
    DirectorCabinet(int Number): room(Number,7){
        roomNumber=Number;
        typeOfRoom = directorCabinet;
    }
};
#endif //BOJESPASI_ROOMS_H
