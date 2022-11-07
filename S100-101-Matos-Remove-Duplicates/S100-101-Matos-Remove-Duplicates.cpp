// S100-101-Matos-Remove-Duplicates.cpp 

#include <iostream>
#include <vector>
using namespace std;

//Prototypes ---------------------------------------------------
void showVector(vector<int> v, string caption);
int  countOccurrences(int item, vector<int> v);
void removeDuplicatesVersion1(vector<int>& v1);
void removeDuplicatesVersion2(vector<int>& v1);

int main()
{
    vector<int> v1 = { 5, 2, 5,5, 1, 10, 7, 5, 4, 7 };

    showVector(v1, "This is v1 before removal version1");
    //removeDuplicatesVersion1(v1);
    removeDuplicatesVersion2(v1);
    showVector(v1, "This is v1 after removal version1");

}

//User-defined functions ----------------------------------------
void showVector(vector<int> v, string caption)
{
    cout << endl << caption << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << ", ";
    }
    cout << endl;
}


void removeDuplicatesVersion1(vector<int>& v1)
{
    vector<int> vNew;
    for (int i = 0; i < v1.size(); i++)
    {
        if (countOccurrences(v1[i], v1) == 1)
        {
            vNew.push_back(v1[i]);
        }
    }
    v1 = vNew;
}

int countOccurrences(int item, vector<int> v)
{
    int counter = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == item) counter++;
    }
    return counter;
}

void removeDuplicatesVersion2(vector<int>& v)
{
    int i = 0;
    while(i < v.size())
    {
        int item = v[i];
        bool found = false;
        //Visiting neigbors from rigth to left
        int j = v.size() - 1;

        while (j > i) 
        {
            if (v[j] == item)
            {
                v.erase(v.begin() + j);
                found = true;
            }
            j--;
        }

        if (found)
        {
            v.erase(v.begin() + i);
        }
        i++;
    }
}