#include "../include/conformations.h"


conformations::conformations(int proteinsize)
{
    thisproteinlength = proteinsize; //ctor
    SetCompassS(); // N E S W, starts by going South
    cout << endl;
    string StartingPoint = "S";
    CreateAllConformations(1, false, StartingPoint);


    cout << "Number of conformations before validating = " << ListOfConformations.size() << endl;
    //Remove any conformations from the list that are not valid
    for(ConformationsIterator=ListOfConformations.begin(); ConformationsIterator!=ListOfConformations.end(); ConformationsIterator++)
    {

        if(!ValidConformation(*ConformationsIterator))
        {
            ConformationsIterator = ListOfConformations.erase(ConformationsIterator);
            --ConformationsIterator;
        }

    }
    cout << "Number of conformations after ValidConformation = " << ListOfConformations.size() << endl;

    for(ConformationsIterator=ListOfConformations.begin(); ConformationsIterator!=ListOfConformations.end(); ConformationsIterator++)
    {
        if(!MapConformation(*ConformationsIterator, "HHHHHHHHHHHHHHHHH"))
        {
            ConformationsIterator = ListOfConformations.erase(ConformationsIterator);
            --ConformationsIterator;
        }
    }
    cout << "Number of conformations after Map Check = " << ListOfConformations.size() << endl;
    /*for(ConformationsIterator=ListOfConformations.begin(); ConformationsIterator!=ListOfConformations.end(); ConformationsIterator++)
    {
        MapConformation(*ConformationsIterator, "HHHHHHHHHHHHHHH");
        if (!LikelyConformation(LIKELY))
        {

            ConformationsIterator = ListOfConformations.erase(ConformationsIterator);
            --ConformationsIterator;
        }
    }
    */
    CreateOrderedList();

    /*

    for(ConformationsIterator=ListOfConformations.begin(); ConformationsIterator!=ListOfConformations.end(); ConformationsIterator++)
    {
        cout<< endl << *ConformationsIterator << endl;
        //MapConformation(*ConformationsIterator, "HHHHHHHHHHHHHHH");
        //PrintMap();
        cout << "Interactions = " << CountInteractions() << endl;
        cout << "Likely Conformation? " << LikelyConformation(LIKELY) << endl;
    }

    for(ConformationsIterator=OrderedConformations.begin(); ConformationsIterator!=OrderedConformations.end(); ConformationsIterator++)
    {
        cout << *ConformationsIterator << endl;

        //PrintMap();

    }
    */
    ConformationsIterator=OrderedConformations.begin();
    cout << "First of ordered list = " << *ConformationsIterator << endl;
    cout << "Number of conformations after LikelyConformation = " << ListOfConformations.size() << endl;


}
/** @brief (one liner)
  *
  * (documentation goes here)
  */
void conformations::CreateOrderedList()
{
    int ExtraInteractions=0;
    char charExtraInteractions;
    string IndexedConformation = "";
    for(ConformationsIterator=ListOfConformations.begin(); ConformationsIterator!=ListOfConformations.end(); ConformationsIterator++)
    {
        MapConformation(*ConformationsIterator, "HHHHHHHHHHHHHHHH");
        ExtraInteractions = CountInteractions() - (thisproteinlength-1);
        if (ExtraInteractions > 9) ExtraInteractions = 9;
        charExtraInteractions = '0' + ExtraInteractions;
        IndexedConformation = charExtraInteractions + *ConformationsIterator;
        if (ExtraInteractions>3) OrderedConformations.push_front(IndexedConformation);

    }
    OrderedConformations.sort();
    OrderedConformations.reverse();
    cout << "Number of conformations in ordered list = " << OrderedConformations.size() << endl;

    return;

}
/** @brief (one liner)
  *
  * (documentation goes here)
  */
void conformations::CreateIterationsIndex()
{
     for(ConformationsIterator=ListOfConformations.begin(); ConformationsIterator!=ListOfConformations.end(); ConformationsIterator++)
    {

}





/** @brief (one liner)
  *
  * (documentation goes here)
  */
int conformations::BestConformation(string ProteinSequence)
{
    int HighestInteractions = 0;
    for(ConformationsIterator=ListOfConformations.begin(); ConformationsIterator!=ListOfConformations.end(); ConformationsIterator++)
    {
        MapConformation(*ConformationsIterator, ProteinSequence);
        if (CountInteractions() > HighestInteractions)
        {
            HighestInteractions = CountInteractions();
            //BestConformationIterator = ConformationsIterator;
        }
    }
    //Uncomment this to print out data on the best conformation found for this sequence
    //MapConformation(*BestConformationIterator, ProteinSequence);
    //cout << "Best Conformation string = " << *BestConformationIterator << endl;
    //PrintMap();

    return HighestInteractions;
}

int conformations::OptimisedConformation(string ProteinSequence, int MaxInteractions)
{
    int HighestInteractions = 0;
    int Interactions = 0;
    string Conformation;

    for(ConformationsIterator=OrderedConformations.begin(); ConformationsIterator!=OrderedConformations.end(); ConformationsIterator++)
    {
        Conformation = *ConformationsIterator;
        Conformation = Conformation.substr(1,(Conformation.size()-1));
        //cout << Sequence << " ";
        MapConformation(Conformation, ProteinSequence);
        Interactions=CountInteractions();
        if (Interactions > HighestInteractions)
        {
            HighestInteractions = Interactions;
            BestConformationIterator = ConformationsIterator;
            if (Interactions == MaxInteractions)
            {
                //cout << "Broke for Interactions = MaxInteractions" << MaxInteractions << endl;
            return HighestInteractions;
            }

        }
    }
    //Uncomment this to print out data on the best conformation found for this sequence
    //MapConformation(*BestConformationIterator, ProteinSequence);
    //cout << "Best Conformation string = " << *BestConformationIterator << endl;
    //PrintMap();

    return HighestInteractions;


}

void conformations::PrintConformations()
{
    for(ConformationsIterator=ListOfConformations.begin(); ConformationsIterator!=ListOfConformations.end(); ConformationsIterator++)
    {
        cout << " * " << *ConformationsIterator;
    }
    cout << endl<< "Number of Conformations = " << ListOfConformations.size() << endl;

}

conformations::~conformations()
{
    //dtor
    }

void conformations::CreateAllConformations(int position, bool turnedcorner, string ThisConformation)
{
    //Creates all possible conformations - not all will be valid

    if(position<thisproteinlength)
    {
        int newposition = ++position;

        if(position<3) //1st and 2nd residues always straight
        {
            CreateAllConformations(newposition, false, ThisConformation+"S");
            return;
        }

        //if not turned corner then can only go straight or left

        CreateAllConformations(newposition, turnedcorner, ThisConformation+"S"); //try going straight
        CreateAllConformations(newposition, true, ThisConformation+"L"); //try going left

        if(turnedcorner) // L + R are equivalent until symmetry has been broken by at least one turn
        {
            CreateAllConformations(newposition, true, ThisConformation+"R"); //if it has turned corner can try going right too
        }
    }
    else
    {
        ListOfConformations.push_front(ThisConformation);
    }

    //cout << "End" << endl;
    return;
}
bool conformations::ValidConformation(string ThisConformation)
{
    //Conformation must contain at least 2 turns
    int LCount=0;
    int RCount=0;
    for(int n=0; n<thisproteinlength; n++)
    {
        if (ThisConformation[n]=='L') LCount++;
        if (ThisConformation[n]=='R') RCount++;

    }
    if (LCount<2 && RCount<2) return false;


    return true;
}
/** @brief (one liner)
  *
  * (documentation goes here)
  */
bool conformations::LikelyConformation(int ExtraInteractions)
{
    if (CountInteractions()<(thisproteinlength+(ExtraInteractions-1)))return false;

    return true;
}


char conformations::CalcDirection(char RelativeDirection)
{
    ;
}

void conformations::SetCompassS () // (N, E, S, W)
{
    compass.reset(); // 0000
    compass.set(1, 1); // 0010
}

/** @brief Map Conformation
  *
  * Takes a conformation as a string then plots out its path
  */
bool conformations::MapConformation(string ThisConformation, string ThisSequence)
{
    SetCompassS();
    ResetMap();
    MapX = 12;
    MapY = 11;

    for(int n=0; n<ThisConformation.size(); n++)
    {
        switch (ThisConformation[n])
        {
        case 'S':
            break;
        case 'L':
            RotateAntiClockwise();
            break;
        case 'R':
            RotateClockwise();
            break;
        default:
            cout << "Error parsing conformation string in MapConformation"<< endl;
            return false;
        }
        //cout << compass << endl;
        if (MapMaker(ThisSequence[n])==false) return false;
    }
    //PrintMap();
    return true;
}

/** @brief (one liner)
 *
 * (documentation goes here)
 */
void conformations::RotateClockwise()
{
    compass>>=1;
    if (compass.none())
    {
        compass.set(3,1);
    }
    return;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void conformations::RotateAntiClockwise()
{
    compass<<=1;
    if (compass.none())
    {
        compass.set(0,1);
    }
    return;

}
/** @brief (one liner)
  *
  * (documentation goes here)
  */
bool conformations::MapMaker(char Protein)
/** @brief (one liner)
  *
  * (documentation goes here)
  */
{
    if (compass[3])
    {
        MapY--;
    }
    if (compass[2])
    {
        MapX++;
    }
    if (compass[1])
    {
        MapY++;
    }
    if (compass[0])
    {
        MapX--;
    }
    if(MapX < 0 || MapX > (MAP_SIZE-1)) return false;
    if(MapY < 0 || MapY > (MAP_SIZE-1)) return false;
    if(Map[MapX][MapY]=='.')
    {
        Map[MapX][MapY]=Protein;
        return true;
    }
    return false;
}
void conformations::ResetMap()
{
    for (int x=0; x<MAP_SIZE; x++)
    {
        for (int y=0; y<MAP_SIZE; y++)
        {
            Map[x][y]='.';
        }
    }
    return;
}

/** @brief (one liner)
  *
  * (documentation goes here)
  */
void conformations::PrintMap()
{
    for (int y=0; y<MAP_SIZE; y++)
    {
        for (int x=0; x<MAP_SIZE; x++)
        {
            cout << Map[x][y] << " ";
        }
        cout << endl;
    }

}
/** @brief (one liner)
  *
  * (documentation goes here)
  */
int conformations::CountInteractions()
{
    int InteractionCount = 0;
    for (int x=0; x<(MAP_SIZE - 1); x++)
    {
        for (int y=0; y<(MAP_SIZE - 1); y++)
        {
            if(Map[x][y]=='H')
            {
                if (Map[x+1][y]=='H') InteractionCount++;
                if (Map[x][y+1]=='H') InteractionCount++;
            }
        }
    }
    return InteractionCount;

}



