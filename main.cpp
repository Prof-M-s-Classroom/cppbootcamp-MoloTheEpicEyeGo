#include <iostream>
#include <string>
using namespace std;

// Step 1: Define the Robot class
class Robot {
private:
    string name;
    string model;
    int batteryLife;

public:
    // Constructor
    //initializing the Robot constructor
    //similar to java
    Robot(string n, string m, int b):name(n),model(n),batteryLife(b){}


    //setters for all vars
    void setName(string n)
    {
        name = n;
    }

    void setModel(string m)
    {
        model = m;
    }

    void setBatteryLife(int b)
    {
        batteryLife = b;
    }

    //getters for all vars
    string getName(){return name;}
    string getModel(){return model;}
    int getBatteryLife(){return batteryLife;}


    // Display function
    void displayRobot() {
        cout << "Robot: " << name << " | Model: " << model << " | Battery Life: " << batteryLife << "%\n";
    }
};

//passing a value to c
// Step 2: Function to modify robot (pass by value)
void modifyRobotV(Robot r)
{
    //doesnt change for some reason
    r.setBatteryLife(200);
    cout << "inside function passing by value" <<  r.getBatteryLife() << endl;
}

// Step 3: Function to modify robot (pass by reference)
//passing a reference/address
void modifyRobotR(Robot& r)
{
    //does change for some reason
    r.setBatteryLife(200);
    cout << "inside function passing by reference" << r.getBatteryLife() << endl;
}

// Step 4: Template class for a Fleet that stores multiple robots
template <typename T>  class Fleet
{
private:
    T* robots;
    int capacity;
    int count;

public:
    // Constructor: Allocates space for 'capacity' robots
    Fleet(int cap) {
        capacity = cap;
        count = 0;
        robots = new T[capacity];
    }

    // Add robot to fleet
    void addRobot(T robot) {
        if (count < capacity) {
            robots[count] = robot;
            count++;
        } else {
            cout << "Fleet is full!\n";
        }
    }

    // Display all robots
    void showFleet() {
        cout << "Fleet contains:\n";
        for (int i = 0; i < count; i++) {
            cout << "- " << robots[i] << "\n";
        }
    }

    // Destructor: Free allocated memory
    ~Fleet() {
        delete[] robots;
    }
};

int main() {
    // Step 5: Create a Robot object
    Robot scotty = Robot("Scotty", "1.0", 100);


    // Step 6: Use pointers to access Robot object
    Robot* robotPtr = &scotty;
    cout << "Updated Battery Life (using pointer): " << robotPtr->getBatteryLife() << "%\n";

    // Step 7: Pass by value (no change outside function)
    modifyRobotV(scotty);
    cout << "After modifyRobotByValue, Battery Life: " << scotty.getBatteryLife() << "%\n";

    // Step 8: Pass by reference (changes persist)
    modifyRobotR(scotty);
    cout << "After modifyRobotByReference, Battery Life: " << scotty.getBatteryLife() << "%\n";

    // Step 9: Use the Fleet template class
    Fleet<string> myFleet(3);
    myFleet.addRobot("Autobot-X");
    myFleet.addRobot("Cybertron-7");
    myFleet.addRobot("NanoDroid-3");

    Fleet<string> myFleet2(1);
    myFleet2.addRobot("scotty");

    myFleet.showFleet();
    myFleet2.showFleet();

    return 0;
}