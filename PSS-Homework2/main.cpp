#include <iostream>
#include "users.h"
#include "rooms.h"
using namespace std;

/* University access system
 *
 * @author Kirilin Anton
 * @version 1.1
 * @since 22.03.2021
 */

int main() {
    cout <<"This is an example of system work, it's show how objects are interact with each other."<<endl;
    cout <<"For more information check Readme file";
//creating users
    Director director1("Kirill","Semenihin",44);
    Admin admin1 ("Aleksey","Sirnikov",30000);
    Admin admin2 ("Dmitrii","Bulgakov",30200);
    Professor professor1("Eugene","Zuev",true,PSS);
    Professor professor2("Alexander","Frolov",false,DM);
    Professor professor3("Emanuel","Mazzara",true,TCS);
    Professor professor4("Ivan","Konukhov",false,Calculus);
    Employee employee1("Oleg","Bulichev",AGLA);
    Employee employee2("Shokhista","Ergasheva",PSS);
    Employee employee3("Bader","Rasheed",DSA);
    Employee employee4("Rusilia","Smirnova",DM);
    Employee employee5("Mansur","Khazeev",PSS);
    Employee employee6("Timur"," Fayzrakhmanov",Philosophy);
    Employee employee7("Zamira","Kholmatova",Calculus);
    Employee employee8("Mike","Mirzayanov",PSS);
    Student student1("Sergey","Pasynkov",4.6);
    Student student2("Anton","Kirilin",4.6);
    Student student3("Fedor","Krasilnikov",4.8);
    Student student4("Ruslan","Khakimov",4.9);
    Student student5("Pavel","Roganin",5);
    Student student6("Andrey","Kuzmickiy",4.7);
    Student student7("Artem","Voronov",5);
    Student student8("Roman","Voronov",5);
    Student student9("Lev","Kozlov",4);
    Student student10("Vagif","Khalilov",4.6);
    Student student11("Khabib","Khays",4.8);
    Student student12("Anatoliy","Baskakov",4);
    Student student13("Vladimir","Ivanutenko",3);
    Student student14("Mikhail","Panimash",4);
    Student student15("Tasha","Sakovets",4.3);
    Student student16("Ruslan","Gilvanov",5);
    Guest guest("Vladimir","prigogin",3000000);//just guest at university
//now creating rooms
    ClassRoom classRoom1(313,30);
    ClassRoom classRoom2(320,20);
    LectureRoom lectureRoom1(208,120);
    LectureRoom lectureRoom2(106,120);
    ConferenceRoom conferenceRoom1(201,10);
    ConferenceRoom conferenceRoom2(212,30);
    ConferenceRoom conferenceRoom3 (109,15);
    Cabinet cabinet1(405,professor1);
    Cabinet cabinet2 (412,professor2);
    Cabinet cabinet3 (410,professor3);
    Cabinet cabinet4 (407,professor4);
    DirectorCabinet directorCabinet1(501);
// now let's use our system
    cout<<endl<<endl<<"Cabinets examples"<<endl<<endl;
//Profs try to open cabinets
    cabinet1.tryToOpen(professor1);//okay
    cabinet1.tryToOpen(professor2);// cannot
    cabinet2.tryToOpen(professor2);//can
    cabinet4.tryToOpen(professor2);// cannot
    cabinet3.tryToOpen(student14);// cannot
// now admins will try to open cabinets
    cabinet3.tryToOpen(admin1);// they can
    cabinet2.tryToOpen(admin2);//they can


    cout<<endl<<"Director's cabinet examples"<<endl<<endl;
// Now accessing to directors cabinet
    directorCabinet1.tryToOpen(director1);//can
    directorCabinet1.tryToOpen(admin1);//can
    directorCabinet1.tryToOpen(professor2);//cannot
    directorCabinet1.tryToOpen(student1);//cannot

//now accessing to lecture, conference and class rooms
    cout <<endl<<"lecture,conference and class rooms examples"<<endl<<endl;
    lectureRoom2.tryToOpen(professor2);//can
    lectureRoom2.tryToOpen(employee8);//can
    lectureRoom2.tryToOpen(student12);//can
    classRoom1.tryToOpen(student2);//can
    classRoom1.tryToOpen(professor3);//can
    classRoom1.tryToOpen(employee4);//can
    classRoom1.tryToOpen(director1);//can
    conferenceRoom1.tryToOpen(director1);//can
    conferenceRoom1.tryToOpen(employee2);//cannot
    conferenceRoom1.tryToOpen(student11);//cannot
    conferenceRoom1.tryToOpen(admin2);//cannot

//now guest will try to open them and can open only first two,because they are on the first floor
    cout <<endl<<"Guest try to open"<<endl<<endl;
    lectureRoom2.tryToOpen(guest);
    conferenceRoom3.tryToOpen(guest);
    classRoom1.tryToOpen(guest);
    cabinet2.tryToOpen(guest);
    directorCabinet1.tryToOpen(guest);
// but admins can give access if that guest is important
    guest.changeAccessLevel(admin2,red);//changing of access level
    cout <<endl<<"Guest try to open second time(with new access level)"<<endl<<endl;
    lectureRoom2.tryToOpen(guest);//can
    classRoom1.tryToOpen(guest);//can
    conferenceRoom1.tryToOpen(guest);//can
    cabinet2.tryToOpen(guest);//cannot
    directorCabinet1.tryToOpen(guest);//cannot
// now let's show what admins can change
    cout <<endl<<"Admins' abilities"<<endl<<endl;
    cout<<student2.getName()<<" "<<student2.getLastName()<<" ";
    cout<<student2.getAverageGrade()<<" "<<student2.getId()<<endl;//print information about student
//student try to open cabinets
    directorCabinet1.tryToOpen(student2);//cannot
    cabinet1.tryToOpen(student2);//cannot
    conferenceRoom1.tryToOpen(student2);//cannot
//now student tries to increase his grade
    student2.setAverageGrade(student2,5);//cannot
//admin change information
    student2.setAverageGrade(admin1,5);
    student2.setName(admin1,"Mels");
    student2.changeAccessLevel(admin1,red);
    student2.setPersonId(admin1,0);
    cout <<endl<<"changed student's information"<<endl<<endl;
    cout<<student2.getName()<<" "<<student2.getLastName()<<" ";
    cout<<student2.getAverageGrade()<<" "<<student2.getId()<<endl;//print information about student
//student try to open cabinets with new level of access
    directorCabinet1.tryToOpen(student2);//cannot
    cabinet1.tryToOpen(student2);//cannot
    conferenceRoom1.tryToOpen(student2);//now can
// now let's show some special information, than change it
    cout <<endl<<"special information examples"<<endl<<endl;
    cout <<"director's age "<<director1.getAge()<<endl;
    director1.setAge(director1,1);
    director1.setAge(admin1,45);
    cout <<"new director's age "<<director1.getAge()<<endl;

// new examples (except changing guest one) with fixed features and new ones.
//lets start with granting especial access to the room
    cout <<endl<<"granting access to special room for persons"<<endl<<endl;
    cout <<"several persons try to get access to the rooms"<<endl;
    conferenceRoom1.tryToOpen(student10);
    cabinet2.tryToOpen(employee7);
    cabinet3.tryToOpen(student7);
    directorCabinet1.tryToOpen(professor4);
    cout <<endl<<"now admins will provide them special access only for those rooms and they will try to open"<<endl;
conferenceRoom1.addAccessiblePerson(student10,admin2);
cabinet2.addAccessiblePerson(employee1,admin1);
cabinet3.addAccessiblePerson(student7,admin2);
directorCabinet1.addAccessiblePerson(professor4,admin1);
//now they open them
conferenceRoom1.tryToOpen(student10);
cabinet2.tryToOpen(employee1);
cabinet3.tryToOpen(student7);
directorCabinet1.tryToOpen(professor4);
cout <<endl<<" but they still cannot open other rooms of the same level access requirements"<<endl;
cabinet3.tryToOpen(employee1);
conferenceRoom3.tryToOpen(student10);
cabinet1.tryToOpen(student7);
cout <<endl<<"also admins can remove that access"<<endl;
cabinet2.removeAccessiblePerson(employee1,admin2);//notice that one admin added access another removed
conferenceRoom1.removeAccessiblePerson(student10,admin1);
directorCabinet1.removeAccessiblePerson(professor4,admin2);
cabinet3.removeAccessiblePerson(student7,admin2);
conferenceRoom1.tryToOpen(student10);
cabinet2.tryToOpen(employee7);
cabinet3.tryToOpen(student7);
directorCabinet1.tryToOpen(professor4);
// example of emergency situation
cout <<endl<<"Example of emergency situation"<<endl<<endl;
cout <<"usual try to open several rooms by users"<<endl;

conferenceRoom1.tryToOpen(student7);
cabinet2.tryToOpen(employee7);
directorCabinet1.tryToOpen(professor4);
cabinet1.tryToOpen(professor2);
cout <<endl<<"now not admins will try to call emergency protocol"<<endl;
Room::emergencySituationProtocol(student7);
Room::emergencySituationProtocol(director1);
cout <<endl<<"admins call it and users will try to open rooms"<<endl;
Room::emergencySituationProtocol(admin2);
conferenceRoom1.tryToOpen(student7);
cabinet2.tryToOpen(employee7);
directorCabinet1.tryToOpen(professor4);
cabinet1.tryToOpen(professor2);
cout <<endl<<"but it was some stud at the dorm< who tried fry the pasta-";
cout <<" admins disable emergency protocol"<<endl;
Room::emergencySituationProtocol(admin1);
conferenceRoom1.tryToOpen(student7);
cabinet2.tryToOpen(employee7);
directorCabinet1.tryToOpen(professor4);
cabinet1.tryToOpen(professor2);
    return 0;
}
