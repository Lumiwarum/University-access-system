#ifndef BOJESPASI_ROOMS_H
#define BOJESPASI_ROOMS_H
#include "enums.h"
#include "users.h"
#include <vector>
using namespace std;

class Room {
public:
    int getRoomFloor(){
        return floor;
    }
    int getRoomNumber(){
        return roomNumber;
    }
    int getNumberOfSeats(){
        return seatCapacity;
    }
    rooms getTypeOfRoom(){
        return typeOfRoom;
    }
    Room(int Number,int seats){
        roomNumber=Number;
        seatCapacity=seats;
        this->floor=Number/100;
    }
    void addAccessiblePerson(person personAdd,person isAdmin){
        if(isAdmin.getPersonType()==admin){
            accessibleIds.push_back(personAdd.getId());
        } else{
            cout <<isAdmin.getName()<<" "<<isAdmin.getLastName()<<" cannot add access for room ";
            cout <<roomNumber<<" to user with id "<<personAdd.getId()<<endl;
        }

    }
    void removeAccessiblePerson(person personAdd,person isAdmin){
        if(isAdmin.getPersonType()==admin){
            int pos=findAccessiblePerson(personAdd.getId());
            if (pos>-1){
                accessibleIds.erase(accessibleIds.begin()+pos);
            } else {
                cout <<"there is no such user"<<endl;
            }
        } else{
            cout <<isAdmin.getName()<<" "<<isAdmin.getLastName()<<" cannot remove access for room ";
            cout <<roomNumber<<" to user with id "<<personAdd.getId()<<endl;
        }

    }
    static void emergencySituationProtocol(person Admin){
        if (Admin.getPersonType()==admin){
            if (!emergencySituation){
            emergencySituation= true;
            cout <<"Attention! Emergency situation, please leave the building immediately using";
            cout <<" emergency exists!"<<endl<<endl;
            } else
            {
                emergencySituation= false;
                cout <<"Emergency situation ended, please return to your workplaces"<<endl;
            }

        } else {
            cout <<Admin.getName()<<" "<<Admin.getLastName()<<" cannot call emergency protocol"<<endl;
        }
    }
protected:
    int findAccessiblePerson(int idToFind){
        for (int i=0;i<accessibleIds.size();i++){
            if (idToFind==accessibleIds.at(i)){
                return i;}
        }

        return -1;
    }
    vector<int> accessibleIds;
    int seatCapacity;
    int roomNumber;
    int floor;
    rooms typeOfRoom;
    static inline bool emergencySituation = false;
};

class ClassRoom: public Room{
public:
    void tryToOpen(person opener){
        if ((opener.getAccessLevel()>=green)||(opener.getPersonType()==admin)||(findAccessiblePerson(opener.getId())>-1)){
            cout<<opener.getName()<<" "<<opener.getLastName();
            cout<<" successfully open "<<roomNumber<<" class room"<<endl;
        } else {
            if (emergencySituation){
                cout<<opener.getName()<<" "<<opener.getLastName();
                cout<<" successfully open "<<roomNumber<<" class room because of emergency situation"<<endl;
            } else {

                cout << opener.getName() << " " << opener.getLastName();
                cout << " unsuccessfully cannot open " << roomNumber << " class room" << endl;
            }
        }
    }
    ClassRoom(int Number, int seats): Room(Number,seats){
        roomNumber=Number;
        seatCapacity=seats;
        typeOfRoom = classRoom;
    }
};
class LectureRoom: public Room{
public:
    void tryToOpen(person opener){
        if ((opener.getAccessLevel()>=green)||(opener.getPersonType()==admin)||(findAccessiblePerson(opener.getId())>-1)){
            cout<<opener.getName()<<" "<<opener.getLastName();
            cout <<" successfully open "<<roomNumber<<" lecture room"<<endl;
        } else {
            if ((opener.getAccessLevel()==blue)&&(floor==1)){
                cout<<opener.getName()<<" "<<opener.getLastName();
                cout<<" successfully open "<<roomNumber<<" lecture room on the first floor as a guest"<<endl;
            } else {
                if (emergencySituation){
                    cout<<opener.getName()<<" "<<opener.getLastName();
                    cout<<" successfully open "<<roomNumber<<" lecture room because of emergency situation"<<endl;
                } else {
                cout << opener.getName() << " " << opener.getLastName();
                cout << " unsuccessfully cannot open " << roomNumber << " lecture room" << endl;
                }
            }
        }
    }
    LectureRoom(int Number, int seats): Room(Number,seats){
        roomNumber=Number;
        seatCapacity=seats;
        typeOfRoom = lectureRoom;
    }
};

class ConferenceRoom: public Room {
public:
    void tryToOpen(person opener){
        if ((opener.getAccessLevel()>=yellow)||(opener.getPersonType()==admin)||(findAccessiblePerson(opener.getId())>-1)){
            cout<<opener.getName()<<" "<<opener.getLastName()<<" successfully open "<<roomNumber<<" conference room"<<endl;
        } else {
            if ((opener.getAccessLevel()==blue)&&(floor==1)){
                cout<<opener.getName()<<" "<<opener.getLastName();
                cout<<" successfully open "<<roomNumber<<" conference room on the first floor as a guest"<<endl;
            } else {
                if (emergencySituation){
                    cout<<opener.getName()<<" "<<opener.getLastName();
                    cout<<" successfully open "<<roomNumber<<" conference room because of emergency situation"<<endl;
                } else {
            cout <<opener.getName()<<" "<<opener.getLastName()<<" unsuccessfully cannot open ";
            cout <<roomNumber<<" conference room"<<endl;
                }
        }
        }
    }
    ConferenceRoom(int Number, int seats): Room(Number,seats){
        roomNumber=Number;
        seatCapacity=seats;
        typeOfRoom = conferenceRoom;
    }
};
class Cabinet: public Room{
public:
    void changeOwner(person isAdmin,person newOwner){
        if (isAdmin.getPersonType()==admin){
            cout <<isAdmin.getName()<<" "<<isAdmin.getLastName();
            cout <<" set"<<newOwner.getName()<<" "<<newOwner.getLastName()<<"as owner of"<<roomNumber<<" cabinet"<<endl;
            ownerId=newOwner.getId();
        }
    }
    void tryToOpen(person opener){
        if (ownerId==opener.getId()||(opener.getPersonType()==admin)||(findAccessiblePerson(opener.getId())>-1)){
            cout<<opener.getName()<<" "<<opener.getLastName()<<" successfully open "<<roomNumber<<" cabinet"<<endl;
        } else {
            if (emergencySituation){
                cout<<opener.getName()<<" "<<opener.getLastName();
                cout<<" successfully open "<<roomNumber<<" cabinet because of emergency situation"<<endl;
            } else {
            cout<<opener.getName()<<" "<<opener.getLastName()<<" unsuccessfully cannot open ";
            cout<<roomNumber<<" cabinet"<<endl;
            }
        }
    }
    Cabinet(int Number,person owner): Room(Number,5){
        roomNumber=Number;
        typeOfRoom = cabinet;
        ownerId=owner.getId();
    }


protected:
    int ownerId;
};
class DirectorCabinet: public Room{
public:
    void tryToOpen(person opener){
        if (((opener.getPersonType()==director)&&(opener.getAccessLevel()>=red))||(opener.getPersonType()==admin)||(findAccessiblePerson(opener.getId())>-1)){
            cout<<opener.getName()<<" "<<opener.getLastName();
            cout <<" successfully open "<<roomNumber<<" director's cabinet"<<endl;
        } else {
            if (emergencySituation){
                cout<<opener.getName()<<" "<<opener.getLastName();
                cout<<" successfully open "<<roomNumber<<" director's cabinet because of emergency situation"<<endl;
            } else {
            cout<<opener.getName()<<" "<<opener.getLastName();
            cout<<" unsuccessfully cannot open "<<roomNumber<<" director's cabinet"<<endl;
            }
        }
    }
    DirectorCabinet(int Number): Room(Number,7){
        roomNumber=Number;
        typeOfRoom = directorCabinet;
    }
};
#endif //BOJESPASI_ROOMS_H
