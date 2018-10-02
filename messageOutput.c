#include <iostream>

void output_table()
{
	//we have to get a bit of information to know how to output this badboy
	//get destination message type and store it in a parallel array to the destination pid
	//get destination pid of a message
	//get source message type and store it in a parallel array to the soruce pid
	//get source pid of a message
	//get min possible pid
	//get max possible pid
	//This code may come in handy for creating the process table if that is something we have to do
		//create_proc_table()
		// while(messagesLeft != 0)
		// {
		// proc_table[destinationPid][sourcePid] = proc_table[destinationPid][sourcePid]++;
		// messagesLeft--;
		//}
	int[] pidList1 = new bool[maxPid - minPid];
	int[] pidList2 = new bool[maxPid - minPid];
	bool flag;
	//check if any horizontal rows are all 0
	//thus we do not need to output that row
	//so we set the list in the pidList equal to false
	for(int i = minPid; i < maxPid; i++)
	{
		for(int j = minPid; j < maxPid; j++)
		{
			if(flag != false && proc_table[i][j] == 0)
			{
				flag = true;
			}
			else
			{
				flag = false;
			}
		}
		pidList2[i] = !flag;
		flag = true;
	}
	//check if any vertical columns are all 0
	//thus we do not need to output that column
	//so we set the list in the pidList equal to false
	for(int j = minPid; j < maxPid; j++)
	{
		for(int i = minPid; i < maxPid; i++)
		{
			if(flag != false && proc_table[i][j] == 0)
			{
				flag = true;
			}
			else
			{
				flag = false;
			}
		}
		pidList2[j] = !flag;
		flag = true;
	}
	//now output the actuall thing
	//use cout?
	for(int i = minPid; i < maxPid; i++)
	{
		std::cout << proc_name << i;
		for(int j = minPid; j < maxPid; j++)
		{
			std::cout << proc_table[i][i];
		}
		std::cout << endl;
	}
}