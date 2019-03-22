/*
Author: Ryan Bezold
Assignment: Project 1
Section 402
*/
#include < IOStream >
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	//initialize text reading
	ifstream f;
	ofstream fout;
	//initalize variables
	string date;
	int numReadings, max = 0, min = 99;

	//if reading the file doesnt fail
	if (!f.fail())
	{
		//open file for reading
		f.open("tempsin.txt");
		fout.open("tempsout.txt");
			
			//print table head
			fout << "DATE       HIGH  LOW" << endl;
			fout << "---------- ---- ----" << endl;

			//continue as long as the value ENDOFDATE is not where the date should be
			while (date != "ENDOFDATA")
			{
				//reset min and max values
				max = 0;
				min = 99;

				//get the date from the text document and set it to date
				f >> date;

				//if it read a date and not ENDOFDATA continue
				if (date != "ENDOFDATA")
				{
					//get the number of readings from the text document
					f >> numReadings;

					//loop as many of times as the text document says
					for (int i = 0; i < numReadings; i++)
					{
						int temp;
						f >> temp;
						if (temp > max)
						{
							//compare current value with max and set it to max if it is bigger
							max = temp;
						}
						if (temp < min)
						{
							//compare current value with min and set it to min if it is smaller
							min = temp;
						}
					}
					// output today's values
					fout << date << "   " << setw(2) << right << max << "   " << setw(2) << right << min << endl;
				}
				
			}

		
		// close for reading
		f.close();
		fout.close();

	}
	else // if the file failed to be read
	{
		//output it failed
		cout << "Error reading file.";

		//end program
		return 0;
	
	}
	//pause the system for the user to input

	//end program
	return 0;

}