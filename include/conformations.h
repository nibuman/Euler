#ifndef CONFORMATIONS_H
#define CONFORMATIONS_H
#include <list>
#include <bitset>
#include <string>
#include <iostream>
#define LIKELY 5
#define MAP_SIZE 23
#include <new>

using namespace std;

class conformations
{
public:
    conformations(int proteinsize);

    virtual ~conformations();
    int BestConformation (string ProteinSequence);
    int OptimisedConformation(string ProteinSequence, int MaxInteractions);

protected:

private:
    int thisproteinlength;
    int MapX;
    int MapY;

    list<string> ListOfConformations;
    list<string> OrderedConformations;
    list<int> InteractionIndex;
    list<int>::iterator InteractionIterator;
    list<string>::iterator ConformationsIterator;
    list<string>::iterator BestConformationIterator;

    void CreateIterationsIndex();
    char Map[MAP_SIZE][MAP_SIZE];
    char CalcDirection(char RelativeDirection); //calculates the absolute direction (N,E,S,W) of the next segment from the relative movement (S, L, R)
    void CreateAllConformations(int position, bool turnedcorner, string ThisConformation);
    bool ValidConformation(string ThisConformation);
    bool LikelyConformation (int ExtraInteractions);
    bitset<4> compass; //keeps track of the current absolute direction (N, E, S, W)
    void SetCompassS();
    void PrintConformations();
    bool MapConformation(string ThisConformation, string ThisSequence);
    bool MapConformation(string ThisConformation);

    void RotateClockwise ();
    void RotateAntiClockwise();
    bool MapMaker(char Protein);
    void ResetMap();
    void PrintMap();
    int CountInteractions();
    void CreateOrderedList();

};

#endif // CONFORMATIONS_H
