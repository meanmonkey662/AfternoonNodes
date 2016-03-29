/*
 * NodeController.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: kkoc6943
 */

#include "NodeController.h"
#include <iostream>
#include <stdlib.h

using namespace std;

NodeController::NodeController()
{
	notHipsterInts = new CTECArray<int>(5);
}

NodeController::~NodeController()
{

}

void NodeController :: start()
{
	for(int index = 0; index < notHipsterInts->getSize(); index++)
	{
		notHipsterInts->set(index, (index * 23));
	}

	for(int index = notHipsterInts->getSize()-1; index >= 0; index--)
	{
		cout << "The contents of the notHipsterInts array node" << index << " are: " << notHipsterInts->get(index) << endl;
	}

	arrayTimer.stopTimer();
	arrayTimer.dislayTimerInformation();

}

void NodeController::sortData();
{
    /*
     creare a CTECList, CTECArray
     Fill them with random stuff(numbers)
     Start a timer, sort, stop timer, display info for list
     Start a timer, sort, stop timer, display info for array
     */
    CTECArray<int> randomNumberArray(5000);
    CTECList<int> randomNumberList;
    intmyCPlusPlusArray[5000];
    
    for(int spot = 0; spot <5000; spot++)
    {
        int myRandom = rand();
        randomNumberArray.set(spot, myRandom);
        randomNumberList,addToEnd(myRandom);
        myCPlusPlusArray[spot] = myRandom;
    }
    
    Timer sortTimer;
    sortTimer.startTimer();
    randomNumberArray.selectionSort();
    sortTimer.stopTimer();
    sortTimer.displayTimerInformation();
    
    sortTimer.resetTimer();
    
    sortTimer.startTimer();
    std::sort(std::begin(mCPlusPlusArray), std::end(myCPlusPlusArray));
    sortTimer.stopTimer();
    sortTimer.displayTimerInformation();
    
    sortTimer.resetTimer();
}
