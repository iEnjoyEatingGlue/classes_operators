#include <iostream>

using namespace std;

class Time
{
private:
    int seconds;
    int minutes;
    int hours;
    int remainder;

public:
    Time(int sec = 0, int min = 0,int hour = 0, int rem = 0)
    {
        seconds = sec;
        minutes = min;
        hours = hour;
        remainder = rem;
    }
    void convert(bool y)
    {
        if (y == true)
        {
            hours = seconds/3600;
            remainder = seconds % 3600;
            minutes = remainder/60;
            seconds = remainder % 60;
        }
        else
        {
            seconds = hours*3600 + minutes*60 + seconds;
            hours = 0;
            minutes = 0;
        }
    }
    Time operator+(Time &t2)
    {
        return(hours += t2.hours, minutes += t2.minutes, seconds += t2.seconds);
    }
    Time operator-(Time &t2)
    {
        return(hours -= t2.hours, minutes -= t2.minutes, seconds -= t2.seconds);
    }
    Time operator*(int a)
    {
        return(hours *= a, minutes *= a, seconds *= a);
    }
    friend std::ostream& operator<<(std::ostream& stream, const Time &time);
};

std::ostream& operator<<(std::ostream& stream, const Time &time)
{
    stream << time.hours << "h:" <<  time.minutes << "m:" << time.seconds << "s" << endl;
    return(stream);
}

int main()
{

    int a, b;
    bool x = true;
    bool y = true;
    int init_1, init_2;

    cout << "initialize first duration time in seconds" << endl;
    cin  >> init_1;
    Time time1(init_1);
    cout << "Entered: " << time1 << endl;

    cout << "initialize second operand" << endl;
    cin  >> init_2;
    Time time2(init_2);
    cout << "Entered: " << time2 << endl;



    while(x)
    {
        cout << "Press 1 to exit" << endl;
        cout << "Press 2 to add second operand to duration time" << endl;
        cout << "Press 3 to substract second operand from duration time" << endl;
        cout << "Press 4 to multiply initialized duration time by a scalar" << endl;
        cout << "Press 5 to print duration time" << endl;
        cout << "Press 6 to convert duration time to and from seconds" << endl;

        cin >> a;

        switch(a)
        {
            case 1:
            {
                x = !x;
                break;

//                cout << "Provide second operand" << endl;
//                cin  >> init;
//                time2(init);

//                cout << "Entered: " << time2 << endl;
//                break;
            }
            case 2:
            {
                time1 + time2;
                cout  << time1;
                break;
            }
            case 3:
            {
                time1 - time2;
                cout << time1;
                break;
            }
            case 4:
            {
                cout << "Provide a scalar" << endl;
                cin >> b;
                cout << time1 * b;
                break;
            }
            case 5:
            {
                cout << time1 << endl;
                break;
            }
            case 6:
            {
                time1.convert(y);
                time2.convert(y);
                y = !y;
                cout << "Duration time after change: " << time1 << endl <<  "Second operand after change: " << time2 <<endl;
                break;
            }
            default:{}
        }
    }
}
