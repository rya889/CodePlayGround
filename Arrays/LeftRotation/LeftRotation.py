
import math


class LeftRotation:
	
	n = d = 0
	n_arr = []
	def __init__(self,n_arr_in, n_in, d_in):
		self.n = n_in
		self.d = d_in
		self.n_arr = n_arr_in

	def solve(self):

		print self.n
		print self.d
		print self.n_arr
		temp = self.n_arr[self.d:len(self.n_arr)]
		temp.extend(self.n_arr[0:self.d])

		return temp



def main():
	f = open("input.txt");
	nd = []
	n = []
	
	nd = ([int(i) for i in f.readline().rstrip().split()])
	n_arr = ([int(i) for i in f.readline().rstrip().split()])
	#print(nd);
	#print(n);
	print(LeftRotation(n_arr,nd[0],nd[1]).solve())
main()