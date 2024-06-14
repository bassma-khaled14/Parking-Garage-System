#include <iostream>
#include <ctime>
//#define MAX_CARS 100
using namespace std;
class Vehicle{
private:
    const double secondrate = (5 / 60.0) / 60;
    string modelname,arrivaltime,depraturetime;
    int uniqueid,modelyear,slot;
    int parkedcars;
    static float income;
    bool parked;
    static int MAX_PARKING_SLOT;

public:
    Vehicle()
    {

    }
    Vehicle(string modelname,int vehicleid, int modelyear,int parkedcars,int slot)
    {
        modelname=modelname;
        uniqueid=vehicleid;
        modelyear=modelyear;
        slot=slot;
    }

    int printemptyslots()
    {
        cout<<"Enter the parkedcars:"<<endl;
        cin>>parkedcars;
        cout<<"The empty slots are:";
        cout<<MAX_PARKING_SLOT-parkedcars;

    }

    bool ParkIn()
    {
        cout<<"Please enter your slot number:"<<endl;
        cin>>slot;
        if(slot==parked)
        {
            cout <<"car is already parked" << endl;
            return false;
        }
        else
        {
            parkedcars++;
            return true;
       }
    }
     int ParkOut()
    {
        if(this->parked)
        {

            cout<<"Enter the time taken:"<<endl;
             int time_taken;
            cin>>time_taken;
            long double fee;
            cout<<"Enter the fees:"<<endl;
            cin>>fee;
            fee = fee*(time_taken);
            income += fee;
            parkedcars--;
            cout << "Car is out and the fee is " << fee << " and it stayed for " << ((long double)time_taken/60.0)/60.0 << " hours" << endl;
        }
        else
        {
            cout << "The car is Already out" << endl;
        }
    }
    int calculateincome()
    {
        int totalnumberofvehicles;
        double giventime;
        cout<<"please enter the total numbers of vehciles:"<<endl;
        cin>>totalnumberofvehicles;
        cout<<"please enter the given time:"<<endl;
        cin>>giventime;
        cout<<"The income =" <<((double)totalnumberofvehicles*giventime);

    }

    friend ostream &operator << (ostream &out, Vehicle & v);

    friend istream &operator>>(istream& in, Vehicle& v);


};

float Vehicle::income=0;
int Vehicle :: MAX_PARKING_SLOT=80;
ostream &operator << (ostream &out, Vehicle &v)
{
    out<<v.modelname<<"enter modename";
    out<<v.modelyear<<"enter modelyear";
    out<<v.uniqueid<<"enter uniqueid";
}
istream &operator >>(istream &in, Vehicle &v)
{
        cout<<endl;
        cout<<"Enter vehicle's model name:"<<endl;
        in>>v.modelname;
        cout<<"Enter vehicle's model year:"<<endl;
        in>>v.modelyear;
        cout<<"Enter vehicle's unique id:"<<endl;
        in>>v.uniqueid;
        return in;

    }

int main()
{

    Vehicle v1;
    cout<<"Welcome to the parking system"<<endl;



    cin>>v1;
    cout<<v1.printemptyslots()<<endl;
    cout<<v1.ParkIn();
    cout<< v1.ParkOut();
    cout<<v1.calculateincome();

}





