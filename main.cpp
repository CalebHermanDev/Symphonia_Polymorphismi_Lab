#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Instrument
{
protected:
    string name;
    string sound;

public:
    Instrument(string n, string s)
    {
        name = n;
        sound = s;
    }

    virtual void play() = 0;

    virtual ~Instrument() {}
};

class Trumpet : public Instrument
{
public:
    Trumpet() : Instrument("Trumpet", "doot") {}

    void play() override
    {
        cout << name << ": ";
        for (int i = 0; i < 3; i++)
            cout << sound << " ";
        cout << endl;
    }
};

class Violin : public Instrument
{
public:
    Violin() : Instrument("Violin", "vwa") {}

    void play() override
    {
        cout << name << ": ";
        for (int i = 0; i < 5; i++)
            cout << sound << " ";
        cout << endl;
    }
};

class Piano : public Instrument
{
public:
    Piano() : Instrument("Piano", "Dee") {}

    void play() override
    {
        cout << name << ": ";
        for (int i = 0; i < 2; i++)
            cout << sound << " ";
        cout << endl;
    }
};

class Trombone : public Instrument
{
public:
    Trombone() : Instrument("Trombone", "Dwooooo~") {}

    void play() override
    {
        cout << name << ": " << sound << endl;
    }
};

class Singer : public Instrument
{
public:
    Singer() : Instrument("Singer", "Blah") {}

    void play() override
    {
        cout << name << ": ";
        for (int i = 0; i < 6; i++)
            cout << sound << " ";
        cout << endl;
    }
};

class Orchestra
{
private:
    vector<Instrument *> instruments;

public:
    void addInstrument(Instrument *instrument)
    {
        instruments.push_back(instrument);
    }

    void play()
    {
        for (Instrument *instrument : instruments)
        {
            instrument->play();
        }
    }

    ~Orchestra()
    {
        for (Instrument *instrument : instruments)
        {
            delete instrument;
        }
    }
};

int main()
{
    Orchestra orchestra;

    orchestra.addInstrument(new Trumpet());
    orchestra.addInstrument(new Violin());
    orchestra.addInstrument(new Piano());
    orchestra.addInstrument(new Trombone());
    orchestra.addInstrument(new Trumpet());
    orchestra.addInstrument(new Singer());

    orchestra.play();

    return 0;
}

/*
Though provoking questions:

1. This exact same model can be used in many real-world applications where different objects
perform the same operations but in different ways. For example, in a graphics application, you might have different shapes
(like Circle, Square, Triangle) that all have a method to draw themselves. Each shape would implement the draw method differently,
but the application can treat them all as Shape objects and call draw on them without knowing the specific type of shape.

2. I believe the place to put these kinds of restrictions would likely be in the Orchestra class, as it is responsible for managing
the collection of instruments. Specifically, the addInstrument method could be modified to check the type of the instrument being added and enforce any
restrictions on the number of specific types of instruments.
*/