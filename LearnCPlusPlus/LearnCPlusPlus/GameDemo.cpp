#include <iostream>
#include <bitset>
#include <fstream>

#include<vector>
#include<thread>
#include<mutex>
#include<time.h>
#include <chrono> 

using namespace std;

#define RULE_SIZE 8
#define SIZE  512
#define NUMBER_OF_RULES 232

class CellularAutomaton {


private: 
    mutex mtx;

public:

    void saveToFile(int imageWidth, int imageHeight, int** imageAsNumber, string filePath) {

        ofstream myfile;
        myfile.open(filePath, ios::out | ios::trunc);
        myfile << "P2\n";
        myfile << imageWidth << " " << imageHeight << "\n";
        myfile << "255\n";

        for (int row = 0; row < imageWidth; row++) {
            for (int col = 0; col < imageHeight; col++) {
                myfile << imageAsNumber[row][col] * 255 << " ";
            }
            myfile << "\n";
        }

        myfile.close();

    }

    int applRule(int** imageAsNumber, int imageWidth, int midCol, int prevRow, string rule) {

        int leftCol = (midCol - 1) < 0 ? imageWidth - 1 : midCol - 1;
        int rightCol = (midCol + 1) >= imageWidth ? 0 : midCol + 1;
        int prevLeft = imageAsNumber[prevRow][leftCol]; //0
        int prevCenter = imageAsNumber[prevRow][midCol]; //1
        int prevRight = imageAsNumber[prevRow][rightCol]; //0
        int ruleIndex = (prevLeft << 2) | (prevCenter << 1) | (prevRight);
        // 0<<2   | 1<<1  | 0
        // 000   | 10 | 0   == > 010 ==> 2

        return (rule[RULE_SIZE - 1 - ruleIndex] == '1' ? 1 : 0);
    }

    void solveSequential(int imageWidth,
        int imageHeight,
        int** imageAsNumber,
        string rule) {

        for (int row = 1; row < imageWidth; row++) {
            for (int col = 0; col < imageHeight; col++) {
                imageAsNumber[row][col] = this->applRule(imageAsNumber, imageWidth, col, row - 1, rule);
            }
        }
        this_thread::sleep_for(chrono::seconds(1));
    }

    void reset(int imageWidth, int imageHeight, int** imageAsNumber) {

        for (int j = 0; j < imageHeight; j++) {
            imageAsNumber[0][j] = 0;
        }
        imageAsNumber[0][imageWidth / 2] = 1;
    }

    void seqSolution() {
        int imageWidth = SIZE;
        int imageHeight = SIZE;

        int* imageAsNumber[SIZE];
        for (int i = 0; i < imageHeight; i++) {
            imageAsNumber[i] = new int[imageWidth];
        }
 
        for (int ruleID = 0; ruleID <= NUMBER_OF_RULES; ruleID++) {
            string rule = bitset<RULE_SIZE>(ruleID).to_string();
            //cout << ruleID << endl;
           // cout << rule << endl;

            //sequenatail
            this->reset(imageWidth, imageHeight, imageAsNumber);

            string filePathSeq = "game/pgm" + rule + "Seq.pgm";
            this->solveSequential(imageWidth, imageHeight, imageAsNumber, rule);
            this->saveToFile(imageWidth, imageHeight, imageAsNumber, filePathSeq);

        }

        //clean
        for (int i = 0; i < imageHeight; i++) {
            delete[] imageAsNumber[i];
        }
    }



    void worker(int imageWidth,int imageHeight, int& ruleID) {

        //cout << "\nworker thread ID:" << this_thread::get_id() << endl;

        int* imageAsNumber[SIZE];
        for (int i = 0; i < imageHeight; i++) {
            imageAsNumber[i] = new int[imageWidth];
        }
        CellularAutomaton cellularAutomaton;

        while (true) {
            //cout <<"\n ->worker Wating ID:" << this_thread::get_id() << endl;
            this->mtx.lock();
            string rule = bitset<RULE_SIZE>(ruleID).to_string();
            ruleID = ruleID + 1;
            if (ruleID > NUMBER_OF_RULES) {
                this->mtx.unlock();
                break;
            }
            this->mtx.unlock();
            //cout << "\n->worker Start ID:" << this_thread::get_id() << endl;


            //sequenatail
            cellularAutomaton.reset(imageWidth, imageHeight, imageAsNumber);

            string filePathSeq = "game/pgm" + rule + "Parl.pgm";
            //cout << "worker start index:" << this_thread::get_id() << ", pick image:" << filePathSeq << endl;
            cellularAutomaton.solveSequential(imageWidth, imageHeight, imageAsNumber, rule);
            //cout << "worker start index:" << this_thread::get_id() << ", Save image:" << filePathSeq << endl;
            cellularAutomaton.saveToFile(imageWidth, imageHeight, imageAsNumber, filePathSeq);

        }

        //clean
        for (int i = 0; i < imageHeight; i++) {
            delete[] imageAsNumber[i];
        }

    }

    void parSolution() {
       

        int imageWidth = SIZE;
        int imageHeight = SIZE;
        int ruleID = 0;

        int numberOfThreads = 10;

        vector<thread> listOfThreads;
        for (int i = 0; i < numberOfThreads; i++) {
          //  cout << " Thread is added with index:" << i << endl;
            listOfThreads.push_back(thread(&CellularAutomaton::worker,this, imageWidth,imageHeight,ref(ruleID)));
        }

       // cout << " Waiting for thread to finish" << endl;
        for (auto& thread : listOfThreads) {
            thread.join();
        }
       // cout << " All thread works done" << endl;

    }

};




 
 

int main22() {

    cout << "main thread ID:" << this_thread::get_id() << endl;

    CellularAutomaton cellularAutomaton;
   
    clock_t start = clock();
    cellularAutomaton.seqSolution();
    clock_t end = clock();
    double timeSpend = (end - start) / CLOCKS_PER_SEC * 1000;
    cout << "Time to finish seqSolution was:" << timeSpend << "ms" << endl;
     


    start = clock();
    cellularAutomaton.parSolution();
    end = clock();
    timeSpend = (end - start) / CLOCKS_PER_SEC * 1000;
    cout << "Time to finish parallel was:" << timeSpend << "ms" << endl;

    return 0;
}

