#include <iostream>

/*
A printing shop runs 16 batches (jobs) every week and each batch requires a sheet of special colour-proofing paper of size A5.

Every Monday morning, the foreman opens a new envelope, containing a large sheet of the special paper with size A1.

He proceeds to cut it in half, thus getting two sheets of size A2. Then he cuts one of them in half to get two sheets of size A3 and so on until he obtains the A5-size sheet needed for the first batch of the week.

All the unused sheets are placed back in the envelope.
At the beginning of each subsequent batch, he takes from the envelope one sheet of paper at random. If it is of size A5, he uses it. If it is larger, he repeats the 'cut-in-half' procedure until he has what he needs and any remaining sheets are always placed back in the envelope.

Excluding the first and last batch of the week, find the expected number of times (during each week) that the foreman finds a single sheet of paper in the envelope.

Give your answer rounded to six decimal places using the format x.xxxxxx .
*/

using namespace std;

long double batchcount[16];
long double onesheetcount[16];
int maxbatches=16;
long double paths=0;
long double sspaths=0;
long double ppaths=0;
long double psspaths=0;


int gotonextbatch (int *sheets, int multiplier, int batchnum, int ssthispath, double prob);

int main(){
    long double batchprob[16];
    long double weekprob = 0;
    cout.precision(7);

    for(int n=0; n<16; n++){
        batchcount[n]=0;
        onesheetcount[n]=0;
        batchprob[n]=0;
    }

    int thissheet[5];
    thissheet[0] = 1; //A1
    thissheet[1] = 0; //A2
    thissheet[2] = 0; //A3
    thissheet[3] = 0; //A4
    thissheet[4] = 0; //A5

    gotonextbatch(thissheet, 1, 1, 0,1);

    for(int n=0; n<16; n++){
        if(batchcount[n]){
            batchprob[n] = static_cast<long double> (onesheetcount[n] / batchcount[n]);
            cout << "Batch: " << n+1 << " Single Sheets: " << onesheetcount[n] << " Total: " << batchcount[n] << "  Prob:" << batchprob[n] << endl;
            }
        }
    for (int n=0; n<16; n++){
        weekprob = weekprob + batchprob[n];
        }
    cout << "Week Prob: " << weekprob << endl;
    cout << "Paths approach:" << endl;
    cout << "Paths: " << paths << endl;
    cout << "Single sheet paths: " << sspaths << endl;
    long double thissspath = static_cast<long double>(sspaths/paths);
    cout << "Expected no: " << thissspath << endl;
    cout << " Try again" << endl;
    cout << "Prob paths: " << ppaths << endl;
    cout << "single paths: " <<psspaths << endl;
    cout << "Prob result: " << psspaths/ppaths << endl;

    return 0;

}

int gotonextbatch(int *sheets, int multiplier, int batchnum, int ssthispath, double prob){
    /*cout << "Batch = " << batchnum << "  mult = " << multiplier << " Sheets: ";
    cout << sheets[0] << " " << sheets[1] << " "<< sheets[2] << " " << sheets[3] << endl;
    char tmp[1];
    cin >> tmp;
*/
    double totalsheets = 0;
    double newprob = 1;
    //test current batch


    for (int n=0; n<5; n++){totalsheets = totalsheets + sheets[n];} //Count number of sheets in bag

    if (totalsheets==1) {
        onesheetcount[batchnum-1] = onesheetcount[batchnum-1] + multiplier;
        ssthispath++;
    } //Is there just one?

    batchcount[batchnum-1] = batchcount[batchnum-1] + multiplier;

    //Now start to pick a sheet for the next batch

    for(int n=0; n<5; n++){
        int newsheets[5];
        for(int m=0; m<5; m++){
            newsheets[m]=sheets[m];
            }
        if (sheets[n]==0) {continue;}
        newprob = prob*(sheets[n]/totalsheets);
        switch (n){
            case 0: //A1
                newsheets[0]--; //A1
                newsheets[1]++; //A2
                newsheets[2]++; //A3
                newsheets[3]++; //A4
                newsheets[4]++; //A5
                break;
            case 1: //A2
                newsheets[1]--; //A2
                newsheets[2]++; //A3
                newsheets[3]++; //A4
                newsheets[4]++; //A5
                break;
            case 2: //A3
                newsheets[2]--; //A3
                newsheets[3]++; //A4
                newsheets[4]++; //A5
                break;
            case 3: //A4
                newsheets[3]--; //A4
                newsheets[4]++; //A5
                break;
            case 4: //A5
                newsheets[4]--; //A5
                break;
            }
    if (batchnum==maxbatches) {
        sspaths = sspaths + (ssthispath*multiplier);
        psspaths = psspaths +  (ssthispath*prob);
        paths = paths + multiplier;
        ppaths= ppaths+ prob;
        return 0;} //Reached final batch
    gotonextbatch(newsheets, multiplier * sheets[n], batchnum+1, ssthispath, newprob);
    }
}
