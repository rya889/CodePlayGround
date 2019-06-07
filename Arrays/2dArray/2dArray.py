# 2dArray.py
# https://www.hackerrank.com/challenges/2d-array/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays 
import math

def main():
	# import from input
	f = open("input.txt", "r")
	arr = []
	for i in f:
		#print([int(i) for i in i.rstrip().split()])
		#arr.append(list())
		arr.append([int(i) for i in i.rstrip().split()])
	f.close()
	#print(arr)
	sol = array2d(arr).solve()
	print(sol)
	#invoke class

class array2d:
	
	def __init__(self, arr_in):
		self.arr = arr_in

	def solve(self):
		max_sum = float("-inf")
		for x in range(1,len(self.arr[0])-1):
			for y in range(1,len(self.arr[0])-1):
				sum_pos = self.sumI(x,y)
				if sum_pos > max_sum:
					max_sum = sum_pos

		return max_sum
	def sumI(self,x, y):
		#Assumes hour glass is valid
		# Sums top row

		sum_hourglass = sum(self.arr[x-1][y-1:y+2])
		sum_hourglass += self.arr[x][y]
		sum_hourglass += sum(self.arr[x+1][y-1:y+2])
		return sum_hourglass

main()