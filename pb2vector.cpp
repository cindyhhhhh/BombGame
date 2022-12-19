#include"helper.h"
#include <stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <stdint.h>
#include <iostream> 
#include <inttypes.h>
#include<string.h>
#include<vector>

using namespace std;

struct event
{
	int t;
    int c;
    long long d;
    int l;
    int r;
    long long p;
    int k;
    int code;
};


bool sortpower(event A, event B)
{
    return A.p<B.p;
}

bool sortdefense(event A, event B)
{
    return A.d>B.d;
}

int Bombing(vector<event> input, int first, int last, vector<int>&Output)
{
	if(last-first == 0)
	{
		return 0;
	}
	if(last-first == 1)//2 char
    {
        if(input[first].t==0 && input[last].t==1)//PA
        {
            if(input[first].c >= input[last].l && input[first].c <= input[last].r)
            {
                if(input[first].d <= input[last].p)
                {
                    int index = input[first].code;
                    Output[index] = Output[index] + input[last].k;
                }
            }
        }
        return 0;
    }

    
    int mid=(first+last)/2;
    vector<event> Left;
    vector<event> Right;
    vector<event> UsedBomb;


    Left.assign(input.begin(),input.begin()+ mid);
    Right.assign(input.begin()+mid,input.end());


    Bombing(Left, 0, Left.size(), Output);
    Bombing(Right, 0, Right.size(), Output);

    sort(Left.begin(), Left.end(), sortdefense);
    sort(Right.begin(), Right.end(), sortpower);


    for(int i = 0; i < Left.size() && Left[i].d > 0; i++)
    {
        while(Right.size()!=0 && Right[Right.size()-1].p >= Left[i].d)
        {
            Memory::add(Right[Right.size()-1].l, Right[Right.size()-1].r, Right[Right.size()-1].k);
            UsedBomb.push_back(Right[Right.size()-1]);
            Right.pop_back();
        }
        int index = Left[i].code;
        Output[index] = Output[index] + Memory::get(Left[i].c);
    }
    for(int j = 0; j < UsedBomb.size(); j++)
    {
        Memory::add(UsedBomb[j].l, UsedBomb[j].r, -UsedBomb[j].k);
    }

    return 0;
}

int main()
{
	int N, M;
	cin >> N;
	cin >> M;
	vector<event> Input;
    event one;
    int j = 0;
	 
	for( int i = 0 ; i < M; i++)
	{
		char A;
		cin >> A;
		if ( A == 'P')
		{
		    int c;
		    long long d;
            one.code = j;
			one.t = 0;
			scanf("%d %lld", &c, &d); 
			one.c = c;
			one.d = d;
            one.p = -1;
            Input.push_back(one);
            j++;
		}
		if ( A == 'A')
		{
			int l;
		    int r;
		    long long p;
		    int k;
			one.t = 1;
			scanf("%d %d %lld %d", &l, &r, &p, &k); 
			one.l = l;
			one.r = r;
			one.p = p;
			one.k = k;
			one.d = -1;
            Input.push_back(one);
		}
	}
    vector<int> Output(j,0);
	int d =Bombing(Input, 0, M-1, Output);

    for (int i = 0; i < Output.size(); i++)
    {
        printf("%d\n",Output[i]);
    }
	return 0;
}