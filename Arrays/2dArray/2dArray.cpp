#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <vector> 

using namespace std;


void print_2d_vector(vector<vector<int> > arr_in) {
	for(size_t i = 0; i < arr_in.size();i++) {
		for(size_t j = 0; j < arr_in[i].size();j++)	{
			cout << arr_in[i][j];
		}
		cout << endl;
	}

}
class Array2d {
	private:
	vector<vector<int> > arr;
	public:
	Array2d(vector<vector<int> > arr_in) {
		arr = arr_in;
		//print_2d_vector(arr);
	}

	int solve() {
		int max = -360;
		for (size_t i = 1; i<arr.size()-1;i++) {
			for (size_t j = 1; j < arr[0].size()-1 ; j++) {
				int sum = sumI(i,j);
				if (sum > max) {
					max = sum;
				}

			}
		}
		return max;
	}

	int sumI(int x, int y)
	{
		// Assumes valid I shape
		
		//int ret = arr[x-1][y-1]+arr[x][y-1]+arr[x+1][y-1]+arr[x][y]+arr[x-1][y+1]+arr[x][y+1]+arr[x+1][y+1];
		int ret = arr[x-1][y-1]+arr[x-1][y]+arr[x-1][y+1]+arr[x][y]+arr[x+1][y-1]+arr[x+1][y]+arr[x+1][y+1];

		//cout << x << " " << y << " "<< ret<< endl;

		return ret;
	}
};

int main() {
	//std::cout << "Hello world!" << std::endl;
	fstream myfile;
	myfile.open("input2.txt");
	string line,row;
	vector<vector<int> > arr(6);
	if(myfile.is_open()) {
		int i= 0;
		while(getline(myfile,row, '\n')) {

			stringstream ssin(row);
			string word;
			int j = 0;
			arr[i].resize(6);
			while(ssin.good()) {
				ssin >> word;
				arr[i][j] = atoi(word.c_str());
				j++;
			}					
			i++;
		}
	}
	myfile.close();

	Array2d * sol = new Array2d(arr);
	cout << sol->solve() << endl;

}


