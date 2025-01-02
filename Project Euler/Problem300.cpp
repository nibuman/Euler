#define SEQ_LEN 8

#include <iostream>
#include <string>
#include "../include/conformations.h"


using namespace std;

list<string> ListOfSequences;
list<string>::iterator SequencesIterator;
void BuildListOfSequences(int position, string ThisSequence);
int MaxInteractions(string Sequence);
int MaxInteractions2(string Sequence);

int main()
{

    int TotalInteractions = 0;
    conformations ListOfValidConformations(SEQ_LEN);
    cout << "List of Conformations built" << endl;


    //cout << "H Interactions in best conformation = " << ListOfValidConformations.BestConformation("HHPHHPHHH") << endl;
    //cout << ListOfValidConformations.BestConformation("HHPPHHHPHHPH") << endl;
    BuildListOfSequences(0, "");
    cout << "List of Sequences built" << endl;

    int NumberOfSequences = ListOfSequences.size();

    for(SequencesIterator=ListOfSequences.begin(); SequencesIterator!=ListOfSequences.end(); SequencesIterator++)
    {

        //TotalInteractions+=ListOfValidConformations.BestConformation(*SequencesIterator);
        //TotalInteractions+=ListOfValidConformations.OptimisedConformation(*SequencesIterator, MaxInteractions(*SequencesIterator));
        TotalInteractions+=ListOfValidConformations.OptimisedConformation(*SequencesIterator, MaxInteractions2(*SequencesIterator));
        /* if (ListOfValidConformations.BestConformation(*SequencesIterator) > ListOfValidConformations.OptimisedConformation(*SequencesIterator, MaxInteractions2(*SequencesIterator)))
         {
             cout << "Best > Max for this sequence: " << *SequencesIterator << "  Best = " << ListOfValidConformations.BestConformation(*SequencesIterator);
             cout << "  Optimised = " << ListOfValidConformations.OptimisedConformation(*SequencesIterator, MaxInteractions2(*SequencesIterator));
             cout << " Max2 = " << MaxInteractions2(*SequencesIterator) << endl;
         }*/

        //cout << "Sequence: " << *SequencesIterator << "  MaxInteractions:" << MaxInteractions2(*SequencesIterator) << "Total Interactions: " << ListOfValidConformations.OptimisedConformation(*SequencesIterator, MaxInteractions(*SequencesIterator)) << endl;

    }
    cout << "Max Interactions for \"PPHHPPHPPPPPPH\"= " << MaxInteractions("PPHHPPHPPPPPPH") << endl;
    cout << "Max Interactions2 for \"PPHHPPHPPPPPPH\"= " << MaxInteractions2("PPHHPPHPPPPPPH") << endl;
    cout << "For protein length " << SEQ_LEN << " total number of interactions = " << TotalInteractions << endl;
    cout << "Total number of sequences = " << ListOfSequences.size() << endl;
    cout << "Average number of interactions = " << TotalInteractions / ListOfSequences.size() << endl;
}

int MaxInteractions(string Sequence)
{
    int intrinsic=0;
    int HCount=0;
    int SequenceLength = Sequence.size();
    for(int n=0; n<(SequenceLength-1); n++)
    {
        if (Sequence[n]=='H')
        {
            HCount++;
            if (Sequence[n+1]=='H') intrinsic++;
        }
    }
    if (Sequence[SequenceLength-1]=='H') HCount++;
    return (intrinsic + (HCount/2));

}

int MaxInteractions2(string Sequence)
{
    int surfaces[15];
    int interactions=0;

    int SeqLength = Sequence.size();

    surfaces[0]=4;

    for (int n=0; n<(SeqLength-1); n++)
    {
        int m=(n+1);
        surfaces[m]=4;
        bool adjacent=true;
        surfaces[n]--;
        surfaces[m]--;

        if (Sequence[n]=='H')
        {
            while(adjacent||(surfaces[n]>0 && m<SeqLength))
            {
                if (Sequence[m]=='H')
                {
                    interactions++;
                    if(!adjacent)
                    {
                        surfaces[n]--;
                        surfaces[m]--;
                    }
                }
                m+=2;
                adjacent = false;
            }
        }
    }
    /*for (int n=0; n<SeqLength; n++)
    {
        cout << surfaces[n] << " ";
    }
    cout << endl; */

    return interactions;

}
void BuildListOfSequences(int position, string ThisSequence)
{
    //Creates all possible sequences

    if(position<SEQ_LEN)
    {
        int newposition = ++position;

        BuildListOfSequences(newposition, ThisSequence+"H"); //Add an H
        BuildListOfSequences(newposition, ThisSequence+"P"); //Add a P
    }

    else
    {
        ListOfSequences.push_front(ThisSequence);
        //cout << ThisSequence << endl;
    }

    //cout << "End" << endl;
    return;
}


