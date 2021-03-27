#ifndef BOJESPASI_USERS_H
#define BOJESPASI_USERS_H
#include "enums.h"
using namespace std;


class person {
public:
    void setPersonId(person isAdmin,int newId){
        if (isAdmin.getPersonType()== admin){
            cout <<isAdmin.getName()<<" "<<isAdmin.getLastName()<<" has changed ";
            cout <<this->getName()<<" "<<this->getLastName()<<"'s Id"<<endl;
            Id=newId;
        } else{
            cout <<isAdmin.getName()<<" "<<isAdmin.getLastName();
            cout <<"is not admin and cannot do this operation"<<endl;
        }
    }
    void setPersonType(person isAdmin,persons newType){
        if (isAdmin.getPersonType()== admin){
            cout <<isAdmin.getName()<<" "<<isAdmin.getLastName()<<" has changed ";
            cout <<this->getName()<<" "<<this->getLastName()<<"'s person type"<<endl;
            personType=newType;
        }else{
            cout <<isAdmin.getName()<<" "<<isAdmin.getLastName();
            cout <<" is not admin and cannot do this operation"<<endl;
        }
    }
    void setLastName(person isAdmin,string newName){
        if (isAdmin.getPersonType()== admin){
            cout <<isAdmin.getName()<<" "<<isAdmin.getLastName()<<" has changed ";
            cout <<this->getName()<<" "<<this->getLastName()<<"'s last name"<<endl;
            lastName=newName;
        }else{
            cout <<isAdmin.getName()<<" "<<isAdmin.getLastName();
            cout <<" is not admin and cannot do this operation"<<endl;
        }
    }
    void setName(person isAdmin,string newName){
        if (isAdmin.getPersonType()== admin){
            cout <<isAdmin.getName()<<" "<<isAdmin.getLastName()<<" has changed ";
            cout <<this->getName()<<" "<<this->getLastName()<<"'s name"<<endl;
            firstName=newName;
        }else{
            cout <<isAdmin.getName()<<" "<<isAdmin.getLastName();
            cout <<" is not admin and cannot do this operation"<<endl;
        }
    }
    void changeAccessLevel(person isAdmin,levelAccess newLevel){
        if (isAdmin.getPersonType()== admin){
            levelOfAccess=newLevel;
            cout <<isAdmin.getName()<<" "<<isAdmin.getLastName()<<" has changed ";
            cout <<this->getName()<<" "<<this->getLastName()<<"'s level of access"<<endl;
        }else{
            cout <<isAdmin.getName()<<" "<<isAdmin.getLastName();
            cout <<" is not admin and cannot do this operation"<<endl;
        }
    }
    string  getName(){
        return firstName;
    };
    string  getLastName(){
        return lastName;
    };
    levelAccess getAccessLevel(){
        return levelOfAccess;
    }
    persons getPersonType(){
        return personType;
    }
    int getId(){
        return Id;
    }
    person(string Name,string Surname){
        levelOfAccess=noLevel;
        firstName=Name;
        lastName=Surname;
        Id=newId++;
    }
private:
protected:
    levelAccess levelOfAccess;
    string firstName;
    string lastName;
    persons personType;
    int Id;
    inline static int newId=0;
};

class Guest: public person{
public:
    Guest(string Name,string Surname,int money): person (Name,Surname){
        levelOfAccess=blue;
        personType=guest;
        amountOfMoney=money;
    }

private:
    int amountOfMoney;
};

class Professor: public person{
public:
    void setTeachingSubject(person isAdmin,subject newSubject){
        if (isAdmin.getPersonType()== admin){
            cout <<isAdmin.getName()<<" "<<isAdmin.getLastName()<<" has changed ";
            cout <<this->getName()<<" "<<this->getLastName()<<"'s teaching subject"<<endl;
            teachingSubject=newSubject;
        }else{
            cout <<isAdmin.getName()<<" "<<isAdmin.getLastName();
            cout <<" is not admin and cannot do this operation"<<endl;
        }
    }
    subject getTeachingSubject(){
        return teachingSubject;
    }
    bool getEngineerSkill(){
        return fluentWithTechnique;
    }
Professor(string Name,string Surname,bool engineer,subject teaching) : person(Name,Surname) {
    levelOfAccess=yellow;
    personType=professor;
    fluentWithTechnique=engineer;
    teachingSubject=teaching;
}
private:
    bool fluentWithTechnique= false;
 subject teachingSubject;
};

class Student: public person {
public:
    double getAverageGrade(){
        return averageGrade;
    }
    void setAverageGrade(person isAdmin,double grade){
        if (isAdmin.getPersonType()== admin){
            cout <<isAdmin.getName()<<" "<<isAdmin.getLastName()<<" has changed ";
            cout <<this->getName()<<" "<<this->getLastName()<<"'s study subject"<<endl;
            averageGrade=grade;
        }else{
            cout <<isAdmin.getName()<<" "<<isAdmin.getLastName();
            cout <<" is not admin and cannot do this operation"<<endl;
        }
    }
    Student(string Name,string Surname,double averageGrade): person(Name,Surname){
        levelOfAccess=green;
        personType=student;
        this->averageGrade=averageGrade;
    }

protected:
    double averageGrade;
};

class Employee: public person {
public:
    void setStudySubject(person isAdmin,subject newSubject){
        if (isAdmin.getPersonType()== admin){
            cout <<isAdmin.getName()<<" "<<isAdmin.getLastName()<<" has changed ";
            cout <<this->getName()<<" "<<this->getLastName()<<"'s study subject"<<endl;
            studySubject=newSubject;
        }else{
            cout <<isAdmin.getName()<<" "<<isAdmin.getLastName();
            cout <<" is not admin and cannot do this operation"<<endl;
        }
    }
    subject getStudySubject(){
        return studySubject;
    }
    Employee(string Name,string Surname,subject studying): person(Name,Surname){
        levelOfAccess=yellow;
        personType=employee;
        studySubject=studying;
    }

protected:
subject studySubject;
};

class Director: public person {
public:
    int getAge(){
        return age;
    }
    void setAge(person isAdmin,int age){
        if (isAdmin.getPersonType()== admin){
            cout <<isAdmin.getName()<<" "<<isAdmin.getLastName()<<" has changed ";
            cout <<this->getName()<<" "<<this->getLastName()<<"'s age"<<endl;
            this->age=age;
        }else{
            cout <<isAdmin.getName()<<" "<<isAdmin.getLastName();
            cout <<" is not admin and cannot do this operation"<<endl;
        }
    }
    Director(string Name,string Surname,int age): person(Name,Surname){
        levelOfAccess=red;
        personType=director;
        this->age=age;
    }

protected:
int age;
};

class Admin: public person {
public:
    int getSalary(){
        return salary;
    }
    void setSalary(int money){
        salary=money;
    }
    Admin(string Name,string Surname,int money): person(Name,Surname){
        levelOfAccess=red;
        personType=admin;
        salary=money;
    }

protected:
    int salary;
};
#endif //BOJESPASI_USERS_H
