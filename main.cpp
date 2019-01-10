/*
Ramamurthy Sundar
student id: 00667077
netid: rsundar
CPS 272 - Machine Problem 2
Fall 2018

main.cpp

Driver for Machine Problem 2.  This program asks for a file name from the user 
and then stores that information in vectors.  These vectors are candidate and vote
vectors.

The vectors themeselves are a student defined class called an Election vector.
This program makes use of the student defined vector in class.h.  Please see
the corresponding class.cpp file for the implementation of the class.

The program creates a processed vector which shows the percentage of votes
earned by each candidate. 

The 3 vectors are then sorted with a simple bubble sort algorithm, which sorts the
candidates based on who earned the most votes.
   
The results are then posted in an output text file.
*/
#include "class.h"

using namespace std;

//helper function
void swap(int *x, int *y) {

	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int main() {
	
	//recieve input from user
	string fileName;
	cout << "Please Enter a Filename: "; 
	cin >> fileName;

	//create file streams
	ifstream infile; 
	ofstream outfile;
	infile.open(fileName);
	outfile.open("OutputFile");
	
	//reading from infile
	string candidateName;
	int numberOfVotes;
	string header1, header2;
	ElectionVector<int> voteVector(0);
	ElectionVector<string> candidateVector(0);
	
	//push the info from the file stream to the vectors
	infile >> header1 >> header2;
	while (!infile.eof()) {
		infile >> candidateName >> numberOfVotes;
		voteVector.push_back(numberOfVotes);
		candidateVector.push_back(candidateName);
	}

	//find total number of votes
	double sum = 0;
	for (unsigned int i = 0; i < voteVector.size(); i++) {
		sum += voteVector[i];
	}
	//push the percentages onto a vector
	ElectionVector<double> percentageVector(0);
	for (unsigned int i = 0; i < voteVector.size(); i++) {
		percentageVector.push_back(100 * (voteVector[i] / sum));
	}

	//arange the vectors with a bubble sort algorithm
	int i, j;
	bool swapped;
	for (i = 0; i < voteVector.size() - 1; i++)
	{
		swapped = false;
		for (j = 0; j < voteVector.size() - i - 1; j++)
		{
			if (percentageVector[j] < percentageVector[j + 1]) {
				swap(candidateVector[j], candidateVector[j + 1]);
				swap(percentageVector[j], percentageVector[j + 1]);
				swap(voteVector[j], voteVector[j + 1]);
			}
			swapped = true;
		}
		// IF no two elements were swapped by inner loop, then break 
		if (swapped == false) break;
	}
	
	//output the results into a text file
	int candidate_align = 30; int percentage_align = 20;
	outfile << "Candidate" << setw(20) << "Votes Revieced" << setw(20) << "% Votes" << endl;
	for (unsigned int i = 0; i < voteVector.size(); i++) {
		outfile << std::setprecision(1) << std::fixed; //set number of decimals
		outfile << candidateVector[i] << setw(candidate_align - candidateVector[i].size())
			<< voteVector[i] << setw(percentage_align) << percentageVector[i] << endl;
	}

	//close file streams
	infile.close();
	outfile.close();

	return 0;
}