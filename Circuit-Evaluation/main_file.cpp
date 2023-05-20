/////////////////////////////////////////////////// Hamvir Dev EE2204M0089 ////////////////////////////////////////////////////
#include<bits/stdc++.h>
//#include<iostream>
//#include<fstream>
//#include<string.h>
//#include<vector>
using namespace std;

/////// GATE STRUCTURE ///////

struct gate
{
    string gate_name,gate_type;           // stores gate name and type
    vector<int> v;                        // stores gate inputs and outputs
};


///// FUNCTION FOR STRING TO INT CONVERSION /////

//int stoi(string str)
//{
//	int x=0;
//	int j=1;
//	for(int i=str.size()-1;i>=0;i--)
//	{
//		x=x+j*(str[i]-48);
//		j=j*10;
//	}
//	return(x);
//}

///// FUNCTION TO FIND OUTPUT OF A GATE /////

void find_output(struct gate obj, int *arr, int n)
{
	if(obj.gate_type=="AND2")
	{
		if(arr[obj.v[0]-1]==1 && arr[obj.v[1]-1]==1)
		arr[obj.v[2]-1]=1;
		else
		arr[obj.v[2]-1]=0;
	}
	else if(obj.gate_type=="OR2")
	{
		if(arr[obj.v[0]-1]==1 || arr[obj.v[1]-1]==1)
		arr[obj.v[2]-1]=1;
		else
		arr[obj.v[2]-1]=0;
	}
	else if(obj.gate_type=="NOT")
	{
		if(arr[obj.v[0]-1]==1)
		arr[obj.v[1]-1]=0;
		else
		arr[obj.v[1]-1]=1;
	}
	else if(obj.gate_type=="NAND2")
	{
		if(arr[obj.v[0]-1]==1 && arr[obj.v[1]-1]==1)
		arr[obj.v[2]-1]=0;
		else
		arr[obj.v[2]-1]=1;
	}
	else if(obj.gate_type=="NOR2")
	{
		if(arr[obj.v[0]-1]==0 && arr[obj.v[1]-1]==0)
		arr[obj.v[2]-1]=1;
		else
		arr[obj.v[2]-1]=0;
	}
	else if(obj.gate_type=="XOR2")
	{
		if(arr[obj.v[0]-1] == arr[obj.v[1]-1])
		arr[obj.v[2]-1]=0;
		else
		arr[obj.v[2]-1]=1;
	}
	else if(obj.gate_type=="XNOR2")
	{
		if(arr[obj.v[0]-1] == arr[obj.v[1]-1])
		arr[obj.v[2]-1]=1;
		else
		arr[obj.v[2]-1]=0;
	}
	else if(obj.gate_type=="NAND3")
	{
		if(arr[obj.v[0]-1]==1 && arr[obj.v[1]-1]==1 && arr[obj.v[2]-1]==1)
		arr[obj.v[3]-1]=0;
		else
		arr[obj.v[3]-1]=1;
	}
	else if(obj.gate_type=="NOR3")
	{
		if(arr[obj.v[0]-1]==0 && arr[obj.v[1]-1]==0 && arr[obj.v[2]-1]==0)
		arr[obj.v[3]-1]=1;
		else
		arr[obj.v[3]-1]=0;
	}
	else
	{
		cout<<"Given gate is not specified"<<endl;
	}
}

int main()
{
    ifstream infile;
    string skip;
    int N,E,P;                // input params

    infile.open("input_data.txt",ios::in | ios::binary );

    /////////////////////////  PART - 1 - READING INPUTS FROM FILE /////////////////////////////


    ///// READING N E P /////

    for(int i=0;i<3;)
    {
        char c = infile.get();
        infile.seekg(-1,ios::cur);

        if(c=='#')
        {
            getline(infile,skip);               // discard lines starting with #
            continue;
        }
        else                                    // else read the 1st 3 inputs
        {
            i++;
            string str;
            getline(infile,str);

            if(i==1)
            N=stoi(str);
            else if(i==2)
            E=stoi(str);
            else
            P=stoi(str);

        }
    }
    //cout<<N<<endl<<E<<endl<<P<<endl;
    int Net[N];

    for(int i=0;i<N;i++)                         // initialising all net values
    Net[i]=-1;

    ///// READING GATES DATA /////

    struct gate U[E];

    for(int i=0;i<E;)
    {
        char c = infile.get();
        infile.seekg(-1,ios::cur);
        if(c=='#')
        {
            getline(infile,skip);                 // discard lines starting with #
            continue;
        }
        else                                      // else read data and store in gate structure
        {

            string str,temp;
            getline(infile,str);
            int k=1;

            for(int j=0;j<str.size();j++)
            {

                if(str[j]==' ')
                {
                    if(k>2)
                    {
                        int x= stoi(temp);
                        temp.clear();
                        (U[i].v).push_back(x);
                    }


                    k++;
                }
                else if(k==1)
                {
                    U[i].gate_name=U[i].gate_name+str[j];
                }
                else if(k==2)
                {
                    U[i].gate_type=U[i].gate_type+str[j];
                }
                else
                {
                    temp = temp+str[j];
                }

            }
            int x= stoi(temp);
            temp.clear();
            (U[i].v).push_back(x);

            i++;
        }
    }


//    cout<<U[0].gate_name<<endl<<U[0].gate_type<<endl;
//    for(int i=0;i<((U[0].v).size());i++)
//    cout<<U[0].v[i]<<endl;
//
//    cout<<U[1].gate_name<<endl<<U[1].gate_type<<endl;
//    for(int i=0;i<((U[1].v).size());i++)
//    cout<<U[1].v[i]<<endl;


 ///// READING INPUT NETS /////

 for(int i=0;i<P;)
 {
 	    char c = infile.get();
        infile.seekg(-1,ios::cur);
//        string temp;
        if(c=='#')                             // discard lines starting with #
        {
            getline(infile,skip);
            continue;
        }
        else                                   // else read and store input values
        {
        	string str,temp;
        	int input,value;
            getline(infile,str);

            for(int j=0;j<str.size();j++)
            {
            	if(str[j]==' ')
            	{
            		input=stoi(temp);
            		temp.clear();

				}
				else
				{
					temp=temp+str[j];
				}
			}
			value=stoi(temp);
            Net[input-1]=value;


        	i++;
		}
 }

// for(int i=0;i<N;i++)
// cout<<Net[i]<<endl;

    /////////////////////////  PART - 2 - CALCULATE OUTPUT  /////////////////////////

    int arr[E]={0};
    int count = 0,prev=-1;
    while(count<E)                                // run till all gates' output are calculated
    {
    	for(int i=0;i<E;i++)                      // for all gate find output given its inputs are known
    	{
    		int flag=0;
    		for(int j=0;j<((U[i].v).size())-1;j++)       // checks if all inputs of a gate are known
    		{
    			if(Net[U[i].v[j]-1]==-1)
    			{
    				flag=1;
    				break;
				}
			}
			if(flag==0 && arr[i]!=1)                     // if all inputs are known then its output is found
			{
				find_output(U[i],Net,N);
				count++;
				arr[i]=1;
			}
		}
		if(prev==count)
		break;
		else
		prev=count;
	}

    ////////////////////// PART - 3 - WRITE OUTPUT IN A TEXT FILE ///////////////////////


	for(int i=0;i<N;i++)          // prints output in running time
	cout<<Net[i]<<endl;

	ofstream outfile;
	outfile.open("output.txt");

	for(int i=0;i<N;i++)          // stores output in a text file
	{
		outfile<<i+1<<" "<<Net[i]<<endl;
	}


 return 0;

}
