#include<iostream>
using namespace std;

class DOOR
{
    private:
    bool vStatus = false;
    bool vLockOrUnlock = true;
    string vKey;
    public:
        DOOR(string);
        string OPEN(string);
        string CLOSE();
        string UNLOCKED(string);
        string LOCK(string);
        bool ISOPEN();
        bool ISCLOSE();
        bool ISLOCK();
        bool ISUNLOCK();
        string OpenAndUnlocked(DOOR, string);
        string OpenAndLocked(DOOR, string);
        string ClosedAndUnlocked(DOOR, string);
        string ClosedAndLocked(DOOR, string);
};

DOOR:: DOOR(string key1)
{
    vKey = key1;
}
bool DOOR::ISOPEN(){
    return vStatus;
}
bool DOOR::ISCLOSE(){
    return !vStatus;
}
bool DOOR::ISLOCK(){
    return !vLockOrUnlock;
}
bool DOOR::ISUNLOCK(){
    return vLockOrUnlock;
}

string DOOR::OPEN(string keyOpen){
    if (vStatus)
    {
        cerr << "La puerta ya esta abierta.";
        return "La puerta ya esta abierta.";
    }
    else if ((vStatus == false)&&(vKey== keyOpen))
    {
        vStatus = true;
        return "La puerta a sido abierta.";
    }
    else if (vKey != keyOpen)
    {
        cerr << "La llave es incorrecta.";
        return "La llave es incorrecta.";
    }
    
    return "done!";    
}
string DOOR::CLOSE()
{
    if (vStatus == false)
    {
        cerr << "La puerta ya esta cerrada.";
        return "La puerta ya esta cerrada.";
    }
    else
    {
        vStatus = false;
        return "La puerta a sido cerrada.";
    }
    return "done!";
}
string DOOR::UNLOCKED(string keyunlock){
    if (vLockOrUnlock)
    {
       cerr << "La puerta ya esta desbloqueada.";
       return "La puerta ya esta desbloqueada.";
    }
    else if ((vLockOrUnlock==false)&&(vKey==keyunlock))
    {
        vLockOrUnlock = true;
        return "La puerta a sido desbloqueada.";
    }
    else
    {
        cerr << "La llave es incorrecta";
        return "La llave es incorrecta";
    }
    return "done!";    
}
string DOOR::LOCK(string keyLock){
    if (vLockOrUnlock == false)
    {
       cerr << "La puerta ya esta bloqueada.";
       return "La puerta ya esta bloqueada.";
    }
    else if ((vLockOrUnlock)&&(vKey==keyLock))
    {
        vLockOrUnlock = false;
        return "La puerta a sido bloqueada.";
    }
    else
    {
        cerr << "La llave es incorrecta";
        return "La llave es incorrecta";
    }
    return "done!"; 
}

string DOOR::OpenAndUnlocked(DOOR door, string keyOpenAndUnLocked){
    if ((door.ISOPEN())||(door.ISUNLOCK()))
    {       
        cerr << "La puerta ya esta abierta o desbloqueada";
        return "La puerta ya esta abierta o desbloqueada";
    }
    else
    {
        return door.OPEN(keyOpenAndUnLocked) + " and " + door.UNLOCKED(keyOpenAndUnLocked); 
    }
    return "done!";
}
string DOOR::OpenAndLocked(DOOR door, string keyOpenAndLocked){
    if ((door.ISOPEN())||(door.ISLOCK()))
    {       
        cerr << "La puerta ya esta abierta o bloqueada";
        return "La puerta ya esta abierta o bloqueada";
    }
    else
    {
        return door.OPEN(keyOpenAndLocked) + " and " + door.LOCK(keyOpenAndLocked); 
    }
    return "done!";
}
string DOOR::ClosedAndUnlocked(DOOR door, string keyClosedAndUnlocked){
    if ((door.ISCLOSE())||(door.ISUNLOCK()))
    {       
        cerr << "La puerta ya esta cerrada o desbloqueada";
        return "La puerta ya esta cerrada o desbloqueada";
    }
    else
    {
        return door.CLOSE() + " and " + door.UNLOCKED(keyClosedAndUnlocked); 
    }
    return "done!";
}
string DOOR::ClosedAndLocked(DOOR door, string keyClosedAndLocked){
    if ((door.ISCLOSE())||(door.ISLOCK()))
    {       
        cerr << "La puerta ya esta cerrada o bloqueada";
        return "La puerta ya esta cerrada o bloqueada";
    }
    else
    {
        return door.CLOSE() + " and " + door.LOCK(keyClosedAndLocked); 
    }
    return "done!";
}