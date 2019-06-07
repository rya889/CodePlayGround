using System;
using System.IO;

namespace _2dArrayProject
{

    public class Array2d
    {   
        private int[][] arr;
        public Array2d(int[][] arr_in)
        {
            arr = arr_in;
        }
        public int solve()
        {
            int max = -36000;

            for (int i = 1;i < arr.Length-1;i++)
            {
                for (int j = 1;j < arr.Length-1;j++)
                {
                    int result = sumI(j,i);
                    if (result > max)
                    {
                        max = result;
                    }
                }
            }
            return max;
        }
        public int sumI(int x,int y)
        {
            return arr[y-1][x-1]+arr[y-1][x]+arr[y-1][x+1]+arr[y][x]+arr[y+1][x-1]+arr[y+1][x]+arr[y+1][x+1];
        }
    }    
    class Program
    {

        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            int[][] arr = new int[6][];
            using (StreamReader sr = new StreamReader("../input.txt"))
            {
                String line; 
                int i = 0;
                while ((line = sr.ReadLine()) != null)
                {                       
                    string[] str_split = line.Split(" ");
                    //arr[i] = Int32.TryParse(str_split);
                    arr[i] = Array.ConvertAll(str_split, int.Parse);
                    i++;
                }                
            }
            Console.WriteLine(new Array2d(arr).solve());
        }
    }
}
