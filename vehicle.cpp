//
//  vehicle.cpp
//  cs 32 hw 3
//
//  Created by Jacqueline Nguyen on 2/10/23.
//

class Vehicle {
public:
    Vehicle(string ID, bool canHover, string description);
    virtual ~Vehicle() {};
    string id() const;
    virtual bool canHover() const { return true; };
    string description() const { return m_description; };
private:
    string m_id;
    bool m_canHover;
    string m_description;
};

string Vehicle::id() const {
    return m_id;
}

Vehicle::Vehicle(string ID, bool canHover, string description) {
    m_id = ID;
    m_canHover = canHover;
    m_description = description;
    
}

//class HoverVehicles: public Vehicle {
//public:
//    HoverVehicles(string ID, string description)
//    : Vehicle(ID, true, description) {
//
//    }
//    virtual bool canHover() const {
//        return true;
//    }
//};

// Drone Class Implementation and declaration
class Drone: public Vehicle{
public:
    Drone(string ID);
    virtual ~Drone();
//    virtual string description() const;
};

Drone::Drone(string ID)
: Vehicle(ID, false, "a drone")
{ }

Drone::~Drone () {
    cout << "Destroying " << id() << ", a drone" << endl;
}

// balloon
class Balloon: public Vehicle {
public:
    Balloon (string ID, double diameter);
    virtual ~Balloon ();
//    virtual string description() const;
};

string typeOfBalloon(double diameter) {
    if (diameter >= 8) {
        return "a large balloon";
    } else {
        return "a small balloon";
    }
}

Balloon::Balloon(string ID, double diameter)
: Vehicle(ID, false, "a balloon")
{ }

Balloon::~Balloon () {
    cout << "Destroying the balloon " << id() << endl;
}



class Satellite: public Vehicle {
public:
    Satellite (string ID);
    virtual ~Satellite ();
    virtual bool canHover() const;
//    virtual string description() const;
};

Satellite::Satellite(string ID)
: Vehicle(ID, false, "a satellite")
{ }

Satellite::~Satellite () {
    cout << "Destroying the satellite " << id() << endl;
}

bool Satellite::canHover() const {
    return false;
}
