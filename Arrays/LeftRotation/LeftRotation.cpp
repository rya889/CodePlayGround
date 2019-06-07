
#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <vector> 


using namespace std;


void printvector(vector<int> arr_in) {
	for(size_t i = 0; i < arr_in.size();i++) {		
		cout << arr_in[i];
		cout << endl;
	}

}
class LeftRotation
{
	private:
		int n, d;
		vector<int> arr;
	public:
		LeftRotation(int d_in, vector<int> arr_in)
		{
			d = d_in;
			arr = arr_in;
		}
		vector<int> solve()
		{
			vector<int> answer(arr.size());
			int d_mod = d % arr.size();
			int x = 0;

			for (int i = d_mod;i<arr.size(); i++)
			{
				answer[x] = arr[i];
				x++;
			}

			for (int i = 0;i<d_mod;i++)
			{
				answer[x] = arr[i];
				x++;
			}
			return answer;

		}

};

int main()
{
	fstream myfile;
	myfile.open("input.txt");
	string line, row;
	vector<int> arr;
	int n, d = 0;
	if (myfile.is_open()) {
		
		getline(myfile, row, '\n');
		stringstream ssin(row);
		string word;
		ssin >> word;
		n = atoi(word.c_str());
		ssin >> word;
		d = atoi(word.c_str());

		getline(myfile, row, '\n');
		ssin.str(row);
		ssin.clear();
		arr.resize(n);
		int i = 0;

		while(ssin.good()) {
			ssin >> word;
			arr[i] = atoi(word.c_str());
			i++;
		}
	}
	//printvector(arr);
	printvector((new LeftRotation(d, arr))->solve());
	myfile.close();
}