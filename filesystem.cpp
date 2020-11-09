#include <iostream>
#include "filesystem.h"

FileSystem::FileSystem()
{
string temp=".txt";
ostringstream os;
Monte object;
int howmanyfiles=4; //4 because we have 4 files. If we had more files we would simply name them tn.txt where n is a number and we set this to the amount we have
for(int i=1;i<=howmanyfiles;i++)
{
 os.str("");
 temp.clear();
 os << "t" << i << ".txt";
 temp = os.str();
file.open(temp);
if( file.fail())
{cout <<"Fail";
exit(1);}

cout << "Simulation " << i << ": " << endl << endl;
Read(); // this reads the file that was just opened
Display(); // Display the simulation..
Run(); // this creates the data set for the run
object.Run(batches,samples,numitems); //this runs the monte alg on this particular set of files that were created
Delete(); //this deletes the files that were created
Compute();
cout << endl << endl;
}

}

void FileSystem::Run()
{

cout << "Generating data sets: " << endl << endl;
Random object;
double badbatch = batches*(percbatch/100); // badbatch is the total bad batches that must be created
//we must create
string temp=".txt";
ostringstream os;
//creating the data sets in this for loop
for(int j=1; j<=batches; j++)
{
	os.str("");
	temp.clear();
	os << "ds" << j << ".txt";
	temp = os.str(); // temp is now the name of the file to be created
  
	if(j<=badbatch) // creating bad batch
	{
	write.open(temp);
	int randomnumber;
	int badcount=0;
	cout << "Create bad set batch # " << j << ", ";
		for(int k=1;k<=numitems;k++)
       		{
		randomnumber= object.getrand(100); // random number from 1 to 100
			if(randomnumber<=percitems) // case where random number is less than the percentage of bad items meaning that we need to write a bad item.
			{
			write << "b\n";	
			badcount++;
			}
			else
			{
			write << "g\n";
			}

		}
	write.close();
	cout << "totBad = " << badcount << "  total= " << numitems << "  badpct = " << percitems << endl; 
	}
	else // good batches
	{
		write.open(temp);
		for(int k=1;k<=numitems;k++)
		{write << "g\n";}
		write.close();
	}

}

}

void FileSystem::Read()
{
file>>batches;
file>>numitems;
file>>percbatch;
file>>percitems;
file>>samples;
file.close();
}
void FileSystem::Delete()
{
string temp=".txt";
ostringstream os;
for(int i=1; i<=batches; i++)
{
        os.str("");
        temp.clear();
        os << "ds" << i << ".txt";
        temp = os.str(); // temp is now the name of the file to be created
	if(remove(temp.c_str()) !=0)
	cout<<"Remove operation failed"<<endl;
}
}

void FileSystem::Display()
{
cout << "Number of batches of items: " <<batches  << endl;
cout << "Number of items in each batch " << numitems << endl;
cout << "Percentage of batches containing bad items " <<percbatch  << " % "<< endl;
cout << "Percentage of items that are bad in a bad set " << percitems << "%"<<endl;
cout << "Items sampled from each set " << samples << endl << endl;
}
void FileSystem::Compute()
{
double base= (100-percitems)/100;
double prob= pow(base,samples);
cout << endl<<" Base = " << base << "  exponent = " << samples << endl;
cout << "P(failure to detect bad batch) = " << prob <<endl;
cout << "Percentage of bad batches actually detected = " << 100-(prob*100) << " %" <<endl << endl;
}
