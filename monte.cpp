#include <iostream>
#include "monte.h"

Monte::Monte()
{
}
void Monte::Run(double batches, double samples,double items)
{
cout << "Analyzing Data Sets:  " << endl << endl;	
Random object;
int randomnumber;
fstream f;
ostringstream os;
string temp=".txt",s;
bool decision=true;
for(double i=1; i<=batches;i++)
{	
	decision=true;
	os.str("");
        temp.clear();
        os << "ds" << i << ".txt";
        temp = os.str(); 
	f.open(temp);
	
	for(double j=1; j<=samples; j++)
	{
		s.clear();
		randomnumber=object.getrand(items); // generate a random number from 1 to amount of items in a particular batch
		GotoLine(f,randomnumber);
		f>>s;

		if(s=="b")
		{decision=false;}

	}
	f.close();
	
	if(decision)
	{//good file
	}		
	else
	{// bad file
	cout << "File #" <<i << " is bad ." << endl;
	}	


}

}

fstream& Monte::GotoLine(fstream& file, unsigned int num)
{
    file.seekg(ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    return file;
}
